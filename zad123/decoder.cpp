#include "decoder.h"
#include "Logs.h"

#define DEF_FRAME_SIZE 1000
#define DEF_FILE_NAME "result.xlsx"

decoder::decoder() {
    Logs::logcreatecodersucces();
    //this->con = nullptr;
    this->file_name = DEF_FILE_NAME;
    this->file_size = 0; // Assuming file size starts at 0
    this->frame_size = DEF_FRAME_SIZE;
    this->get_buffer = nullptr;
    this->Print = new std::ofstream(file_name, std::ios::binary);
}

decoder::decoder(Connection con) {
    Logs::logcreatecodersucces();
    //this->con = con;
    this->file_name = DEF_FILE_NAME;
    this->file_size = con.get_file_size();
    this->frame_size = DEF_FRAME_SIZE;
    this->get_buffer = con.get_send_buffers();
    this->Print = new std::ofstream(file_name, std::ios::binary);
}

void decoder::set_file_name(std::string file_name) {
    Logs::logset();
    this->file_name = file_name;
}

decoder::~decoder() {
    delete Print;
    Logs::logdecoderdestruct();
}
