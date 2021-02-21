#ifndef DSU_H
#define DSU_H

#include<bits/stdc++.h>
using namespace std;

class DSU : vector<tuple<int, int, int>> {

    private:
        vector<int> id;
        vector<int> size;
    
    public:
        DSU(int n_vertices);
        ~DSU();

        int find(int x);
        void uni(int x, int y);
};

#endif