// EchoPrint.cpp
// Changed
//
// EchoPrint codegen wrapper for SampleShipper
//
// Takes Audio object, extracts PCM, recieves Codegen response

#include <stdio.h>
#include <string>
#include <iostream>
#include "EchoPrint.h"
#include <cstring>

using namespace std;

//const string CODEGEN_PATH =
//"../lib/echoprint-codegen/echoprint-codegen";


string EchoPrint::ID(string filename){
	string songCode = codegen(filename);
	string rawSongInfo = echoServer(songCode);
	return "done";
}

//Calls codegen, returns codegen output (songCode)
string EchoPrint::codegen(string filename){

	int BIG_SIZE = 4096;
	int LINE_SIZE = 512;

	FILE *fp;
	fp = popen("../lib/echoprint-codegen/echoprint-codegen ../src/data/hung21.mp3", "r");

	char big_buffer[BIG_SIZE];
	char small_buffer[LINE_SIZE];
	unsigned used = 0;

	big_buffer[0] = '\0'; // initialize the big buffer to an empty string

	// read a line data from the child program
	while (fgets(small_buffer, LINE_SIZE, fp)) {
	    // check that it'll fit:
	    size_t len = strlen(small_buffer);
	    if (used + len >= BIG_SIZE)
	        break;

	    // and add it to the big buffer if it fits
	    strcat(big_buffer, small_buffer);
	    used += strlen(small_buffer);
	}
	
	cout << "I got this from Codgen call: " << big_buffer;
	return big_buffer;
}

//Sends songCode to echoPrint server, returns result (rawSongInfo)
string EchoPrint::echoServer(string songCode){
	return "done";
}