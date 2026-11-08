#ifndef TRANSLATOR_H // so that file doesn't get included more than once
#define TRANSLATOR_H
#include "Model.h" // so that it can use Model class
#include <string> // for std::string


class Translator { // translates english words and sentences using Model class
    public:
        Translator(); // constructor
        ~Translator(); // destructor

        std::string translateEnglishWord(std::string e); // translates word to robber language
        std::string translateEnglishSentence(std::string e); // transkates sentence to robber language

    private:
        Model m; // to translate individual characters
};
#endif // ends header guard