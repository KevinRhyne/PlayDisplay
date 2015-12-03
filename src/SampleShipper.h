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
#include "coverart/CoverArt.h"
#include <fstream>

class SampleShipper {
	public:
		Song ship(string);
	private:
		Song stringToSong(string);
		string getMBID(string);
		string JSONtoMBID(string);
		void getArt(string);
};

#endif
