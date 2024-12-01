#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

// Function to display the menu.
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

    // Check if the file can be opened.
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Read each line of code and store it in the tree.
    while(getline(inputFile, code)) {
        tree.insertNode(code);
    }

    inputFile.close();

    // Display the menu and have the user pick an option.
    displayMenu();
    cout << "Enter your choice: ";
    cin >> input;

    while(input != 5){
        cin.ignore();
        switch(input) {
            // If the user picks 1, prompt the user, and add the code.
            case 1: {
                cout << "Enter a code to add: ";
                getline(cin, code);
                tree.insertNode(code);
                break;
            }
            // If the user picks 2, prompt the user, and delete the code.
            case 2: {
                cout << "Enter a code to delete: ";
                getline(cin, code);
                tree.remove(code);
                break;
            }
            // If the user picks 3, prompt the user and search for the code.
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
            // If the user picks 4, modify a code.
            case 4: {
                string oldCode, newCode;
                // User picks which code to modify.
                cout << "Enter a code to modify: ";
                getline(cin, oldCode);
                // User enters a new code to replace it.
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