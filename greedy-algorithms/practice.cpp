#include<bits/stdc++.h>
using namespace std;



class DSU {
    int* arr;
    int* size;
    int n;
public:
    DSU(int n) {
        // NOTICE THAT INDEXES ARE CONSIDERED AS THE ACTUAL ELEMENT AND THE VALUE AT A SPECIFIC INDEX IS CONSIDERED AS THE PARENT OF THAT ELEMENT
        // THE MOST ROOT OF THE TREE THE VALUE AT IT'S INDEX IS IT'SELF

        for (int i = 0;i < n;i++) {
            // initially all elements point to them selves
            arr[i] = i;
            // size is 1 ofcourse because they are not assigned any other element instead themselves.
            size[i] = 1;
        }
    }

    int find_root(int i){
        if(i == arr[i])
           return i;
        return find_root(arr[arr[i]]);
    }

    int belongs_to_same_parent(int x,int y){
        if(find_root(x) == find_root(y))
           return true;
        else 
           return false;
    }

    int unite(int x,int y){
         int root_x = find(x);
         int root_y = find(y);

         if(size[root_x] > size[root_y])
         {   size[root_x] += size[root_y];
           
         }else{
              size[root_y] += size[root_x];
         }
    }
}


int main() {
    DSU dsu(10);
    // dsu.unite(4, 3);
    // dsu.unite(8, 0);
    // cout << "result "<<dsu.are_connected(3, 8);
    cout << "FINDING ROOT " << dsu.root(0);
    return 0;
}