#include<iostream>
#include<string>

using namespace std;

int compression(string s) {
	string compare1 ,compare2 , sc;
	int min = 0, x, count = 1;
	
	cin >> s;
	if (s.size() == 1) return 1;

	for (int i = 1; i <= s.size() / 2; i++) { // 비교할 문자열의 갯수
		for (int z = 0; z < i; z++) {
			compare1 += s[z];
		}
		x = i;
		while (1) {
			for (int z = 0; z < i; z++) {
				compare2 += s[x];
				x++;
				if (s[x] == NULL) break;

			}
			if (compare1 == compare2) count++;
			else {
				if (count > 1) {
					string num(to_string(count));
					sc += num;
				}
				count = 1;
				sc += compare1;
				compare1 = compare2;
			}
			compare2 = {};
			if (x == s.size() ) {
				if (count > 1) { 
					string num(to_string(count));
					sc += num;
				}
				count = 1;
				sc += compare1;
				break;
			}
			
		}
		if (min == 0 || min > sc.size()) min = sc.size();
		sc = {}, compare1 = {};
	}
	return min;

}
int main() {
	string s;

	int min = compression(s);
	cout << min << endl;
	return 0;
}