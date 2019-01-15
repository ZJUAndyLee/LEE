#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct TreeNode {
	int v;
	TreeNode *left;
	TreeNode *right;
	int flag;
};

TreeNode *creatnode(int v) {
	TreeNode *T = new TreeNode;
	T->v = v;
	T->left = NULL;
	T->right = NULL;
	T->flag = 0;
	return T;
}

TreeNode *insert(TreeNode *T, int v) {
	if (!T) {
		T=creatnode(v);
	}
	else {
		if (T->v > v) T->left=insert(T->left, v);
		else if (T->v < v) T->right=insert(T->right, v);
	}
	return T;
}
TreeNode *newtree(int N) {
	TreeNode *T = NULL;
	int v;
	for (int i = 0; i < N; i++) {
		cin >> v;
		T = insert(T, v);
	}
	return T;
}
int panduan(TreeNode *T,int v) {
	if (!T->flag) {
		if (T->v == v) { T->flag = 1; return 1; }
		else return 0;
	}
	else {
		if (T->v > v) return panduan(T->left, v);
		else if (T->v < v) return panduan(T->right, v);
		else return 0;
	}
}
int judge(TreeNode *T, int N) {
	int flag = 0;
	int v;
	cin >> v;
	if (T->v == v) {
		T->flag = 1;
	}
	else flag = 1;
	for(int i=1;i<N;i++){
		cin >> v;
		if (!flag && !panduan(T, v)) flag = 1;
	}
	if (!flag) return 1;
	else return 0;
}
void setflag(TreeNode *T) {
	T->flag = 0;
	if(T->left) setflag(T->left);
	if(T->right) setflag(T->right);
}
void FreeT(TreeNode *T) {
	if (T->left) FreeT(T->left);
	if (T->right) FreeT(T->right);
	free(T);
}
int main() {
	int N, L;
	TreeNode *T;
	cin >> N;
	while (N) {
		cin >> L;
		T = newtree(N);
		for (int i = 0; i < L; i++) {
			if (judge(T, N)) cout << "Yes" << endl;
			else cout << "No" << endl;
			setflag(T);
		}
		FreeT(T);
		cin >> N;
	}
}
