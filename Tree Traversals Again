#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
#include<string>
using namespace std;

struct Treenode {
        int v;
        Treenode *left;
        Treenode *right;
};

Treenode *createnode(int v) {
        Treenode *tree=new Treenode;
        tree->v= v;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
}

Treenode *createTree(int *pre,int *in,int len) {
        Treenode *T = new Treenode;
        T = createnode(pre[0]);
        if (len <= 0) {
                return NULL;
        }
        else if (len == 1 && *pre == *in) return T;
        else
        {
                for (int i = 0; i < len; i++) {
                       // cout<<in[i]<<endl;
                        if (in[i] == pre[0]) {
                                T->left = createTree(pre + 1, in, i);
                                T->right = createTree(pre + i + 1, in + i + 1, len - i - 1);
                        }
                }
        }
        return T;
}

void initia(int *pre, int *in,int m) {
        int i=0,j=0,n;
        string str;
        stack<int> s;
        while (j<m) {
                cin >> str;
                if (str == "Push") {
                        cin >> n;
                        pre[i] = n;
                        s.push(n);
                        i++;
                }
                else {
                        in[j] = s.top();
                        s.pop();
                        j++;
                }
        }
}

void pt(Treenode *t, int v) {
        if (t) {
                pt(t->left,v);
                pt(t->right,v);
   if (t->v != v) {
                        cout << t->v << " ";
                }
                else cout << v;
        }
}
int main() {
        int m;
        cin >> m;
        int *pre = new int[m];
        int *in = new int[m];
        initia(pre,in,m);
        /*for(int i=0;i<m;i++){
            cout<<*(pre+i)<<endl;
        }*/
        Treenode *t = new Treenode;
        t = createTree(pre, in, m);
        pt(t, pre[0]);
}
