#include<bits/stdc++.h>
using namespace std;

/*

QUESTION:
There are given n ropes of different lengths, we need to connect these ropes into one rope.
The cost to connect two ropes is equal to the sum of their lengths.
We need to connect the ropes with minimum cost.

                                                     REACTO
1- Repeat:
     Redefine: Find the sum of number elements by adding two at atime in ascending order and including their sum as an element too by removing the recently
added elements too.

     Specific: size:The elements are not limited to size in their total number, situation: We want to find the minimum amount required. , timing: no eany kind of timing mentioned

2- Example:

Given : { 4, 3, 2, 6 }; = 3 + 2 = 5 + 4 = 9 + 6 = 15
Result = 5 + 9 + 15 = 29


Given : { 14, 3, 2, 2,3 }; = 2 + 2 = 3 + 3 = 6+4= 10 + 14 = 24
Result = 4 + 6 + 10+24 = 44

3- Approach:
    approach 1 :
                 priority_queue.add(elements,ascending)
                 get(2 elements)
                 sum(elem1,elem2)
                 remove(elem1,elem2)
                 priority_queo.push(sum)
                 vector.push(sum)
                 return vector.sum();



4- Code


5- Test

6- Optimize

*/

class ConnectedRopes {
    priority_queue<int, vector<int>, greater<int>> rope_lengths;
public:
    ConnectedRopes();
    ConnectedRopes(vector<int> ropes_length) {
        for (int elem : ropes_length)
            this->rope_lengths.push(elem);
    }

    int minimized_cost() {
        vector<int> length_sum_up;

        while (!rope_lengths.empty()) {
            int elem1 = rope_lengths.top();
            rope_lengths.pop();
            int elem2 = rope_lengths.top();
            rope_lengths.pop();
            int sum = elem1 + elem2;

            if (!rope_lengths.empty())
                rope_lengths.push(sum);
            length_sum_up.push_back(sum);
        }

        int sum = 0;
        for (int elem : length_sum_up)
            sum += elem;
        cout << "\n\n";
        return sum;
    }


};

int main() {
    vector<int> ropes_length ={ 14, 3, 2, 2,3 };
    ConnectedRopes connectedRopes(ropes_length);
    cout << "Minimized cost: " << connectedRopes.minimized_cost();
    return 0;
}