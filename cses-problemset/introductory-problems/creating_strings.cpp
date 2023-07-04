#include <bits/stdc++.h>
using namespace std;


void helper(set<string> &allStrs, int idx, string str){
    if(idx == str.length() - 1){
        allStrs.insert(str);
        return;
    }
    for(int i = idx; i < str.length(); i++){
        swap(str[i], str[idx]);
        helper(allStrs, idx + 1, str);
        swap(str[i], str[idx]);
    }
}

int main()
{
    string str;
    cin >> str;
    set<string> allStrs;
    helper(allStrs, 0, str);

    cout<<allStrs.size()<<endl;
    for(string str:allStrs)
     cout<<str<<endl;
    return 0;
}