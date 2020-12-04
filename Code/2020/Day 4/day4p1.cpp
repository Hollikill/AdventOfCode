#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// this code line is from this post https://stackoverflow.com/a/20170989
template <typename T> std::string type_name();
//type_name<decltype()>()

int main () {
    ifstream infile;
    infile.open ("input.txt");

    int valid;

    if (infile.is_open()) {
        string psprt = " ";
        string temp;
        while (infile.good()) {
            char c[256];

            infile.getline(c, 256);
            psprt+=" ";
            psprt+=c;
            temp = c;
            if (temp == "") {
                psprt+="                    ";
                if (psprt.find(" byr:") != string::npos && psprt.find(" iyr:") != string::npos && psprt.find(" eyr:") != string::npos && psprt.find(" hgt:") != string::npos && psprt.find(" hcl:") != string::npos && psprt.find(" ecl:") != string::npos && psprt.find(" pid:") != string::npos) {
                    valid++;
                }
                psprt="";
            }
        }
    }

    cout << valid+1;

    return 0;
}