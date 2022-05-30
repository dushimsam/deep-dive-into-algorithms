#include<bits/stdc++.h>

using namespace std;

int detectSpy(vector<int> arr) {
    int spy1 = 0;
    int count_spy1 = 1;
    int spy2;

    for (int i = 1;i < arr.size();i++) {
        if (arr[spy1] == arr[i]) count_spy1++;
        else spy2 = i;
    }

    if (count_spy1 == 1) return spy1+1; else return spy2+1;
}
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        while (n--) {
            int elem;
            cin >> elem;
            arr.push_back(elem);
        }
        cout << detectSpy(arr)<<endl;

    }
    return 0;
}