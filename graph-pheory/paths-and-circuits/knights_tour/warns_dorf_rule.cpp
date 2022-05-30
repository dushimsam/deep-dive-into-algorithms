#include<bits/stdc++.h>
using namespace std;

/***
                              WARNS DORF RULE ALGORITHM
 Summary: This algorithm is based on prefering the next position to be that one which will yield the minimum next move possibilities.
 We want to visit each chess board's cell atleast once. 

 // This is the same algorithm i think can be used on Hamilitanian algorithm , where 
 we intend to visit every vertice at least once in a complete traversal.

                         APPROACH 
let x = 0
let y = 0
let counter = 2 // next position

while(counter <= 64)
     possible_moves = getPossibilites(x,y)
     
     minimum = INT_MAX
     min_move = possible_moves[0]

     for(move of possible_moves)
        moves_found = getPossibilites(move.x,move.y)

        if(moves_found.size() < minimum)
           minimum = moves_found.size()
           min_move = move

     x = min_move.x
     y = min_move.y
     chess_board[x][y] = counter
     counter++;
 
***/

int main(){


    return 0;
}