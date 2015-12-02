#include "EchoPrint.h"
#include "Song.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
    cout << "Hello from tester." << endl;
    EchoPrint echoTest;
    echoTest.ID("./src/data/hung21.mp3");
    //echoTest.JSONtoCode()


    return 0;
}
