#include <iostream>
#include "SpeakerView.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) { // needs a program name and one file name
        cerr << "Error: Incorrect usage. Try again: " << argv[0] << " intput_file_name.txt" << endl; // tells user how to run it
        return 1;
    }
    try { // catches errors
        SpeakerView speakerView(argv[1]); // input file name
        speakerView.processFile(); // reads file and prints
    } catch (const exception& e) {
        cerr << e.what() << endl; // prints what went wrong
        return 1;
    }
    return 0;
}