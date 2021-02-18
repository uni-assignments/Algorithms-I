#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
#include "dsu.hpp"
using namespace std;

class Graph {

    private:
        vector<tuple<int, int, int, int >> edges; // weight, touristic attractiveness, vertex 1, vertex 2
        vector<int> conections_in_mst;
        vector<tuple<int, int, int, int >> mst;
    
    public:
        Graph(int n_vertices);
        ~Graph();

        void insert_edge(int v1, int v2, int w, int tour_value);
        void print_answer();
        pair<int, int> kruskal(DSU *dsu);

};

#endif