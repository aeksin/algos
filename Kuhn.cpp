#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;
#define ll  long long
#define ull unsigned long long
#define ld long double

int kuhn(ll i,vector<vector<int>> &graph,vector<int> &used,vector<ll> &mt){
    if (used[i]){
        return 0;
    }
    used[i]=1;
    for (auto x:graph[i]){
        if (mt[x]==-1 || kuhn(mt[x],graph,used,mt)){ // если ребро не посещено или есть увеличивающая цепь
            mt[x]=i;
            return 1;
        }
    }
    return 0;
}

int main(int argc,char* argv[]){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int n;
    cin>>n;
    //вводим одну долю
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    int m;
    cin>>m;
    //вводим другую долю
    vector<int> b(m);
    for (int i=0;i<m;i++){
        cin>>b[i];
        b[i]--;
    }
    vector<vector<int>> graph(n+m+1);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (abs(a[i]-b[j])<=1){
                graph[i].push_back(j);
                //создаём ребро из первой доли во вторую, функцию заменить на свою
            }
        }
    }
    int ans=0;
    vector<int>used(n,0); // храним "посещённость вершин для DFS"
    vector<ll> mt(m,-1); // с какой вершиной первой доли связана вершина из второй
    for (int i=0;i<n;i++ ){
        used.assign(n+m+1,0); // заполняем нулями на каждом шаге
        if (kuhn(i,graph,used,mt)){
            ans++;

        }

    }
    cout<<ans<<"\n";
    for (int i=0;i<mt.size();i++){
        if (mt[i]!=-1){
            cout<<i<<" "<<mt[i]<<'\n';
        }
    }



}
