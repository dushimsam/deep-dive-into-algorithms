#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/***
 * Question: Throught the series of games return the winner of the competition.
 * url: https://www.algoexpert.io/questions/tournament-winner
 ***/

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results)
{
    map<string, int> points;

    for (int i = 0; i < competitions.size(); i++)
    {
        points.insert(pair<string, int>(competitions[i][0], 0));
        points.insert(pair<string, int>(competitions[i][1], 0));
    }

    string max_winner = competitions[0][0];
    int max_points = 0;

    for (int i = 0; i < competitions.size(); i++)
    {

        string winner = results[i] == 0 ? competitions[i][1] : competitions[i][0];
        points[winner] += 3;

        if (points[winner] > max_points)
        {
            max_points = points[winner];
            max_winner = winner;
        }
    }
    return max_winner;
}

int main()
{
    vector<vector<string>> competitions = {
        {"HTML", "C#"},
        {"C#", "Python"},
        {"Python", "HTML"}};

    vector<int> results = {0, 0, 1};

    cout << "Winner is " << tournamentWinner(competitions, results);
    return 0;
}