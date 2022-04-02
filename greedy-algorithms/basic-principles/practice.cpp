#include<bits/stdc++.h>
using namespace std;

int numberOfLargestIncreasingSubsequences(vector<int> arr) {
    int  n = arr.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    int maxEl = 0;

    for (int i = 1;i < n;i++) {
        for (int j = 0;j < i;j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] == dp[j]) {
                    dp[i] += 1;
                    count[i] = count[j];
                }
                else if (dp[i] == dp[j] + 1) {
                    count[i] += count[j];
                }
            }
        }
        maxEl = max(maxEl, dp[i]);
    }

    int res = 0;
    for (int i = 0;i < n;i++) {
        if (dp[i] == maxEl) res += count[i];
    }
    return res;
}

int numberOfPathsToExit(int n, int m, int startCol, int startRow, int maxMoves) {
    vector<vector<int>> dirs = { {0,1},{0,-1},{1,0},{-1,0} };
    vector<vector<int>> visited(m, vector<int>(n, 0));
    visited[0][0] = 1;
    int res = 0;
    for (int i = 1; i <= maxMoves;i++) {
        vector<vector<int>> temp(m, vector<int>(n, 0));
        for (int j = 0;j < m;j++) {
            for (int k = 0;k < n;k++) {

                for (auto d : dirs) {
                    int nr = j + d[0];
                    int nc = k + d[1];

                    if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                        res += visited[j][k];
                    }
                    else {
                        temp[nr][nc] += visited[j][k];
                    }
                }

            }
        }
        visited = temp;
    }
    return res;
}
int main() {
   set<int> s;
   s.insert(10);
   s.insert(20);
   s.insert(30);
   cout<<s.size();
   return 0;
}