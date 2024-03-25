#ifndef DECODER_H
#define DECODER_H

#include "Connection.h"
#include <fstream>
#include <string>

class decoder {
public:
    decoder();
    decoder(Connection con);
    void set_file_name(std::string file_name);
    ~decoder();
private:
    std::string file_name; 
    int file_size;
    int frame_size;
    ofstream* Print;
    char** send_buffers;
    char** get_buffer; 
    bool get_string;
};
#endif /* DECODER_H */