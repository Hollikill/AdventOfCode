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
        int answerers = 0;
        while (infile.good()) {
            char c[256];
            infile.getline(c, 256);
            tmpstr=c;
            if (!infile.good()) {
                questioninput+=c;
                questioninput+="#";
                answerers++;
                tmpstr = "";
            }
            if (tmpstr == "") {
                bool vans[26];
                for (int i = 0; i < 26; i++) {
                    vans[i] = true;
                }
                for (int x = 0; x < answerers; x++) {
                    string tmpquestioninput =  questioninput;
                    for (int i = 0; i < x; i++) {
                        tmpquestioninput = tmpquestioninput.substr(tmpquestioninput.find("#")+1);
                    }
                    for (int i = 0; i < 26; i++) {
                        if (tmpquestioninput.substr(0,tmpquestioninput.find("#")).find(letters.at(i)) == string::npos) vans[i] = false;
                    }
                }
                for (int i = 0; i < 26; i++) {
                    if (vans[i]) {
                        validanswers++;
                        //cout << questioninput << endl;
                    }
                }
                questioninput="";
                answerers=0;
            }
            else {
                questioninput+=c;
                questioninput+="#";
                answerers++;
            }
        }
    }

    cout << validanswers;

    return 0;
}