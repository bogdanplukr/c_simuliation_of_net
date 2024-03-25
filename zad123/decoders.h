#ifndef DECODERS_H
#define DECODERS_H


#include <fstream>
#include <string>
using namespace std;

class decoders {
public:
    decoders(int file_size, char ** send_buffers);
    void set_file_name(string file_name);
    ~decoders();
    void decode();
private:
    string file_name;
    int file_size;
    int frame_size;
    ofstream* Print;
    char** send_buffers;   //otprawka
    char** get_buffer;  //poluczka
    bool get_string;
    int iter();
    int get_numerico(char* send_buffers, int iter);
    char* rezult;
};

#endif // DECODERS_H
