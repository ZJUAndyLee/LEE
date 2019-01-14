#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
#include<algorithm>
using namespace std;
#define MAX1 100000000
bool compare(int x,int y){
        return x>y;
}

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
                        else {G[i][j] = MAX1; G[j][i] = MAX1;}
                }
        }
        for (int i = 0; i < m; i++) {
                cin >> v1 >> v2 >> w;
                G[v1-1][v2-1] = w;
                G[v2-1][v1-1] = w;
        }
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        for (int k = 0; k < n; k++) {
                                if (G[j][i] + G[i][k] < G[j][k]) G[j][k] = G[j][i] + G[i][k];
                        }
                }
        }
        /*for(i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<G[i][j]<<" ";
            cout<<endl;
        }*/
        int mindist=MAX1;
        int maxdist,val;
        for (int i = 0; i < n; i++){
                maxdist=G[i][0];
                for (int j = 0; j < n; j++) {
                        if (i!=j && G[i][j] > maxdist)maxdist=G[i][j];
                }
                if(maxdist==MAX1){cout<<"0"<<endl;break;}
                if(maxdist<mindist) {mindist=maxdist;val=i+1;}
        }
        if(mindist!=MAX1) cout << val << " " << mindist;
}
