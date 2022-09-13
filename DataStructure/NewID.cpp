#include <iostream>
#include <string.h>

using namespace std;

#define endl "\n";

string compareList = "~ ! @ # $ % ^ & * ( ) = + [ { ] } : ? , < > / ";

int printList(int check, string newID , int level) {
	if (check == 1)
	{
		cout << level <<"단계 :  " << newID << endl;
	}
	else if (check == 2) {
		cout << level << "단계 :  문자열이 비었습니다." << endl;
		return check;
	}
	else {
		cout << level << "단계 :  거의 변화가 없습니다." << endl;
	}
	return check = 0;
}

void inputData(string newID) {
	int check = 0, level = 1;
	
	cin >> newID;

	for (int z = 1; z < 8; z++) {
		if (z == 1) {
			for (int i = 0; i < newID.size(); i++) {
				if ('A' <= newID[i] && 'Z' >= newID[i]) {
					newID[i] += 32;
					check =		1;
				}
			}
		}
		if (z == 2) {
			for (int i =  newID.size() - 1; i >= 0 ; i--) {
				for (int j = 0; j < compareList.size(); j++) {
					if (newID[i] == compareList[j]) {
						newID.erase(i, 1);
						check = 1;
					}
				}
			}
		}
		if (z == 3) {
			for (int i = newID.size()-1 ; i >  0; i--) {
				if (newID[i] == '.' && newID[i - 1] == '.' ) {
					newID.erase(i, 1);
					check = 1;
				}
			}
		}
		if (z == 4) {
			if (newID.size() == 1 && newID[0] == '.') {
				newID.erase(0, 1);
				check = 2;
			}
			else if( newID[newID.size() - 1] == '.' || newID[0] == '.'){
					if (newID[0] == '.') {
						newID.erase(0, 1);
					}
					if (newID[newID.size() - 1] == '.') {
						newID.erase(newID.size()-1, 1);
					}
					check = 1;
			}
		}
		if (z == 5) {
			if (check == 2) {
				newID += 'a';
				check = 1;
			}
			else {
				check = 0;
			}
		}
		if (z == 6) {
			if (newID.size() > 15) {
				newID.erase(15, newID.size() - 15);
				check = 1;
				if (newID[newID.size() - 1] == '.') {
					newID.erase(newID.size() - 1, 1);
				}
			}
		}
		if (z == 7) {
			if (newID.size() <= 2) {
				int index = newID.size();
				for (int i = newID.size() - 1; i < 2; i++) {
					newID += newID[index-1];
				}
				check = 1;
			}
		}
		check = printList(check, newID, z);
		
	}

}
int main() {
	string newID;
	
	inputData(newID);

	
}