#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maximumArraySum(vector<int> arr, int n, int max_negations) {
  // SPECIAL CASES 
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  int sum = 0;


    int min_negative_index = -1;
    int min_positive_index = -1;

  for (int i = 1;i <= max_negations;i++) {
    int count_negatives = 0;
    int count_positives = 0;
    int min_positive = INT_MAX;
    int min_negative = INT_MAX;


    for (int j = 0;j < n;j++) {
      if (arr[j] >= 0) {
        count_positives++;
        if (min_positive > arr[j])
        {
          min_positive_index = j;
          min_positive = arr[j];
        }
      }
      else {
        count_negatives++;
        if (min_negative > arr[j])
        {
          min_negative = arr[j];
          min_negative_index = j;
        }
      }
      sum += arr[j];
    }


    if (!count_negatives)
    {
      min_positive *= -1;
      sum += min_positive;
    }
    else {
      sum += -min_negative;
      arr.erase(arr.begin() + min_negative_index);
      n -=1;
    }

  }

  for(int i=0;i<n;i++){
    if(i != min_positive_index)
       sum+= arr[i];
  }
  return sum;
}
int main() {
  vector<int> arr = { 9, 8, 8, 5 };
  cout << maximumArraySum(arr, arr.size(), 4);
  return 0;
}