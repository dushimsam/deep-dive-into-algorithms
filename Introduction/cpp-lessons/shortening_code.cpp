#include <bits/stdc++.h>
using namespace std;

// type names
typedef long long ll;
typedef vector<int> vi;

// macros
#define PB push_back
#define MP make_pair

int main()
{

    ll a = 12;
    ll b = 10;
    cout << a * b << "\n";

    vi v;
    v.PB(2);
    v.PB(3);
     for(int i : v){
         cout << i<<"\n";
     }
    return 0;
}