#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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







int main() {
    cout << ('o' - 'e');
    return 0;
}