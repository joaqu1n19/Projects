#ifndef BLOCK_H
#define BLOCK_H
#include <string>

using namespace std;

class Block {
    public:
        Block(); // constructor 
        Block(int i, string h, string p); // makes new blokc using current time
        Block(int i, string t, string h, string p, string c); // remakes block that was saved in a file
        ~Block(); // destructor

        int getIndex(); // return index
        string getTimestamp(); // returns timestamp
        string getData(); // returns data
        string getPrevHash(); // returns previous hash
        string getCurrHash(); // retuens current hash
        string calcHash(); // figures out what hash should be based on blocks content

    private:
        int index; // position of block in chain
        string timestamp; // when the block was made
        string data; // transaction thats stored in block
        string prevHash; // hash of previous block
        string currHash; // hash of current block
        string intToHexStream(int num); // turns number to hex string

};
#endif