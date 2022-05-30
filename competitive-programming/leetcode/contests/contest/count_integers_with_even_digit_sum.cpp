#include<bits/stdc++.h>

using namespace std;


int count_digits(int maximum) {
    int count_digits = 0;
    int curr_seq = 1;
    int i = 1;
    int count_nums = 1;

    while (i <= maximum) {

        string str = to_string(i);
        int count_sum = 0;
        for (int j = 0; j < str.length(); j++) {
            count_sum += str[j];
        }

        if (count_sum % 2 == 0) count_digits++;

        i++;

    }

    return count_digits;

}
int main() {
    int num = 30;
    cout << endl << endl;
    cout << count_digits(num) << endl;

    return 0;
}