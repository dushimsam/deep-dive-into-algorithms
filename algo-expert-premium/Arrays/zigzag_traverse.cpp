#include<bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> vi;

// Move diagonally upwards
vector<int> moveUp(int row,int col,int maxRows,int maxCols,vi arr){
   while(row > 1 && col < maxCols){
         cout << arr[row-1][col-1] << endl;
         row--;
         col++;
   }

   if(row == 1 && col < maxCols){
      col++;
   } else if(row == 1 && col == maxCols){
    row++;
   }
   return {row,col};
}


// Move diagonally downwards

vector<int> moveDown(int row,int maxRows,int col,int maxCols,vi arr){
    while(row < maxRows && col > 1){
         cout << arr[row-1][col-1] << endl;
         row++;
         col--;
    }
  
    if(col == 1 && row < maxRows){
       row++;
    }else if(row == maxRows && col == 1){
        col++;
    }
   return {row,col};
}

int main(){
    
vi arr = {
  {1, 3, 4, 10},
  {2, 5, 9, 11},
  {6, 8, 12, 15},
  {7, 13, 14, 16}
};

int row = 1, col = 1;
int maxRows = arr.size();
int maxCols = arr[0].size();


while(row < maxRows && col < maxCols){
    cout << arr[row-1][col-1] << endl;
    vector<int> res= moveDown(row,maxRows,col,maxCols,arr);
    row = res[0];
    col = res[1];
    cout << arr[row-1][col-1] << endl;
    res = moveUp(row,maxRows,col,maxCols,arr);
}
    return 0;
}