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
                if (psprt.find(" byr:") == string::npos || psprt.find(" iyr:") == string::npos || psprt.find(" eyr:") == string::npos || psprt.find(" hgt:") == string::npos || psprt.find(" hcl:") == string::npos || psprt.find(" ecl:") == string::npos || psprt.find(" pid:") == string::npos) {
                    
                }
                else {
                    string rule1str = psprt.substr(psprt.find(" byr:")+5,4);
                    bool rule1 = 2003 > stoi(rule1str) && stoi(rule1str) > 1919;
                    string rule2str = psprt.substr(psprt.find(" iyr:")+5,4);
                    bool rule2 = 2021 > stoi(rule1str) && stoi(rule2str) > 2009;
                    string rule3str = psprt.substr(psprt.find(" eyr:")+5,4);
                    bool rule3 = 2031 > stoi(rule1str) && stoi(rule3str) > 2019;

                    string rule4str = psprt.substr(psprt.find(" hgt:")+5,7);
                    bool rule4 = false;
                    if (rule4str.find("in") != string::npos) {
                        rule4 = 194 > stoi(rule4str.substr(0,rule4str.find("in"))) && stoi(rule4str.substr(0,rule4str.find("in"))) > 149;
                    }
                    else if (rule4str.find("cm") != string::npos) {
                        rule4 = 77 > stoi(rule4str.substr(0,rule4str.find("in"))) && stoi(rule4str.substr(0,rule4str.find("in"))) > 58;
                    }

                    string rule5str = psprt.substr(psprt.find(" hcl:")+5,7);
                    bool rule5 = true;
                    for (int i = 1; i < 7; i++) {
                        if (
                        rule5str.at(i) != '0' &&
                        rule5str.at(i) != '1' &&
                        rule5str.at(i) != '2' &&
                        rule5str.at(i) != '3' &&
                        rule5str.at(i) != '4' &&
                        rule5str.at(i) != '5' &&
                        rule5str.at(i) != '6' &&
                        rule5str.at(i) != '7' &&
                        rule5str.at(i) != '8' &&
                        rule5str.at(i) != '9' &&
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

                    string rule7str = psprt.substr(psprt.find(" ecl:")+5,9);
                    bool rule7 = stoi(rule1str)%1 == 0;
                    
                    if (
                    rule1 &&
                    rule2 &&
                    rule3 &&
                    //rule4 &&
                    rule5 &&
                    rule6 &&
                    rule7
                    ) {
                        valid++;
                    }
                    else {
                        cout << psprt << endl;
                    }
                }
                psprt="";
            }
        }
    }

    cout << valid+1;

    return 0;
}