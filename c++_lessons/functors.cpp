#include <bits/stdc++.h>

using namespace std;

// Transform: is used to make an operation on each element of the array.
//transform(begin_iterator,end_iterator,result_storage,function)

// 1. OLD WAY OF IMPLEMENTATION - WHAT IF I WANT THE INCREMENT TO TAKE A PARAMETER ???

// int increment(int x){ return x+5; }
// int main(){
//     int arr[]={3,4,5,6,6,7};
//     // increment each element of this array
//     int n = sizeof(arr)/sizeof(arr[0]);
//     transform(arr,arr+n,arr,increment);

//      for (int i=0; i<n; i++)
//         cout << arr[i] << " ";

//     return 0;
// }

// 2. NEW WAY OF IMPLEMENTATION - WHAT IF I WANT THE INCREMENT TO TAKE A PARAMETER ???

class increment
{
    int num;

public:
    //SAVING THE STATE OF "n" as the value of arr at atime.
    increment(int n) : num(n) {}

    // OPERATOR OVERLOADING
    int operator()(int addition) const
    {
        return num + addition;
    }
};

int main()
{
    int arr[] = {3, 4, 5, 6, 6, 7};
    // increment each element of this array
    int n = sizeof(arr) / sizeof(arr[0]);
    transform(arr, arr + n, arr, increment(2));

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}