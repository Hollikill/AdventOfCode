#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
            if (temp == "" || !infile.good()) {
                psprt+="#########";
                if (psprt.find(" byr:") == string::npos || psprt.find(" iyr:") == string::npos || psprt.find(" eyr:") == string::npos || psprt.find(" hgt:") == string::npos || psprt.find(" hcl:") == string::npos || psprt.find(" ecl:") == string::npos || psprt.find(" pid:") == string::npos) {
                    
                }
                else {
                    string rule1str = psprt.substr(psprt.find(" byr:")+5,4);
                    bool rule1 = 2003 > stoi(rule1str) && stoi(rule1str) > 1919;
                    string rule2str = psprt.substr(psprt.find(" iyr:")+5,4);
                    bool rule2 = 2021 > stoi(rule2str) && stoi(rule2str) > 2009;
                    string rule3str = psprt.substr(psprt.find(" eyr:")+5,4);
                    bool rule3 = 2031 > stoi(rule3str) && stoi(rule3str) > 2019;

                    string rule4str = psprt.substr(psprt.find(" hgt:")+5,5);
                    bool rule4 = false;
                    if (rule4str.find("cm") == 3) {
                        if (194 > stoi(rule4str.substr(0,3)) && stoi(rule4str.substr(0,3)) > 149) rule4 = true;
                    }
                    else if (rule4str.find("in") == 2) {
                        if( 77 > stoi(rule4str.substr(0,2)) && stoi(rule4str.substr(0,2)) > 58) rule4 = true;
                    }

                    string rule5str = psprt.substr(psprt.find(" hcl:")+5,7);
                    bool rule5 = true;
                    for (int i = 1; i < 7; i++) {
                        if (
                        !isdigit(rule5str.at(i)) &&
                        rule5str.at(i) != 'a' &&
                        rule5str.at(i) != 'b' &&
                        rule5str.at(i) != 'c' &&
                        rule5str.at(i) != 'd' &&
                        rule5str.at(i) != 'e' &&
                        rule5str.at(i) != 'f'
                        ) rule5=false;
                    }
                    if (rule5str.at(0) != '#') rule5 = false;

                    string rule6str = psprt.substr(psprt.find(" ecl:")+5,3);
                    bool rule6 = true;
                    if (
                    rule6str != "amb" &&
                    rule6str != "blu" &&
                    rule6str != "brn" &&
                    rule6str != "gry" &&
                    rule6str != "grn" &&
                    rule6str != "hzl" &&
                    rule6str != "oth"
                    ) rule6 = false;

                    string rule7str = psprt.substr(psprt.find(" pid:")+5,10);
                    bool rule7 = true;
                    for (int i = 0; i < 9; i++) {
                        if (!isdigit(rule7str.at(i))) rule7 = false;
                    }
                    if (rule7str.at(9) != ' ') rule7 = false;
                    
                    if (
                    rule1 &&
                    rule2 &&
                    rule3 &&
                    rule4 &&
                    rule5 &&
                    rule6 &&
                    rule7
                    ) valid++;
                }
                psprt="";
            }
        }
    }

    cout << valid;

    return 0;
}