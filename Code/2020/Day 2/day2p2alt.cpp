#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream infile;
    infile.open ("input.txt");

    string total;

    if (infile.is_open()) {
        char c[256];
        while (infile.good()) {
            infile.getline(c, 256);
            total+=c;
            total+=",";
        }
    }

    int pos;
    int min;
    int max;
    string letter;

    //do better this time

    //cout << "valid:" << valid;

    return 0;
}