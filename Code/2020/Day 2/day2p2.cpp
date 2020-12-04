#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    ifstream infile;
    infile.open ("input.txt");
    int valid = 0;

    int pos1;
    int pos2;
    char letter;
    string tmp;

    if (infile.is_open()) {
        while (infile.good()) {
            char c[256];
            infile.getline(c, 256);

            tmp = c;
            pos1 = stoi( tmp.substr(0, tmp.find('-')) )-1;
            pos2 = stoi( tmp.substr(tmp.find('-')+1, tmp.find(' ')))-1;
            letter = tmp.at(tmp.find(' ')+1);


            if ((c[pos2+tmp.find(':')+2] == letter) != (c[pos1+tmp.find(':')+2] == letter)) {
                valid++;
            }
        }
    }

    cout << "valid:" << valid;

    return 0;
}