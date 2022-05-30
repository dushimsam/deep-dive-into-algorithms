#include<bits/stdc++.h>
using namespace std;
/*
 /// INPUT PRESENTED IN ADJACENCY LIST

ALGORITHM:

visited[]
unvisited[]

isSafe(node , color){
   loop(neigbours)
      loop(visited where i = neigbour)
            if(color == visited[i].color)
                 return false
   return true
}

n *  M


while(unvisited != NULL)
     elem = unvisted.get()

     found = 0;
     loop(colors):
         if(isSafte(node , color)){
               visited.push(elem);
               found = 1;
               unvisted.delete(elem);
         }
      return false;


*/

struct Node {
      int elem;
      int assigned_color;
      vector<int> neigbours;
};

class GraphColoring {
      vector<Node> visited;
      vector<Node> unvisited;
      int* colors;
      int maxColors = 0;

public:
      GraphColoring();
      GraphColoring(vector<Node> unvisited,int maxColors) {
            this->unvisited = unvisited;
            colors = new int[maxColors];
      }

      bool isSafe(Node elem, int intendedColor) {
            for (int i = 0; i < elem.neigbours.size(); i++) {
                  for (int j = 0; j < visited.size(); j++) {
                        if (visited[j].elem == elem.neigbours[i] && visited[j].assigned_color == intendedColor) {
                              return false;
                        }
                  }
            }
            return true;
      }
      void countColors() {
            int i = 0;
            while (!unvisited.empty()) {
                  for (int j = 0; j < (sizeof(colors)/sizeof(colors[0])); j++) {

                        if (colors[j] == -1) {
                              if (j == 0)
                                    colors[j] = 0;
                              else
                                    colors[j] = colors[j - 1] + 1;
                        }

                        if (isSafe(unvisited[i], colors[j])) {
                              Node newNode = unvisited[i];
                              newNode.assigned_color = colors[j];
                              visited.push_back(newNode);
                              unvisited.erase(unvisited.begin() + i);
                              break;
                        }
                  }
                  i++;
            }
      }

};


int main() {

      GraphColoring graphColoring;

      return 0;
}