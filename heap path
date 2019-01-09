#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main() {
	int m,n,v,j=0;
	cin >> m >> n;
	int *p = new int[m+1];
	p[0] = -10001;
	int size = 0;
	for (int i = 1; i <= m; i++) {
		cin >> v;
		//cout << v << endl;
		for (j = (size + 1); v < p[j/2]; j = j / 2) {
			p[j] = p[j / 2];	
		}
		size++;
		p[j] = v;
	}
	for (int i = 0; i < n; i++) {
		cin >> v;
		for (j = v; j > 0; j = j / 2) {
			if (j / 2) {
				cout << p[j] << " ";
			}
			else cout << p[j] << endl;
		}
	}
	//cin >> n;
}
