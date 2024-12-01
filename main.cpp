#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Add a code\n";
    cout << "2. Delete a code\n";
    cout << "3. Search for a code\n";
    cout << "4. Modify a code\n";
    cout << "5. Exit\n";
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

    displayMenu();
    cout << "Enter your choice: ";
    cin >> input;

    while(input != 5){
        cin.ignore();
        switch(input) {
            case 1: {
                cout << "Enter a code to add: ";
                getline(cin, code);
                tree.insertNode(code);
                break;
            }
            case 2: {
                cout << "Enter a code to delete: ";
                getline(cin, code);
                tree.remove(code);
                break;
            }
            case 3: {
                cout << "Enter a code to search for: ";
                getline(cin, code);
                if(tree.searchNode(code)){
                    cout << "Code found." << endl;
                }
                else {
                    cout << "Code not found." << endl;
                }
                break;
            }
            case 4: {
                string oldCode, newCode;
                cout << "Enter a code to modify: ";
                getline(cin, oldCode);
                cout << "Enter a new code to enter: ";
                getline(cin, newCode);
                tree.remove(oldCode);
                tree.insertNode(newCode);
                break;
            }

        }
        displayMenu();
        cout << "Enter your choice: ";
        cin >> input;
    }
    return 0;
}