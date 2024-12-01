#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    IntBinaryTree tree;
    ifstream inputFile("codes.txt");
    string code;

    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while(getline(inputFile, code)) {
        tree.insertNode(code);
    }

    inputFile.close();

    tree.displayInOrder();
    cout << endl;

    return 0;
}