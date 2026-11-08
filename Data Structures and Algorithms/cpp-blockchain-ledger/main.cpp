#include <iostream>
#include <string>
#include "Blockchain.h"

using namespace std;

int main() {
    Blockchain ledger; // creates vlockchaon. automatically makes genesis block
    string choice; // option picked by user
    string input; // data or file name user typed 
    while (choice != "6") { // runs until user exits
        cout << "1. Add a new block" << endl;
        cout << "2. Display the blockchain" << endl; 
        cout << "3. Validate the blockahin" << endl;
        cout << "4. Save blockchain to file" << endl;
        cout << "5. Load blockchain from file" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        getline(cin, choice); // reads option user picked

        if (choice == "1") { // add block
            cout << "Enter data for the block: ";
            getline(cin, input);
            ledger.addBlock(input); 
        }
        else if (choice == "2") { // display
            ledger.displayChain();
        }
        else if (choice == "3") { // validate
            if (ledger.validateChain()) {
                cout << "The blockchain is valid" << endl;
            }
            else {
                cout << "The blockchain is not valid" << endl;
            }
        }
        else if (choice == "4") { // save
            cout << "Enter file name to save to: ";
            getline(cin, input);
            ledger.saveToFile(input);
        }
        else if (choice == "5") { // load
            cout << "Enter file name to load from: ";
            getline(cin, input);
            ledger.loadFromFile(input);
        }
        cout << endl;
    }
    return 0;
}