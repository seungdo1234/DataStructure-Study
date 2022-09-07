#include<iostream>
#include<queue>
#include<string.h>

#define endl "\n"

using namespace std;

int main() {
	int number = 0, n = 0;
	char command[6] = { };
	queue<int> que;

	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> command;
		if ((strcmp(command, "push")) == 0) {
			cin >> n;
			que.push(n);
		}
		else if ((strcmp(command, "front")) == 0) {
			if (que.empty() != 1) {
				cout << que.front() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if ((strcmp(command, "back")) == 0) {
			if (que.empty() != 1) {
				cout << que.back() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if ((strcmp(command, "pop")) == 0) {
			if (que.empty() != 1) {
				cout << que.front() << endl;
				que.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if ((strcmp(command, "size")) == 0) {
			cout << que.size() << endl;
		}
		else if ((strcmp(command, "empty")) == 0) {
			cout << que.empty() << endl;
		}
	}
	return 0;
}