#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int find(int *S, int n) {
	for (n = n - 1; S[n] >= 0; n = S[n]);
	return n;
}
void Check(int *S) {
	int n, m,root1,root2;
	cin >> n >> m;
	root1 = find(S, n);
	root2 = find(S, m);
	if (root1!=root2) cout << "no" << endl;
	else cout << "yes" << endl;
}
void Insert(int *S) {
	int n, m,root1,root2;
	cin >> n >> m;
	root1 = find(S, n);
	root2 = find(S, m);
	if (root1 != root2) {
		if (S[root1] > S[root2]) {
		  S[root2] = S[root2] + S[root1];
			S[root1] = root2;
		}
		else {
		  S[root1] = S[root1] + S[root2];
			S[root2] = root1;
			
		}
	}
}
void Stop(int *S,int x) {
	int ct = 0;
	for (int i = 0; i < x; i++) {
		if (S[i] < 0) ct++;
	}
	if (ct == 1) cout << "The network is connected.";
	else cout << "There are " << ct << " " << "components.";
}
int main() {
	char a;
	int x;
	cin >> x;
	int *S = new int[x];
	for (int i = 0; i < x; i++) {
		S[i] = -1;
	}
	do {
		cin >> a;
		switch (a) {
		case('C'): Check(S); break;
		case('I'): Insert(S); break;
		case('S'):Stop(S, x); break;
		}
	} while (a != 'S');
	//cin >> a;
}
