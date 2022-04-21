#include<bits/stdc++.h>
using namespace std;



int newPosition(vector<int> arr, int l, int r, int direction) {
    int sum = 0;

    if (direction == 0) {
        while (r > l && sum < arr[l]) {
            sum += arr[r];
            if (sum == arr[l]) return r;
            r--;
        }

    }
    else {

        while (l < r && sum < arr[r]) {
            sum += arr[l];
            if (sum == arr[r]) return l;
            l++;
        }

    }

    return 0;
}

int countCandies(vector<int> arr) {
    int right = 0
        int left = len - 1;
    int maxV = 0;

    while (l < r) {
        if (arr[l] < arr[r]) {
            l = newPosition(arr, l, r, 1)
                if (l == 0) return  l + 1 + r + 1);
        }
        else if (arr[l] == arr[r]) {
            l++;
            r--;
        }
        else {
            r = newPosition(arr, l, r, 0);
            if (r == 0) return (l + 1+ r + 1);
        }
    }

}

int main() {



    return 0;
}