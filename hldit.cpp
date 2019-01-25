#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

struct edge {
        int v;
        int nd;
        edge *p;
};

struct graph {
        int v;
        int out, in;
        edge *p;
};
typedef graph *gra;
edge *creatn(int nd,int v) {
        edge *p = new edge;
        p->v = v;
        p->nd = nd;
        p->p = NULL;
}

void creatg(graph *g,int m) {
        int s, e, v;
        edge *pt = new edge;
        for (int i = 0; i < m; i++) {
                cin >> s >> e >> v;
                if ((g + s)->p) {
                        pt = (g + s)->p;
                        while (pt->p) pt = pt->p;
                        pt->p = creatn(e, v);
                        g[s].out++;
                        g[e].in++;
                }
                else {
                        (g + s)->p = creatn(e, v);
                        g[s].out++;
                        g[e].in++;
                }
        }
}

int renew(graph *g,int n) {
        graph *p = new graph;
        edge *pt = new edge;
        queue<gra> qu;
        int ct=0;
        for (int i = 0; i < n; i++) {
                if (g[i].in == 0) qu.push(g + i);
        }
        while (!qu.empty()) {
                p = qu.front();
                pt = p->p;
                qu.pop();
                ct++;
                while (pt) {
                        if (g[pt->nd].v < p->v + pt->v) g[pt->nd].v = p->v + pt->v;
                        g[pt->nd].in--;
                        if (g[pt->nd].in == 0) qu.push(g + pt->nd);
                        pt = pt->p;
                }
        }
        if(ct!=n) return 0;
        else return 1;
}

int main() {
        int n, m;
        cin >> n >> m;
        graph *g = new graph[n];
        for (int i = 0; i < n; i++) {
                g[i].v = g[i].out = g[i].in = 0;
                g[i].p = NULL;
        }
        creatg(g, m);
        if (renew(g, n)) {
                int max = 0;
                for (int i = 0; i < n; i++) {
                  if(g[i].v>max) max=g[i].v;
                }
                cout << max;
        }
        else cout << "Impossible";
}
