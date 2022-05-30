
#include<bits/stdc++.h>
using namespace std;

/*
Redefine:
           redefined:Assign jobs to the workers such that the total time for completing the job assigned to each worker is minimized.

           translation: -Group the elements in the given k number groups such that the maximum sum from each group is minimized.
           - Group the elements so that the sum of each group is balanced.

Examples:

Input:  k = 2, T = 5, job[] = {4, 5, 10}
Output: 50
The minimum time required to finish all the jobs is 50.
There are 2 assignees available. We get this time by
assigning {4, 5} to first assignee and {10} to second
assignee.

Input:  k = 4, T = 5, job[] = {10, 7, 8, 12, 6, 8}
Output: 75
We get this time by assigning {10} {7, 8} {12} and {6, 8}

Approach:
1. sums[k](priority queue... smallest first) , vector elements[n]
2. sort(elements,ascending)
3. for(i=n until k) i--
      sums[i] = elements[i];
      elements.remove(elements[i]);
4.
   while(arr != NULL){
    // choose the smallest element from the sums
    let elem_index = sums.smallest()
    let smallest_chosen;
    let smallest_diff = INT_MAX;

    for(i through arr )
       chosen = arr[i];
       new_sum = chosen + sums[elem_index];
       let total_diff=0;

       for(i throught sums)
           diff += abs(new_sum - sums[i])

       if(smallest_diff > total_diff)
         {
            smallest_diff = total_diff;
            smallest_chosen = i;
         }
    }
    sums[elem_index] += arr[smallest_chosen];
    elements.remove(smallest_chosen);
   }

*/


class MinimumTime {
    vector<int> sums;
    vector<int> elements;

public:
    MinimumTime(vector<int> elements, int k) {
        this->elements = elements;

        sort(elements.begin(), elements.end());
        int t = elements.size() - 1;

        for (int i = 0; i < k;i++) {
            sums.push_back(elements[t]);
            t--;
        }

         for(int i = elements.size() - 1; i >= (elements.size() - k); i--) {
            elements.erase(elements.begin(), elements.begin() + i);
        }

    }


    int minIndex() {
        int smallest_sum_index = 0;

        for (int i = i; i < sums.size();i++) {
            if (sums[smallest_sum_index] > sums[i]) {
                smallest_sum_index = i;
            }
        }

        return smallest_sum_index;
    }

    int findMinimumTime() {
       
       for(int i = 0; i < elements.size();i++)
          cout<<endl<<elements[i] << "\n";

        // while (elements.size() != 0) {
        //     int smallest_sum_index = minIndex();
        //     int smallest_chosen_elem_index = 0;
        //     int smallest_diff = INT_MAX;

        //     for (int i = 0;i < elements.size();i++) {
        //         int new_sum = elements[i] + sums[smallest_sum_index];

        //         int total_diff = 0;

        //         for (int j = 0;j < sums.size();j++)
        //             total_diff += abs(new_sum - sums[j]);


        //         if (total_diff < smallest_diff)
        //         {
        //             smallest_diff = total_diff;
        //             smallest_chosen_elem_index = i;
        //         }
        //     }

        //     sums[smallest_sum_index] += elements[smallest_chosen_elem_index];
        //     elements.erase(elements.begin(), elements.begin() + smallest_chosen_elem_index);
        // }

       int maxElem = *max_element(sums.begin(), sums.end());
    return maxElem;
    }
};

int main() {

    vector<int> jobs = { 3,2,3 };
    int k = 3;


    MinimumTime minimumTime(jobs, k);

    cout << "Minimum time: " << minimumTime.findMinimumTime();
    return 0;
}