#include "Block.h"
#include <ctime>
#include <sstream>

using namespace std;

Block::Block() { // constructor
    index = 0;
    timestamp = "";
    data = "";
    prevHash = "";
    currHash = "";
}

Block::Block(int i, string h, string p) { // makes new block
    index = i;
    time_t currT = time(0); // gets current time
    timestamp = ctime(&currT); // turns time into string
    timestamp.pop_back(); // removes new line ctime adds
    data = h;
    prevHash = p;
    currHash = calcHash(); // hash is made from  the other stuff
}

Block::Block (int i, string t, string h, string p, string c) { // remakes block from a file
    index = i;
    timestamp = t;
    data = h;
    prevHash = p;
    currHash = c; // keeps saved hash

}

Block::~Block() {} // destructor

int Block::getIndex() {
    return index;
}

string Block::getTimestamp() {
    return timestamp;

}
string Block::getData () {
    return data;

}

string Block::getPrevHash() {
    return prevHash;
}

string Block::getCurrHash() {
    return currHash;
}

string Block::calcHash() {
    string content = to_string(index); // starts with index
    content += timestamp; // adds timestamp
    content += data; // adds data
    content += prevHash; // adds previous hash
    int total = 0; // adds up number of each character
    size_t position = 0; // spot in string thats being looked at
    while (position < content.size()) { // goes through string
        total += content.at(position); // adds number character stands for
        ++position;
    }
    return intToHexStream(total); // hex string is the hash
}

string Block::intToHexStream (int num) { // turns number into hex
    stringstream ss;
    ss << hex << num;
    return ss.str();
}