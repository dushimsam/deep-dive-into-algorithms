#include<bits/stdc++.h>
using namespace std;
// NOTICE THAT IN THE DSU DATA STRUCTURES ELEMENTS ARE CONSIDERED AS INDEXES.
// THE VALUE AT A SPECIFIC INDEX INDICATES THE PARENT OF THAT INDEX.

class DSU {
    int* arr;

    // SIZE FOR CHANGING FROM LINEAR TIME TO log(n)
    int* size;

    int n;
public:
    DSU() {}
    DSU(int n) {
        // DON'T FORGET THE TWO LINES ::: MEANING BEFORE YOU STARING USING THE POINTER ARRAYS
        // YOU SHOULD SPECIFY THEIR SIZES
        arr = new int[n];
        size = new int[n];
        for (int i = 0;i < n;i++) {
            arr[i] = i;
            // initialy every element has size of one.
            size[i] = 1;
        }
    }


    //  THIS FUNCTION RETURNS THE INDEX (ELEMENT) WHICH REPRESENTS THE ROOT NODE OF THE SUB_SET
    int find_root(int i) {
        // the utmost root points to it's self which should terminate the recursion.
        if (i == arr[i])
            return i;
        // Path compression technique which log(n)... we are jumping to the grandparent at each iteration.
        return find_root(arr[arr[i]]);
    }

    bool are_connected(int elem1, int elem2) {
        if (find_root(elem1) == find_root(elem2))
            return true;
        return false;
    }


    // PERFORMS UNION OF THE TWO SUBSETS BASED ON THE ROOTS

    void unite(int elem1, int elem2) {
        
// cout <<"ROOT 1 "<<elem1;
// cout<<" ROOT 2 "<<elem2;
        int root_A = find_root(elem1);
        int root_B = find_root(elem2);


        // Checking size before connnecting
        if (size[root_A] < size[root_B])
        {
            arr[root_A] = arr[root_B]; // arr[root_A] = root_B (since roots pointst to themselves)
            size[root_B] += size[root_A];
        }
        else {
            arr[root_B] = arr[root_A]; // arr[root_B] = root_A (since roots pointst to themselves)
            size[root_A] += size[root_B];
        }
    }

};

int main() {
    DSU dsu(10);
    dsu.unite(4, 3);
    dsu.unite(8, 0);
    cout << "result "<<dsu.are_connected(3, 8);
    return 0;
}