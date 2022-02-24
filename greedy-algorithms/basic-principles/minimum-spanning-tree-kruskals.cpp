#include<bits/stdc++.h>
using namespace std;

class Dsu {
    int* root;
public:
    Dsu(int n) {
        root = new int[n];
        for (int i = 0;i < n;i++)
            root[i] = i;
    }

    int parent(int i) {
        if (i == root[i])
            return i;
        return parent(root[root[i]]);
    }

    void union_find(int x, int y) {
        int parent_x = parent(x);
        int parent_y = parent(y);
        root[parent_x] = root[parent_y];
    }
};

class Graph {
    vector<pair<int, pair<int, int>>> p;

public:


    void addEdge(int x, int y, int w) {
        p.push_back(make_pair(w, make_pair(x, y)));
    };

    int kruskals() {
        sort(p.begin(), p.end());

        int total_costs = 0;
        int a,b;
        Dsu dsu(p.size());

        for (int i = 0;i < p.size();i++) {
               a = p[i].second.first;
               b = p[i].second.second;
            if (dsu.parent(a) != dsu.parent(b))
            {            
                int cost = p[i].first;
                total_costs += cost;
                dsu.union_find(a,b);
            }
        }
          return total_costs;
    }
};


    int main() {
        Graph graph;
        graph.addEdge(0, 1, 10);
        graph.addEdge(1, 2, 18);
        graph.addEdge(2, 3, 13);
        graph.addEdge(0, 2, 21);
        graph.addEdge(1, 3, 22);
        cout<<"\n\n\n Total costs "<< graph.kruskals();
        return 0;
    }