#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>  numbers, int target) {

    int leftPointer = 0;
    int rightPointer = numbers.size() - 1;

    while (leftPointer < rightPointer) {
        int sum = numbers[leftPointer] + numbers[rightPointer];

        if (sum < target) {
            leftPointer++;
        }
        else if (sum > target) {
            rightPointer--;
        }
        else {
            return{ numbers[leftPointer], numbers[rightPointer] };
        }
    }

    return {};
}
int main() {
    stack<int> nums;
    nums.push(3);
    nums.push(4);
    nums.push(1);
    cout<<nums.top()<<endl;
    cout<<nums.pop()<<endl;
    cout<<nums.top()<<endl;
    return 0;
}
