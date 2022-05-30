#include<bits/stdc++.h>
using namespace std;

void buildFirstRows(int cols) {
    char currentChar = '+';
    for (int i = 1;i <= 2;i++) {
        for (int j = 1;j <= ((cols * 2) + 1);j++) {
            if (j <= 2) {
                cout << ".";
            }
            else {
                if (i == 1) {

                    if (j % 2 != 0)
                        cout << "+";
                    else cout << "-";
                }
                else {
                    if (j % 2 != 0)
                        cout << "|";
                    else cout << ".";
                }
            }
        }
        cout << endl;
    }
}
void build_card(int r, int c) {

    char currentChar = '+';
    buildFirstRows(c);

    for (int i = 1;i <= (r * 2 - 2 + 1);i++) {

        for (int j = 1;j <= ((c * 2) + 1);j++) {
            if (i % 2 != 0) {
                if (j % 2 != 0) cout << "+";
                else cout << "-";
            }
            else {
                if (j % 2 != 0) cout << "|";
                else cout << ".";
            }
        }
        cout << endl;
    }
}

int main() {

    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        int r, c;
        cin >> r >> c;

        cout << "Case #" << test_case << ": ";
        cout<<endl;
        build_card(r, c);
    }
    return 0;
}