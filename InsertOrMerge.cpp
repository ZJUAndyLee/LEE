#include<iostream>
using namespace std;

int judge(int *l, int *n, int num) {
	int tmp=n[0],i;
	for ( i = 1; i < num; i++) {
		if (tmp > n[i]) break;
		tmp = n[i];
	}
	tmp = i;
	for (; i < num; i++) {
		if (l[i] != n[i]) break;
	}
	if (i < num - 1) return tmp;
	else return 0;
}

void Insert(int *n, int num) {
	int i,tmp=n[0];
	for (i = 0; i < num; i++) {
		if (tmp > n[i]) break;
		else tmp = n[i];
	}
	tmp = n[i];
	for (i = i - 1; i > -1; i--) {
		if (n[i] > tmp) n[i + 1] = n[i];
		else break;
	}
	n[i + 1] = tmp;
	return;
}

void Merge1(int *n, int *tmp, int L, int length,int last) {
	int R = L + length;
	int left = L + length;
	int tp = L;
	while (L < left && R < last+1) {
		if (n[L] < n[R]) { tmp[tp] = n[L]; L++; tp++; }
		else { tmp[tp] = n[R]; R++; tp++; }
	}
	while (L < left) { tmp[tp] = n[L]; L++; tp++; }
	while (R < last+1) { tmp[tp] = n[R]; R++; tp++; }
}

void Merge_pass(int *n, int length, int num) {
	int *tmp = new int[num];
	int i;
	for ( i = 0; i < num - 2 * length; i = i + 2 * length) {
		Merge1(n, tmp, i, length,i+2*length-1);
	}
	if (i + length < num) Merge1(n, tmp, i, length, num-1);
	else {
		for (; i < num; i++) tmp[i] = n[i];
	}
	for (i = 0; i < num; i++) {
	  if(n[i]!=tmp[i]) break;
	}
	if(i<num-1) {
	  for(int i=0;i<num;i++) n[i]=tmp[i];
	 return;
	}
	else Merge_pass(n,2*length, num);
}

int findL(int *n, int num) {
	int tmp = n[0], i,j;
	int tmp1,k;
	for (i = 1; i < num; i++) {
		if (tmp > n[i]) break;
		tmp = n[i];
	}
	tmp = i;
	for (j = i; j > 0; j--) {
		tmp1 = n[j];
		for ( k = j + 1; k < num; k++) {
			if (tmp1 > n[k])break;
			tmp1 = n[k];
		}
		if ((k - j) == tmp)return tmp;
		tmp--;
	}
}


int main() {
	int num,tmp;
	cin >> num;
	int *last = new int[num];
	int *next = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> last[i];
	}
	for (int i = 0; i < num; i++) {
		cin >> next[i];
	}
	tmp = judge(last, next, num);
	if (!tmp) {
		Insert(next, num);
		cout << "Insertion Sort" << endl;
		for (int i = 0; i < num; i++) {
			if (i != 0)cout << " ";
			cout << next[i];
		}
	}
	else {
		Merge_pass(next, findL(next,num), num);
		cout << "Merge Sort" << endl;
		for (int i = 0; i < num; i++) {
			if (i != 0)cout << " ";
			cout << next[i];
		}
	}
}
