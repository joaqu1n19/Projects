#ifndef FILEPROCESSOR_H // prevents file from getting included more than once
#define FILEPROCESSOR_H
#include "Translator.h"
#include <string> // for std::string


class FileProcessor { // handles reading input file and writing translated output
    public:
        FileProcessor(); // constructor
        ~FileProcessor(); // destructor

        void processFile(std::string input, std::string output); // reads input file and writes translated html file

    private:
        Translator t; // to translate each line of the file
};
#endif