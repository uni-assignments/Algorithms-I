#include<bits/stdc++.h>
#include "../lib/grafo.hpp"

using namespace std;


Graph::Graph(int n_v){
    conections_in_mst.resize(n_v);
    fill(conections_in_mst.begin(), conections_in_mst.end(), 0);
}

void Graph::insert_edge(int v1, int v2, int w, int tour_value){
    edges.emplace_back(w, tour_value, v1, v2);
}

void Graph::print_answer(){
    
    for(auto i: conections_in_mst) cout << i << " ";
    cout << endl;

    for(auto edge: mst)  cout << get<2>(edge) << " " << get<3>(edge) << " " << get<0>(edge) << endl;
    cout << endl;
}

pair<int, int> Graph::kruskal(DSU *dsu){
    
    sort(edges.begin(), edges.end(), 
        [](const tuple<int, int, int, int> &t1, const tuple<int, int, int, int> &t2) {
            if(get<0>(t1) == get<0>(t2)) return get<1>(t1) > get<1>(t2); 
            else return get<0>(t1) < get<0>(t2);// Sort according to smaller weight, then largest touristic value
    });
    
    int cost = 0, touristic_value = 0;
    for(auto[w, tv, v1, v2] : edges){
        if(dsu->find(v1) != dsu->find(v2)){
            dsu->uni(v1, v2);
            touristic_value += tv, cost += w;
            conections_in_mst[v1]++, conections_in_mst[v2]++;
            mst.emplace_back(w, tv, v1, v2);
        }
    } 
    
    return make_pair(cost, touristic_value);
}   