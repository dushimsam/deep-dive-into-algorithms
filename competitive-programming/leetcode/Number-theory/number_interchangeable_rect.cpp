#include<bits/stdc++.h>
using namespace std;

bool compare_float(float x, float y){
     return (x == y);
}

int countRect(vector<vector<int>> rect){
    vector<double> ratios;
    int n = rect.size();

    for(int i=0;i<n;i++){
         ratios.push_back((double)rect[i][0]/(double)rect[i][1]);
    }

    map<double,int> map_count;
    
    int count_pairs = 0;

    for(int i=0;i<ratios.size();i++){
        if(map_count[ratios[i]]){
             count_pairs += map_count[ratios[i]];
        }
        map_count[ratios[i]]++;
    }

    return count_pairs;
}
int main(){

vector<vector<int>> rectangles = {{4,8},{3,6},{10,20},{15,30}};
cout<<countRect(rectangles);

    return 0;
}