#include<bits/stdc++.h>
#include "../lib/dsu.hpp"

using namespace std;

DSU::DSU(int n_vertices){
    id.resize(n_vertices);
    iota(id.begin(), id.end(), 0);
    size.resize(n_vertices);
    fill(size.begin(), size.end(), 1);
}

void DSU::uni(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    if(size[x] > size[y]) std::swap(x,y);
    id[x] = y;
    size[y] += size[x];
}

int DSU::find(int x){
    return id[x] = (id[x] == x ? x : find(id[x]));
}