#include "Connection.h"
#include "Logs.h"
Connection::~Connection()
{
	delete net;
	delete decoder;
}

Connection::Connection( Net* net)
{

	this->net = net;
	
}
Connection::Connection()
{

	this->net = nullptr;
}
void Connection::connection_coder_net()
{
	
	this->decoder = new decoders(this->get_file_size(), this->get_send_buffers());
	decoder->decode();
}

int Connection::get_file_size()
{
	return net->get_file_size();
}

char** Connection::get_send_buffers()
{
	return *net->get_send_buffers();
}

void Connection::set_send_buffer(char*** send_buffer)
{
	net->set_get_buffers(*send_buffer);
	net->randoming();
}

void Connection::set_file_size(int file_size)
{
	this->net->set_file_size(file_size);
}

