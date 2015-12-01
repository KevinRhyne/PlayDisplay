// Song.h
//
//

#ifndef SONG_H
#define SONG_H


#include <string>

using namespace std;

class Song{
	public:
		string getTitle();
		string getAlbum();
		string getArtist();
		Song(string, string, string);

	private:
		string title;
		string album;
		string artist;
};

#endif
