#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maximumSum(vector<vector<int>> arr) {

    int sum = 0;
    int prev_max = 0;
    for (int i = arr.size() - 1;i >= 0;i--) {
        vector<int> item = arr[i];
        int max_elem = item[0];

        for (int j = 0;j < item.size();j++) {

            int  temp_max = max(item[j], max_elem);

            if (i == arr.size() - 1)
                max_elem = temp_max;
            else if (i <  (arr.size() - 1) && prev_max > temp_max) 
                max_elem = temp_max;
            
        }


         if ((i < (arr.size() - 1) && prev_max > max_elem) || ((i  == arr.size()-1)))
        {
            sum += max_elem;
            prev_max = max_elem;
        }else{
            sum =0;
        }
    }
    return sum;
}
int main() {
    vector<vector<int>> arr = { {9, 8, 7},
                   {6, 5, 4},
                   {3, 2, 1} };

    cout << maximumSum(arr);
    return 0;
}