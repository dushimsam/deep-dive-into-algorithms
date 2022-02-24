#include<bits/stdc++.h>

using namespace std;
/*
Input: V = 70
Output: 2
We need a 50 Rs note and a 20 Rs note.

Input: V = 121
Output: 3
We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.
*/

/*
            ALGORITHM
1. ADD AVAILABLE COINS IN THE PRIORITY QUEUE.
2. LOOP THROUGH THOSE COINS.
3. IF OUR CURRENT_COIN_VALUE <= TARGET
   i. Find all possible combinations possible of that coin in the given target. // (target / coin_value)
   ii. If they are ; add counted_coins, remove correponding value (counted_coins * coin_value) from the target. (target-counted_value)
4. DONE
*/
class CoinChange {
    priority_queue<int> coins;
    int target;

public:
    CoinChange();
    CoinChange(vector<int> coins, int target) {
        for (int i = 0;i < coins.size();i++)
            this->coins.push(coins[i]);
        this->target = target;
    }

    int minimizeCoins() {
        int total_coins =0;

        while(!coins.empty()) {
            if(target == 0)
              break;
             int curr_coin_value = coins.top();
             if(curr_coin_value <= target){
                 int combinations = target / curr_coin_value;
                 total_coins += combinations;
                 cout<<"\n"<<curr_coin_value<<" VALUE: "<< (combinations * curr_coin_value)<<" COMBINATIONS "<<combinations;
    
                 target -= (combinations * curr_coin_value);
                 cout<<"\n"<<" CURR TARGET VALUE "<<target;
             }
             coins.pop();
        }
      
        if(total_coins != 0)
            total_coins = -1;
            cout<<"\n\n";
        return total_coins;
    }
};

int main() {
    //requires dynammic programming procedure.
vector<int> vect = {186,419,83,408};
int target = 6249;
CoinChange coins(vect,target);
cout<<coins.minimizeCoins();
    return 0;
}