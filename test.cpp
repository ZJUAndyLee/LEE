#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
#include<algorithm>
using namespace std;

int main() {
	int n, m,i;
	int v1, v2, w;
	cin >> n >> m;
	int **G = new int*[n];
	for (int i = 0; i < n; i++) {
		G[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) { G[i][j] = 0; G[j][i] = 0; }
			else {G[i][j] = INT_MAX; G[j][i] = 100000000;}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> w;
		G[v1][v2] = w;
		G[v2][v1] = w;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (G[i][j] + G[j][k] < G[i][k]) G[i][k] = G[i][j] + G[j][k];
			}
		}
	}
	int *tmp1 = new int[n];
	int *tmp2 = new int[n];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] = tmp1[j];
		}
		sort(tmp1, tmp1 + n);
		for (int j = 0; j < n; j++) {
			if (G[i][j] == tmp1[0]) {
				tmp2[i] = G[i][j];
			}
		}
	}
	int val = 0;
	for (int i = 1; i < n; i++) {
		if (tmp2[i] < tmp2[val]) val = i;
	}
	cout << i << " " << tmp2[i];
	//now i have changed this code so what will happen?
}