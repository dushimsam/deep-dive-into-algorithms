#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

bool isPalindrome(string str)
{
  int left = 0;
  int right = str.length() - 1;
  while (left <= right)
  {
    if (str[left] != str[right])
      return false;
    left++;
    right--;
  }
  return true;
}
int palindromePartitioningMinCuts(string str)
{
  // Write your code here.
  vi minCuts(str.length(), 0);
  for (int i = str.length() - 2; i >= 0; i--)
  {
    for (int j = str.length() - 1; j >= i; j--)
    {
      string prefix = str.substr(i, j + 1 - i);
      if (isPalindrome(prefix))
      {
        cout << " Prefix "<< prefix << endl;
        minCuts[i] = j == str.length() - 1 ? 0 : minCuts[j + 1] + 1;
      }
    }
  }

  // for(int n:minCuts) cout << n << endl;
  return minCuts[0];
}

int main()
{

  string str = "noonabbad";
  int res = palindromePartitioningMinCuts(str);
  // cout <<  << endl;
  return 0;
}