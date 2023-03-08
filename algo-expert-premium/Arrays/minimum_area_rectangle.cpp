#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vii;

string convertToString(int x, int y)
{
    return to_string(x) + ":" + to_string(y);
}

set<string> createSetPoints(vii points)
{
    set<string> setPoints;
    for (vector<int> point : points)
    {
        setPoints.insert(convertToString(point[0], point[1]));
    }

    return setPoints;
}

int minimumAreaRectangle(vector<vector<int>> points)
{
    // createSetPoints
    set<string> setPoints = createSetPoints(points);
    // createMinVariable
    int minArea = INT_MAX;
    // Go through all the points
    for (int i = 1; i < points.size(); i++)
    {
        // Exatract x and y from the current point
        int point1x = points[i][0];
        int point1y = points[i][1];

        // Go through all the points below the current point
        for (int j = i - 1; j >= 0; j--)
        {
            // Extract x and y from the point2
            int point2x = points[j][0];
            int point2y = points[j][1];
            // check if any of the dot is shared, otherwise you would yield the same point in the next step of finding diagonal
            if (point1x == point2x || point1y == point2y)
                continue;
            // Find if point1 in diagonal exists
            bool point1Exists = setPoints.find(convertToString(point1x, point2y)) != setPoints.end();
            bool point2Exists = setPoints.find(convertToString(point2x, point1y)) != setPoints.end();
            if (point1Exists && point2Exists)
            {
                int area = abs(point2x - point1x) * abs(point2y - point1y);
                minArea = min(area, minArea);
            }
        }
    }

    return minArea == INT_MAX ? 0 : minArea;
}

int main()
{
    vii points = {
        {1, 5},
        {5, 1},
        {4, 2},
        {2, 4},
        {2, 2},
        {1, 2},
        {4, 5},
        {2, 5},
        {-1, -2}};

    // Expected result : 3
    cout << minimumAreaRectangle(points) << endl;
    return 0;
}