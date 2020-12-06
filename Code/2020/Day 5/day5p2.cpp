#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    ifstream infile;
    infile.open ("input.txt");

    int topid = 0;
    string allids;

    if (infile.is_open()) {
        string brdps = "";
        while (infile.good()) {
            char ch[256];
            infile.getline(ch, 256);
            brdps+=ch;
            //cout << "{" << brdps << "}" << endl;

            int r = 127;
            int c = 7;

            for (int i = 0; i < 7; i++) {
                if (brdps.at(i) == 'F') {
                    switch (i) {
                        case 0:
                            r-=64;
                            break;
                        case 1:
                            r-=32;
                            break;
                        case 2:
                            r-=16;
                            break;
                        case 3:
                            r-=8;
                            break;
                        case 4:
                            r-=4;
                            break;
                        case 5:
                            r-=2;
                            break;
                        case 6:
                            r-=1;
                            break;
                        default:
                            break;
                    }
                }
            }
            for (int i = 7; i < 10; i++) {
                if (brdps.at(i) == 'L') {
                    switch (i) {
                        case 7:
                            c-=4;
                            break;
                        case 8:
                            c-=2;
                            break;
                        case 9:
                            c-=1;
                            break;
                        default:
                            break;
                    }
                }
            }

            int id = (r*8 + c);
            if (topid < id) topid = id;
            allids += to_string(id) + '#';

            brdps="";
        }
    }

    //cout << allids;
    for (int i = 1; i < topid; i++) {
        int x=i-1;
        int y=i+1;
        if (allids.find(to_string(x)+"#") != string::npos && allids.find(to_string(y)+"#") != string::npos && allids.find(to_string(i)+"#") == string::npos) {
            cout << i;
        }
    }

    return 0;
}