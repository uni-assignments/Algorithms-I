#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<vector<int>> tg;



int main(){ _

    int vertices, edges, w, u, v; cin >> vertices >> edges;
    g.resize(vertices);

    for(int i = 0; i < edges; i++){ 
        cin >> w >> u >> v; 
        g[u].push_back(v);  g[v].push_back(u);
    }
	
    return 0;
