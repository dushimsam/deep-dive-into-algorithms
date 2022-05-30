#include<bits/stdc++.h>

using namespace std;

/*
Input:
Items as (value, weight) pairs
arr[] = {{60, 10}, {100, 20}, {120, 30}}
Knapsack Capacity, W = 50;

Output:
Maximum possible value = 240
by taking items of weight 10 and 20 kg and 2/3 fraction
of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240
*/

/*
                      ALGORITHM
1. Find the (value/weight) ratio for every item and assign to each item it's corresponding ratio.
2. Sort the items by the ratio in descending order.
3. Go through the items holding in mind not to exceed the given Knapasack capacity.
4. If the knapsack capacity is reached then terminate.

NOTE:
    if the item's quantity is not capable of fitting into the remaining quantities. Take the capacity that can fit into the remaining quantities from the item and then multiply
    to the value of one quantity to get the total value.

*/

struct Item {
    char itemName;
    float value;
    float quantity;
};

bool compareItems(Item& a, Item& b) {
    return (a.value / a.quantity) > (b.value / b.quantity);
}

class FractionalKnapsack {
    vector<Item> items;
    float knapsack_quantity = 0;
public:
    FractionalKnapsack();
    FractionalKnapsack(vector<Item>& items, float max_quantity) {
        this->items = items;
        knapsack_quantity = max_quantity;
    }

    float findMaximumValue() {
        sort(items.begin(), items.end(), compareItems);

        float total_amount = 0;
        for (Item item : items) {
            // cout<<item.itemName;
            if (knapsack_quantity == 0)
                break;
            float diff = knapsack_quantity - item.quantity;

            if (diff > 0)
            {
                total_amount += item.value;
                knapsack_quantity -= item.quantity;
            }else
            {
                total_amount += (knapsack_quantity * (item.value / item.quantity));
                knapsack_quantity -= knapsack_quantity;
            }

        }

        return total_amount;
    }

};


int main() {
    // test case A
    vector<Item> vect = { {'A',60, 10}, {'B',100, 20}, {'C',120, 30} };
    float knapasack_quantity = 50;

    //test case B
    vect = { {'A',1,3}, {'B',2,2}, {'C',3,1} };
     knapasack_quantity = 4;

    FractionalKnapsack fractionalKnapsack(vect, knapasack_quantity);
    cout <<"\n"<< fractionalKnapsack.findMaximumValue();
    return 0;
}