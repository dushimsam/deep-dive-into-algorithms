#include <bits/stdc++.h>

using namespace std;

bool isOutOfBounds(int width, int height, int row, int col)
{
    return row < 0 || col < 0 || row > height || col > width;
}
vector<int> zigzagTraverse(vector<vector<int>> array)
{

    int width = array[0].size() - 1;
    int height = array.size() - 1;
    int row = 0;
    int col = 0;
    bool goingDown = true;
    vector<int> res;
    while (!isOutOfBounds(width, height, row, col))
    {
        res.push_back(array[row][col]);
        if (goingDown)
        {
            if (col == 0 || row == height)
            {
                goingDown = false;
                if (row == height)
                {
                    col++;
                }
                else
                {
                    row++;
                }
            }
            else
            {
                col--;
                row++;
            }
        }
        else
        {
            if (row == 0 || col == width)
            {
                goingDown = true;
                if (col == width)
                {
                    row++;
                }
                else
                {
                    col++;
                }
            }
            else
            {
                row--;
                col++;
            }
        }
    }

    return res;
}

int main()
{

    return 0;
}