#include<bits/stdc++.h>
using namespace std;
const int N = 7;
string S;
bool visited[N+1][N+1];
long long ans = 0;


bool inbound(int x, int y){
    return (x >= 1 && x <= N) && (y >= 1 && y <= N);
}

void dfs(int x, int y, int i){
    if((i == N * N - 1)|| (x == N && y == 1)){
        ans += (i == N * N - 1) && (x == N && y == 1);
        return;
    }
    // special cases
    if((!inbound(x + 1, y) || visited[x + 1][y]) && (!inbound(x - 1, y) || visited[x - 1][y])){
        if(inbound(x, y + 1) && !visited[x][y + 1] && inbound(x, y - 1) && !visited[x][y - 1])
          return;
    }

    if((!inbound(x, y + 1) || visited[x][y + 1]) && (!inbound(x, y - 1) || visited[x][y - 1])){
        if(inbound(x + 1, y) && !visited[x + 1][y] && inbound(x - 1, y) && !visited[x - 1][y])
         return;
    }

    visited[x][y] = true;
    // real work through
    if(S[i] == 'D' || S[i] == '?'){
        if(inbound(x + 1, y) && !visited[x + 1][y])
          dfs(x + 1, y, i + 1);
    }

    if(S[i] == 'U' || S[i] == '?'){
        if(inbound(x - 1, y) && !visited[x - 1][y])
         dfs(x - 1, y, i + 1);
    }

    if(S[i] == 'R' || S[i] == '?'){
        if(inbound(x, y + 1) && !visited[x][y + 1])
         dfs(x, y + 1, i + 1);
    }

    if(S[i] == 'L' || S[i] == '?'){
        if(inbound(x, y -1) && !visited[x][y - 1])
         dfs(x, y - 1, i + 1);
    }

    visited[x][y] = false;
}

int main(){
    cin >> S;
    dfs(1, 1, 0);
    cout << ans <<"\n";
    return 0;
}