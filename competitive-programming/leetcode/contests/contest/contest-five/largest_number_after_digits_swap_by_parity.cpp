#include<bits/stdc++.h>
using namespace std;


vector<int> convertIntoInts(int n) {
    vector<int> vec_nums;
    int r;

    while (n > 0) {
        r = n % 10;
        int digit = n % 10;
        n = n / 10;
        vec_nums.push_back(digit);
    }
    return vec_nums;
}


int giveLargest(bool isEven, vector<int> vec_nums, int i) {
    int maxElem = vec_nums[i];
    int maxIndex = i;

    for (int j = i + 1;j < vec_nums.size();j++) {


        if (isEven == 0 && vec_nums[j] % 2 == 0) {

            if (maxElem < vec_nums[j]) {
                maxElem = vec_nums[j];
                maxIndex = j;
            }
        }
        else if (isEven == 1 && vec_nums[j] % 2 == 1) {


            if (maxElem < vec_nums[j]) {
                maxElem = vec_nums[j];
                maxIndex = j;
            }
        }
    }

    return maxIndex;
}


int largestNumber(int num) {
    vector<int> vec_nums = convertIntoInts(num);
    reverse(vec_nums.begin(),vec_nums.end()); 

    for (int i = 0;i < vec_nums.size();i++) {

        int swapIndex = giveLargest(vec_nums[i] % 2 == 0, vec_nums, i);
     
        if (swapIndex != i) {
            int temp = vec_nums[i];
            vec_nums[i] = vec_nums[swapIndex];
            vec_nums[swapIndex] = temp;
        }
    }

    string result;
    for (int i = 0;i < vec_nums.size();i++) {
        char elem = (char)vec_nums[i];
        result.push_back(elem);
    }
    return stoi(result);
}




int main() {


    int num = 1234;
    cout << largestNumber(1234);

    return 0;
}