#include <vector>
typedef vector<int> vi;
using namespace std;

vector<int> largestRange(vector<int> array)
{

  int maxRange = 0;
  vi res(2, 0);

  unordered_map<int, bool> visited;

  for (int n : array)
  {
    visited[n] = false;
  }

  for (int n : array)
  {
    if (visited[n])
      continue;

    int countLen = 1;
    int left = n - 1;
    int right = n + 1;
    while (visited.find(left) != visited.end())
    {
      countLen++;
      visited[left] = true;
      left--;
    }

    while (visited.find(right) != visited.end())
    {
      countLen++;
      visited[right] = true;
      right++;
    }
    if (countLen > maxRange)
    {
      maxRange = countLen;
      res[0] = left + 1;
      res[1] = right - 1;
    }
  }
  return res;
}

int main()
{
  vector<int> arr = {1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6};
  vector<int> res = largestRange(arr);
  

  return 0;
}