#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream infile;
    infile.open ("input.txt");

    string total[500];
    int i = 0;

    if (infile.is_open()) {
        while (infile.good()) {
            char c[40];

            infile.getline(c, 256);
            
            total[i]+=c;
            i++;
        }
    }

    int trees = 0;
    int lnSize = total[0].length();

    for (int x = 0; x < i; x++) {
        int loc =(x*3)%lnSize;
        if (total[x].at(loc) == '#') {
            trees++;
        }
    }

    cout << "trees: " << trees;

    return 0;
}