#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main() {
	int number = 0, n = 0;
	char command[6] = { };
	stack<int> sta;

	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> command;
		if ((strcmp(command, "push")) == 0) {
			cin >> n;
			sta.push(n);
		}
		else if ((strcmp(command, "top")) == 0) {
			if (sta.empty() != 1) {
				cout << sta.top() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if ((strcmp(command, "pop")) == 0) {
			if (sta.empty() != 1) {
				cout << sta.top() << endl;
				sta.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if ((strcmp(command, "size")) == 0) {
			cout << sta.size() << endl;
		}
		else if ((strcmp(command, "empty")) == 0) {
			cout << sta.empty() << endl;
		}
	}
	return 0;
}