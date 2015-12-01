#include "EchoPrint.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
    cout << "Hello from tester." << endl;
    EchoPrint echoTest;
    echoTest.ID("./src/data/hung21.wav");
    //echoTest.JSONtoCode()


    return 0;
}
