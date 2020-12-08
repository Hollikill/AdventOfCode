#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string bagtypes (string bagrulesorg, string containedbag) {
    string bagrules = bagrulesorg;
    string containerbags = "";
    bool containable = false;
    while (!(bagrules.find("^"+containedbag) == string::npos || bagrules.find("^"+containedbag) > bagrulesorg.length())) {
        containable = true;
        while (bagrules.substr(1,bagrules.find("^"+containedbag)).find("#") != string::npos) {
            bagrules = bagrules.substr(bagrules.substr(1).find("#")+2);
        }
        containerbags += "#" + bagrules.substr(0,bagrules.find("^"));
        //cout << containedbag << " >> " << bagrules.substr(0,bagrules.find("^")) << endl;
        bagrules = bagrules.substr(bagrules.find("^"+containedbag)+1+containedbag.length());
    }
    if (containable) {
        string metacontainedbag = "";
        metacontainedbag += containerbags;
        while (containerbags.substr(1).find("#") != string::npos) {
            metacontainedbag += bagtypes(bagrulesorg, containerbags.substr(1, containerbags.substr(1).find("#")));
            containerbags = containerbags.substr(containerbags.substr(1).find("#")+1);
        }
        metacontainedbag += bagtypes(bagrulesorg, containerbags.substr(1));
        
        string tmpmetacontainedbag = "";
        tmpmetacontainedbag += metacontainedbag;
        int loc = 0;
        while (tmpmetacontainedbag.substr(1).find("#") != string::npos) {
            cout << tmpmetacontainedbag.substr(tmpmetacontainedbag.substr(1).find("#")+1) << endl;
            if (tmpmetacontainedbag.substr(tmpmetacontainedbag.substr(1).find("#")+1).find(tmpmetacontainedbag.substr(0,tmpmetacontainedbag.substr(1).find("#")+1)) != string::npos) {
                metacontainedbag = metacontainedbag.substr(0,loc) + metacontainedbag.substr(loc+tmpmetacontainedbag.substr(1).find("#")+1);
                loc-=tmpmetacontainedbag.substr(1).find("#")+1;
            }
            loc+=tmpmetacontainedbag.substr(1).find("#")+1;
            tmpmetacontainedbag = tmpmetacontainedbag.substr(tmpmetacontainedbag.substr(1).find("#")+1);
        }
        if (tmpmetacontainedbag.substr(tmpmetacontainedbag.substr(1).find("#")+1).find(tmpmetacontainedbag.substr(0,tmpmetacontainedbag.substr(1).find("#")+1)) != string::npos) {
            metacontainedbag = metacontainedbag.substr(0,loc) + metacontainedbag.substr(loc+tmpmetacontainedbag.substr(1).find("#")+1);
        }
        loc+=tmpmetacontainedbag.substr(1).find("#")+1;
        tmpmetacontainedbag = tmpmetacontainedbag.substr(tmpmetacontainedbag.substr(1).find("#")+1);

        return metacontainedbag;
    }
    else {
        return "#"+containedbag;
    }
}

int main () {
    ifstream infile;
    infile.open ("input.txt");

    string bagrules = "";

    if (infile.is_open()) {
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

    cout << "enter address:" << endl;
    string targetbag = "shiny gold";
    //in >> targetbag;
    cout << endl;
    string difbagstr = bagtypes(bagrules, targetbag);
    int difbags = 0;

    while (difbagstr.find("#") != string::npos) {
        difbags++;
        difbagstr = difbagstr.substr(difbagstr.find("#")+1);
    }

    cout << difbags;

    return 0;
}