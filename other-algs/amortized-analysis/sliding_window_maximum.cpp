#include<bits/stdc++.h>
using namespace std;

/***
 *          
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

 *
 *
 *
***/
/// TIME COMPLEXITY IS VERY HIGH.
int findMaximum(queue<int> queue_elements) {
    queue<int> q = queue_elements;
    int maxElem = q.front();
    q.pop();

    while (!q.empty()) {
        maxElem = max(q.front(), maxElem);
        q.pop();
    }
    return maxElem;
}

vector<int> slidingWindow(vector<int> elements, int windowSize) {
    vector<int> results;
    queue<int> windowElements;

    for (int i = 0;i < windowSize;i++) {
        windowElements.push(elements[i]);
    }
    results.push_back(findMaximum(windowElements));

    for (int end = windowSize;end < elements.size();end++) {
        windowElements.pop();
        windowElements.push(elements[end]);
        results.push_back(findMaximum(windowElements));
    }
    return results;
}

// USING DEQUE DSA THE MOST EFFICIENT ALGORITHM
/***                             APPROACH
 * 
 * 1. DECLARE results[] , deque[] 
 * 2. for(i to n)
 *      // protecting the front bound of our sliding window
 *         if(deque.isNotEmpty AND deque.front() == i-k) deque.pop_front();
 * 
 *            //As long as the current element is greater than the back element.
 *            // remove the current back element.
 *        while(deque.IsNotEmpty() AND arr[i] > arr[deque.back()]) deque.pop_back()
 *           
 *        // Its a perfect time now to add the current element.
 *        deque.push_back(arr[i])
 *        
 *        // You should start adding results when we have atleast made k iterations
 *        if(i >= k-1 ) results.push(deque.front())
 *  
 *    return results;
 * 
 *          CONSTRAINTS
 * 1. The stack element are mantained to be decreasing order.
***/


vector<int> slidingWindowOptimized(vector<int> arr, int windowSize) {
      vector<int> results;
      deque<int> deque_elements;

     for(int i=0;i<arr.size();i++){
         // protecting the out of bounds with given windowSize.
        if(!deque_elements.empty()){
               if(deque_elements.front() == (i-windowSize)) deque_elements.pop_front();
               while(!deque_elements.empty() && arr[i] > arr[deque_elements.back()]) deque_elements.pop_back();
        }
        deque_elements.push_back(i);
        
       // Start printing after i has made "k" iterations.
       if (i>=windowSize-1) results.push_back(arr[deque_elements.front()]);
     }

     return results;
}

int main() {
    vector<int> nums = { 1,5,6,1,3 };
    int k = 2;
    vector<int> results = slidingWindowOptimized(nums, k);
    for (int i = 0;i < results.size();i++)
        cout << results[i]<<" , ";

    return 0;
}