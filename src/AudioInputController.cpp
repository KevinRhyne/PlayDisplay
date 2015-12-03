
#include "AudioInputController.h"

using namespace std;

string AudioInputController::recordSample(){

	string recorder = "arecord -f dat -d 20 -D hw:1,0 ./src/data/tempRecord.wav ";
	FILE* recordHandle = popen(recorder.c_str(), "r");
	pclose(recordHandle);

	string fileupdater = "mv ./src/data/tempRecord.wav ./src/data/OTA.wav ";
	FILE* updateHandle = popen(fileupdater.c_str(), "r");
	pclose(updateHandle);

	return "./src/data/OTA.wav";

}