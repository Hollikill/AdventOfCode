#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool bagtypes (string bagrulesorg, string containerbag) {
    string containedbags = "";
    string bagrules = "";
    bagrules+=bagrulesorg;
    if (bagrules.substr(bagrules.find("#"+containerbag)).find("#") != string::npos) {
        containedbags = bagrules.substr(bagrules.find("#"+containerbag)+containerbag.length()+1);
    }
    containedbags = bagrules.substr(bagrules.find("#"+containerbag)+containerbag.length()+1, bagrules.find("#"+containerbag)+bagrules.substr(bagrules.find("#"+containerbag)+1).find("#")+1);
    if (containedbags.find("^shiny gold") != string::npos) {
        return true;
    }
    else if (containedbags == "") {
        return false;
    }
    else {
        bool returnval = false;
        while (containedbags.substr(1).find("^") != string::npos) {
            if (bagtypes(bagrulesorg, containedbags.substr(1,containedbags.substr(1).find("^")+1))) returnval = true;
            containedbags = containedbags.substr(containedbags.substr(1).find("^")+1);
        }
        if (bagtypes(bagrulesorg, containedbags.substr(1))) returnval = true;
        return returnval;
    }
    return false;
}

int main () {
    ifstream infile;
    infile.open ("input.txt");

    string bagrules = "";

    if (infile.is_open()) { // read the data and put it in the format: #containing bag^contained bag^contained bag#containing bag^contained bag
        string bagrulestr = "";
        string tmpstr = "";
        while (infile.good()) {
            char c[256];

            infile.getline(c, 256);
            bagrulestr=c;
            tmpstr = "";
            tmpstr = bagrulestr;

            int tmpint = 0;

            bagrules += "#" + tmpstr.substr(0,tmpstr.find(" bags"));
            tmpstr = tmpstr.substr(tmpstr.find("contain ")+8);
            if (tmpstr.find("no other bags") == string::npos) {
                while (tmpstr.find(',') != string::npos) {
                    char tmpchar = tmpstr.at(0);
                    tmpint = atoi(&tmpchar);
                    tmpstr = tmpstr.substr(2);
                    if (tmpstr.substr(0,tmpstr.find(",")).find("bags")) {
                        bagrules += "^" + tmpstr.substr(0,tmpstr.find(",")-5);
                    }
                    else {
                        bagrules += "^" + tmpstr.substr(0,tmpstr.find(",")-4);
                    }
                    tmpstr = tmpstr.substr(tmpstr.find(",")+2);
                }
                char tmpchar = tmpstr.at(0);
                tmpint = atoi(&tmpchar);
                tmpstr = tmpstr.substr(2);
                if (tmpstr.substr(0,tmpstr.find(".")).find("bags")) {
                    bagrules += "^" + tmpstr.substr(0,tmpstr.find(".")-5);
                }
                else {
                    bagrules += "^" + tmpstr.substr(0,tmpstr.find(".")-4);
                }
            }
        }
    }

    int difbags = 0;
    string bagrulescp = "";
    bagrulescp += bagrules;
    while (bagrulescp.substr(1).find("#") != string::npos) {
        if (bagtypes(bagrules, bagrulescp.substr(1,bagrulescp.find("^"))))difbags++;
        bagrulescp = bagrulescp.substr(bagrulescp.substr(1).find("#")+1);
    }
    if (bagtypes(bagrules, bagrulescp.substr(1,bagrulescp.find("^"))))difbags++;
    cout << difbags;

    return 0;
}