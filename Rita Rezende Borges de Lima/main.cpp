#include <bits/stdc++.h>
#include "lib/grafo.hpp"
#include "lib/dsu.hpp"

using namespace std;


void read_and_insert_in_structures(Graph *g, int n_vertices, int n_edges){
    int v1, v2, w;
    vector<int> values(n_vertices);
    
    for(auto &v: values) cin >> v;    
    for (int i = 0; i < n_edges; i++){
        cin >> v1 >> v2 >> w;
        g->insert_edge(v1, v2, w, values[v1] + values[v2]);
    }
}


int main(){
    int v, e; cin >> v >> e;
    Graph *g = new Graph(v);
    DSU *dsu = new DSU(v);
    
    read_and_insert_in_structures(g, v, e);   
    pair<int,int> resp = g->kruskal(dsu);

    cout << resp.first << " " << resp.second << endl;
    g->print_answer();

    return 0;
}