#include <string>
#include <sstream>
#include <vector>
#include<iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> procedure;
    string stringBuffer;
   
    for (int i = 0; i < record.size(); i++) {
        vector<string> pro;
        istringstream ss(record[i]);
        getline(ss, stringBuffer, ' ');
        if (stringBuffer == "Enter")  pro.push_back("1");
        if (stringBuffer == "Leave")  pro.push_back("2");
        if (stringBuffer == "Change")  pro.push_back("3");
        getline(ss, stringBuffer, ' ');
        pro.push_back(stringBuffer);
        if (pro.at(0) == "1" || pro.at(0) == "3") {
            getline(ss, stringBuffer, ' ');
            pro.push_back(stringBuffer);
            if (procedure.empty() != true) {
                for (int j = 0; j < procedure.size(); j++) {
                    if (procedure[j][1] == pro[1]) procedure[j][2] = pro[2];
                }
            }
        }
        else if (pro.at(0) == "2") {
            for (int j = 0; j < procedure.size(); j++) {
                if (procedure[j][1] == pro[1]) {
                    pro.push_back(procedure[j][2]);
                    break;
                }
            }
        }
        if (pro.at(0) == "1" || pro.at(0) == "2")   procedure.push_back(pro);
    }
    for (int j = 0; j < procedure.size(); j++) {
        if (procedure[j][0] == "1") {
            answer.push_back(procedure[j][2] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        }
        if (procedure[j][0] == "2") {
            answer.push_back(procedure[j][2] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        }
    }

    return answer;
}

int main() {
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234",
            "Enter uid1234 Prodo","Change uid4567 Ryan" };

    solution(record);
    
}