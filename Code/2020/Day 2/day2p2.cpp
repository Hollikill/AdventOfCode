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

            if ((c[--max] == necessaryC) != (c[--min] == necessaryC)) {
                valid++;
            }
        }
    }

    cout << "valid:" << valid-1;

    return 0;
}