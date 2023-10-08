#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;
#define ll  long long
#define ull unsigned long long
#define ld long double
vector<int> parent;
vector<int> r;
void make_set(int v){
    parent[v]=v;
    r[v]=0;
}
int find_set(int v){
    if (parent[v]==v){
        return v;
    }
    return parent[v]= find_set(parent[v]);
}
void union_sets(int i,int j){
    i= find_set(i);
    j= find_set(j);
    if (i!=j) {
        if (r[i] < r[j]) {
            swap(i, j);
        }
        parent[j] = i;
        if (r[i] == r[j]) {
            r[i]++;
        }
    }
}
int main(int argc,char* argv[]){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int, pair<int,int>>> edges;
    for (int i=0;i<m;i++){
        int x,y,c;
        cin>>x>>y>>c;
        x--;
        y--;
        edges.push_back({c,{x,y}});
    }
    sort(edges.begin(),edges.end());
    parent.assign(n,0);
    r.assign(n,0);
    for (int i=0;i<n;i++){
        make_set(i);
    }
    ll sum=0;
    vector<pair<int,int>> res;
    for(int i=0;i<m;i++){
        if (find_set(edges[i].second.first)!= find_set(edges[i].second.second)){
            sum+=edges[i].first;
            res.push_back(edges[i].second);
            union_sets(edges[i].second.first,edges[i].second.second);
        }
    }
}
