#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Activity{
int starting_time;
int ending_time;
};

bool activityCompare(Activity activity1,Activity activity2){
    return (activity1.ending_time < activity2.ending_time);
}

void find_maximum_activities(Activity arr[] ,int n){

    int i =0;
    sort(arr,arr+n,activityCompare);

    cout<<"Activity: "<<i<<"\n";
    cout<<"Which is: "<<arr[i].starting_time<<" ,"<<arr[i].ending_time<<"\n";

    for(int j=0;j<n;j++){
        if(arr[j].starting_time >= arr[i].ending_time){
            i = j;
            cout<<"Activity: "<<j<<"\n";
            cout<<"Which is: "<<arr[j].starting_time<<" ,"<<arr[j].ending_time<<"\n";
        }
    }

}

int main()
{
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    find_maximum_activities(arr ,n);
    return 0;
}
