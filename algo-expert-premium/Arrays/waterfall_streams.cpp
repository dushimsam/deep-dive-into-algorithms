#include <bits/stdc++.h>
typedef vector<vector<int>> vi;
using namespace std;

vector<double> waterfallStreams(vector<vector<double>> array, int source)
{
    array[0][source] = -1;
    for (int i = 1; i < array.size(); i++)
    {
        for (int j = 0; j < array[0].size(); j++)
        {
            if (array[i - 1][j] != 1 && array[i - 1][j] != 0)
            {
                if (array[i][j] != 1)
                {
                    array[i][j] += array[i - 1][j];
                }
                else
                {
                    int left = j - 1;
                    int currParc = array[i][j];
                    while (left >= 0)
                    {
                        if (array[i][left] != 1 && array[i - 1][left] != 1)
                        {
                            array[i][left] += (currParc/2);
                            break;
                        }

                        left--;
                    }

                    int right = j+1;

                    while(right < array[0].size()){
                          if (array[i][right] != 1 && array[i - 1][right] != 1)
                        {
                            array[i][right] += (currParc/2);
                            j = right;
                            break;
                        }

                        right++;
                    }
                }
            }
        }
    }

    vector<double> finalPercentages;

    for(int i = 0; i < array[0].size();i++){
        finalPercentages.push_back(array[array.size()-1][i] * -100);
    }
    return finalPercentages;
}

int main()
{

    return 0;
}