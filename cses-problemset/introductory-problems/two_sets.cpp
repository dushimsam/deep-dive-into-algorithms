#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << "NO\n";
        return 0;
    }

    vector<long long> arr1, arr2;

    if (n % 4 == 3)
    {
        for (long long i = 2; i <= (n / 2); i += 2)
        {
            arr1.push_back(i);
            arr1.push_back(n - i);
        }
        arr1.push_back(n);
        for (long long i = 1; i <= (n / 2)+1; i += 2)
        {
            arr2.push_back(i);
            arr2.push_back(n - i);
        }
    }
    else
    {
        for (long long i = 2; i <= (n / 2); i += 2)
        {
            arr1.push_back(i);
            arr1.push_back(n - i + 1);
            arr2.push_back(i - 1);
            arr2.push_back(n - i + 2);
        }
    }

    cout <<"YES"<<endl;
    cout << arr1.size() << endl;
    for (int e : arr1)
        cout << e << " ";

    cout << endl;
    cout << arr2.size() << endl;
    for (int e : arr2)
        cout << e << " ";
    return 0;
}