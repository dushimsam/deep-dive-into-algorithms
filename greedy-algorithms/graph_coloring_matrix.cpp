#include<bits/stdc++.h>

using namespace std;


class GraphColoring {
    int V;
    int max;
    int* colors;
    vector<vector<int>> graph;

public:
    GraphColoring();
    GraphColoring(vector<vector<int>> my_graph, int max) {
        this->V = my_graph.size();
        this->max = max;
        this->graph = my_graph;

        colors = new int[max];
        for (int i = 1;i <= max;i++) {
            colors[i - 1] = i;
        }

        if (!canBeColored(0))
            cout << "The graph can't be colored with available colors";
        else cout << "Yes possible";
    }


    bool isSafe(int v, int c) {
        for (int j = 0;j < V;j++) {
            if (graph[v][j] && colors[j] == c)
                return false;
        }

        return true;
    }
    bool canBeColored(int v) {
        if (v == V)
            return true;

        for (int c = 1; c <= max; c++) {
            if (isSafe(v, c)) {
                colors[v] = c;
                if (canBeColored(v + 1)) return true;
                colors[v] = 0;
            }
        }

        return false;
    }

};

int main() {

    vector<vector<int>> graph = { { 0, 1, 1, 1 },
                         { 1, 0, 1, 0 },
                         { 1, 1, 0, 1 },
                         { 1, 0, 1, 0 } };

    // Number of colors
    int m = 3;
    GraphColoring graphColoring(graph, m);

    return 0;
}