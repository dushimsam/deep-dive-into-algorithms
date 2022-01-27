#include <bits/stdc++.h>

using namespace std;
// The problem is to maximize as much profit as possible.
//  ALGORITHM:
// STEP 1: Sort all jobs accoring  to their priority (priority means their encome level) in descending order.
// STEP 2: Make an array to track the position which were already occupied.
// STEP 3: Loop through the jobs in descending order 
// STEP 4: Get one job at atime and see in the array_tracking if they is a position it can be placed in. (Make sure you dont go beyond 0 into negativity)

struct Job {
    int tasks;
    int deadline;
    int priority;
};

bool compareJobs(Job& a, Job& b) {
    return a.priority > b.priority;
}

class JobSequencing {
    vector<Job> jobs;
    vector<Job> sequencedJobs;
    vector<int> jobSequenceTracking;

public:
    JobSequencing();
    JobSequencing(vector<Job> jobs){
        this->jobs = jobs;
        jobSequenceTracking.resize(this->jobs.size());
        fill(jobSequenceTracking.begin(),jobSequenceTracking.end(),-1);
    }

    void sequenceJobs() {
        sort(jobs.begin(), jobs.end(), compareJobs);
        for (int i = 0; i < jobs.size();i++) {
            for (int j = jobs[i].deadline - 1;j >= 0;j--) {
                if (jobSequenceTracking[j] == -1) {
                    jobSequenceTracking[j] = 1;
                    sequencedJobs.push_back(jobs[i]);
                    break;
                }
            }
        }
    }

    void printSequencedJobs() {
        cout << "\n TASKS\t\tDEADLINE\t\tPRIORITY";
        int total = 0;
        for (Job job : sequencedJobs) {
            cout << "\n\t" << job.tasks << "\t\t" << job.deadline << "\t\t" << job.priority;
            total+= job.priority;
        }
        cout<<"\n\n\t\t TOTAL PROFIT "<<total;
    }
};
int main() {
    vector<Job> jobs =
    {
        {1, 9, 15}, {2, 2, 2}, {3, 5, 18}, {4, 7, 1}, {5, 4, 25},
        {6, 2, 20}, {7, 5, 8}, {8, 7, 10}, {9, 4, 12}, {10, 3, 5}
    };

    JobSequencing jobSequencing(jobs);
    jobSequencing.sequenceJobs();
    jobSequencing.printSequencedJobs();

    return 0;
}