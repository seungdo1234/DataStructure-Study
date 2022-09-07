#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int length,value;
	
	cin >> length;


	int* arr = new int[length];

	for (int i = 0; i < length; i++) {
		cin >> value;
		arr[i] = value;
	}
	
	sort(arr, arr + length);
	
	for (int i = 0; i < length; i++) {
		cout << arr[i] << "\n";
	}

	delete[] arr;
	return 0;
}