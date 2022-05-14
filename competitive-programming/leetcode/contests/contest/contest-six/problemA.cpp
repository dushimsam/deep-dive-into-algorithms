#include<bits/stdc++.h>
using namespace std;

vector<string> extractSubsets(int num, int k) {
    vector<string> subsets;
    string numStr = (string)num;

    for (int i = 0;i < numStr.length();i++) {
        string curr;
        for (int j = i;j < (i + k);j++) {
            curr.push_back(numStr[j]);
        }
        subsets.push_back(curr);
    }

    return subsets;
}


int getKBeatuyNum(int num, int k) {
    vector<string> subs = extractSubsets(num, k);

}
int main() {




}