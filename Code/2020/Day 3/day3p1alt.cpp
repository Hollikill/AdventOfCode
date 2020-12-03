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

    int xmov;
    int ymov;
    cout << "enter slope (x per y)" << endl << endl;
    cin >> xmov;
    cout << "per" << endl;
    cin >> ymov;
    cout << endl;
    int trees = 0;
    int lnSize = total[0].length();
    int orgLnSize = lnSize;

    while (lnSize < i) {
        for (int x = 0; x < i; x++) {
            total[x] += total[x].substr(0,orgLnSize);
        }
        lnSize += orgLnSize;
    }
    lnSize = total[0].length();

    for (int x = 0; x < i; x++) {
        int loc =(x*(xmov/ymov)+(xmov%ymov))%lnSize;
        if (total[x].at(loc) == '#') {
            trees++;
            total[x] = total[x].substr(0,loc)+"X"+total[x].substr(loc+1);
        }
        else {
            total[x] = total[x].substr(0,loc)+"\\"+total[x].substr(loc+1);
        }
    }
    for (int x = 0; x < i; x++) {
        for (int y = 0; y < lnSize; y++) {
            if (total[x].at(y) == '#') {
                total[x] = total[x].substr(0,y)+"-"+total[x].substr(y+1);
            }
            else if (total[x].at(y) == '.') {
                total[x] = total[x].substr(0,y)+" "+total[x].substr(y+1);
            }
        }
    }

    ofstream outfile;
    outfile.open("output.txt");
    for (int x = 0; x < i; x++) {
        outfile << total[x] << endl;
        cout << total[x] << endl;
    }

    cout << "trees hit: " << trees;

    return 0;
}