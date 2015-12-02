#include "EchoPrint.h"
#include "SampleShipper.h"
#include "SoundMonitor.h"
#include "AudioInputController.h"
#include "Song.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
    cout << "Hello from tester." << endl;
    /*
    EchoPrint echoTest;
    AudioInputController audiocontroller;
    SampleShipper sampleshipper;

    string filepath = audiocontroller.recordSample();
    Song dummySong = sampleshipper.ship(filepath);

    cout << string("I am tester, I recieved this ID") +
    		  "\n ARTIST: " + dummySong.getArtist() +
    		  "\n TITLE: " + dummySong.getTitle() +
    		  "\n ALBUM: " + dummySong.getAlbum() << endl << endl;

    */
    SoundMonitor soundmonitor;
    Song latestSong = soundmonitor.update();
    cout << string("\n\n\nI am tester, SoundMonitor gave me the latest track: ") +
              "\n ARTIST: " + latestSong.getArtist() +
              "\n TITLE: " + latestSong.getTitle() +
              "\n ALBUM: " + latestSong.getAlbum() << endl << endl;

    latestSong = soundmonitor.update();
    cout << string("\n\n\nI am tester, SoundMonitor 2nd run gave me the latest track: ") +
              "\n ARTIST: " + latestSong.getArtist() +
              "\n TITLE: " + latestSong.getTitle() +
              "\n ALBUM: " + latestSong.getAlbum() << endl << endl;


    return 0;
}
