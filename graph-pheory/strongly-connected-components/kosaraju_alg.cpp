#include <bits/stdc++.h>
using namespace std;

/***
 *
 *  KOSARAJU ALGORITHM IS ALL ABOUT FINDING THE ALL CONNECTED COMPONENTS.
 *  in O(V+E)
 *
 *  APPROACH
 *  summary :: 1. DFS1 2. GRAPH.REVERSE() 3. DFS2 based on STACK
 *
 * 1. CREATE  A STACK
 *
 *    DFS1(int v)
 *      visited[v] = true
 *      for(neigbours of v)
 *          if(neibour is not visited)
 *             DFS1(neibour)
 *      stack.push(v)  // This to make the first vertice we started on DFS1 to be the first on stack.front().
 *
 * 2. PERFORM A DFS1 ON THE GRAPH TO ADD ELEMENTS IN THE STACK.//
 *
 *      for(auto v:vertices)
 *         if(v is not visited) DFS1(v)
 *
 * 4. Graph.reverse() // reversing the edges of the graph
 *
 * 5. reset visited[for each] => false
 *
 * 5.  perform DFS2 BASED ON THE STACK  FOR PRINTING THE ELEMENTS OF EACH PARTICULAR STRONG CONNNECTED COMPONENT.
 *
 *    DFS2(v)
 *         visited[v] = true
 *         print(v)
 *
 *        for(neigbours of V)
 *              if(neibour IS NOT visited)
 *                 DFS2(neigbour)
 *
 *
 *     while(stack IS NOT empty)
 *       if(v is NOT visited)
 *           DFS2(v)
 *           print(NEW_LINE)
 *
 * 
 *    NOTE:
 *     1. Diff between DFS1,DFS2
 *            DFS1 uses the original adjacency list | It is used to populate elements into stack.
 *            DFS2 uses the reversed adjancency list. | It is used to print members of the connected elements.
 * 
 *    
 ***/


class Graph
{
    map<int, list<int>> adj;
    map<int,list<int>> rev_adj;

    vector<bool> visited;
    stack<int> s;

public:
    Graph(int n)
    {
        visited.resize(n, false);
    }
    void addEdge(int w, int x)
    {
        adj[w].push_back(x);
    }

    void DFS1(int v)
    {
        visited[v] = true;
        list<int>::iterator it;

        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (!visited[*it])
                DFS1(*it);
        }
        s.push(v);
    }

    void DFS2(int v)
    {
        visited[v] = true;
        list<int>::iterator it;

        cout << v << " ";
        for (it = rev_adj[v].begin(); it != rev_adj[v].end(); it++)
        {
            if (!visited[*it])
                DFS2(*it);
        }
    }

    void resetVisited()
    {
        fill(visited.begin(), visited.end(), false);
    }

    void reverseGraph()
    {
        for (auto v : adj)
        {
            list<int>::iterator it;

            for (it = adj[v.first].begin(); it != adj[v.first].end(); it++)
            {
                rev_adj[*it].push_back(v.first);
            }
        }
    }

    void implementKosaraju()
    {
        for (auto v : adj)
        {
            if (!visited[v.first])
                DFS1(v.first);
        }

        resetVisited();
        reverseGraph();

        while (!s.empty())
        {
            int curr = s.top();
            s.pop();

            if (!visited[curr])
            {
                DFS2(curr);
                cout << "\n";
            }
        }
    }
};

int main()
{
    int n = 5;
    Graph graph(n);
    vector<vector<int>> adj_list = {{1,0},{0,2},{2,1},{0,3},{3,4}};
    
    for(int i=0;i<adj_list.size();i++){
      graph.addEdge(adj_list[i][0],adj_list[i][1]);
    }

    cout<<"\n\nSTRONGLY CONNECTED COMPONENTS IN THE GRAPH";
    cout<<"\n\n";
    graph.implementKosaraju();
    return 0;
}