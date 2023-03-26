#include<bits/stdc++.h>
using namespace std;


int getNewStrings(string str){
   set<string> newStrings;
   int i =0;
   int j= 1;
   int count = 0;
   while(j < str.length()){
    string newStr = str.substr(i, j-i+1);
     if(newStrings.find(newStr) == newStrings.end()){
       newStrings.insert(newStr);
       count++;
     }
     i++;
     j++;
   }

   return count;
}

int main(){
   int n;
   cin >> n;
   while(n--){
    int s;
    cin >> s;
    string str;
    cin >> str;
    cout << getNewStrings(str) << endl;
   }
return 0;
}