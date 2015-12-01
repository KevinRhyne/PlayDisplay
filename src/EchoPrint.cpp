// EchoPrint.cpp
// Changed
//
// EchoPrint codegen wrapper for SampleShipper
//
// Takes Audio object, extracts PCM, recieves Codegen response

#include "EchoPrint.h"

using namespace std;

//const string CODEGEN_PATH =
//"../lib/echoprint-codegen/echoprint-codegen";


string EchoPrint::ID(string filename){
	string songCode = codegen(filename);
	cout << "I, ID, have the code: " + songCode << endl;
	string rawSongInfo = echoServer(songCode);
	return "done";
}

string EchoPrint::JSONtoCode(string codegenOutput){

	FILE* fp = fopen(codegenOutput.c_str(), "r");

	char readBuffer[65536];
	rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	rapidjson::Document codegenJSON;
	codegenJSON.ParseStream(is);
	fclose(fp);

	//rapidjson::Document codegenJSON;

	//codegenJSON.Parse(codegenOutput.c_str());
	assert(codegenJSON.IsObject());	
	assert(codegenJSON.HasMember("metadata"));
	string bitrate = codegenJSON["metadata"]["filename"].GetString();
	string code = codegenJSON["code"].GetString();
	cout << "Hello from JSONtoCode, I found metadata.filename to be: " + bitrate << endl;
	return code;
}


//Calls codegen, returns codegen output (songCode)
string EchoPrint::codegen(string filename){

	popen("./lib/echoprint-codegen/echoprint-codegen ./src/data/hung21.mp3", "r");
	return JSONtoCode("./bin/json/out.json");
}

//Sends songCode to echoPrint server, returns result (rawSongInfo)
string EchoPrint::echoServer(string songCode){
	return "done";
}