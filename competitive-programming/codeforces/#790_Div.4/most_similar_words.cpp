#include<bits/stdc++.h>
using namespace std;

int solve(vector<string> words, int size) {
    int res = 0;

    for (int i = 0;i < size;i++) {
        int dist = 0;
        for (int w = 0;w < words.size();w++) {
            dist += abs(dist - words[w][i]);
        }
        res += abs(dist);
    }
    return res;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        vector<string> strs;
        int words;
        int size;
        cin >> words;
        cin >> size;
        for (int w = 0;w < words;w++) {
            string curr_word;
            cin >> curr_word;
            strs.push_back(curr_word);
        }

        cout << solve(strs, size)<<endl;
    }
    return 0;
}