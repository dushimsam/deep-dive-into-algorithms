#include <bits/stdc++.h>
using namespace std;

#define K 100

int count_difference(string bits1, string bits2) {
	int count = 0;
	for (int i = 0;i < bits1.length();i++) {
               if(bits1[i] != bits2[i]) count++;
	}
	return count;
}

bool not_forbidden(string str, vector<string> forbidden)
{
    for (int i = 0; i < forbidden.size(); i++)
        if (forbidden[i] == str)
            return false;
    return true;
}
// Function to find all combinations k-bit numbers with
// n-bits set where 1 <= n <= k
vector<string> findBitCombinations(int k, vector<string> forbidden)
{
    vector<string> DP[K][K];
    string default_str = "";
      
    // DP[k][0] will store all k-bit numbers  
    // with 0 bits set (All bits are 0's)
    for (int len = 0; len <= k; len++) 
    {
        DP[len][0].push_back(default_str);
        default_str = default_str + "0";
    }
      
    // fill DP lookup table in bottom-up manner
    // DP[k][n] will store all k-bit numbers  
    // with n-bits set
    for (int len = 1; len <= k; len++)
    {
        for (int n = 1; n <= len; n++)
        {
            // prefix 0 to all combinations of length len-1 
            // with n ones
            for (string str : DP[len - 1][n])
                DP[len][n].push_back("0" + str);
  
            // prefix 1 to all combinations of length len-1 
            // with n-1 ones
            for (string str : DP[len - 1][n - 1])
                DP[len][n].push_back("1" + str);
        }
    }
      
        
    vector<string> availables;

    // print all k-bit binary strings with
    // n-bit set
    for (int n = 0; n <= k; n++) 
    {
       for (string str : DP[k][n])
        {
            if (not_forbidden(str, forbidden))
                availables.push_back(str);
        }
      }

    return availables;
}


int count_minimum_complains(vector<string> availables,vector<string> choices){
     int min_complaints = INT_MAX;
     for(int i = 0; i < availables.size(); i++){

         int total = 0;
         for(int j = 0; j < choices.size(); j++){
             total += count_difference(availables[i],choices[j]);
         }

         min_complaints = min(min_complaints,total);
     }

     return min_complaints;
}
int main()
{

    int n_choices, k, n_forbiddens;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {

        vector<string> choices;
        vector<string> forbiddens;
        

        cin >> n_choices >> n_forbiddens >> k;

        for (int j = 1; j <= n_choices; j++)
        {
            string choice;
            cin >> choice;
            choices.push_back(choice);
        }

        for (int j = 1; j <= n_forbiddens; j++)
        {
            string forbidden;
            cin >> forbidden;
            forbiddens.push_back(forbidden);
        }

        vector<string> availables = findBitCombinations(k,forbiddens);
        cout << "Case #" << i << ": ";
        cout<<count_minimum_complains(availables,choices)<<endl;

    }

    return 0;
}