#include<bits/stdc++.h>

using namespace std;

class Tree {
    vector<pair<char, pair<char, char>>> tree;
public:
    void addElement(char element, pair<char, int> child1, pair<char, int> child2) {
        char leftChild;
        char rightChild;

        if (child1.second < child2.second)
        {
            leftChild = child1.first;
            rightChild = child2.first;
        }
        else {
            leftChild = child2.first;
            rightChild = child1.first;
        }

        tree.push_back(make_pair(element, make_pair(leftChild, rightChild)));
    }

    vector<pair<char, pair<char, char>>>  getTree() {
        return this->tree;
    }
};

class HuffmanEnconding {
    string text;
    typedef pair<int, pair<char, string>> P;
    priority_queue<P, vector<P>, greater<P>> list;
    Tree tree;

public:
    HuffmanEnconding(string test) {
        unordered_map<char, int> d;
        for (char s : test) {
            d[s]++;
        }
        for (char s : test) {
            if (d[s] != 0) {
                list.push(make_pair(d[s], make_pair(s, "DEFAULT")));
                d[s] = 0;
            }
        }
    }

    void makeEncoding() {
        while (!list.empty()) {
            pair<int, pair<char, string>> pair_1 = list.top();
            list.pop();
            pair<int, pair<char, string>> pair_2 = list.top();
            list.pop();

            int sum = pair_1.first + pair_2.first;

            if (!list.empty())
                list.push(make_pair(sum, make_pair(sum, "NOT_DEFAULT")));


            if (pair_1.second.second == "DEFAULT")
            {
                tree.addElement(pair_1.second.first, make_pair('0', 0), make_pair('0', 0));
            }
            else if (pair_2.second.second == "DEFAULT") {
                tree.addElement(pair_1.second.first, make_pair('0', 0), make_pair('0', 0));
            }

            tree.addElement(sum, make_pair(pair_1.second.first, pair_1.first), make_pair(pair_2.second.first, pair_2.first));
        }
    }

    void displayEncoding() {
        stack<pair<char, pair<char, char>>> on_stack;
        on_stack.push(tree.getTree()[0]);
         
        //  while(!on_stack.empty()){
        //        cout<<"Left "<<on_stack.

        //  }
    }
};
int main() {
    HuffmanEnconding huffmanEnconding("ABBCDBCCDAABBEEEBEAB");
    huffmanEnconding.makeEncoding();
    return 0;
}