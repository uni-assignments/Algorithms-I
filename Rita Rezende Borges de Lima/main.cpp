#include <iostream>
#include <vector>
#include <sstream>

#include "./lib/grafo.hpp"
using namespace std;

void le_entrada(int qtd_centros, int qtd_postos, vector<int> &centros, Grafo *g){
    int a; string text_line;
    
    scanf("\n");
    for(int i = 0; i < qtd_centros; i++){
        centros.push_back(i);
        getline(cin, text_line);
        istringstream input_stream(text_line);
        while (input_stream >> a) if(a != 0) {
            a--;
            g->lista_adjacencia[i].push_back(a+qtd_centros);
        }
    }
    
    scanf("\n");
    for(int i = 0; i < qtd_postos; i++){
        std::getline(cin, text_line);
        std::istringstream input_stream(text_line);
        while (input_stream >> a) if(a != 0){
            a--;
            g->lista_adjacencia[i + qtd_centros].push_back(a+qtd_centros);
        } 
    }
}

void imprime_postos_alcancados(int qtd_centros, set<int> resp){
    set<int>::iterator it;

    // Imprime o tamanho de nosso set, ou seja a quantidade de postos alcancados
    std::cout << resp.size() << endl;

    // Itera pelo set que possui postos alcancados imprimindo cada um deles;
    if(!resp.size()) std::cout << "*";
    else for(it = resp.begin(); it != resp.end(); it++){
        if(*it >= qtd_centros) std::cout << *it - qtd_centros + 1 << " ";
    }
    std::cout << endl;
}


int main (){
    int qtd_centros, qtd_postos, incremento_temp;
    cin >> qtd_centros >> qtd_postos >> incremento_temp;

    Grafo *g = new Grafo(qtd_centros + qtd_postos);
    vector<int> centros;
    vector<int> visi(qtd_centros+qtd_postos,0);
    
    // le as arestas do grafo (rotas entre postos e centros de distribuicao)
    le_entrada(qtd_centros, qtd_postos, centros, g);
    
    // Acha os postos que foram alcancados
    set<int> postos_alcancados = g->bfs_multi_source(centros, 30/incremento_temp, visi);
    
    //Imprime a quantidade e quais postos foram alcancados com as variaveis passadas pelo usuario
    imprime_postos_alcancados(qtd_centros, postos_alcancados);
    
    //Verifica se o grafo possui ciclo, se tiver imprime 1, caso contrario imprime 0
    g->procura_ciclo(centros);
    delete g;

}