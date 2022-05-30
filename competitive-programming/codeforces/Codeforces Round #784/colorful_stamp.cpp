#include<bits/stdc++.h>
using namespace std;


int count_minimum_edit_distance(string a, string b) {

    int dp_matrix[a.length() + 1][b.length() + 1];

    for (int i = 0;i <= a.length();i++) {
        dp_matrix[i][0] = i;
    }

    for (int j = 1;j <= b.length();j++) {
        dp_matrix[0][j] = j;
    }


    for (int i = 1;i <= a.length();i++) {

        for (int j = 1;j <= b.length();j++) {
            int diag = dp_matrix[i - 1][j - 1];
            int top = dp_matrix[i - 1][j];
            int left = dp_matrix[i][j - 1];

            if (a[i - 1] == b[j - 1]) dp_matrix[i][j] = diag;
            else dp_matrix[i][j] = min(top, min(left, diag))+1;
        }
    }

    return dp_matrix[a.length()][b.length()];
}

int main(){
int n;
cin >> n;

while(n--){
   int len;
   cin >> len;
   string str;
   while(len--){
     char ch;
     cin >> ch;
     str.push_back(ch);
   }
   if()
}
    return 0;
}