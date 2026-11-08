#include "SpeakerView.h"
#include "MonoStack.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

SpeakerView::SpeakerView() { // constructor
    inputFile = ""; // no file
    numRows = 0; // no rows
    numCols = 0; // no cols
    heights = nullptr;
}

SpeakerView::SpeakerView(string input) { // constructor
    inputFile = input; // saves file name
    numRows = 0;
    numCols = 0;
    heights = nullptr;
}

SpeakerView::~SpeakerView() { // destructor
    for (int i = 0; i < numRows; ++i) { // frees each row
        delete[] heights[i];
    }
    delete[] heights; // frees array of rows
}

void SpeakerView::processFile() {
    getDimensions(); // sees how big grid is
    if (numRows == 0 || numCols == 0) { // nothing was read
        cerr << "Error: Couldnt find heights in " << inputFile << endl;
        return;
    }
    getHeights(); // fills second array
    visibility(); // prints results
}

void SpeakerView::getDimensions() { // counts rows and columns in file
    ifstream file(inputFile); // outputs file
    string line;
    numRows = 0;
    numCols = 0;

    if (!file.is_open()) { // file didnt open 
        return;
    }

    while (getline(file, line)) {
        if (line.find("END") != string::npos) { // stops at END
            break;
        }
        istringstream iss(line); // pulls numbers out of line
        double height;
        int currCols = 0;
        while (iss >> height) { // counts numbers on line
            ++currCols;
        }
        if (currCols > 0) { // skip BEGIN and blank lines
            ++numRows;
            if (numCols == 0) { // decides how many cols there are
                numCols = currCols;
            }
        }
    }
    file.close();
}

void SpeakerView::getHeights() { // reads heights
    ifstream file(inputFile); // opens file
    string line;
    heights = new double*[numRows]; // a pointer for each row
    for (int i = 0; i < numRows; ++i) { 
        heights[i] = new double[numCols]; // each row ggets numCols spot
        for (int j = 0; j < numCols; ++j) {
            heights[i][j] = 0;
        }
    }

    int row = 0;
    while (row < numRows && getline(file, line)) {
        if (line.find("END") != string::npos) { // stops at END
            break;
        }
        istringstream iss(line);
        double height;
        int col = 0;
        while (col < numCols && iss >> height) { // reads up to numCols numbers
            heights[row][col] = height;
            ++col;
        }
        if (col > 0) { 
            ++row;
        }
    }
    file.close();
}

void SpeakerView::visibility() { // runs decreasing monostack on each columna and prints
    for (int col = 0; col < numCols; ++col) { // a column at a time
        MonoStack<double> stack(numRows, 'd'); // decreasing stack
        double* visibleHeights = new double[numRows]; // holds heights of people that can see
        int visCount = 0; // how many people can see

        for (int row = 0; row < numRows; ++row) { // starts at front row and moves back
            double height = heights[row][col]; 
            
            while (!stack.isEmpty() && stack.peek() <= height) {
                stack.pop(); // everyone infront who isnt taller gets popped. 
            }
            if (stack.isEmpty()) {
                visibleHeights[visCount] = height; // saves height if there isnt anyone taller infront of them 
                ++visCount;
            }
            stack.push(height); // could block people behind
        }
        cout << "In column " << col << " there are " << visCount << " that can see. Their heights are: ";
        for (int i = 0; i < visCount; ++i) {
            cout << visibleHeights[i]; // default formatting
            if (i < visCount - 1) { // , between heights but not after last one
                cout << ", ";
            }
        }
        cout << " inches." << endl;
        delete[] visibleHeights; // frees array
    }
}