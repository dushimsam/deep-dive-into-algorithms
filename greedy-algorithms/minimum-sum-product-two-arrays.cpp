#include<bits/stdc++.h>
using namespace std;

int minimumProductTwoArrays(vector<int> arr1, vector<int> arr2, int k) {
    int pair_min_index = 0;
    int operations = k * 2;
    int min_result = INT_MAX;
    for (int i = 0;i < arr1.size();i++) {
        if (arr1[i] >= 0 && arr2[i] >= 0) {
            int result = (arr1[i] - operations) * arr2[i];
        
            if (min_result > result)
            {
                min_result = result;
                pair_min_index = i;
            }
        }
        else {
            int result = (arr1[i] + operations) * arr2[i];
            if (min_result > result)
            {
                min_result = result;
                pair_min_index = i;
            }
        }
    }

    int sum = 0;
    for (int i = 0;i < arr1.size();i++) {

        if (i == pair_min_index) {
            sum += min_result;
        }else {
            sum += (arr1[i] * arr2[i]);
        }
    }

    return sum;
}

int main() {
    vector<int> a = {2, 3, 4, 5, 4};
    vector<int> b = {3, 4, 2, 3, 2};

    int  k = 5;
    cout << minimumProductTwoArrays(a,b,k);
    return 0;
}