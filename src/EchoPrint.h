//Echoprint.h
//
//

#ifndef ECHOPRINT_H
#define ECHOPRINT_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>

using namespace std;

class EchoPrint {
	public:
	    string ID(string);
	private:
		string JSONtoCode(string);
        string codegen(string); //Codegens mp3 file
        string echoServer(string); // Talks to server with REST

};


#endif
