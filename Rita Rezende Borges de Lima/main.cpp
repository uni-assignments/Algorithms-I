#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;    


void imprime_grafo_de_acordo_com_entrada(vector<vector<int>> g, int qtd_centros, int qtd_postos){
    
    for (size_t i = 0; i < qtd_centros + qtd_postos; i++){
        
        if(i < qtd_centros) cout << endl << "C" << i + 1 << ": ";
        else cout << endl << "P" << i - qtd_centros + 1 << ": ";
        for(auto w : g[i]){
            cout << w - qtd_centros + 1 << " ";
        }
    }
    cout << endl;
}

void imprime_grafo_certo(vector<vector<int>> g, int qtd_centros, int qtd_postos){
    for (size_t i = 0; i < qtd_centros + qtd_postos; i++){
        
        if(i < qtd_centros) cout << endl << "C" << i << ": ";
        else cout << endl << "P" << i << ": ";
        for(auto w : g[i]){
            cout << w << " ";
        }
    }
    cout << endl;
}

set<int> bfs_multi_source(vector<vector<int>> g, vector<int> centros, int *vis, int *dist, int max){
    set<int> resp;
    queue<int> q;
    for(auto c: centros){
        q.push(c); 
        vis[c] = 1; dist[c] = 0;
    }
    while(!q.empty()){
        int v = q.front(); q.pop();
        
        for(auto adj: g[v]) if(!vis[adj] and dist[v] < max){
            q.push(adj); 
            vis[adj] = 1; dist[adj] = dist[v] + 1;
            resp.insert(adj);
        } 
    }
    return resp;
}


void dfs(int v, vector<vector<int>> g, int *vis){
    vis[v] = 1;
    for(auto p: g[v]){
        if(!vis[p]) return dfs(p, g, vis);
        else if(p != v){ 
            std::cout << 1 << endl; 
            exit(1);
        }
    }
}

int main (){
    int qtd_centros, qtd_postos, incremento_temp;
    cin >> qtd_centros >> qtd_postos >> incremento_temp;
    vector<vector<int>> g;
    vector<int> centros;
    set<int> resp;
    set<int>::iterator it;

    int *vis = (int * )calloc((qtd_postos + qtd_centros), sizeof(int));
    int *dist = (int * )calloc((qtd_postos + qtd_centros), sizeof(int));
    memset(dist, INF, sizeof(dist));
    g.resize((qtd_postos + qtd_centros)); // na modelagem todos os postos assumirao seu valor original + qtd de centros
    
    int a;
    string text_line;
    scanf("\n");
    for(int i = 0; i < qtd_centros; i++){
        centros.push_back(i);
        std::getline(cin, text_line);
        std::istringstream input_stream(text_line);
        while (input_stream >> a){
            if(a != 0) {
                a--;
                g[i].push_back(a+qtd_centros);
            }
        }
    }
    scanf("\n");
    for(int i = 0; i < qtd_postos; i++){
        std::getline(cin, text_line);
        std::istringstream input_stream(text_line);
        while (input_stream >> a){
            if(a != 0){
                a--;
                g[i+qtd_centros].push_back(a+qtd_centros);
            } 
        }
    }

    resp = bfs_multi_source(g, centros, vis, dist, (30/incremento_temp));

    //Imprime set com todos os elementos visitados
    std::cout << resp.size() << endl;
    if(!resp.size()) std::cout << "*";
    else for(it = resp.begin(); it != resp.end(); it++){
        if(*it >= qtd_centros) std::cout << *it - qtd_centros + 1 << " ";
    }
    std::cout << endl;
    //DFS PARA ACHAR CICLO
    for(auto rota: centros){
        memset(vis, 0, sizeof vis);
        dfs(rota, g, vis);    
    }
    std::cout << 0 << endl;

}