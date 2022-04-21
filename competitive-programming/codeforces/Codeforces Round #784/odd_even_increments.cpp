#include<bits/stdc++.h>
using namespace std;

string handleOddEvenIncrements(vector<int> nums) {
    bool checkEven = true;
    bool isAllSame = true;
    for (int i = 0;i < nums.size();i++) {
        if (i == 0) {
            checkEven = nums[i] % 2 == 0;
        }
        else {
            if ((checkEven && nums[i] % 2 == 1) || (!checkEven && nums[i] % 2 == 0)) isAllSame = false;
        }
    }
    if (!isAllSame) {

        //check odds
        bool firsLoopChecksEven = true;
        for (int i = 0;i < nums.size();i += 2) {
            if (i == 0) {
                if (nums[i] % 2 == 0) {
                    firsLoopChecksEven = true;
                }
                else {
                    firsLoopChecksEven = false;
                }
            }
            else {
                if ((nums[i] % 2 != 0 && firsLoopChecksEven) || (nums[i] % 2 != 1 && !firsLoopChecksEven)) return "NO";
            }
        }

        for (int i = 1;i < nums.size();i += 2) {
            if ((firsLoopChecksEven && nums[i] % 2 == 0) || (!firsLoopChecksEven && nums[i] % 2 == 1)) return "NO";
        }

    }


    return "YES";
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int len;
        vector<int> nums;
        cin >> len;

        while (len--) {
            int num;
            cin >> num;
            nums.push_back(num);
        }
        cout << handleOddEvenIncrements(nums) << endl;
    }

    return 0;
}