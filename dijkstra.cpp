#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef pair<int, int> Edge;

vector<int> dijkstra(vector<vector<Edge>> g, int src){
    priority_queue<Edge> pq; vector<int> dist(g.size());
    
    for (auto &i: dist) i = INF; 
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while(!pq.empty()){ //Quando não der mais para percorrer outros nós
        auto [w, idx] = pq.top(); pq.pop(); //Pega elemento com menor distancia
        if(-w > dist[idx]) continue; //Caso a distancia do caminho atual seja maior q a distancia calculada
        //Se o vizinho tiver distancia calculada maior do que a do caminho atual
        for(auto [neigh_w, neigh] : g[idx]) if(neigh_w + dist[idx] < dist[neigh]) {
                dist[neigh] = neigh_w + dist[idx]; //Atualizamos a distancia
                pq.push(make_pair(-dist[neigh], neigh)); //Adicionamos o vizinho no Heap 
        }
    }
    
    return dist;
}


int main(){ _

    int vertices, edges, weight, u, v, src, destination; cin >> vertices >> edges;
    vector<vector<Edge>> graph(vertices);

    for(int i = 0; i < edges; i++){ cin >> weight >> u >> v; graph[u].push_back(make_pair(weight, v)); }
	
    cin >> src;
    vector<int> dist = dijkstra(graph, src);

    for(auto d: dist) cout << d << " ";  
    return 0;
}