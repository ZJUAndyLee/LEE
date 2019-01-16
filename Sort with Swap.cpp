#include<iostream>
using namespace std;

int main() {
	int num,n=0,tt=0,tmp;
	cin >> num;
	int *q = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> q[i];
	}
	if (q[0] == 0) {
		for (int i = 0; i < num; i++) {
			if (q[i] != i) {
				q[0] = q[i];
				q[i] = 0;
				tt++;
                                break;
			};
		}
	}
	for (int i = 0; i < num; i++) {
		if (q[i] == i) n++;
	}
	bool *index = new bool[num];
	for (int i = 0; i < num; i++) index[i] = 0;
	for (int i = 0; i < num; i++) {
                tmp = q[i];
		if (!index[i]) {
			if (q[i] != i) {
				while (tmp != i) {
                                        index[tmp]=1;
					tmp = q[tmp];
				}
				tt++;
			}
		}
	}
        if(num==1) cout<<"0"
	else cout<<num-1-n+tt-1;
}
