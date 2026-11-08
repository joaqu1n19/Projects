#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "Block.h"
#include <string>

using namespace std;

class Blockchain {
    public: 
        Blockchain(); // constructor
        ~Blockchain(); // destructor

        void addBlock(string h); // adds block to end of chain
        bool validateChain(); // checks that hash is correct
        void displayChain(); // prints blocks in order
        void saveToFile(string output); // saves chain to a file
        void loadFromFile(string input); // loads chain from file

    private:
        Block** blocks; // array of pointers to blocks
        int numBlocks; // number of blocks in chain
        int capacity; // amount array can hold
        void appendBlock(Block* b); // puts block at end. makes array bigger if full
        void clearBlocks(); // clears all the blocks

};
#endif