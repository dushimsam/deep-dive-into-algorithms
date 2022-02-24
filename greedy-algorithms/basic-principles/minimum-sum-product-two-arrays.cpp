#include<bits/stdc++.h>
using namespace std;


//NOT COMPLETED
int minimumProductTwoArrays(vector<int> arr1, vector<int> arr2, int k) {
    int pair_min_index = 0;
    int operations = k * 2;
    int min_result = INT_MAX;
    int min_product = 0;

    for (int i = 0;i < arr1.size();i++) {
        int curr_product = arr1[i] * arr2[i];

        if (arr1[i] >= 0 && arr2[i] >= 0 && curr_product > min_product) {
            int result = (arr1[i] - operations) * arr2[i];
        
            if (min_result >= result)
            {
                min_result = result;
                pair_min_index = i;
                min_product = curr_product;
            }
        }
        else {
            int result = (arr1[i] + operations) * arr2[i];
            if (min_result >= result)
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

    //O(logn)

    return sum;
}

int main() {

    vector<int> a =  {2, 3, 4, 5, 4};
    vector<int> b = {3, 4, 2, 3, 2};

    int  k = 3;
    cout << minimumProductTwoArrays(a,b,k);
    return 0;
}