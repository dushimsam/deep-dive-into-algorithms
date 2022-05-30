#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int main() {

    vi arr1 = { 2,3,4 }, arr2 = { 6,7 };

    vi par_arr(5);

    // for the arr1
    int i = 0;

    //for the arr2
    int j = 0;

    // indexing the position of the next element in the parent arr
    int k = 0;

    while (i < arr1.size() && j < arr2.size()) {

        if (arr1[i] < arr2[j]) {
            par_arr[k] = arr1[i];
            i++;
        }
        else {
            par_arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < arr1.size()) {
        par_arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < arr2.size()) {
        par_arr[k] = arr2[j];
        j++;
        k++;
    }

    for (int e : par_arr) {
        cout << e << endl;
    }
    return 0;
}