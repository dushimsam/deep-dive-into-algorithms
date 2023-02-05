#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/***   QUESTION: Given two arrays , determine whether the second array is a subsequence of the first one.
 * 
***/

bool isValidSubsequence(vector<int> array,vector<int> sequence){
    int currE = 0;
  
    for(int i = 0; i < array.size() && currE < sequence.size();i++){
        if(array[i] == sequence[currE]){
            currE++;
        }
    }
    return currE == sequence.size();
}

int main(){

vector<int> arr = {5, 1, 22, 25, 6, -1, 8, 10};
vector<int> sequence = {1, 6, -1, 10};

cout << isValidSubsequence(arr,sequence) << endl;

return 0;
}