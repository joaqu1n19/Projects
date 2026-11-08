#include "Model.h" // include class declaration

using namespace std; // so that i dont have to keep writing std::

Model::Model() { // constructor

}

Model::~Model() { // destructor

}

string Model::translateSingleConsonant(char c) { // translates consonant into robber language
    string result = ""; // starts with empty sting
    result += c; // adds the constonant
    result += "o"; // adds the letter o
    result += c; // adds the consonant again
    return result;
}

string Model::translateSingleVowel(char c) { // translates vowel into robber langiage
    string result = ""; // starts with empty string
    result += c; // adds the vowel
    return result;
}