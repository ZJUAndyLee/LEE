#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;
struct graph {
        bool v;
        int i;
        graph *p;
};

graph *creatN(int i) {
        graph *x = new graph;
        x->i = i;
        x->v = false;
        x->p = NULL;
        return x;
}

void createG(graph *g, int(*line)[2], int n, int m) {
        graph *link = new graph;
        for (int j = 0; j < n; j++) {
                g[j].p = creatN(j + 1);
                link = g[j].p;
                for (int i = 0; i < m; i++) {
                        if (line[i][0] == j + 1) {
                                link->p = creatN(line[i][1]);
                                link = link->p;
                        }
                        if(line[i][1]==j+1){
                                link->p = creatN(line[i][0]);
                                link = link->p;
                        }
                }
        }
}

void test(int i, graph *g) {
        typedef graph *f;
        int j = 0, j1 = 0;
        int s = 0;
        int nl = 0;
        int ct=0;
        f link = g[i].p;
        f node;
        vector<f> set;
        g[i].v = true;
        set.push_back(g[i].p);
        while (set.size()) {
                link = set[0];
                node = link;
                set.erase(set.begin(), set.begin() + 1);
                while (node) {
                        if (!g[node->i - 1].v) {
                                g[node->i - 1].v = true;
                                set.push_back(g[node->i - 1].p);
                                j = j + 1;
                        }
                        node = node->p;
                }
                if (!node) {
                        nl++;
                        ct++;
  }
                if (nl == j1 || ct==1) {
                        j1 = j;
                        nl = 0;
                        j = 0;
                        s++;
                }
                if (s == 6) break;
        }
}

void reset(graph *g,int n) {
        for (int i = 0; i < n; i++) {
                g[i].v = false;
        }
}

int main() {
        int n, m, ct = 0;
        cin >> n >> m;
        graph *g = new graph[n];
        graph *link = new graph;
        int(*line)[2] = new int[m][2];
        for (int i = 0; i < m; i++) {
                cin >> line[i][0] >> line[i][1];
        }
        createG(g, line, n, m);
        for (int i = 0; i < n; i++) {
                test(i, g);
                ct=0;
                for (int j = 0; j < n; j++) {
                                if (g[j].v) ct++;
                }
                cout <<i+1<<": "<<fixed<<setprecision(2)<< 100*double(ct) / n <<"%"<< endl;
                reset(g, n);
        }

}
