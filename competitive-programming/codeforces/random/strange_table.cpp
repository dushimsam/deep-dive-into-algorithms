#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> mx){

    vector<vector<int>> new_mx;
    
    int curr_row = 0;
    int curr_col = 0;

    for(int i=0; i<mx.size();i++){
        for(int j=0; j<mx.size(); j++){

            if(curr_row == 3){
                curr_row = 0;
                curr_col += 1;
            }
        
            new_mx[i][j] = mx[curr_row][curr_col];
            curr_row++;
        }
    }

    // find element 
    
}

int main(){




    return 0;
}