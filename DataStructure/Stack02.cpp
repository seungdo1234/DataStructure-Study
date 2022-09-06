#include<iostream>
#include<stack>
using namespace std;

#define endl "\n"

int main() {
	int length = 0, x = 1, y = 0, z = 0;
	cin >> length;

	stack <int> sta;
	int* arr = new int[length];
	int* result = new int[length * 2];
	for (int i = 0; i < length; i++) {
		cin >> arr[i];
	}

	while (1) {
		if (sta.empty() == 1 || (x <= length && sta.top() != arr[y])) {
			sta.push(x);
			result[z] = 1;
			x++;
		}
		else if (sta.top() == arr[y]) {
			sta.pop();
			result[z] = 2;
			y++;

		}
		z++;
		if (sta.empty() == 1 && z == length * 2) {
			for (int i = 0; i < length * 2; i++) {
				if (result[i] == 2) {
					cout << "-" << endl;
				}
				else if (result[i] == 1) {
					cout << "+" << endl;
				}
			}
			break;
		}
		else if (sta.empty() == 0 && z > length * 2 - 1) {
			cout << "NO" << endl;
			break;
		}

	}

	delete[] arr;
	delete[] result;
	return 0;
}