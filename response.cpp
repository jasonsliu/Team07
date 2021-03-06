//Based off http://www.boost.org/doc/libs/1_62_0/doc/html/boost_asio/example/cpp11/http/server/Response.cpp

#include "response.hpp"
#include <string>

namespace http {
namespace server {

namespace status_strings {

const std::string ok =
  "HTTP/1.1 200 OK\r\n";
const std::string created =
  "HTTP/1.1 201 Created\r\n";
const std::string accepted =
  "HTTP/1.1 202 Accepted\r\n";
const std::string no_content =
  "HTTP/1.1 204 No Content\r\n";
const std::string multiple_choices =
  "HTTP/1.1 300 Multiple Choices\r\n";
const std::string moved_permanently =
  "HTTP/1.1 301 Moved Permanently\r\n";
const std::string moved_temporarily =
  "HTTP/1.1 302 Moved Temporarily\r\n";
const std::string not_modified =
  "HTTP/1.1 304 Not Modified\r\n";
const std::string bad_request =
  "HTTP/1.1 400 Bad Request\r\n";
const std::string unauthorized =
  "HTTP/1.1 401 Unauthorized\r\n";
const std::string forbidden =
  "HTTP/1.1 403 Forbidden\r\n";
const std::string not_found =
  "HTTP/1.1 404 Not Found\r\n";
const std::string internal_server_error =
  "HTTP/1.1 500 Internal Server Error\r\n";
const std::string not_implemented =
  "HTTP/1.1 501 Not Implemented\r\n";
const std::string bad_gateway =
  "HTTP/1.1 502 Bad Gateway\r\n";
const std::string service_unavailable =
  "HTTP/1.1 503 Service Unavailable\r\n";

std::string to_string(Response::ResponseCode rcode)
{
  switch (rcode)
  {
  case Response::ok:
    return ok;
  case Response::created:
    return created;
  case Response::accepted:
    return accepted;
  case Response::no_content:
    return no_content;
  case Response::multiple_choices:
    return multiple_choices;
  case Response::moved_permanently:
    return moved_permanently;
  case Response::moved_temporarily:
    return moved_temporarily;
  case Response::not_modified:
    return not_modified;
  case Response::bad_request:
    return bad_request;
  case Response::unauthorized:
    return unauthorized;
  case Response::forbidden:
    return forbidden;
  case Response::not_found:
    return not_found;
  case Response::internal_server_error:
    return internal_server_error;
  case Response::not_implemented:
    return not_implemented;
  case Response::bad_gateway:
    return bad_gateway;
  case Response::service_unavailable:
    return service_unavailable;
  default:
    return internal_server_error;
  }
}



boost::asio::const_buffer to_buffer(Response::ResponseCode rcode)
{
  switch (rcode)
  {
  case Response::ok:
    return boost::asio::buffer(ok);
  case Response::created:
    return boost::asio::buffer(created);
  case Response::accepted:
    return boost::asio::buffer(accepted);
  case Response::no_content:
    return boost::asio::buffer(no_content);
  case Response::multiple_choices:
    return boost::asio::buffer(multiple_choices);
  case Response::moved_permanently:
    return boost::asio::buffer(moved_permanently);
  case Response::moved_temporarily:
    return boost::asio::buffer(moved_temporarily);
  case Response::not_modified:
    return boost::asio::buffer(not_modified);
  case Response::bad_request:
    return boost::asio::buffer(bad_request);
  case Response::unauthorized:
    return boost::asio::buffer(unauthorized);
  case Response::forbidden:
    return boost::asio::buffer(forbidden);
  case Response::not_found:
    return boost::asio::buffer(not_found);
  case Response::internal_server_error:
    return boost::asio::buffer(internal_server_error);
  case Response::not_implemented:
    return boost::asio::buffer(not_implemented);
  case Response::bad_gateway:
    return boost::asio::buffer(bad_gateway);
  case Response::service_unavailable:
    return boost::asio::buffer(service_unavailable);
  default:
    return boost::asio::buffer(internal_server_error);
  }
}

} // namespace status_strings

namespace misc_strings {

const char name_value_separator[] = { ':', ' ' };
const char crlf[] = { '\r', '\n' };

} // namespace misc_strings

namespace stock_responses {

const char ok[] = "";
const char created[] =
  "<html>"
  "<head><title>Created</title></head>"
  "<body><h1>201 Created</h1></body>"
  "</html>";
const char accepted[] =
  "<html>"
  "<head><title>Accepted</title></head>"
  "<body><h1>202 Accepted</h1></body>"
  "</html>";
const char no_content[] =
  "<html>"
  "<head><title>No Content</title></head>"
  "<body><h1>204 Content</h1></body>"
  "</html>";
const char multiple_choices[] =
  "<html>"
  "<head><title>Multiple Choices</title></head>"
  "<body><h1>300 Multiple Choices</h1></body>"
  "</html>";
const char moved_permanently[] =
  "<html>"
  "<head><title>Moved Permanently</title></head>"
  "<body><h1>301 Moved Permanently</h1></body>"
  "</html>";
const char moved_temporarily[] =
  "<html>"
  "<head><title>Moved Temporarily</title></head>"
  "<body><h1>302 Moved Temporarily</h1></body>"
  "</html>";
const char not_modified[] =
  "<html>"
  "<head><title>Not Modified</title></head>"
  "<body><h1>304 Not Modified</h1></body>"
  "</html>";
const char bad_request[] =
  "<html>"
  "<head><title>Bad Request</title></head>"
  "<body><h1>400 Bad Request</h1></body>"
  "</html>";
const char unauthorized[] =
  "<html>"
  "<head><title>Unauthorized</title></head>"
  "<body><h1>401 Unauthorized</h1></body>"
  "</html>";
const char forbidden[] =
  "<html>"
  "<head><title>Forbidden</title></head>"
  "<body><h1>403 Forbidden</h1></body>"
  "</html>";
const char not_found[] =
  "<html>"
  "<head><title>Not Found</title></head>"
  "<body><h1>404 Not Found</h1></body>"
  "</html>";
const char internal_server_error[] =
  "<html>"
  "<head><title>Internal Server Error</title></head>"
  "<body><h1>500 Internal Server Error</h1></body>"
  "</html>";
const char not_implemented[] =
  "<html>"
  "<head><title>Not Implemented</title></head>"
  "<body><h1>501 Not Implemented</h1></body>"
  "</html>";
const char bad_gateway[] =
  "<html>"
  "<head><title>Bad Gateway</title></head>"
  "<body><h1>502 Bad Gateway</h1></body>"
  "</html>";
const char service_unavailable[] =
  "<html>"
  "<head><title>Service Unavailable</title></head>"
  "<body><h1>503 Service Unavailable</h1></body>"
  "</html>";

std::string to_string(Response::ResponseCode rcode)
{
  switch (rcode)
  {
  case Response::ok:
    return ok;
  case Response::created:
    return created;
  case Response::accepted:
    return accepted;
  case Response::no_content:
    return no_content;
  case Response::multiple_choices:
    return multiple_choices;
  case Response::moved_permanently:
    return moved_permanently;
  case Response::moved_temporarily:
    return moved_temporarily;
  case Response::not_modified:
    return not_modified;
  case Response::bad_request:
    return bad_request;
  case Response::unauthorized:
    return unauthorized;
  case Response::forbidden:
    return forbidden;
  case Response::not_found:
    return not_found;
  case Response::internal_server_error:
    return internal_server_error;
  case Response::not_implemented:
    return not_implemented;
  case Response::bad_gateway:
    return bad_gateway;
  case Response::service_unavailable:
    return service_unavailable;
  default:
    return internal_server_error;
  }
}

} // namespace stock_replies

void Response::SetStatus(const ResponseCode response_code)
{
	this->response_code = response_code;
}

void Response::AddHeader(const std::string& header_name, const std::string& header_value)
{
	header head;
	head.name = header_name;
	head.value = header_value;

	headers.push_back(head);
}

void Response::SetBody(const std::string& body)
{
	content.append(body);
}

Response Response::stock_response(Response::ResponseCode rcode)
{
  std::string body = stock_responses::to_string(rcode);
  Response resp;
  resp.SetStatus(rcode);
  resp.SetBody(body);
  resp.AddHeader("Content-Length", std::to_string(body.size()));
  resp.AddHeader("Content-Type", "text/html");
  return resp;
}

std::vector<boost::asio::const_buffer> Response::to_buffers()
{
  std::vector<boost::asio::const_buffer> buffers;
  buffers.push_back(status_strings::to_buffer(response_code));
  for (std::size_t i = 0; i < headers.size(); ++i)
  {
    header& h = headers[i];
    buffers.push_back(boost::asio::buffer(h.name));
    buffers.push_back(boost::asio::buffer(misc_strings::name_value_separator));
    buffers.push_back(boost::asio::buffer(h.value));
    buffers.push_back(boost::asio::buffer(misc_strings::crlf));
  }
  buffers.push_back(boost::asio::buffer(misc_strings::crlf));
  buffers.push_back(boost::asio::buffer(content));
  return buffers;
}

std::string Response::ToString()
{

  std::string resp = status_strings::to_string(response_code);
  std::vector<header>::iterator it;
  for (it = headers.begin(); it != headers.end(); it++) {
    std::string header = it->name;
    std::string header_val = it->value;
    if (header == "Content-Type") {
      resp += "Content-Type: " + header_val + "\r\n";
    } else if (header == "Content-Length") {
      resp += "Content-Length: " + header_val + "\r\n";
    } else {
      resp += header + ": " + header_val + "\r\n";
    }
  }
  //resp += "\r\n";

  resp += content;

  return resp;
}

} // namespace server
} // namespace http
