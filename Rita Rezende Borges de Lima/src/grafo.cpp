#include "../lib/grafo.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <string.h>
#include <queue>
#include <assert.h>

using namespace std;

const int INF = 0x3f3f3f3f;    

Grafo::Grafo(int qtd_v){
    qtd_vertices = qtd_v;
    
    lista_adjacencia.resize(qtd_vertices);                // inicializa a lista de adjacencia com seu respectivo tamanho
    
    vis = (int*)calloc(this->qtd_vertices, sizeof(int));  // aloca e inicializa nosso vetor de visitados com 0
    
    dist = (int*)malloc(this->qtd_vertices*sizeof(int));  // aloca e iniciliza nosso vetor de distancia com infinito
    memset(dist, INF, sizeof(*dist));
}

Grafo::~Grafo(){
    free(vis); free(dist); // ao final do programa libera memoria
}

// Busca em largura onde temos CD vertices iniciais passados pelo usuario
set<int> Grafo::bfs_multi_source(vector<int> centros, int max){    
    set<int> resp;
    queue<int> q;
    for(auto c: centros){
        q.push(c);  //adicionamos nossos centros iniciais na fila 
        vis[c] = 1; dist[c] = 0; //marcamos que eles foram visitados e que sua distancia inicial é 0
    }
    while(!q.empty()){ 
        int v = q.front(); q.pop(); // para cada elemento de nossa fila olhamos seus adjacentes
        
        for(auto adj: lista_adjacencia[v]) if(!vis[adj] and dist[v] < max){ //  se os adjacentes não tiverem sido visitados 
            q.push(adj);                                                    //  e não tivermos procurado a dist maxima
            vis[adj] = 1; dist[adj] = dist[v] + 1;          //  iremos visitar e adicionar esse vertice na fila 
            resp.insert(adj);                               //  e adicionar o vertice em nossa resposta
        } 
    }
    return resp;
}

void Grafo::dfs(int v){
    vis[v] = 1;
    for(auto p: this->lista_adjacencia[v]){
        if(vis[p] == 0) return dfs(p);
        else if(vis[p] == 1){           // Caso durante a rota chegue em um vertice ja visitado significa que a rota não é ótima
            possui_ciclo = true;        // Marca a flag
        }
    }
    vis[v] = 2;
}

// Para cada um de nossos centros 
void Grafo::procura_ciclo(vector<int> &centros){
    possui_ciclo = false;

    memset(vis, 0, sizeof(*vis)); // Zera o vetor de visitados

    for(int i = 0; i < this->qtd_vertices; i++) 
        assert(vis[0] == 0);

    for(auto c: centros){        // Para cada um de nossos centros faz uma busca em profundidade (que pode ser entendida no exemplo como a rota)
        if(vis[c] == 0) dfs(c);    
    }

    cout << possui_ciclo << endl;
}