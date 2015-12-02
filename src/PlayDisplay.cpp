
#include "PlayDisplay.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "PlayDisplay: Hello! I am here to command things around. Let's go!" << endl;



	SoundMonitor soundmonitor;
	Displayer display;

	while(1){

	    Song latestSong = soundmonitor.update();

	    cout << string("\nPlayDisplay: I have IDed the current playing track: ") +
	              "\n ARTIST: " + latestSong.getArtist() +
	              "\n TITLE: " + latestSong.getTitle() +
	              "\n ALBUM: " + latestSong.getAlbum() << endl << endl;
	   
	  display.displaySong(latestSong);
	}

}
