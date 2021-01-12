#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Grafo {

    private:
        int qtd_vertices;          // Quantidade de vértives = qtd de postos + qtd de centros de distribuicao
        int *dist;                 // Distancia de cada posto ao centro de distribuicao mais proximo
        bool possui_ciclo = false; // Flag que diz se nossas rotas são ótimas

    public:
        Grafo(int qtd_vertices);
        ~Grafo();

        set<int> bfs_multi_source(vector<int> centros, int max, vector<int> vis);        

        void procura_ciclo(vector<int> centros);
        void dfs(int v, vector<int> visi);
        vector<vector<int>> lista_adjacencia;
};

#endif