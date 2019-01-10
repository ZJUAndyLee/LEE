#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

void cbst(int *p, int *r, int tt, int n) {
        if (tt == 0) return;
        else {
                int lt, rt, x;
                x = log(tt)/log(2);
                if (tt - pow(2, x) + 1 <= pow(2, x - 1)) {
                        lt = tt - pow(2, x - 1);
                        rt = pow(2, x - 1) - 1;
                        r[n] = p[lt];
                        cbst(p, r, lt, 2 * n + 1);
                        cbst(p + lt + 1, r, rt, 2 * n + 2);
                }
                else {
                        lt = pow(2, x)-1;
                        rt = tt - lt - 1;
                        r[n] = p[lt];
                        cbst(p, r, lt, 2 * n + 1);
                        cbst(p + lt + 1, r, rt, 2 * n + 2);
                }
        }
        return;
}

int main() {
        int n, m;
        double x;
        cin >> n;
        int *p = new int[n];
        for (int i = 0; i < n; i++) {
                cin >> p[i];
        }
        sort(p, p + n);
        x = pow(n, 0.5);
        m = floor(x + 1);
        m = int(pow(2, m)) - 1;
        int *r = new int[m];
        /*for (int i = 0; i < m; i++) {
                r[i] = -1;
        } 多一个赋值语句最后一个测试点竟然就直接超时了*/
        cbst(p, r, n, 0);
        for (int i = 0; i < n-1; i++) {
                cout << r[i]<<" ";
        }
        cout << r[n - 1];
}
