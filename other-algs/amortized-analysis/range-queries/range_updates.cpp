#include <bits/stdc++.h>
using namespace std;

/***
 *
 *   QUESTION
 *  Raise the marks of the students between [a,b] range by a constant "c"
 *  // Write the A datastructure that 's going to help you achieve this in the minimal time complexity
 *  as possible.
 *
 *              APPROACH
 * 1. Create a differences based array from the original array. diff[]
 * 2. let diff[a] = diff[a] + c , diff[b+1] = diff[b+1] - c
 * 3. To retrieve the element at aparticular index i in the original array
 *     elem = 0;
 *     for(let j= 0 until j = i)  elem += diff[j]
 * ***/

int retrieveElem(vector<int> diff, int i)
{
    int elem = 0;
    for (int j = 0; j <= i; j++)
        elem += diff[j];

    return elem;
}

void computerDiffs(vector<int> original_arr, vector<int> diff)
{
    diff[0] = original_arr[0];
    for (int i = 1; i < original_arr.size(); i++)
    {
        diff[i] = original_arr[i] - original_arr[i-1];
    }
}

void performUpdates(vector<int> &diff, int a, int b, int c)
{
    diff[a] += a; 
    diff[b+1] -= a;
}
int main()
{
   
    vector<int> original_arr = {3,3, 1 ,1, 1, 5, 2, 2};
     vector<int> diff;  
    computerDiffs(original_arr,diff);

    int a = 1;
    int b = 4;
    int c = 5;
    // performUpdates(diff,a,b,c);

    cout<<retrieveElem(diff,6);
    return 0;
}