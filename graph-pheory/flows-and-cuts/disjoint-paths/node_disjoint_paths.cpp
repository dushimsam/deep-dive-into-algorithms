#include <bits/stdc++.h>
using namespace std;

/***
                   NODE DISJOINT PATH PROBLEM

Definition: What is the maximum number of paths from source to sink , given that each node should appear at most once in every route.
Same problem but on vertice not edge.

                   APPROACH
1. Divide each node into two , for each original node pointing to the new node.
2. Apply the same algorithm of fulkerson-ford for holding in mind that each edge has a weight of 1.

***/

class Graph
{
vector<vector<int>> graph;
int n;
public:
     Graph(int n,vector<vector<int>> givenGraph){
     this -> n = (n-2)*2 + 2;
     formGraph(givenGraph);
     }

     void formGraph(vector<vector<int>> givenGraph){
        graph.resize(n,vector<int>(n,0));
         
        
        for(int i=0;i<n;i++){
 
        }

     }

};

int main()
{
    int n = 6;
    vector<vector<int>> gr = {{0, 8, 0, 0, 3, 0},
                              {0, 0, 9, 0, 0, 0},
                              {0, 0, 0, 0, 7, 2},
                              {0, 0, 0, 0, 0, 5},
                              {0, 0, 7, 4, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    return 0;
}