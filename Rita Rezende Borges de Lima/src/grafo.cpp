#include "../lib/grafo.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <string.h>
#include <queue>
#include <assert.h>
#include <functional>

using namespace std;

const int INF = 0x3f3f3f3f;    

Grafo::Grafo(int qtd_v){
    qtd_vertices = qtd_v;
    
    lista_adjacencia.resize(qtd_vertices);                // inicializa a lista de adjacencia com seu respectivo tamanho
        
    dist = (int*)malloc(this->qtd_vertices*sizeof(int));  // aloca e iniciliza nosso vetor de distancia com infinito
    memset(dist, INF, sizeof(*dist));
}

Grafo::~Grafo(){
    free(dist); // ao final do programa libera memoria
}

// Busca em largura onde temos CD vertices iniciais passados pelo usuario
set<int> Grafo::bfs_multi_source(vector<int> centros, int max, vector<int> vis){    
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

void Grafo::dfs(int v, vector<int> visi){
    visi[v] = 1;
    for(auto p: this->lista_adjacencia[v]){
        if(visi[p] == 0) dfs(p, visi);
        else if(visi[p] == 1){           // Caso durante a rota chegue em um vertice ja visitado significa que a rota não é ótima
            possui_ciclo = true;        // Marca a flag
        }
    }
    visi[v] = 2;
}

// Para cada um de nossos centros 
void Grafo::procura_ciclo(vector<int> &centros){
    possui_ciclo = false;

    vector<int> visi(this->qtd_vertices,0);

    for(int i = 0; i < this->qtd_vertices; i++) 
        assert(visi[0] == 0);

    for(auto c: centros){        // Para cada um de nossos centros faz uma busca em profundidade (que pode ser entendida no exemplo como a rota)
        if(visi[c] == 0) dfs(c, visi);    
    }

    cout << possui_ciclo << endl;
}
