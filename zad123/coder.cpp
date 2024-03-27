#include "coder.h"
#include "Logs.h"
coder::coder()
{
	this->file_name = DEF_FILE_NAME;
	this->frame_size = DEF_FRAME_SIZE;
    this->con = * new Connection(new Net(this->file_size, this->frame_size, this->send_buffers));
    this->lenght_array = 0;
    Logs::logcreatecodersucces();
}

coder::coder(string file_name)
{
	this->file_name = file_name;
	this->frame_size = DEF_FRAME_SIZE;
    this->lenght_array = 0;
    Logs::logcreatecodersucces();
}

coder::coder(int frame_size)
{
	this->file_name = DEF_FILE_NAME;
	this->frame_size = frame_size;
    this->lenght_array = 0;
    Logs::logcreatecodersucces();
}

coder::coder(string file_name, int frame_size)
{
	this->file_name = file_name;
	this->frame_size = frame_size;
    this->lenght_array = 0;
    Logs::logcreatecodersucces();
}

coder::~coder()
{
	delete[] send_buffers, buffers, buffer;
	delete myfile;
    Logs::logdecoderdestruct();
}

string coder::get_file_name()
{
    Logs::logget();
	return this->file_name;
    
}

void coder::set_file_name(string file_name)
{
    Logs::logset();
	this->file_name = file_name;
}

int coder::get_frame_size()
{
    Logs::logget();
	return frame_size;
}

void coder::set_frame_size(int frame_size)
{
    Logs::logset();
	this->frame_size =  frame_size;
}

char** coder::get_send_buffer()
{
    Logs::logget();
	return this->send_buffers;
}

string coder::get_send_buffer_str()
{
    Logs::logget();
	char* rezult = new char[file_size];
	for (int i = 0; i <= iter(); i++)
		for (int j = 0; j < frame_size; j++)
			if (i * frame_size + j < file_size)
				rezult[i * frame_size + j] = this->send_buffers[i][j];
	return rezult;
}
int length_of_int(int num) {
    if (num == 0) return 1;
    int length = 0;
    while (num != 0) {
        num /= 10;
        length++;
    }
    return length;
}

int coder::iter()
{
	return file_size/frame_size;
}
bool chek_empty(char* array, int frame_size)
{
    for (int i = 0; i < frame_size; i++)
        if (array[i] != 0||array[i]!='\0')
            return true;
    return false;
}
void coder::start()
{
	try{
        if (!new ifstream(this->file_name, ios::binary | ios::ate)) throw NO_FILE_EXEPTION() ;
        if (this->frame_size <= 0) throw SMULL_FRAME_SIZE_EXEPTION();
        Logs::lognoerror();
        Logs::loggetfromfile();
        myfile= new ifstream(this->file_name, ios::binary | ios::ate);
        this->file_size = myfile->tellg();
        this->con.set_file_size(this->file_size);
        myfile->seekg(0, ios::beg);
        this->buffer = new char[this->file_size];
        myfile->read(this->buffer, this->file_size);
        myfile->close();
        if (iter() * 128 < file_size)
            lenght_array = iter() + 1;
        else
            lenght_array = iter();
        con.set_file_size(file_size);
        this->buffers = new char* [this->lenght_array];
        
        Logs::logstarttocodefile();
        for (int i = 0; i < this->lenght_array; i++)
        {
            this->buffers[i] = new char[this->frame_size];
            for (int j = 0; j < this->frame_size; j++)
            {
                if (i * this->frame_size + j < this->file_size)
                    this->buffers[i][j] = buffer[i * this->frame_size + j];
                else this->buffers[i][j] = 0;
            }
        }
            this->send_buffers = new char* [this->lenght_array];
       
        for (int i = 0; i < this->lenght_array; i++)
        {
                send_buffers[i] = new char[frame_size + length_of_int(iter())];
                for (int j = 0; j < frame_size + length_of_int(iter()); j++) {
                    if (j < frame_size) send_buffers[i][j] = buffers[i][j];
                    else {
                        send_buffers[i][j] = i % static_cast<int>(pow(128, j - frame_size + 1)) / static_cast<int>(pow(128, j - frame_size)); //cout << i % static_cast<int>(pow(128, j - size_min + 1)) / static_cast<int>(pow(128, j - size_min)) << "\n";
                    }
                }
        }
        Logs::logfinishtocodefile();
	}
	catch (NO_FILE_EXEPTION e) {
        Logs::errorlog();
        cout << e.NO_FILE();
	}
    catch (SMULL_FRAME_SIZE_EXEPTION e) {
        Logs::errorlog();
        cout << e.SMULL_FRAME_SIZE();
    }
    cout << "\n\n\n\n\n";
    for (int i = 0; i < lenght_array; i++)
        for (int j = 0; j < this->frame_size; j++)
            if (send_buffers[i] != NULL)
                cout << send_buffers[i][j];
    this->send_to_net();
    //
}

void coder::send_to_net()
{
    Logs::logsendframestolan();
    this->con.set_send_buffer(&this->send_buffers);
    
    this->con.connection_coder_net();
    //net = new Net(this->file_size, this->frame_size, this->send_buffers);
}



