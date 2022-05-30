#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adj;
    stack<int> cpath;
    stack<int> epath;
   vector<bool> visited;
    int n;

public:
    Graph(int n)
    {
        this->n = n;
        visited.resize(n);
    }

    void addEdge(int x, int y)
    {
        // Because it is undirected graph
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void removeEdge(int x, int y)
    {
        adj[x].remove(y);
        adj[y].remove(x);
    }

    void DFS_isConnected(int v)
    {
        visited[v] = true;

        list<int>::iterator it;

        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (!visited[*it])
                DFS_isConnected(*it);
        }
    }


    void printEurlerCircuits(){
        while(!epath.empty()){
            cout<<"Circuit: "<<epath.top()<<" ";
            epath.pop();
        }
    }


    int findStartingNode(){

        for(auto e : adj)
        {
            if(e.second.size() % 2 == 1) return e.first;
        }
 
        return 1;      
    }
    // printing Eurler
    void findEulerCircuits(){

        int v = findStartingNode();
       
        while(!cpath.empty()){

            if(adj[v].size() == 0){
                epath.push(v);
                cpath.pop();
                printEurlerCircuits();
            }else{
                list<int>::iterator it = adj[v].begin();
                cpath.push(*it);
                removeEdge(v,*it);
            }

        }
    }

    // First make sure  that the input graph G is connected and
    bool isConnected()
    {
        
        for (auto elem : adj)
        {
            DFS_isConnected(elem.first);
            if (find(visited.begin(), visited.end(), false) != visited.end())
                return false;
        }
        return true;
    }

    // Second  make sure contains exactly 0 or 2 odd degree vertices.
    bool containsCircuitPath()
    {
        int odds = 0;
        for (auto elem : adj)
        {
            if (elem.second.size() % 2 == 1)
                odds++;
        }

        if (odds == 0 || odds == 2)
            return true;
        else
            return false;
    }
};

main()
{
    Graph G(6);
    // adding edges to the graph
    // this graph is same as the final graph in the example section
    G.addEdge(1, 6);
    G.addEdge(6, 3);
    G.addEdge(3, 2);
    G.addEdge(2, 1);
    G.addEdge(2, 5);
    G.addEdge(5, 4);
    G.addEdge(4, 2);
    
   if(G.containsCircuitPath())
      G.findEulerCircuits();

    return 0;
}