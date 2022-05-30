#include<bits/stdc++.h>
using namespace std;

struct Cell {
    string name;
    string index = "";
    vector<string> neighbors;
};

class Graph {
    vector<Cell*> graph_channel;
    int size = 0;

public:
    Graph();
    Graph(int size, char(*board)[100]) {
        /// create blue cells channel
        vector<string> first_neigbours;
        vector<string> last_neigbours;

        for (int i = 0; i < size;i++) {

            if (board[i][0] == 'B' || board[i][0] == 'R')
                first_neigbours.push_back(i + "" + 0);

            if (board[i][size - 1] == 'B' || board[i][size - 1] == 'R')
                last_neigbours.push_back(i + "" + (size - 1));
        }

        create_cell("X","", first_neigbours);
        create_cell("Xo","", last_neigbours);

        this->size = size;
    }

    void initializeAllChannels(char(*board)[100]) {
        int i = 0;
        while (i < size) {

            for (int j = 0; j < size;j++) {
                vector<string> cell_neigbours;
                if (i == 0) {
                    cell_neigbours.push_back("Y");
                    if (j == 0) {
                        cell_neigbours.push_back("X");
                    }
                    else if (j == (size - 1)) {
                        cell_neigbours.push_back("Xo");
                    }

                }else if (j == (size - 1)) {
                      cell_neigbours.push_back("Y");
                    if (j == 0) {
                        cell_neigbours.push_back("Xo");
                    }
                    else if (i == (size - 1)) {
                        cell_neigbours.push_back("Yo");
                    }
                }

                // go top
                if (i != 0 && board[i - 1][j] != '.')
                    cell_neigbours.push_back((i - 1) + "" + j);

                // go down 
                if (i != (size - 1) && board[i + 1][j] != '.')
                    cell_neigbours.push_back((i + 1) + "" + j);

                // go left
                if (j != 0 && board[i][j - 1] != '.')
                    cell_neigbours.push_back(i + "" + (j - 1));

                // go left
                if (j != (size - 1) && board[i][j + 1] != '.')
                    cell_neigbours.push_back(i + "" + (j + 1));

                create_cell(i+""+j,""+board[i][j]+"",cell_neigbours);
            }
        }

        i++;
    }

    void create_cell(string index,string name, vector<string> neighbors) {
        struct Cell* cell = new Cell();
        cell->name = name;
        cell->neighbors = neighbors;
        graph_channel.push_back(cell);
    }
};

int main() {


    return 0;
}