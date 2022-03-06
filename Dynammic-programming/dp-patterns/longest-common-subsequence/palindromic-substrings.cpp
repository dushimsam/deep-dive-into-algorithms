#include <bits/stdc++.h>
using namespace std;

int palindromicStrings(string s, string reversed_s)
{
    int rows = s.length() + 1;
    int cols = reversed_s.length() + 1;

    vector<vector<int>> dp_matrix(rows, vector<int>(cols, 0));
    int possible_substrings = 0;

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (s[i - 1] == reversed_s[j - 1])
            {
                int prev = dp_matrix[i - 1][j - 1];
                int newV = prev+1;
 
                if (prev != 0)
                {
                    possible_substrings -= (pow(2 ,prev) - 1);
                    cout<<"Substracted "<<(pow(2 ,prev) - 1)<<" "<<possible_substrings<<endl;
                }

                possible_substrings += (pow(2 , newV) - 1);
                dp_matrix[i][j] = newV;
                cout<<" New value "<<newV<<endl<<endl;
                cout<<"For "<<i<<" and "<<j<<" is "<<possible_substrings;
                cout<<"\n";
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<dp_matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n\n";
    return possible_substrings;
}

int main()
{

    string s = "abc";
    string originalStr = s;
    reverse(s.begin(), s.end());
    string reverseStr = s;

    cout << palindromicStrings(originalStr, reverseStr);

    return 0;
}