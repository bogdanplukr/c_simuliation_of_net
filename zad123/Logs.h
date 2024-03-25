#include <iostream>
#include <string>
using namespace std;
#define process_log "."
#define log_create_coder_succes "Index of log 1.  Log: \"coder create succes\"\n"
#define log_start_to_code_file "Index of log 2.  Log: \"started of file coding\"\n"
#define log_finish_to_code_file "Index of log 3.  Log: \"finished of file coding\"\n"
#define log_rndoming_frames "Index of log 4.  Log: \"finished of file randoming\"\n"
#define log_sended_to_decoder "Index of log 5.  Log: \"send to decoder via lan\"\n"
#define log_start_to_decode_file "Index of log 6.  Log: \"started of file decoding\"\n"
#define log_finish_to_decode_file "Index of log 7.  Log: \"finished of file decoding\"\n"
#define log_file_saved "Index of log 8.  Log: \"file saved\"\n"
#define log_coder_destruct "Index of log 9.  Log: \"coder destructed\"\n"
#define log_decoder_destruct "Index of log 10. Log: \"decoder destructed\"\n"
#define log_set "Index of log 11. Log: \"decoder destructed\"\n"
#define log_get "Index of log 12. Log: \"decoder destructed\"\n"
#define log_no_error "Index of log 13. Log: \"passed all werification\"\n"
#define unexpected_log "Index of log undefine. Log: \"unexpected_log\"\n"   
#define error_log "Index of log undefine. Log: \"error_log\"\n"
#define log_get_from_file "Index of log 14. Log: \"getting information from file\"\n"
#define log_create_net_succes "Index of log 15. Log: \"net create succes\"\n"
#define log_delete_net_succes "Index of log 16. Log: \"net delete succes\"\n"
#define log_start_rndoming_frames "Index of log 17. Log: \"started of file randoming\"\n"
#define log_send_frames_to_lan "Index of log 18. Log: \"send frames to lan\"\n"
#define log_decreate_coder_succes "Index of log 19. Log: \"decoder create succes\"\n"

class Logs
{
public:
	Logs();
	~Logs();
	static void logcreatecodersucces();
	static void processlog();
	static void logstarttocodefile();
	static void logfinishtocodefile();
	static void logrndomingframes();
	static void logsendedtodecoder();
	static void logstarttodecodefile();
	static void logfinishtodecodefile();
	static void logfilesaved();
	static void unexpectedlog();
	static void logcoderdestruct();
	static void logdecoderdestruct();
	static void logset();
	static void logget();
	static void lognoerror();
	static void errorlog();
	static void loggetfromfile();
	static void logcreatenetsucces();
	static void logdeletenetsucces();
	static void logstartrndomingframes();
	static void logsendframestolan();
	static void logdecreatecodersucces();
private:

};

