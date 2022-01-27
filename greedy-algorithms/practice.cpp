#include <iostream>
#include <queue>
using namespace std;
 typedef pair<int, pair<int,int>> P;


// Function to print the data of
// the priority queue ordered by first
void showpq(
     priority_queue<P,vector<P>,greater<P>> g)
{
    // Loop to print the elements
    // until the priority queue
    // is not empty
    while (!g.empty()) {
        cout << g.top().first
             << " " << g.top().second.second
             << endl;
        g.pop();
    }
    cout << endl;
}
  


// Driver Code
int main()
{
    priority_queue<P,vector<P>,greater<P>> p1;
  
    p1.push(make_pair(4, make_pair(5,6)));
    p1.push(make_pair(5, make_pair(1,4)));
    p1.push(make_pair(1, make_pair(9,0)));
    p1.push(make_pair(7, make_pair(3,7)));
    p1.push(make_pair(9, make_pair(2,3)));
    showpq(p1);
    return 0;
}