//Echoprint.h
//
//

#ifndef ECHOPRINT_H
#define ECHOPRINT_H

#include <string>

using namespace std;

class EchoPrint {
	public:
	    string ID(string);
	private:

        string codegen(string); //Codegens mp3 file
        string echoServer(string); // Talks to server with REST

};


#endif
