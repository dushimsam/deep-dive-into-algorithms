#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL 
#include "algo/debug.h"
#else
#define debug(...) 
#endif

int count_digits(int n) {
    int num = 0;
    while (n != 0)
    {
        n /= 10; 
        num++;
    }
    return num;
}

bool exists(int num, int new_num) {

    while (new_num != 0) {
        int digit = new_num % 10;
        new_num = new_num / 10;

        while (num != 0) {
            int digit2 = num % 10;
            num = num / 10;
            if (digit2 == digit) return true;
        }
    }

    return false;
}


void minimumDivisibility(int num) {
    int rem = num % 7;
    int addition = 7-rem;
     
     if (rem ==0) {
        cout << num << "\n";
    } else {
        int newnum = num - addition;
        if ((count_digits(newnum) == count_digits(num)) && exists(num, newnum)) {
            cout << newnum << "\n";
        }
        else {
            newnum = num + addition;
            cout << newnum << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, num;
    cin >> t;
    while (t--) {
        cin >> num;
        minimumDivisibility(num);
    }

    return 0;
}