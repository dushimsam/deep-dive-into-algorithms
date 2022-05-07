#include<bits/stdc++.h>
using namespace std;

bool compare_float(float x, float y){
     return (x == y);
}

int countRect(vector<vector<int>> rectangles){
     int N = rectangles.size();
    int count = 0;
    for(int mask=0;mask < (1 << N);mask++){
        vector<vector<int>> found;
        for(int j=0;j<N;j++){
            if(mask & (1 <<j)){
               found.push_back(rectangles[j]);
            }
        }

        if(found.size() == 2){
                vector<int> rect = found[0];
                float x = (float)rect[0] / (float)rect[1];
                rect = found[1];
                float y = (float)rect[0] / (float)rect[1];  
                if(compare_float(x, y))count++;
        }
    }

    return count;
}
int main(){

vector<vector<int>> rectangles = {{4,8},{3,6},{10,20},{15,30}};
cout<<countRect(rectangles);

    return 0;
}