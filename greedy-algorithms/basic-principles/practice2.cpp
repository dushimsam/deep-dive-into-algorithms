#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int main() {

    vi arr = { 6,5,12,10,9,1 };
    int minE = arr[0];
    int maxE = arr[0];

    for (int i = 1;i < arr.size();i++) {
        minE = min(arr[i], minE);
        maxE = max(arr[i], maxE);
    }
    cout << "Max el " << maxE << endl;
    cout << "Min el " << minE << endl;

    return 0;
}