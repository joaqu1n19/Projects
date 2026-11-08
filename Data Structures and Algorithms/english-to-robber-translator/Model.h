#ifndef MODEL_H // will prevent file from being included more than once
#define MODEL_H
#include <string> // need for std::string


class Model { // handles translation rules
    public:
        Model(); // constructor
        ~Model(); // destructor

        std::string translateSingleConsonant(char c); // translates consonant to robber language
        std::string translateSingleVowel(char c); // tranlate vowel to robber language
};
#endif // end of header