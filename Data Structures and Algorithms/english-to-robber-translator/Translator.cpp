#include "Translator.h"
#include <sstream> // needed for string stream

using namespace std;

Translator::Translator() { // constructor

}

Translator::~Translator() { // destructor

}

string Translator::translateEnglishWord(string e) { // translates a single english word to robber langiage
    string result = "";
    for (size_t i = 0; i < e.size(); ++i) { // loops through every character
        char c = e.at(i); // gets current character
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' ||
            c == 'I' || c == 'O' || c == 'U') { // check for uppercase and lowercase vowels
            result += m.translateSingleVowel(c); // translate vowel and adds it
        }
        else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) { // any other letter is consonant
            result += m.translateSingleConsonant(c); // translate consonant and add it
        }
        else {
            result += c; // leaves the rest the smae
        }
    }
    return result; // returns translated word
}

string Translator::translateEnglishSentence(string e) { // translate english sentence word by words
    stringstream ss(e); // allows to split sentence by spaces
    string word; // holds each word when getting extracted
    string result = ""; // string to build translated sentence
    bool firstWord = true; // checks to see if space is needed before next word

    while (ss >> word) { // gets next word from sentence
        if (!firstWord) {
            result += " "; // adds spoace between words
        }
        result += translateEnglishWord(word); // translate current word and add it
        firstWord = false;
    }
    return result; // returns translated sentence
}