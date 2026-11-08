#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include <string>

using namespace std;

class SpeakerView {
    public:
        SpeakerView(); // constructor
        SpeakerView(string input);
        ~SpeakerView(); // destructor

        void processFile(); // reads file and prints 

    private:
        string inputFile; // name of file with heights
        int numRows; // nuumber of rows
        int numCols; // number of columns
        double** heights; // second array of heights

        void getDimensions(); // counts rows and cols in file
        void getHeights(); // reads heights
        void visibility(); // runs decreasing monostack on each col and prints
};
#endif