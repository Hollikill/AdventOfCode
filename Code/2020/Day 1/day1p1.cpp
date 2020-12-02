#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream infile;
    infile.open ("day1.txt");
    int arr[200];
    if (infile.is_open()) {
        for (int x = 0; x < 200; x++) {
            char c[10];
            infile.getline(c, 256);
            arr[x] = atoi(c);
            //cout << c << endl;
        }
    }
    for (int x = 0; x < 200; x++) {
        for (int y = x; y < 200; y++) {
            //cout << "test";
            if ((arr[x] + arr[y]) == 2020) {
                cout << (arr[x] * arr[y]);
            }
        }
        //cout << endl;
    }
    return 0;
}