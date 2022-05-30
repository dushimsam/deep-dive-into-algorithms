#include<bits/stdc++.h>
using namespace std;


int findLongestLine(vector<int> numbers) {
    int counts = 0;
    sort(numbers.begin(), numbers.end());
    for (int i = 0;i < numbers.size();i++) {
        if (numbers[i] > counts) counts++;
    }
    return counts;
}

int main() {

    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        vector<int> numbers;
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            int currN;
            cin >> currN;
            numbers.push_back(currN);
        }
        cout << "Case #" << test_case << ": ";
        cout << findLongestLine(numbers);
        cout << endl;
    }


    return 0;
}