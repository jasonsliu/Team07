#ifndef BASE_REQUEST_HANDLER_HPP
#define BASE_REQUEST_HANDLER_HPP
#include "request.hpp"
#include "reply.hpp"
namespace http {
namespace server {

class base_handler{
public:
	base_handler() {};
	
	// Handle a request and set up corresponding reply.
	virtual void handle_request(const request& req, reply& rep) = 0;
	
};

} // namespace server
} // namespace http

#endif //  BASE_REQUEST_HANDLER_HPP
