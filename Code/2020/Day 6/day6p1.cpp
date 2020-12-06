#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    ifstream infile;
    infile.open ("input.txt");

    int validanswers;
    string letters = "abcdefghijklmnopqrstuvwxyz";

    if (infile.is_open()) {
        string questioninput = "";
        string tmpstr;
        while (infile.good()) {
            char c[256];

            infile.getline(c, 256);
            questioninput+=c;
            tmpstr=c;
            if (tmpstr == "" || !infile.good()) {
                int vainqi = 0;
                for (int i = 0; i < 26; i++) {
                    if (questioninput.find(letters.at(i)) != string::npos) vainqi++;
                }
                validanswers+=vainqi;
                questioninput="";
            }
        }
    }

    cout << validanswers;

    return 0;
}