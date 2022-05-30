#include <bits/stdc++.h>
using namespace std;

/***
setting a particular bit formula: bitMaskedNumber = 1 << (kth_bit - 1)

if(GivenNumber && bitMaskedNumber)
   bit is SET
else bit is NOT SET
***/

bool checkIsBitSet(int n, int k_th_bit)
{
    int setBit = 1 << (k_th_bit - 1);
    if (n & setBit)
        return true;
    else
        return false;
}

int main()
{
    cout << checkIsBitSet(21, 3);

    return 0;
}