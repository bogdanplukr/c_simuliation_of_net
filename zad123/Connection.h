#pragma once
#include "decoders.h"
#include "Net.h"
class Net;
class Connection
{
public:
    Connection();
    Connection(Net* net);
    ~Connection();
    void connection_coder_net();
    int get_file_size();
    char** get_send_buffers();
    void connection_net_decoder();
    void set_send_buffer(char*** send_buffer);
    void set_file_size(int file_size);
private:
    Net* net;
    decoders* decoder;
};
