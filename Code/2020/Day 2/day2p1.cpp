#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream infile;
    infile.open ("input.txt");
    int valid = 0;

    int min;
    int max;
    char necessaryC;
    int temp;
    char pre = ' ';

    if (infile.is_open()) {
        while (infile.good()) {
            char c[25];

            infile.getline(c, 256, '-');
            min = 0;
            min = atoi(c);

            infile.getline(c, 256, ' ');
            max = 0;
            max = atoi(c);
            
            infile.get(necessaryC);

            infile.get();infile.get();
            temp = 0;
            while(pre != '\n') {
                c[temp] += infile.get();
                pre = infile.peek();
                temp++;
            }
            infile.getline(c, 256);

            temp = 0;
            for (int ch = 0; ch < 25; ch++) {
                if (c[ch] == 0) {
                    ch = 24;
                }
                else {
                    if (c[ch] == necessaryC) {
                        temp++;
                    }
                }
            }
            if (max >= temp && temp >= min) {
                valid++;
            }
        }
    }

    cout << "valid:" << valid;

    return 0;
}