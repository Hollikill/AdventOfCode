#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream infile;
    infile.open ("input.txt");

    int topid = 0;

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

            brdps="";
        }
    }

    cout << topid;

    return 0;
}