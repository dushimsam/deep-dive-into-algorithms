#include<bits/stdc++.h>

using namespace std;

/*
Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
Explanation: There are at-most three trains at a time (time between 9:40 to 12:00)

Input: arr[] = {9:00, 9:40}
dep[] = {9:10, 12:00}
Output: 1
Explanation: Only one platform is needed.

                 ---- REACTO ---

1. REPEAT
  i.notices: each train is reserved for each platform. , no more than one train on the same platform.
  ii.redifine: Find range of time in which we have the maximum number of trains. And return that maximum number.
  iii.constraints:
     1. The arrival and departure of the train is within that range, arrival_time may be equal to range_start or range_end.

2. EXAMPLES

rr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

the  range of index 1 , 9:40 - 12:00
inside this range we have 9:50 - 11:20 , 11:00 , 11:30
 -> 3 Items in this range.

3. APPROACH

1. sort by duration(start_time,end_time) in descending order
2. for(arr)
       count(trains in range):: +1 - remove items counted.
       prio_queue.add(elem(i),count)

3.get prio_queue.top();

       30 MINUTES TO SOLVE
*/

struct TrainSchedule {
    int arrrival_time;
    int departure_time;
    bool visited;
};

struct TrainScheduleCounter {
    int counts;
    TrainSchedule TrainSchedule;
};

struct compareCounts {
    bool operator()(TrainScheduleCounter const& a, TrainScheduleCounter const& b) {
        return(a.counts < b.counts);
    }
};

bool compareRanges(TrainSchedule& a, TrainSchedule& b) {
    return (a.departure_time - a.arrrival_time) > (b.departure_time - b.arrrival_time);
}

class RailWayPlatformSupervisor {
    vector<TrainSchedule> train_schedules;
    priority_queue<TrainScheduleCounter, vector<TrainScheduleCounter>, compareCounts> supervisedRanges;

public:
    RailWayPlatformSupervisor();
    RailWayPlatformSupervisor(vector<TrainSchedule> train_schedules) {
        this->train_schedules = train_schedules;
    }

    void supervise() {
        sort(train_schedules.begin(), train_schedules.end(), compareRanges);

        for (int i = 0;i < train_schedules.size();i++) {
            int counter = 0;

            if (!train_schedules[i].visited) {
                for (int j = 0;j < train_schedules.size();j++) {
                    if (train_schedules[j].arrrival_time >= train_schedules[i].arrrival_time && train_schedules[j].departure_time <= train_schedules[i].departure_time) {
                        counter++;
                        train_schedules[j].visited = true;
                    }
                }
            }
            train_schedules[i].visited = true;
            supervisedRanges.push({ counter,train_schedules[i] });
        }
    }

    TrainScheduleCounter get_minimum_number() {
        return supervisedRanges.top();
    }
};

int main() {
    vector<TrainSchedule> train_schedules = { {900,910,0} ,{940,1200,0} };
    RailWayPlatformSupervisor supervisor(train_schedules);
    supervisor.supervise();
    cout <<"There are/is "<< supervisor.get_minimum_number().counts<<" minimum number of platforms needed.";

    return 0;
}