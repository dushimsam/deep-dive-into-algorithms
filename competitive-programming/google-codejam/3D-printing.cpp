
#include <bits/stdc++.h>
using namespace std;


void findFourElements(vector<int> arr, int n, int X)
{

    unordered_map<int, pair<int, int> > mp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            mp[arr[i] + arr[j]] = { i, j };

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (mp.find(X - sum) != mp.end()) {
                pair<int, int> p = mp[X - sum];
                if (p.first != i && p.first != j
                    && p.second != i && p.second != j) {
                    cout << arr[i] << ", " << arr[j] << ", "
                        << arr[p.first] << ", "
                        << arr[p.second];
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}

// Driver code
int main()
{

    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX, min5 = INT_MAX;

        for (int i = 1;i <= 3;i++)
        {
            for (int j = 1;j <= 4;j++) {
                int currN;
                cin >> currN;
                if (j == 1) min1 = min(min1, currN);
                else if (j == 2) min2 = min(min2, currN);
                else if (j == 3) min3 = min(min3, currN);
                else if (j == 4) min4 = min(min4, currN);
            }
        }

        vector<int> arr;

        for (int j = 0;j <= min1;j++) {
            arr.push_back(j);
        }

        for (int j = 1;j <= min2;j++) {
            arr.push_back(j);
        }

        for (int j = 1;j <= min3;j++) {
            arr.push_back(j);
        }

        for (int j = 1;j <= min4;j++) {
            arr.push_back(j);
        }


        cout << "Case #" << test_case << ": ";
        int X = 1000000;
        for(int num:arr){
            cout<<num<<endl;
        }
        findFourElements(arr, arr.size(), X);
        cout << endl;
    }


    return 0;
}
