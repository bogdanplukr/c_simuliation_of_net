#include <fstream>
#include <iostream>
#include <string>
#include <random>
using namespace std;
#define DEF_FRAME_SIZE 1000;
class Net
{
public:
	Net();
	Net(int file_size, int frame_size, char** get_buffers);
	~Net();
	void set_get_buffers(char** get_buffers);
	char*** get_send_buffers();
	int get_frame_size();
	int get_file_size();
	void set_frame_size(int frame_size);
	void set_file_size(int file_size);
	void randoming();
	int iter();
	void send_to_receiver();
private:
	char** send_buffers;
	char** get_buffers;
	int frame_size;
	int file_size;
	int lenght_array;
	//decoder* dec;
};

