#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
#include<algorithm>
using namespace std;

struct hfmt {
        char c;
        int v;
        hfmt *nt;
};

struct test {
        char c;
        string str;
        int v;
        int len;
};


void inp(test *p,int n,hfmt *ht){
        hfmt *tmp = new hfmt;
        tmp = ht;
        for (int i = 0; i < n; i++) {
                cin >> p[i].c >> p[i].str;
                p[i].len = p[i].str.length();
                while (tmp) {
                        if (tmp->c == p[i].c) {
                                p[i].v = tmp->v;
                                break;
                        }
                        tmp = tmp->nt;
                }
                tmp = ht;
        }
}

bool judge1(test *p, int n, int tt) {
        int ct=0;
        for (int i = 0; i < n; i++) ct = ct + p[i].v*p[i].len;
        if (ct == tt) return true;
        else return false;
}

bool judge2(test *p, int n) {
        int tmp = 1;
        for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                        if (tmp != 0) {
                                if (p[i].len > p[j].len) tmp = p[i].str.compare(0, p[j].len, p[j].str, 0, p[j].len);
                                else tmp = p[j].str.compare(0, p[i].len, p[i].str, 0, p[i].len);
                        }
                        else return false;
                }
        }
 return true;
}

hfmt *createnode() {
        hfmt *p = new hfmt;
        cin >> p->c >> p->v;
        p->nt = NULL;
        return p;
}
hfmt *createf(int v) {
        hfmt *p = new hfmt;
        p->v = v;
        p->c = '!';
        p->nt = NULL;
        return p;
}
int main() {
        int m,q, ct = 0;
        cin >> m;
        hfmt *ht = new hfmt;
        hfmt *n = new hfmt;
        hfmt *p = new hfmt;
        test *newtree = new test[m];
        p = createnode();
        ht = p;
        n = p;
        for (int i = 1; i < m; i++) {
                p = createnode();
                while (n) {
                        if (p->v > n->v&&n->nt) {
                                if (p->v > n->nt->v) n = n->nt;
                                else {
                                        p->nt = n->nt;
                                        n->nt = p;
                                        break;
                                }
                        }
                        else if (p->v > n->v && !(n->nt)) {
                                n->nt = p;
                                break;
                        }
                        else {
                                p->nt = n;
                                ht = p;
                                break;
                        }
                }
                n = ht;
        }
        p = ht;
        for (int i = 1; i < m; i++) {
                //cout << p->v << " " << p->nt->v << endl;
                n = createf(p->v + p->nt->v);
 hfmt *tmp = new hfmt;
                tmp = p->nt->nt;
                while (tmp) {
                        if (n->v > tmp->v&&tmp->nt) {
                                if (n->v > tmp->nt->v) tmp = tmp->nt;
                                else {
                                        n->nt = tmp->nt;
                                        tmp->nt = n;
                                        break;
                                }
                        }
                        else if (n->v > tmp->v && !(tmp->nt)) {
                                tmp->nt = n;
                                break;
                        }
                        else {
                                p->nt->nt = n;
                                n->nt = tmp;
                                break;
                        }
                }
                if (!tmp) p->nt->nt = n;
                p = p->nt->nt;
        }
        p = ht;
        while (p) {
                if (p->c == '!') ct = ct + p->v;
                p = p->nt;
        }
        //cout<<ct<<endl;
        cin >> q;
        for (int i = 0; i < q; i++) {
                inp(newtree, m, ht);
                if (!judge1(newtree, m, ct)) cout << "No" << endl;
                else {
                        if (judge2(newtree, m)) cout << "Yes" << endl;
                        else cout << "No" << endl;
                }

        }
        return 0;
}
