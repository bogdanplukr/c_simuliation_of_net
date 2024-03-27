#include "Net.h"
#include "Logs.h"
using namespace std;

#define DEF_FRAME_SIZE 100

Net::Net() {
    this->frame_size = DEF_FRAME_SIZE;
    Logs::logcreatenetsucces();
}

Net::Net(int file_size, int frame_size, char** get_buffers) {
    this->file_size = file_size;
    this->frame_size = frame_size;
    this->get_buffers = get_buffers;
    Logs::logcreatenetsucces();
    
}

Net::~Net() {
    Logs::logdeletenetsucces();
    delete[] send_buffers, get_buffers; // Usuñ send_buffers, ale nie get_buffers, poniewa¿ nie zosta³ zaalokowany dynamicznie
}

void Net::set_get_buffers(char** get_buffers) {
    this->get_buffers = get_buffers;
    Logs::logset();
}

char*** Net::get_send_buffers() {
    Logs::logget();
    return &this->send_buffers;
}

int Net::get_frame_size() {
    Logs::logget();
    return this->frame_size;
}

int Net::get_file_size() {
    Logs::logget();
    return this->file_size;
}

void Net::set_frame_size(int frame_size) {
    this->frame_size = frame_size;
    Logs::logset();
}

void Net::set_file_size(int file_size) {
    this->file_size = file_size;
    Logs::logset();
}

void Net::randoming() {
    Logs::logstartrndomingframes();
    //int arraySize = /*sizeof(get_buffers) / sizeof(get_buffers[0]);*/ this->iter(); // Poprawka
    //random_device rd;
    //mt19937 gen(rd()); // U¿yj generatora liczb pseudolosowych z <random>
    //uniform_int_distribution<> distr(0, arraySize - 1);
    if (iter() * 128 < file_size)
        lenght_array = iter() + 1;
    else
        lenght_array = iter();
    this->send_buffers = new char* [lenght_array];
    int* myArray = new int[lenght_array];
    for (int i = 0; i < lenght_array; ++i) {
        bool isUnique;
        do {
            isUnique = true;
            myArray[i] = std::rand() % (lenght_array); // Adjust the range as needed
            for (int j = 0; j < i; ++j) {
                if (myArray[i] == myArray[j]) {
                    isUnique = false;
                    break;
                }
            }
        } while (!isUnique);
    }
    //cout << "\n\n\n\n\n\n\n\n\n";
    for (int i = 0; i < lenght_array; i++)
        this->send_buffers[myArray[i]] = this->get_buffers[i];
    cout << "\n\n\n\n\n";
    for (int i = 0; i < lenght_array; i++)
        for (int j = 0; j < this->frame_size; j++)
            if(send_buffers[i]!=NULL)
                cout << send_buffers[i][j];
    cout << "\n\n\n\n\n";
    delete[] myArray;
    //for (int i = iter(); i > 0; --i) {
    //    int j = distr(gen); // U¿yj dystrybucji pseudolosowej zamiast rand()
    //    char* temp = this->get_buffers[i];
    //    this->get_buffers[i] = this->get_buffers[j];
    //    this->get_buffers[j] = temp;
    //}
    //this->set_get_buffers(get_buffers);
    Logs::logrndomingframes();
}

int Net::iter() {
    return file_size / frame_size;
}

void Net::send_to_receiver() {
    // Implementacja funkcji send_to_receiver()
}
