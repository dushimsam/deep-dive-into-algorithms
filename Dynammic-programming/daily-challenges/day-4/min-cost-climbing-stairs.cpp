#include <bits/stdc++.h>
using namespace std;



int minCost(vector<int> costs)
{
    costs.push_back(0);
    vector<int> dp_arr(costs.size(), 0);
    
    // base cases

    for (int i = 0; i < dp_arr.size(); i++)
    {
        if (i <= 1)
            dp_arr[i] = 0;
        else if (i == 2)
            dp_arr[i] = min(costs[i] + costs[i - 1], costs[i] + costs[i - 2]);
        else
            dp_arr[i] = min(costs[i] + dp_arr[i - 1], costs[i] + dp_arr[i - 2]);
    }
    for (int i = 0; i < costs.size(); i++)
        cout << costs[i] << " ";
    cout << endl;
    return dp_arr[dp_arr.size() - 1];
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << minCost(cost);
    return 0;
}