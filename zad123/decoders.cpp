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
    if (iter() * 128 < file_size)
        lenght_array = iter() + 1;
    else
        lenght_array = iter();
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
int length_of_int_coder(int num) {
    if (num == 0) return 1;
    int length = 0;
    while (num != 0) {
        num /= 10;
        length++;
    }
    return length;
}
int get_index(char* array, int start, int end)
{
    int rez = 0;
    for (int i = start; i < end; ++i) {
        rez += array[i] * pow(128, abs(i - start));
    }
    return rez;
}
void decoders::decode()
{
    cout << "\n\n\n\n\n";
    for (int i = 0; i <lenght_array; i++)
     for (int j = 0; j < this->frame_size; j++)
         if(send_buffers[i]!=NULL)
             cout << send_buffers[i][j];
        get_buffer = new char* [this->lenght_array];
    for (int i = 0; i < this->lenght_array; i++){
        if (send_buffers[i] != nullptr) {
            get_buffer[get_index(send_buffers[i], frame_size, frame_size + length_of_int_coder(iter()))] = new char[frame_size];
            get_buffer[get_index(send_buffers[i], frame_size, frame_size + length_of_int_coder(iter()))] = send_buffers[i];
        }
    }
    cout << "\n\n\n\n\n";
    for (int i = lenght_array - 1; i < lenght_array; i++)
        for (int j = 0; j < this->frame_size; j++)
            if (get_buffer[i] != NULL)
                cout << get_buffer[i][j];
    //cout << "\n\n\n\n\n";
        
    rezult = new char[file_size];
    for (int i = 0; i < this->lenght_array; i++)
        for (int j = 0; j < frame_size; j++)
            {
            rezult[i * frame_size + j] = get_buffer[i][j];
            cout << get_buffer[i][j];
        }
                
    Print->write(rezult, file_size);
    Print->close();
}

int decoders::iter()
{
    return file_size / frame_size;
}
//อออออออออออออออออออออออออออออออออออออออออออออออออออออ
//ออออออออออออออออออออออออออออออออออออออออออออออออออ
//อออออออออออออออออออออออออออออออออออออออออออออออออออ