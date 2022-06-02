#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

void solve(vii arr, int parity) {
    int N = arr.size();

    vii dp_mt(N, vi(N, 0));

    for (int i = 0;i < N;i++) {
        dp_mt[0][i] = arr[0][i];
    }
    for (int j = 0;j < N;j++) {
        dp_mt[j][0] = arr[j][0];
    }

    for (int i = 1;i < N;i++) {
        for (int j = 1;j < N;j++) {

            int path_sum_1 = dp_mt[i - 1][j] + arr[i][j];
            int path_sum_2 = dp_mt[i][j - 1] + arr[i][j];

            dp_mt[i][j] = path_sum_1 % 2 == parity ? path_sum_1 : path_sum_2;

        }
    }

    
}

vii fillArr(int N) {

    vii mt;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            mt[i][j] = (i + 1) + N * ((j + 1) - 1);
        }
    }
    return mt;
}
int main() {




    return 0;

}