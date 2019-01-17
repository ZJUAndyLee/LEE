#include<iostream>
using namespace std;

int toprime(int num) {
	int i;
	for (num;; num++) {
		i = 2;
		while (i < num / 2) {
			if (!(num%i)) break;
			i++;
		}
		if (i == num / 2) break;
	}
	return num;
}

int Insert(int *h, int tmp,int T) {
	int rd = tmp % T;
	int ct = 1;
	while (h[rd] != -1 && ct/2<T) {
		if (ct % 2) {
			rd = (tmp + ((ct + 1) / 2)*((ct + 1) / 2)) % T;
			ct++;
		}
		else {
			rd = tmp - (ct / 2)*(ct / 2); 
			if (rd < 0) { while (rd < 0) rd = rd + T; }
			else rd = rd % T;
			ct++;
		}
	}
	if (h[rd] == -1) {
		h[rd] = tmp;
		return rd;
	}
	else return -1;
}

int main() {
	int Tsize, Msize, tmp;
	cin >> Tsize >> Msize;
	Tsize = toprime(Tsize);
	int *hash = new int[Tsize];
	int *data = new int[Msize];
	for (int i = 0; i < Tsize; i++) hash[i] = -1;
	for (int i = 0; i < Msize; i++) cin >> data[i];
	for (int i = 0; i < Msize; i++) {
		data[i] = Insert(hash, data[i], Tsize);
	}
	for (int i = 0; i < Msize; i++) {
		if (i != 0) cout << " ";
		if (data[i] == -1) cout << "-";
		else cout << data[i];
	}
}
