#include <stdio.h>
#include<iostream>
using namespace std;

int main()
{
        int x = 5, y = 5, z;
        x = ++x; y = --y;
        z = x + ++x ;
        // 7 + 7 + 8 + 8 + 9 => 39

        cout << z;
        return 0;
}
