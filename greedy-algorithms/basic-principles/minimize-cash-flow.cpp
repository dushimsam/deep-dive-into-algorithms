#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/**
                           ALGORITHM
1. Settle the net amount for each person. = (amount_received - amount_sent)
2. Get the most_credited_amount:amount.getMax() , and the most_debited_amount: amount.getMin()
3. Find the minimum of the two.
4. Deduct to the creditor that min amount , and add to the debtor the same amount.
5. Repeat 2,3,4 until the most_debited_amount and most_debited_amount = 0;
  **/


class CashFlow {
    vector<int> amount;
public:
    CashFlow();
    CashFlow(vector<vector<int>> cashflows, int persons) {

        for (int i = 0; i < persons; i++) amount.push_back(0);

        for (int i = 0; i < persons;i++) {
            for (int j = 0; j < persons;j++) {
                // Take the amount in which that person should pay and deduct that which you should pay him as well.
                int net_amount = cashflows[j][i] - cashflows[i][j];
                amount[i] += net_amount;
            }
        }

        minimizeCashFlow(amount);

        for (int i : amount) cout << "Amount " << i << endl;


    }


    int getIndexOfMax() {
        int max = 0;
        for (int i = 0;i < amount.size();i++) {
            if (amount[i] > max) {
                max = i;
            }
        }

        return max;
    }


    int getIndexOfMin() {
        int min = 0;
        for (int i = 0;i < amount.size();i++) {
            if (amount[i] < min) {
                min = i;
            }
        }

        return min;
    }


    void minimizeCashFlow(vector<int> amount) {

        int credMax = *max_element(amount.begin(), amount.end());
        int debtMax = *min_element(amount.begin(), amount.end());

        cout << "Max Cred " << credMax << endl;
        cout << "Min Debt " << debtMax << endl;
        if (credMax == 0 && debtMax == 0) return;

        int minOfTwo = min(-debtMax, credMax);

        int indexMaxCred = getIndexOfMax();
        int indexMaxDebt = getIndexOfMin();

        amount[indexMaxDebt] += minOfTwo;
        amount[indexMaxCred] -= minOfTwo;

        cout << "Min Of Two " << minOfTwo << endl;


        // minimizeCashFlow(amount);
    }

};


int main() {

    // graph[i][j] indicates the amount that person i needs to
       // pay person j
    vector<vector<int>> cashflows = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0} };
    int persons = 3;

    CashFlow cashFlow(cashflows, persons);
    return 0;
}