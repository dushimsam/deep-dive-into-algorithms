#include<bits/stdc++.h>

using namespace std;


class Graph {
    int V;
    vector<vector<int>> edgelist;
    vector<int> vertices;

public:
    Graph() {}

    Graph(vector<int> vertices) {
        this->V = vertices.size();
        this->vertices = vertices;
    }

    vector<int> getVertices() {
        return this->vertices;
    }

    vector<vector<int>> getEdges() {
        return this->edgelist;
    }

    vector<vector<int>> giveNeigbours(int v) {
        vector<vector<int>>  neigbours;

        for (vector<int> item : edgelist) {
            if (item[0] == v)
                neigbours.push_back(item);
        }
        return neigbours;
    }

    void addEdge(int x, int y, int w) {
        if (vertices.size() == 0)
            cout << "Add vertices";
        else
            edgelist.push_back({ x,y,w });
    }

    void traverse() {
        for (vector<int> item : edgelist) {
            cout << "\nx: " << item[0] << " y:"<<item[1] << " w:" << item[2];
        }
    }
};



class DijstralShortestPath {
    vector<vector<int>> un_visited;
    vector<vector<int>> visited;
    int source;
    Graph graph;

public:
    DijstralShortestPath() {}

    DijstralShortestPath(int source, Graph graph) {
        this->graph = graph;
        this->source = source;
        setUnVisited();
    }

    void setUnVisited() {
        // FORMART {element,parent,distance}
        for (int item : graph.getVertices()) {
            if (item == source) {
                un_visited.push_back({ source,-1,0 });
            }
            else {
                un_visited.push_back({ item,-1,INT_MAX });
            }
        }
    }

    vector<int> get_minimum() {
        vector<int> minum = un_visited[0];

        for (vector<int> item : un_visited) {
            if (item[2] < minum[2])
                minum = item;
        }
        return minum;
    }


    bool already_visited(int v) {
        for (vector<int> item : visited) {
            if (item[0] == v)
                return true;
        }
        return false;
    }

    void update_distance(vector<int> neigbour, vector<int> parent) {

        for (int i=0;i<un_visited.size();i++) {
            if (un_visited[i][0] == neigbour[1]) {
                int sum = parent[2] + neigbour[2];

                if (sum < un_visited[i][2]) {
                    un_visited[i][2] = sum;
                    un_visited[i][1] = parent[0];
                }              
            }
        }
    }


    void shortest_path() {

        while (visited.size() != graph.getVertices().size()) {
            vector<int> minimum = get_minimum();
            visited.push_back(minimum);
            un_visited.erase(remove(un_visited.begin(), un_visited.end(), minimum), un_visited.end());
            
            for (vector<int> neigbour : graph.giveNeigbours(minimum[0])) {
                if (!already_visited(neigbour[1]))
                    update_distance(neigbour, minimum);
            }
        }
    }


    void printShortestPath() {
        cout << "\nFrom O TO: " << "\n";
        for (vector<int> item : visited) {
            cout << "\t\t\t " << item[0] << ": " << item[2] << "\n";
        }
    }
};


int main() {
    vector<int> vertices = {0, 1,2,3,4,5,6,7,8 };
    Graph graph(vertices);
      
        graph.addEdge(1,2,8 );
        graph.addEdge(1,0,4 );
        graph.addEdge(1,7,11 );
        graph.addEdge( 0,1,4 );
        graph.addEdge( 0,7,8 );
        graph.addEdge(2,1,8 );
        graph.addEdge( 2,8,2 );
        graph.addEdge( 2,3,7 );
        graph.addEdge( 2,5,4 );
        graph.addEdge( 3,2,7 );
        graph.addEdge( 3,5,14 );
        graph.addEdge( 3,4,9 );
        graph.addEdge(4,3,9 );
        graph.addEdge( 4,5,10 );
        graph.addEdge( 5,3,14 );
        graph.addEdge( 5,2,4 );
        graph.addEdge( 5,6,2 );
        graph.addEdge(5,4,10);
        graph.addEdge( 6,5,2 );
        graph.addEdge( 6,7,1 );
        graph.addEdge( 6,8,6 );
        graph.addEdge( 7,8,7 );
        graph.addEdge( 7,6,1 );
        graph.addEdge( 7,0,8 );
        graph.addEdge( 7,1,11 );
        graph.addEdge( 8,2,2 );
        graph.addEdge( 8,6,6 );
        graph.addEdge( 8,7,7 );
        // graph.traverse();
        DijstralShortestPath dig(0,graph);
        dig.shortest_path();
        dig.printShortestPath();
        return 0;
}