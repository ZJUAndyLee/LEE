#include<iostream>
using namespace std;

int main() {
	int num, tmp = 0, e = 0, tsum = 0, msum = -1, s = 0;
	cin >> num;
	int *q = new int[num];
	for (int i = 0; i < num; i++)cin >> q[i];
	for (int i = 0; i < num; i++) {
		tsum = tsum + q[i];
		if (tsum > msum) {
			msum = tsum;
			e = i;
			s = tmp;
		}
		if (tsum < 0) {
			tsum = 0;
			tmp = i + 1;
		}
	}
	if (msum < 0) cout << 0 << " " << q[0] << " " << q[num - 1];
	else cout << msum << " " << q[s] << " " << q[e];
}