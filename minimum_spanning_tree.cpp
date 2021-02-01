#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef pair<int, int> Edge;
vector<int> dist, parent, son;

void prim(vector<vector<Edge>> g){
    priority_queue<Edge> pq; 
    
    for (auto &i: dist) i = INF; 
    for (auto &i: parent) i = -1; 
    for (auto &i: son) i = -1; 
    dist[0] = 0;
    pq.push(make_pair(0, 0));

    while(!pq.empty()){ //Quando não der mais para percorrer outros nós
        auto [w, idx] = pq.top(); pq.pop(); //Pega elemento com menor distancia
        if(-w > dist[idx]) continue; //Caso a distancia do caminho atual seja maior q a distancia calculada
        //Se o vizinho tiver distancia calculada maior do que a do caminho atual
        for(auto [neigh_w, neigh] : g[idx]) if(neigh_w < dist[neigh]) {
                dist[neigh] = neigh_w; //Atualizamos a distancia
                pq.push(make_pair(-dist[neigh], neigh)); //Adicionamos o vizinho no Heap 
                parent[neigh] = idx;
        }
    }
}


int main(){ _

    int vertices, edges, weight, u, v, src, destination; cin >> vertices >> edges;
    vector<vector<Edge>> graph(vertices);
    
    dist.resize(vertices);
    parent.resize(vertices);
    son.resize(vertices);
    
    for(int i = 0; i < edges; i++){ 
        cin >> weight >> u >> v; 
        graph[u].push_back(make_pair(weight, v)); 
        graph[v].push_back(make_pair(weight, u)); 

    }
	
    prim(graph);
    for(int i = 0; i < vertices; i++)
        cout << parent[i];

    return 0;
}