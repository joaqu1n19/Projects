#include "FileProcessor.h" // include class declaration
#include <iostream> // for cerr
#include <fstream> // of ifstream and ofstream

using namespace std;

FileProcessor::FileProcessor() { // construxtor

}

FileProcessor::~FileProcessor() { // destructor

}

void FileProcessor::processFile(string input, string output) {
    string line; // holds each line read from the input file

    ifstream inFile(input); // opens the input file
    ofstream outFile(output); // makes the html output file

    if (!inFile.is_open() || !outFile.is_open()) { // makes sure both files opened correctly
        cerr << "Error opening file!" << endl;
        return;
    }

    outFile << "<!DOCTYPE html>\n<html>\n<head>\n<title>English to Robber translation</title>\n</head>\n<body>\n"; // writes html header

    while (getline(inFile, line)) { // reads the file line by line
        if (line.empty()) continue; // skips blank lines
// Claude code starts here:
        string translatedText = t.translateEnglishSentence(line);
        outFile << "<p><b>" << line << "</b></p>\n";
        outFile << "<p>&nbsp;</p>\n";
        outFile << "<p><i>" << translatedText << "</i></p>\n";
    }
    outFile << "</body>\n</html>\n";
// Claude code ends here.

    inFile.close(); // closes input file
    outFile.close(); // closes output file
}