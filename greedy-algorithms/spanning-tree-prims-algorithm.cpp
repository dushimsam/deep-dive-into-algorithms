#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Graph {
    int V;
    vector<int> vertices;
    vector<vector<int>> edgelist;
public:
    Graph(){}
    Graph(int V,vector<int> vertices) {
        this->V = V;
        this-> vertices = vertices;
    }

    void addEdge(int x,int y,int w){
        edgelist.push_back({x,y,w});
    }
    int getV(){
        return this->V;
    }
    vector<int> getVertices(){
        return this->vertices;
    }
    vector<vector<int>> getEdges(){
        return this->edgelist;
    }

  vector<vector<int>>   getNeigbours(int v){
     vector<vector<int>>  neigbours;
     for(vector<int> item:edgelist){
         if(item[0] == v)
            neigbours.push_back(item);  
     }

     return neigbours;
   }

};
class DSU{
    int V;
    int* parent;
    public:
    DSU(int V){
        this->V = V;
    }
    
    void setParent(){
        parent = new int[V];
        memset(parent,-1,sizeof(int) * V);
    }

    int find(int i){
        if(i == -1)
          return i;
        return find(parent[i]); 
    }

    int unite(int x,int y){
        int par_v_1 = find(x);
        int par_v_2 = find(y);

        if(par_v_1 != par_v_2){
           parent[par_v_2] = par_v_1;
        }
    }
  

};

class Prim {
    vector<int> visited;
    Graph graph;
public:
    Prim(Graph graph){ this->graph = graph; }

    vector<int> minimumConnected(int v) {
         vector<vector<int>>  neigbours = graph.getNeigbours(v);
         vector<int> minimum = neigbours[0];

         for(vector<int> item:neigbours){
             if(item[2] < minimum[2])
                minimum = item;
         }
         return minimum;
    }
    
    bool formsCycle(){
          
    }

    int spanningTree() {
           for(int i=0;i<graph.getVertices().size();i++){
               
           }
    }
};