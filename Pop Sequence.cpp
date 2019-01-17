
#include<iostream>
#include<stack>
using namespace std;

void judge(int n, int m) {
	int *sq = new int[n];
	int ct = 1;
	for (int i = 0; i < n; i++) {
		cin >> sq[i];
	}
	stack<int> q;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (sq[i] > tmp) {
			for (int j = tmp + 1; j < sq[i]; j++) {
				q.push(j);
			}
			if (q.size() >= m) {
				cout << "NO" << endl;
				return;
			}
			tmp = sq[i];
		}
		else {
			if (sq[i] == q.top()) q.pop();
			else {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
	return;
}

int main() {
	int Msize, num, t;
	cin >> Msize >> num >> t;
	for (int i = 0; i < t; i++) {
		judge(num, Msize);
	}
}
