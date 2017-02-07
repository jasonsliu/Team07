// Based Off http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/example/cpp11/http/server/request_handler.cpp
#include "file_handler.hpp"
#include <fstream>
#include <sstream>

namespace http {
namespace server {

bool file_handler::url_decode(const std::string& in, std::string& out)
{
	out.clear();
	out.reserve(in.size());
	for (std::size_t i = 0; i < in.size(); ++i)
	{
	  if (in[i] == '%')
	  {
	    if (i + 3 <= in.size())
	    {
	      	int value = 0;
	      	std::istringstream is(in.substr(i + 1, 2));
	      	if (is >> std::hex >> value)
	      	{
			out += static_cast<char>(value);
			i += 2;
	      	}
		else
		{
	  		return false;
		}
		}
		else
		{
			return false;
		}
		}
		else if (in[i] == '+')
		{
			out += ' ';
		}
		else
		{
			out += in[i];
		}
	}
	return true;
}

void file_handler::handle_request(const request &req, reply& rep){
	std::string request_path;
	if (!url_decode(req.uri, request_path))
	{
	rep = reply::stock_reply(reply::bad_request);
	return;
	}
	if (request_path.empty() || request_path[0] != '/'
	|| request_path.find("..") != std::string::npos)
	{
	rep = reply::stock_reply(reply::bad_request);
	return;
	}

	if (request_path[request_path.size() - 1] == '/')
	{
	request_path += "index.html";
	}

	// Determine the file extension.
	std::size_t last_slash_pos = request_path.find_last_of("/");
	std::size_t last_dot_pos = request_path.find_last_of(".");
	std::string extension;
 	if (last_dot_pos != std::string::npos && last_dot_pos > last_slash_pos)
	{
	extension = request_path.substr(last_dot_pos + 1);
	}

	std::string full_path = docroot + request_path;
	std::ifstream is(full_path.c_str(), std::ios::in | std::ios::binary);
	if (!is)
	{
	rep = reply::stock_reply(reply::not_found);
	return;
	}

	rep.status = reply::ok;
	char buf[512];
	while (is.read(buf, sizeof(buf)).gcount() > 0)
rep.content.append(buf, is.gcount());
	rep.headers.resize(2);
	rep.headers[0].name = "Content-Length";
	rep.headers[0].value = std::to_string(rep.content.size());
	rep.headers[1].name = "Content-Type";
	
	if(extension == "gif") {
		extension = "image/gif";
	}
	else if (extension == "htm") {
		extension = "text/html";
	}
	else if (extension == "html") {
		extension = "text/html";
	}
	else if (extension == "jpg") {
		extension = "image/jpg";
	}
	else if (extension == "png") {
		extension = "image/png";
	}
	else {
		extension = "text/plain";
	}
	rep.headers[1].value = extension;
}

}
}
