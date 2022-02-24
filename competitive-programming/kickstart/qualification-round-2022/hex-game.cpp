#include <bits/stdc++.h>
using namespace std;

string FindBoardStatus(int size, char(*board)[100]) {


    int i = 1;
    int curr_row = 0;
    int curr_col = 0;

    int red_wins = 0;
    int blue_wins = 0;
    char first_win = 0;

    while (i <= size) {

        if (board[curr_row][0] == board[curr_row][size - 1]) {
            int c = 0;
            for (c = 0; c < size; ++c) {
                if (board[curr_row][c] != board[curr_row][0]) break;
            }
            if (c == size) {
                if (board[curr_row][0] == 'B') {
                    blue_wins++;

                    if (!first_win) first_win = 'B';
                }
                else if (board[curr_row][0] == 'R') {
                    red_wins++;

                    if (!first_win) first_win = 'R';
                }
            }

        }


        if (board[curr_col][0] == board[curr_col][size - 1]) {
            int r = 0;
            for (r = 0; r < size; ++r) {
                if (board[curr_col][r] != board[curr_col][0]) break;
            }

            if (r == size) {
                if (board[curr_col][0] == 'B') {
                    blue_wins++;

                    if (!first_win) first_win = 'B';
                }
                else if (board[curr_col][0] == 'R') {
                    red_wins++;

                    if (!first_win) first_win = 'R';
                }
            }

        }

        curr_row++;
        curr_col++;
        i++;
    }


    cout << "All blue wins \t" << blue_wins << endl;
    cout << "All red wins \t" << red_wins << endl;
    if (blue_wins > 1 || red_wins > 1 && size > 1) return "Impossible";

    if (first_win == 'B') return "Blue wins";
    else if (first_win == 'R') return "Red wins";


    return "Impossible";
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n;
        cin >> n;
        char board[100][100];
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                cin >> board[r][c];
            }
        }

        cout << "Case #" << tc << ": " << FindBoardStatus(n, board) << endl;
    }
    return 0;
}
