#include<bits/stdc++.h>
using namespace std;
int arr[1000];

int fib(int n) {
    if (n == 1 || n == 0) return n;
    if (arr[n]) return arr[n];
    else {
        arr[n] = fib(n - 1) + fib(n - 2);
        return arr[n];
    }
}

int printN(int n) {
    cout << n << " ";
    if (n == 1) return 1;
    return printN(n - 1);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


int findSubArray(vector<int> nums) {
    int sum = 0;
    for(int i=0;i<nums.size();i++) sum += nums[i];

    for(int i=){
    
    }
}


int main() {

    cout << gcd(27, 45);

    return 0;
}