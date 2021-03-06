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
// file path is ./src/data/hung21.mp3"

string EchoPrint::ID(string filename){
	string songCode = codegen(filename);
	cout << "I, ID, have the code: " + songCode << endl;
	string rawSongInfo = echoServer(songCode);
	cout << endl << endl << "I, ID, have fingerprinting with the following JSON info: " << rawSongInfo << endl;

	return rawSongInfo;
}

string EchoPrint::JSONtoCode(string codegenOutput){

	FILE* fp = fopen(codegenOutput.c_str(), "r");

	char readBuffer[4096] = {0};
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
	cout << "JSONtoCode: Here is the code I got: " << code << endl;
	cout << "\nPausing before returning up.";

	return code;
}


//Calls codegen, returns codegen output (songCode)
string EchoPrint::codegen(string filename){

	string commander = "./lib/echoprint-codegen/echoprint-codegen "+ filename;
	FILE* codegenCommander = popen(commander.c_str(), "r");
	pclose(codegenCommander);

	return JSONtoCode("./bin/json/out.json");
}



std::string buffer;

size_t curl_write( void *ptr, size_t size, size_t nmemb, void *stream)
{
	buffer.append((char*)ptr, size*nmemb);
	return size*nmemb;
}

//Sends songCode to echoPrint server, returns result (rawSongInfo)
string EchoPrint::echoServer(string songCode){

	buffer.clear();

	string curlRequest = "http://1.1.1.127:8080/query?fp_code=" + songCode;
		


	CURL *curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, curlRequest.c_str()); 
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	fwrite( buffer.c_str(), buffer.length(), sizeof(char), stdout);

	if (buffer.length() > 3000) {
		buffer = "{\"artist\": \"NOARTIST\", \"track\": \"NOTRACK\", \"track_id\": \"TRUCCPM1515BB84DDF-0\", \"codever\": \"4.12\", \"length\": 159, \"score\": 6.2522736, \"source\": \"local\", \"release\": \"NORELEASE\"}";
	}

	return buffer;
}

