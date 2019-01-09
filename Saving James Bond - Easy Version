#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
struct graph {
        bool v;
        graph *p;
};
int search(int (*p)[2],bool graph[101][101],int i,int n,int m) {
        int answer = 0;
        if (p[i][0] >= 50-n || p[i][1] >= 50-n || p[i][0]<=n-50 || p[i][1]<=n-50) {
                answer = 1;
        }
        else {
                for (int j = 0; j < m; j++) {
                        if(j!=i){
                                if (sqrt(pow(double(p[j][0])-double(p[i][0]), 2.0) + pow(double(p[j][1])-double(p[i][1]), 2.0)) <= n) {
                                        if (!graph[i + 1][j + 1]) {
                                                graph[j + 1][i + 1] = true;
                                                graph[i + 1][j + 1] = true;
                                                answer=search(p, graph, j, n, m);
                                        }

                                }
                        }
                        if (answer) break;
                }
        }
        return answer;
}

int main() {
        int m,n,answer;
        cin >> m >> n;
        int (*p)[2] = new int[m][2];
        if(m==0){
          if(n>=50) cout<<"Yes"<<endl;
          else cout<<"No"<<endl;
        }
        else{
        for (int i = 0; i < m; i++) {
                cin >> p[i][0] >> p[i][1];
        }
        bool graph[101][101] = {0};
        for (int i = 0; i < m; i++) {
                if (sqrt(pow(double(p[i][0]), 2.0) + pow(double(p[i][1]), 2)) <= 7.5+n) {
                        graph[0][i + 1] = true;
                        graph[i + 1][0] = true;
                        answer=search(p,graph,i,n,m);
                }
                if (answer) break;
        }
        if (answer) cout << "Yes" << endl;
        else cout << "No" << endl;
}
}
