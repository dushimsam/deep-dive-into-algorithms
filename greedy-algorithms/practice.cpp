#include <iostream>
#include <vector>
using namespace std;

int count(int S[], int n, int target)
{
    int T[n + 1][target + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (i == 0) {
                T[0][j] = 0;
            }
            else if (j == 0) {
                T[i][0] = 1;
            }
            else if (S[i - 1] > j) {
                T[i][j] = T[i - 1][j];
            }
            else {
                T[i][j] = T[i - 1][j] + T[i][j - S[i - 1]];
            }
        }
    }

    return T[n][target];
}
// Coin Change Problem
int main()
{
    // `n` coins of given denominations
    int S[] = { 186,419,83,408 };
    int n = sizeof(S) / sizeof(S[0]);
    // total change required
    int target = 6249;

    cout << "The total number of ways to get the desired change is "
        << count(S, n, target);

    return 0;
}
