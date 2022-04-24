#include <bits/stdc++.h>
using namespace std;

/***
 *
 * Given an array of different integers . Give the subset such that the sum of it's elements is odd.
 *
 *  APPROACH:
 * 1. If there's one even element ,obviously the subset is found consist of this element.
 * 2. If there are two odd elements, same thing , the subset is found consists of these two elements.
 *
***/



int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> odds;
        int found = 0;
        

        for (int i = 0; i < n; i++) {
            int elem;
            cin >> elem;

            if (elem % 2 == 0) {
                cout << 1 << endl << (i+1) << endl;
                found = 1;
            }
            else {
                  odds.push_back(i+1);  
            }
        }

        if (!found) {

            if (odds.size() > 1) {
                cout << 2 << endl;
                cout << odds[0] << " " << odds[1] << endl;
            }
            else {
                cout << -1 << endl;
            }

        }

    }


    return 0;
}