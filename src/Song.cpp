// Song.cpp
//
// Song class, contains title, album, artist, artwork, length, and playing status

#include "Song.h"

Song::Song(string title, string album, string artist){

	this->title = title;
	this->album = album;
	this->artist = artist;

}

string Song::getTitle() {
	return title;
}

string Song::getAlbum() {
	return title;
}

string Song::getArtist() {
	return title;
}