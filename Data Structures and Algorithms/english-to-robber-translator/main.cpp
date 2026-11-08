#include <iostream>
#include "FileProcessor.h"

using namespace std; 

int main (int argc, char** argv) {
    if (argc < 3) { // checks that both filenames were passed in
        cerr << "Error: please provide input and output files." << endl;
        return 1;
    }

    string inputFile = argv[1]; // first argument is the english input file
    string outputFile = argv[2]; // second argument is the html output file

    FileProcessor fp; // creates the file processor object
    fp.processFile(inputFile, outputFile); // translates input file and writes output file

    return 0;
}