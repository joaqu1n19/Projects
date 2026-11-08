#include "Blockchain.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Blockchain::Blockchain() { // constructor
    numBlocks = 0; // no blocks yet
    capacity = 10; // starting size
    blocks = new Block*[capacity]; // makes array on heap
    appendBlock(new Block(0, "Genesis Block", "0")); // genesis block starts chain
}

Blockchain::~Blockchain() { // destructor
    clearBlocks(); // frees each block
    delete[] blocks; //frees array of pointers
}

void Blockchain::appendBlock (Block* b) { // puts block at end of array
    if (numBlocks == capacity) { // array gets doubled when fulll
        Block** temp = new Block*[2 * capacity]; 
        for (int i = 0; i < numBlocks; ++i) { // copies over pointers
            temp[i] = blocks[i];
        }
        delete[] blocks; // frees old array
        blocks = temp; // points at new array
        capacity *= 2;
    }
    blocks[numBlocks] = b;
    ++numBlocks;
}

void Blockchain::clearBlocks() { // deletes blocks
    for (int i = 0; i < numBlocks; ++i) {
        delete blocks[i];
    }
    numBlocks = 0;
}

void Blockchain::addBlock(string h) { // addsnew block
    string p = blocks[numBlocks - 1]->getCurrHash(); // previous hash is last blocks hash

    appendBlock(new Block(numBlocks, h, p)); // block makes its own hash
}

bool Blockchain::validateChain() { // checks current hash and previous hash 
    for (int i = 0; i < numBlocks; ++i) {
        if (blocks[i]->getCurrHash() != blocks[i]->calcHash()) { // hash doesnt match blocks content
            return false;
        }
        if (i > 0 && blocks[i]->getPrevHash() != blocks[i - 1]->calcHash()) { // doesnt match block before it
            return false;
        }
    }
    return true; // everything matched
}

void Blockchain::displayChain() { // prints every block in order
    for (int i = 0; i < numBlocks; ++i) {
        cout << "Index: " << blocks[i]->getIndex() << endl;
        cout << "Timestamp: " << blocks[i]->getTimestamp() << endl;
        cout << "Data: " << blocks[i]->getData() << endl;
        cout << "Previous Hash: " << blocks[i]->getPrevHash() << endl;
        cout << "Current Hash: " << blocks[i]->getCurrHash() << endl;
        cout << endl;
    }
}

void Blockchain::saveToFile(string output) { // each block goes on its own line
    ofstream outFile(output); // makes output file

    for (int i = 0; i < numBlocks; ++i) {
        outFile << blocks[i]->getIndex() << "|" << blocks[i]->getTimestamp() << "|" << blocks[i]->getData() << "|"
            << blocks[i]->getPrevHash() << "|" << blocks[i]->getCurrHash() << "\n";
    }
    outFile.close(); // closes output file
}

void Blockchain::loadFromFile(string input) { // builds chain from file
    string line; // holds each line
    ifstream inFile(input); // opens input file

    clearBlocks(); // deletes old blocks. genesis blokc comrd from file

    while (getline(inFile, line)) { // reads each line of file
        string fields[5]; // 
        size_t start = 0; // where current field starts

        for (int i = 0; i < 5; ++i) { // pulls each field
            size_t bar = line.find('|', start); // finds | at end of field
            fields[i] = line.substr(start, bar - start); // saves field
            start = bar + 1; // next field starts after|

        }
        int idx = 0; // turns index into number
        istringstream iss(fields[0]);
        iss >> idx;
        appendBlock(new Block(idx, fields[1], fields[2], fields[3], fields[4]));

    }
    inFile.close(); // closes input file
}