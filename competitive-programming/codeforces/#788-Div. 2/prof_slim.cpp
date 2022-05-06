#include<bits/stdc++.h>
using namespace std;

int haveSameSigns(int num1, int num2) {
    return ((num1 > 0 && num2 > 0) || (num1 < 0 && num2 < 0));
}

string solve(vector<int> arr) {
    if (is_sorted(arr.begin(), arr.end())) {
        return "YES";
    }
    else {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            if (arr[left] > arr[right]) {
                if (haveSameSigns(arr[left], arr[right])) return "NO";
                else {
                    arr[left] = 0 - arr[left];
                    arr[right] = abs(arr[right]);
                    left++;
                    right--;
                }
            }
            else {
                left++;
            }
        }
    }
    if (is_sorted(arr.begin(), arr.end())) return "YES";

    return "NO";
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int curr;
            cin >> curr;
            nums.push_back(curr);
        }
        cout << solve(nums) << endl;
    }
    return 0;
}