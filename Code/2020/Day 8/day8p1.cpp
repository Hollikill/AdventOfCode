#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream infile;
    infile.open ("input.txt");

    if (infile.is_open()) {
        string instruc[644];
        int i;
        while (infile.good()) {
            char c[256];
            infile.getline(c, 256);
            instruc[i]=c;
            i++
        }
    }

    cout << topid;

    return 0;
}