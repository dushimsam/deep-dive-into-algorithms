#include <bits/stdc++.h>
using namespace std;


class HIndexProblem {
    vector<int> citations;
    vector<int> visited;

public:
    HIndexProblem();
    HIndexProblem(vector<int> citations) {
        this->citations = citations;
    }

    int findHIndex() {
        int counter = visited.size();
        
        sort(visited.begin(), visited.end());

        while (counter >= 1) {
            int count_found = 0;

            for (int i = visited.size() - 1; i >= 0; ++i) {
                if (visited[i] >= counter) count_found++;
                 if(visited[i] < counter) break;
            }


            if (count_found == counter) {
                return count_found;
            }
            else if (count_found > counter) {
                return counter;
            }

            counter--;
        }

        return 1;
    }
    vector<int> findHIndices() {
        vector<int> h_indices;

        for (int i = 0; i < citations.size();i++) {
            visited.push_back(citations[i]);
            h_indices.push_back(findHIndex());
        }
        return h_indices;
    }

};


int main() {
    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        // Get number of papers for this test case
        int paper_count;
        cin >> paper_count;
        // Get number of citations for each paper
        vector<int> citations(paper_count);
        for (int i = 0; i < paper_count; i++) {
            cin >> citations[i];
        }
        HIndexProblem hindexProblem(citations);
        vector<int> answer = hindexProblem.findHIndices();
        cout << "Case #" << test_case << ": ";
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
