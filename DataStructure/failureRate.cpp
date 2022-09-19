#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int>solution(int N, vector<int>stages) {
	vector<int>answer;
	double* percentage1 = new double[N];
	double* percentage2 = new double[N];
	int x = 1, y = 0, count = 0, vectorSize = stages.size();

	while (x <= N) {
		for (int i = 0; i < stages.size(); i++) {
			if (stages.at(i) == x) count++;
		}
		if (vectorSize > 0) {
			percentage1[y] = (double)count / (double)vectorSize;
			percentage2[y] = (double)count / (double)vectorSize;
			vectorSize -= count;
		}
		else {
			percentage1[y] = -2;
			percentage2[y] = -2;
		}
		x++;
		y++;
		count = 0;
	}

	sort(percentage2, percentage2 + N);

	for (int i = N - 1; i > -1; i--) {
		for (int j = 0; j < N; j++) {
			if (percentage2[i] == percentage1[j]) {
				answer.push_back(j + 1);
				percentage1[j] = -1;
			}
		}

	}
	return answer;
}
int main() {
	int N = 5;

	vector<int>stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

	solution(N, stages);
}