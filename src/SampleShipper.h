// SampleShipper.h
//
//

#ifndef SAMPLESHIPPER_H
#define SAMPLESHIPPER_H

#include "Song.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>
#include "curl/curl.h"

class SampleShipper {
	public:
		Song ship(string);
	private:
		Song stringToSong(string);
		string getMBID(string);

};

#endif
