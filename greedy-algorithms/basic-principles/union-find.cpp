
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Edge{
public: int src,dest;
};

class Graph{
public:
    int V,E;
    //graph contains the array of edges
    Edge* edge;
};

Graph* createGraph(int V,int E){
     Graph* graph = new Graph();
     graph -> V = V;
     graph -> E = E;

     graph -> edge = new Edge[graph->E * sizeof(Edge)];

     return graph;
}

// returns the index of the root parent of a specific node.
int find(int parent[],int i){
if(parent[i] == -1)
    return i;
return find(parent,parent[i]);
}

//units two nodes
// By taking one node to be the parent of another node.
// These should be the head nodes
// That's by making one node a parent of another doesn't override another parent instead these indexes point to the root parents.
void Union(int parent[],int x,int y){
   parent[x] = y;
}

// Check the cycle in the graph.

int isCycle(Graph* graph){

// First create the array of vertices
int* parent = new int[graph->V * sizeof(int)];

// Second initialize the array of vertices.

memset(parent,-1,graph->V * sizeof(int));

//Iterate over all the edges of the graph.
//Check if two nodes share the same root parent.
//IF yes ,then there's a cycle.
// Otherwise connect their roots.

for(int i=0;i<graph->E;++i){
  int x = find(parent,graph->edge[i].src);
  int y = find(parent,graph->edge[i].dest);

  if(x == y)
    return 1;
  Union(parent,x,y);
}
return 0;
}

int main(){
//Create graph
/* Let us create the following graph
        0
        | \
        |  \
        1---2 */
    int V = 3, E = 3;

    Graph* graph = createGraph(V,E);
    graph->edge[0].src = 0;
    graph->edge[0].dest = 2;

    graph->edge[1].src = 2;
    graph->edge[1].dest = 1;

    //graph->edge[2].src = 1;
    //graph->edge[2].dest = 0;

    cout << "There is a cycle: "<< isCycle(graph);
return 0;
}
