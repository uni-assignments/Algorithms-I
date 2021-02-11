#include <bits/stdc++.h>
#include "lib/grafo.hpp"

using namespace std;


Graph *read_and_insert_in_graph(){
    int vertices, edges; cin >> vertices >> edges;
    Graph *g = new Graph(vertices);
    
    
    int a, b, w;
    for (size_t i = 0; i < vertices; i++){
        cin >> a >> b >> w;
        (*g)[a].push_back(Edge(b, w));
        (*g)[b].push_back(Edge(a, w));
    }
    
    return g;
}

int main(){
    Graph *g = read_and_insert_in_graph();
    g->prim();
}