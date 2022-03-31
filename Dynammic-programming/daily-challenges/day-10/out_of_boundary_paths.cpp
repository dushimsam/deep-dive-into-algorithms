#include<bits/stdc++.h>
using namespace std;


/***
 *                                                        QUESTION STATEMENT
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
 * 
 * 
Example 1:


Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:


Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

 *                                                      INSIGHTS FROM THE SOLUTION
 * 1. The number of paths from one cell to its sorrounding. Is always assigned at that cell.
 * 2. We are always listenning for each move that took place.
 *    If the move is outbounding , we increase the res to the number of paths by element at "[j,k]" in visit matrix
 *    Else we increase the new position of temp matrix by the number of paths by element at "[j,k]" in visit matrix.
 * 3. After completing each move . We assign the visit matrix to the temp.
 *    So that the movement can build up from the the new positions.
 *                                                       
 *                                                         APPROACH 
 *  visited[m][n] , res = 0 , possible_dirs = {{-1,0},{1,0},{0,-1},{0,1}}
 *  for(let i=1 <= MAX_MOVES)
 *     temp[m][n]
 *     fill(temp,0);
 * 
 *     for(let j=0 ; j < m; j++)
 *          for(let k=0 ; k < n; k++)
 *               for(dir of possible_dirs)
 *                   let nr = j + dir[0] // new row
 *                   let nc = k + dir[1] // new column
 *                   // checking bounds
 *                   if(nc < 0 || nr < 0 || nr >= m || nc >= n)
 *                        res += visited[j][k] // Add the count from the start point to the new position. Which is kept ofcourse at the starting position.
 *                   else 
 *                        temp[nr][nc] += visited[j][k] 
 *      visited = temp;
 * ***/

int countOutOfBoundPaths(int m,int n,int startCol,int startRow,int maxMove){
       vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        
        visited[startRow][startCol] = 1;
        
        int res = 0;
        int modN = 1e9+7;
        
        for(int i=1;i<=maxMove;++i){
            
            vector<vector<int>> temp(m,vector<int>(n,0));
            
            for(int j=0;j<m;++j){
                for(int k=0;k<n;++k){
                    
                    for(auto &dir:dirs){
                        int nr = j + dir[0];
                        int nc = k + dir[1];
                        
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            res = (res+visited[j][k])%modN;
                        } else {
                            temp[nr][nc] = (temp[nr][nc]+visited[j][k])%modN;
                        }
                     }
                }
            }
            visited = temp;
        }
        return res;
}
int main(){

   int m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;
   cout<< countOutOfBoundPaths(m, n,  startColumn,  startRow,  maxMove);

    return 0;
}