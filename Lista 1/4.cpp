#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<vector<int>> tg;

  
void dfs(int v, vector<int> &vis, int &it, vector<int> &to_look){
    vis[v] = 1;
    for(int u: g[v]) if(!vis[u]) {
        dfs(u, vis, it, to_look);
    }
    to_look[it--] = v;//tempo de termino
}

void dfst(int v, vector<int> &vis, int c, vector<int> &comp){
    vis[v] = 1; comp[v] = c;
    for(int u: tg[v]) if(!vis[u]) {
        dfst(u, vis, c, comp);
    }
}

pair<int, vector<int>> kosaraju(){
    int n = g.size();
    vector<int> vis(n), comp(n), to_look(n);
    int it = n-1;

    for(int i = 0; i < n; i++)if(!vis[i]){
        dfs(i, vis, it, to_look);
    }

    int ncomps = 0;
    fill(vis.begin(), vis.end(), 0);
    for(int u: to_look) if(!vis[u]) {
        dfst(u, vis, ncomps++, comp);
    }

    return make_pair(ncomps, comp);
}

void print_sccs(pair<int, vector<int>> &sccs){
    int it = sccs.second[0];
    cout << endl << "Grupo " << it+1 << ":";
    for(int i = 0; i < sccs.second.size(); i++){
        if(sccs.second[i] != it){
            cout << endl << "Grupo " << sccs.second[i]+1 << ": " << i;
            it = sccs.second[i];
        } else {
            cout << " " << i;
        }
    }
    cout << endl;
}

int main(){ _

    int vertices, edges, u, v; cin >> vertices >> edges;
    g.resize(vertices);
    tg.resize(vertices);

    for(int i = 0; i < edges; i++){ 
        cin >> u >> v; 
        g[u].push_back(v); tg[v].push_back(u);
    }
	
    pair<int, vector<int>> sccs = kosaraju();
    print_sccs(sccs);

    return 0;
}