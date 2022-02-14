#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL 
#include "algo/debug.h"
#else
#define debug(...) 
#endif


bool isInOrder(vector<int> arr){
      for(int i=1; i<arr.size();i++){
           if(arr[i] < arr[i-1]){
                  return false;
           }
      }
      return true;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t, n;
    cin >> t;
    vector<int> arr;
    while (t--)
    {
        cin >> n;
        int num;
        while (n--)
        {
            cin >> num;
            arr.push_back(num);
        }
        if (isInOrder(arr))
            cout << "NO";
        else
            cout<< "YES";
    }
}