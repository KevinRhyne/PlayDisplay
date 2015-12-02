
#include "Displayer.h"

using namespace cv;
using namespace std;

void Displayer::displaySong(Song latestSong){

    Mat image;
    image = imread("./bin/albumimage.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
    }

    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.

    string titleText  = "Track: " + latestSong.getTitle();
    string albumText  = "Album: " + latestSong.getAlbum();
    string artistText = "Artist: " + latestSong.getArtist();

    int fontFace = FONT_HERSHEY_SIMPLEX;
    double fontScale = .7;
    int thickness = 1;  
    cv::putText(image, titleText, Point(10, 130), fontFace, fontScale, Scalar::all(255), thickness,8);
    cv::putText(image, albumText, Point(10, 160), fontFace, fontScale, Scalar::all(255), thickness,8);
    cv::putText(image, artistText, Point(10, 190), fontFace, fontScale, Scalar::all(255), thickness,8);

    imshow( "Display window", image ); 

    waitKey(0);                                          // Wait for a keystroke in the window
	
}