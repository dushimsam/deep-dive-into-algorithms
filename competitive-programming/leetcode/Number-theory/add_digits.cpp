#include<bits/stdc++.h>
using namespace std;

int digitSum(int n){
    int sum = 0;
    while(n >= 10){
        sum += (n % 10);
        n /= 10;
    }
    return sum+n;
}

int addDigits(int n){
    int res = n;
    while(res >= 10){
        res = digitSum(res);
    }
    return res;
}

int main(){
int n = 38;
cout<<addDigits(n);
    return 0;
}