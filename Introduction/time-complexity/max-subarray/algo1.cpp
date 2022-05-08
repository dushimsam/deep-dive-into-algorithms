#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int findMax(vi nums)
{
    int n = nums.size();
    int best = INT_MIN;

    for (int i = 0; i < n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += nums[k];
            }
            best = max(best,sum);
        }
    }

    return best;
}

int main()
{
vi nums = {-1,2,4,-3,5,2,-5,2};
cout<<findMax(nums);
    return 0;
}