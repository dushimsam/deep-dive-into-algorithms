#include<bits/stdc++.h>
using namespace std;

bool correctArr(vector<int> arr) {
    for (int i = 2;i < arr.size();i++) {
        if (arr[i] == (arr[i - 1] + arr[i - 2])) return false;
    }
    return true;
}

void printPermuations(vector<vector<int>> permutations) {
    for (int i = 0;i < permutations.size();i++) {
        for (int j = 0;j < permutations[i].size();j++) {
            cout << permutations[i][j] << " ";
        }
        cout << endl;
    }
}
void giveAntiFibonnaciPermutation(int n) {
    vector<vector<int>> permutations;
    vector<int> arr;
    for (int i = 0;i < n;i++) {
        arr.push_back(i + 1);
    }

    do {
        if (correctArr(arr)) permutations.push_back(arr);
        if (permutations.size() == n) break;
    } while (next_permutation(arr.begin(), arr.end()));

    printPermuations(permutations);
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        giveAntiFibonnaciPermutation(n);
    }
    return 0;
}