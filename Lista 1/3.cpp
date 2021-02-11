#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;

typedef pair<int, int> Edge;

vector<int> dijkstra(vector<vector<Edge>> graph, int ini){
    vector<int> dist(graph.size()); priority_queue<Edge> pq; 
    
    pq.push(make_pair(0, ini));  
    for (auto &i: dist) i = INF; 

    while(!pq.empty()){
        auto [vw, vi] = pq.top(); pq.pop();
        if(-vw > dist[vi]) continue;
        for(auto [uw, ui]: graph[vi])if(dist[ui] > dist[vw] + uw){
            dist[ui] = dist[vw] + uw;
            pq.push(make_pair(-uw, ui));
        } 
    }   
    return dist;
}

// Checks if graph has a diameter bigger then 6
bool biggest_influence(vector<vector<Edge>> graph){

    int current, max = 0, max_i = 0;
    vector<int> dist(graph.size());
    for(int v = 0; v < graph.size(); v++){
        dist = dijkstra(graph, v);
        for(auto d: dist) current += d;
        if(current > max)
            max_i = v, max = current;
    }
    return max_i;
}

int main(){
    int m, n; cin >> n >> m;
    int w, a, b;
    vector<vector<Edge>> graph(n);
    for(int i = 0; i < m; i++){
        cin >> w >> a >> b;
        graph[a].push_back(make_pair(w, b));
    }

    cout << "User with the most influence is: " << biggest_influence(graph)<< endl;
    return 0;
}