#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int ini, vector<vector<int>> graph, int max_dist){
    queue<int> q; q.push(ini);
    vector<int> dist(graph.size());
    vector<int> vis(graph.size());
    dist[ini] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u: graph[v])if(!vis[u]){
            q.push(u); dist[u] = dist[v] + 1; vis[u]  = 1;
            if(dist[u] >= max_dist) return vis;
        }
    }
    return vis;
}

// Checks if graph has a diameter bigger then 6
bool diameter_greater_then_6(vector<vector<int>> graph){
    vector<int> vis;
    for(int v = 0; v < graph.size(); v++){
        vis = bfs(v, graph, 6);
        for(auto i: vis) if(!i) return true;
    }
    return false;
}

int main(){
    int m, n; cin >> n >> m;
    int a, b;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if(diameter_greater_then_6(graph)) cout << "Diametro é maior que 6" << endl;
    else cout << "Diametro é menor que 6" << endl;

    return 0;
}