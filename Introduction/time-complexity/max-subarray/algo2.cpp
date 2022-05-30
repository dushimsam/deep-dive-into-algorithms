#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int findMax(vi nums)
{
    int best = INT_MIN;
    int n = nums.size();

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum +=nums[j];
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