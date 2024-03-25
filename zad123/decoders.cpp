#include "decoders.h"
#include <fstream>
#include <string>
#include <cmath> 
#include "Logs.h"
#define DEF_FRAME_SIZE 100
#define DEF_FILE_NAME "result.xlsx"
using namespace std;
decoders::decoders(int file_size, char** send_buffers) {
    Logs::logcreatecodersucces();
    this->file_name = DEF_FILE_NAME;
    this->file_size = file_size;
    this->frame_size = DEF_FRAME_SIZE;
    this->send_buffers = send_buffers;
    this->Print = new std::ofstream(file_name, std::ios::binary);
}

void decoders::set_file_name(std::string file_name) {
    Logs::logset();
    this->file_name = file_name;
}

decoders::~decoders() {
    delete Print;
    delete send_buffers, get_buffer, rezult;
    Logs::logdecoderdestruct();
}
void decoders::decode()
{
    get_buffer = new char*[iter()+1];
    for (int i = 0; i <= iter(); i++) {
        get_buffer[get_numerico(send_buffers[i], iter())] = new char[this->frame_size];
        get_buffer[get_numerico(send_buffers[i], iter())] = send_buffers[i];
    }


    for (int i = 0; i <= iter(); i++)
        for (int j = 0; j < this->frame_size; j++)
            cout << get_buffer[i][j];

    cout << "\n\n\n\n\n\n\n";
    Print = new ofstream (file_name, ios::binary);
    rezult = new char[this->frame_size];



    for (int i = 0; i <= iter(); i++)
        for (int j = 0; j < frame_size; j++)
            if (i * frame_size + j < file_size)
                rezult[i * frame_size + j] = get_buffer[i][j];



    for (int i = 0; i <= file_size; i++)
        cout << rezult[i];



    Print->write(rezult, file_size);
    //Print->close();
}

int decoders::iter()
{
    return file_size / frame_size;
}
int reverse(int rez)
{
    string reverse = "";
    string rez_to_str = to_string(rez);
    for (int i = rez_to_str.length(); i > 0; i--)
        reverse += to_string( rez_to_str[i]);
    return stoi(reverse);
}
int decoders::get_numerico(char* send_buff, int iter)
{
    int rez = 0;
    int lenght = this->frame_size;
    for (int i = lenght + to_string(iter).length()-1; i >= lenght ; i--)
        if (send_buff[i] != 0 || send_buff[i] != '\0')
            rez += (send_buff[i] - '0') * pow(10, lenght + to_string(iter).length() - 1 - i);
        else rez += 0;
    return rez;
}
