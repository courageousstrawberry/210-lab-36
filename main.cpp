#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Add a record\n";
    cout << "2. Delete a record\n";
    cout << "3. Search for a record\n";
    cout << "4. Modify a record\n";
    cout << "6. Exit\n";
}

int main() {
    IntBinaryTree tree;
    ifstream inputFile("codes.txt");
    int input;
    string code;

    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while(getline(inputFile, code)) {
        tree.insertNode(code);
    }

    inputFile.close();

    while(input != 6){
        displayMenu();
        cout << "Enter your choice: ";
        cin >> input;
        switch(input) {
            case 1: {
                cout << "Enter a code to add: "
            }

        }
    }
    return 0;
}