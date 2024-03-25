#include <fstream>
#include <iostream>
#include <string>
#include "Connection.h"
#include "NO_FILE_EXEPTION.h"
#include "SMULL_FRAME_SIZE_EXEPTION.h"

using namespace std;
#define DEF_FRAME_SIZE 100;
#define DEF_FILE_NAME "exel.xlsx";
#define DEF_GET_STRING false;
class coder
{
public:
	coder();
	coder(string file_name);
	coder(int frame_size);
	coder(string file_name,int frame_size);
	~coder();
	string get_file_name();
	void set_file_name(string file_name);
	int get_frame_size();
	void set_frame_size(int frame_size);
	char** get_send_buffer();
	string get_send_buffer_str();
	int iter();
	void start();
	void send_to_net();
private:
	string file_name;
	int file_size;
	int frame_size;
	ifstream* myfile;
	char* buffer;
	char** buffers;
	char** send_buffers;
	bool get_string;
	Connection con;
	//Net* net;
};

