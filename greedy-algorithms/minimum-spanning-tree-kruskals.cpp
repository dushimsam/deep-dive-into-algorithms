#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class DSU{
    int* parent;
    int* rank;
    
public:
     DSU(int n){
    parent = new int[n];
    rank = new int[n];
    memset(parent,-1,sizeof(int) * n);
    memset(rank,1,sizeof(int) * n);
    }

    void Union(int x,int y){
    parent[x] = y;
    }

    int find(int i){
        if(parent[i] == -1)
           return i;
         parent[i] = find(parent[i]);
    }

    void unite(int v1,int v2){
       int x = find(v1);
       int y = find(v2);

       if(x != y){
           if(rank[x] < rank[y]){
              Union(x,y);
              rank[y]+= rank[x];
           }else{
              Union(y,x);
              rank[x]+= rank[y];
           }
       }
    }
};


class Graph
{
   int V;
   vector<vector<int>> edgelist;

public:
    
    Graph(int V){
      this->V = V;
  } 

   void addEdge(int w, int x,int y){
       edgelist.push_back({w,x,y});
   }

   void traverse(){
       for(auto item:edgelist){
           cout<<"weight "<<item[0]<<" , x "<<item[1]<<" ,y "<<item[2]<<"\n";
       }
   }

   int kruskals_mst(){
       //STEP 1: Sorting the edges
       sort(edgelist.begin(),edgelist.end());
      // Create array resembling our graph for easy union-find
        DSU dsu(V);

       //Iterate through all edges
        int ans =0;
        for(auto item:edgelist){
            int w = item[0];
            int x = item[1];
            int y = item[2];

           // CHECK CYCLE IN THE EDGES 

            if(dsu.find(x) != dsu.find(y))
              {
                 // IF ON THEN START UNITE THE EDGES
                 dsu.unite(x,y);
                 ans += w;
              }
        }
     return ans;
   }
};


 int main()
{
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);
   cout <<"Answer "<< g.kruskals_mst();

}

//// TIME COMPLEXITY 
// sorting - O(ElogE)
// union ,find - O(logV)
//Overall time complexity O(ElogE + ElogV)
// Which is O(ElogE) or O(ElogV)