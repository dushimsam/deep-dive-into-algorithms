#include<bits/stdc++.h>
using namespace std;

struct Task{
    char event;
    int starting_time;
    int ending_time;
};

bool compareTask(Task& a, Task& b){
    return  a.ending_time < b.ending_time;
}

class TaskScheduler {
    vector<Task> tasks;
    vector<Task> scheduled_tasks;
    public:
     TaskScheduler();
     TaskScheduler(vector<Task>& tasks){
         this->tasks = tasks;
     }
  
     void schedule_tasks(){
         sort(tasks.begin(), tasks.end(),compareTask);
         int j=0;

         for(int i = 0; i < tasks.size(); i++){
                  if(tasks[i].starting_time >= tasks[j].ending_time){
                      j=i;
                      scheduled_tasks.push_back(tasks[i]);
                  }
    
         }
     }

      void printScheduledTasks(){
          for(int i= 0;i< tasks.size(); i++)
              cout<<"\nTask:  "<<tasks[i].event<<" STARTING AT: "<<tasks[i].starting_time<< " ENDING AT: "<<tasks[i].ending_time;
      }
};


int main(){
      vector<Task> all_tasks={{'C',4,9},{'B',2,5},{'A',1,3},{'D',6,8}};
      TaskScheduler scheduler(all_tasks);
      scheduler.schedule_tasks();
      scheduler.printScheduledTasks();

    return 0;
}

