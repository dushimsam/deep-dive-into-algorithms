#include <bits/stdc++.h>
using namespace std;

string findLCSubstring(string s1,string s2){
        int rows = s1.length()+1;
        int cols = s2.length()+1;
        
        vector<vector<int>> dp_matrix(rows,vector<int>(cols,0));
        int maxLen = 0;
        int maxIndexRow = 0;
        int maxIndexCol = 0;
        string subString;
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(s1[i-1] == s2[j-1]){
                    dp_matrix[i][j] = 1 + dp_matrix[i-1][j-1];
                    if(maxLen < dp_matrix[i][j]){
                       maxLen = dp_matrix[i][j];
                       maxIndexRow = i;
                       maxIndexCol = j;
                    }
                }else{
                    dp_matrix[i][j] = 0;
                }
            }
        }
        
        int i = maxIndexRow;
        int j = maxIndexCol;

        while(dp_matrix[i][j] != 0){
            subString.push_back(s1[i-1]);
            i--;
            j--;
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++) cout<<dp_matrix[i][j]<<" ";
            cout<<"\n";
        }
              cout<<"\n\n\n";
        reverse(subString.begin(),subString.end());
        return subString;
    }

int main(){
string s ="aacabdkacaa";

string a1 = s;
reverse(s.begin(),s.end());
string a2 =s;
cout<<a2;
cout<<findLCSubstring(a1,a2);
    return 0;
}