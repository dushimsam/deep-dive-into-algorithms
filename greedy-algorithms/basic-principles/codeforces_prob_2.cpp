#include<bits/stdc++.h>
using namespace std;
/**
Redfine : Reorder the elements of the array such that the betwise of consecutive elements is minimum.
1. Form array equal to the number of elements.
2. [0,1,2]
re arrange
[2,0,1]
 */
vector<int> formArray(int len) {
    vector<int> result;
    for (int i = 0; i < len; i++) {
        result.push_back(i);
    }
    return result;
}
void printElements(int len) {
    vector<int> arranged = formArray(len);
    sort(arranged.begin(), arranged.end());
    vector<int> rearranged;
    int j = len - 1;



    for (int i = 0; i <= (len / 2); i++) {
        if (i == j)
            rearranged.push_back(arranged[i]);
        else {
            rearranged.push_back(arranged[j]);
            rearranged.push_back(arranged[i]);
            j--;
        }
    }

    if (len == 1 || len == 2) {
    
        for (int i = 0; i < arranged.size(); i++) {
            cout << arranged[i] << " ";
        }
    }
    else {
        for (int i = 0; i < rearranged.size(); i++) {
            cout<< rearranged[i] << " ";
        }
    }


    cout << "\n";
}

int main() {

    int t, len;
    cin >> t;
    while (t--) {
        cin >> len;
        printElements(len);
    }
    return 0;
}