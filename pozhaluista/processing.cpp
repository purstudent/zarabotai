#include <iostream>
#include <string>
#include "ethernet_protocole.h"
#include "processing.h"

using namespace std;

int sumtime(char* user_char, char *path, int start_hour, int start_minute, int start_second, 
	int end_hour, int end_minute, int end_second){
	string user_string = user_char, stringpath = path;
	if (stringpath.find(user_string) != std::string::npos) {
		int intsumtime = (end_hour - start_hour)
			* 3600 + (end_minute - start_minute)
			* 60 + (end_second - start_second);
		return intsumtime;
	}
}
