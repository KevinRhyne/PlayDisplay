
#include "Displayer.h"

using namespace cv;
using namespace std;

void Displayer::displaySong(Song latestSong){

    Mat image;
    image = imread("./bin/albumimage.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file
    Size imageSize = image.size();


    //Create textbox
    Mat textbox = Mat::zeros(400, imageSize.width, CV_8UC3 );

    string titleText  = "Track: " + latestSong.getTitle();
    string albumText  = "Album: " + latestSong.getAlbum();
    string artistText = "Artist: " + latestSong.getArtist();

    int fontFace = FONT_HERSHEY_SIMPLEX;
    double fontScale = 1.3;
    int thickness = 2;  
    cv::putText(textbox, titleText, Point(150, 160), fontFace, fontScale, Scalar::all(255), thickness,8);
    cv::putText(textbox, albumText, Point(150, 210), fontFace, fontScale, Scalar::all(255), thickness,8);
    cv::putText(textbox, artistText, Point(150, 260), fontFace, fontScale, Scalar::all(255), thickness,8);

    //Merge textbox and album artwork vertically
    Mat fullDisplay;
    vconcat(image, textbox, fullDisplay);

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
    }

    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.


    imshow( "Display window", fullDisplay ); 

    waitKey(0);                                          // Wait for a keystroke in the window
	
}