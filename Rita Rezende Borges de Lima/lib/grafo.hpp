#ifndef GRAPH_H
#define GRAPH_H

#include<bits/stdc++.h>
using namespace std;


typedef pair<int, int> Edge; // weight, index

class Graph : vector<vector<Edge>>{

    private:
        int n_vertices;
        vector<int> values;
    
    public:
        Graph(int n_vertices);
        void set_values();
        void prim();
        
        ~Graph();

};

#endif