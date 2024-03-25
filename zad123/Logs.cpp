#include "Logs.h"
static int int_logcreatecodersucces = 1;
static int int_logstarttocodefile = 2;
static int int_logfinishtocodefile = 3;
static int int_logrndomingframes = 4;
static int int_logsendedtodecoder = 5;
static int int_logstarttodecodefile = 6;
static int int_logfinishtodecodefile = 7;
static int int_logfilesaved = 8;
static int int_processlog = 9;
static int int_unexpectedlog = 10;
static int int_errorlog = 11;
static int int_logcoderdestruct = 12;
static int int_logdecoderdestruct = 13;
static int int_logset = 14;
static int int_logget = 15;
static int int_lognoerror = 16;
static int int_loggetfromfile = 17;
static int int_logcreatenetsucces = 18;
static int int_logdeletenetsucces = 19;
static int int_logstartrndomingframes = 20;
static int int_logsendframestolan = 21;
static int int_logdecreatecodersucces = 22;
void log(int num_log)
{
	if (int_logcreatecodersucces == num_log) cout << log_create_coder_succes;
	else if (int_logstarttocodefile == num_log) cout << log_start_to_code_file;
	else if (int_logfinishtocodefile == num_log) cout << log_finish_to_code_file;
	else if (int_logrndomingframes == num_log) cout << log_rndoming_frames;
	else if (int_logsendedtodecoder == num_log) cout << log_sended_to_decoder;
	else if (int_logstarttodecodefile == num_log) cout << log_start_to_decode_file;
	else if (int_logfinishtodecodefile == num_log) cout << log_finish_to_decode_file;
	else if (int_logfilesaved == num_log) cout << log_file_saved;
	else if (int_processlog == num_log) cout << process_log;
	else if (int_errorlog == num_log) cout << error_log;
	else if (int_logcoderdestruct == num_log) cout << log_coder_destruct;
	else if (int_logdecoderdestruct == num_log) cout << log_decoder_destruct;
	else if (int_logset == num_log) cout << log_set;
	else if (int_logget == num_log) cout << log_get;
	else if (int_lognoerror == num_log) cout << log_no_error;
	else if (int_loggetfromfile == num_log) cout << log_get_from_file;
	else if (int_logcreatenetsucces == num_log) cout << log_create_net_succes;
	else if (int_logdeletenetsucces == num_log) cout << log_delete_net_succes;
	else if (int_logstartrndomingframes == num_log) cout << log_start_rndoming_frames;
	else if (int_logsendframestolan == num_log) cout << log_send_frames_to_lan;
	else if (int_logdecreatecodersucces == num_log) cout << log_decreate_coder_succes;

	else cout << unexpected_log;
}

void Logs::logcreatecodersucces()
{
	log(int_logcreatecodersucces);
}
void Logs::logstarttocodefile()
{
	log(int_logstarttocodefile);
}
void Logs::logfinishtocodefile()
{
	log(int_logfinishtocodefile);
}
void Logs::logrndomingframes()
{
	log(int_logrndomingframes);
}
void Logs::logsendedtodecoder()
{
	log(int_logsendedtodecoder);
}
void Logs::logstarttodecodefile()
{
	log(int_logstarttodecodefile);
}
void Logs::logfinishtodecodefile()
{
	log(int_logfinishtodecodefile);
}
void Logs::logfilesaved()
{
	log(int_logfilesaved);
}
void Logs::processlog()
{
	log(int_processlog);
}
void Logs::unexpectedlog()
{
	log(int_unexpectedlog);
}
void Logs::errorlog()
{
	log(int_errorlog);
}
void Logs::logcoderdestruct()
{
	log(int_logcoderdestruct);
}
void Logs::logdecoderdestruct()
{
	log(int_logdecoderdestruct);
}
void Logs::logset()
{
	log(int_logset);
}
void Logs::logget()
{
	log(int_logget);
}
void Logs::lognoerror()
{
	log(int_lognoerror);
}
void Logs::loggetfromfile()
{
	log(int_loggetfromfile);
}
void Logs::logcreatenetsucces()
{
	log(int_logcreatenetsucces);
}
void Logs::logdeletenetsucces()
{
	log(int_logdeletenetsucces);
}
void Logs::logstartrndomingframes()
{
	log(int_logstartrndomingframes);
}
void Logs::logsendframestolan()
{
	log(int_logsendframestolan);
}
void Logs::logdecreatecodersucces()
{
	log(int_logdecreatecodersucces);
}