#include <bits/stdc++.h>
using namespace std;

int minRewards(vector<int> scores)
{

    vector<int> rewards(scores.size(), 1);
    int i = 1;

    // special cases
    if (scores[0] < scores[1])
    {
        rewards[1] = 2;
    }
    if (scores[scores.size() - 1] < scores[scores.size() - 2])
    {
        rewards[scores.size() - 2] = 2;
    }

    while (i < rewards.size())
    {
        // check if it is a valley
        bool isValley = scores[i] < scores[i - 1] && scores[i] < scores[i + 1];
        if (!isValley)
        {
            i++;
            continue;
        }
        // go to the left assigning the max rewards
        int leftIdx = i - 1;
        while (leftIdx >= 0 && scores[leftIdx] > scores[leftIdx + 1])
        {
            rewards[leftIdx] = max(rewards[leftIdx], rewards[leftIdx + 1] + 1);
            leftIdx--;
        }

        // go the right assigning max rewards
        int rightIdx = i + 1;
        while (rightIdx < scores.size() && scores[rightIdx] > scores[rightIdx - 1])
        {
            rewards[rightIdx] = max(rewards[rightIdx], rewards[rightIdx - 1] + 1);
            rightIdx++;
        }
        i = rightIdx;
    }

    return accumulate(rewards.begin(), rewards.end(), 0);
}

int main()
{
    return 0;
}