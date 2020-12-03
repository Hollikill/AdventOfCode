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

    int trees1half = 0;
    int trees1 = 0;
    int trees3 = 0;
    int trees5 = 0;
    int trees7 = 0;
    int lnSize = total[0].length();

    for (int x = 0; x < i; x=x+2) {
        int loc =(x/2)%lnSize;
        if (total[x].at(loc) == '#') {
            trees1half++;
        }
    }
    for (int x = 0; x < i; x++) {
        int loc =(x)%lnSize;
        if (total[x].at(loc) == '#') {
            trees1++;
        }
    }
    for (int x = 0; x < i; x++) {
        int loc =(x*3)%lnSize;
        if (total[x].at(loc) == '#') {
            trees3++;
        }
    }
    for (int x = 0; x < i; x++) {
        int loc =(x*5)%lnSize;
        if (total[x].at(loc) == '#') {
            trees5++;
        }
    }
    for (int x = 0; x < i; x++) {
        int loc =(x*7)%lnSize;
        if (total[x].at(loc) == '#') {
            trees7++;
        }
    }

    cout << "1/2 slope trees: " << trees1half << endl;
    cout << "1 slope trees: " << trees1 << endl;
    cout << "3 slope trees: " << trees3 << endl;
    cout << "5 slope trees: " << trees5 << endl;
    cout << "7 slope trees: " << trees7 << endl;
    cout << "trees mult: " << trees1half*trees1*trees3*trees5*trees7;

    return 0;
}