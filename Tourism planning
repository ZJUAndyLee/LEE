#include<iostream>
using namespace std;
#define MAX1 65535
struct Edge {
        int dis;
        int val;
};
struct MGraph {
        Edge *e;
        int **G;
        int *dist;
        int *value;
        int *path;
};
MGraph *initiaG(int n) {
        MGraph *graph = new MGraph;
        graph->G = new int*[n];
        for (int i = 0; i < n; i++) (graph->G)[i] = new int[n];
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) graph->G[i][j] = -1;
        }
        return graph;
}

void createG(MGraph *g,int m) {
        int ct1, ct2,dis,val;
        g->e = new Edge[m];
        for (int i = 0; i < m; i++) {
                cin >> ct1 >> ct2 >> dis >> val;
                g->e[i].dis = dis;
                g->e[i].val = val;
                g->G[ct1][ct2] = i;
                g->G[ct2][ct1] = i;
        }
}

void initialdp(MGraph *g, int n,int sp) {
        g->dist = new int[n];
        g->path = new int[n];
        g->value = new int[n];
        for (int i = 0; i < n; i++) {
                if (g->G[sp][i] == -1) { g->dist[i] = MAX1; g->path[i] = -1; g->value[i]=MAX1; }//起点与未和起点相连的父结点的下标均表示为-1
                else {
                        g->dist[i] = g->e[g->G[sp][i]].dis;
                        g->path[i] = sp;
                        g->value[i] = g->e[g->G[sp][i]].val;
                }
        }
        g->dist[sp] = 0;
        g->value[sp] = 0;
}


void findpath(MGraph *g, bool *ex, int n, int sp) {
        int tmp2 = MAX1,ct,tmp;
        while (1) {
                ct=0;
  for (int i = 0; i < n; i++) {
                        if(i!=sp){
                              if (g->dist[i] < tmp2) { if (!ex[i]) { tmp2 = g->dist[i]; tmp=i; ct = 1; } }
                        }
                }
                if (ct == 0) break;
                ex[tmp] = true;
                for (int j = 0; j < n; j++) {
                        if (tmp != j && g->G[tmp][j] != -1) {
                                if (g->dist[tmp] + g->e[g->G[tmp][j]].dis < g->dist[j]) {
                                        g->dist[j] = g->dist[tmp] + g->e[g->G[tmp][j]].dis;
                                        g->path[j] = tmp;
                                        g->value[j] = g->value[tmp] + g->e[g->G[tmp][j]].val;
                                }
                                if(g->dist[tmp] + g->e[g->G[tmp][j]].dis == g->dist[j]){
                                        if(g->value[tmp]+g->e[g->G[tmp][j]].val < g->value[j]){
                                            g->value[j]=g->value[tmp]+g->e[g->G[tmp][j]].val;
                                            g->path[j] = tmp;
                                        }
                                }
                        }
                }
        tmp2 = MAX1;
        }
        return;
}

int cost(MGraph *g, int dt) {
        int tmp1=g->path[dt],tmp2=dt;
        int tt=0;
        while (tmp1 >= 0) {
                tt = tt + g->e[g->G[tmp1][tmp2]].val;
                tmp2 = tmp1;
                tmp1 = g->path[tmp1];
        }
        return tt;
}

int main() {
        int n,m,sp,dt;
        cin >> n >> m >> sp >> dt;
        MGraph *graph = new MGraph;
        graph = initiaG(n);
        createG(graph, m);
        initialdp(graph, n, sp);
        bool *ex = new bool[n];
        for (int i = 0; i < n; i++) ex[i] = false;
        ex[sp] = true;
        findpath(graph, ex, n, sp);
        int value;
        value=cost(graph,dt);
        cout<<graph->dist[dt]<<" "<<value;
}
                                                  
