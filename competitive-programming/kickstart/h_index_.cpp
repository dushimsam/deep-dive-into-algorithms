#include <bits/stdc++.h>
using namespace std;


class HIndexProblem {
    vector<int> papers;
    vector<int> visited;

public:
    HIndexProblem();
    HIndexProblem(vector<int> papers) {
        this->papers = papers;
    }

    int findHIndex() {
        int counter = visited.size();

        while (counter >= 1) {
            int count_found = 0;

            for (int i = 0; i < visited.size(); ++i) {
                if (visited[i] >= counter) count_found++;
            }


            if (count_found == visited.size()) {
                return count_found;
            }
            counter--;
        }

        return 1;
    }
    vector<int> findHIndices() {
        vector<int> h_indices;

        for (int i = 0; i < papers.size();i++) {
            visited.push_back(papers[i]);
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
