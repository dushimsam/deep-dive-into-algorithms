#include<bits/stdc++.h>
using namespace std;

int findMaximum(priority_queue<int> numbers, int initiators) {
    int i = 1;

    int res = 0;
    while (i <= initiators && !numbers.empty()) {

        res += numbers.top();
        numbers.pop();
        i++;
    }
    return res;
}


int main() {

    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        priority_queue<int> numbers;
        set<int> pointers;
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            int currN;
            cin >> currN;
            numbers.push(currN);
        }

        for (int i = 1;i <= n;i++)
        {
            int currN;
            cin >> currN;
            if (currN != 0)
                pointers.insert(currN);
        }

        cout << "Case #" << test_case << ": ";
        cout << findMaximum(numbers, (n - pointers.size()));
        cout << endl;
    }


    return 0;
}