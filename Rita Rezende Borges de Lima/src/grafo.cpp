#include<bits/stdc++.h>
#include "../lib/grafo.hpp"

using namespace std;

const int INF = 0x3f3f3f3f;    

Graph::Graph(int n_vertices_) : vector<vector<Edge>>(n_vertices_), n_vertices(n_vertices_) {}

void Graph::set_values(){
    values.resize(n_vertices);
    for (auto &el: values) 
        cin >> el;
}

void Graph::prim(){
    vector<int> dist(INF), pred(-1);
    priority_queue<Edge> pq;
    
    pq.push(make_pair(0, 0)), dist[0] = 0;

    while(!pq.empty()){ //Quando não der mais para percorrer outros nós
        auto [w, idx] = pq.top(); pq.pop(); //Pega elemento com menor distancia
        if(-w > dist[idx]) continue; //Caso a distancia do caminho atual seja maior q a distancia calculada
        //Se o vizinho tiver distancia calculada maior do que a do caminho atual
        for(auto [neigh_w, neigh] : (*this)[idx]) if(neigh_w < dist[neigh]) {
                dist[neigh] = neigh_w; //Atualizamos a distancia
                pq.push(make_pair(-dist[neigh], neigh)); //Adicionamos o vizinho no Heap 
                pred[neigh] = idx;
        }
    }
}
