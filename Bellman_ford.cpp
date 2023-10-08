#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;
#define ll  long long
#define ull unsigned long long
#define ld long double

int main(int argc,char* argv[]){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> graph(n);
    for (int i=0;i<n;i++){
        int x,y,c;
        cin>>x>>y>>c;
        x--;
        y--;
        graph[x].emplace_back(y,c);
        graph[y].emplace_back(x,c);
    }
    vector<int> d(n,INF);
    int start;
    cin>>start;
    start--;
    d[start]=0;
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n;j++)
            for (auto y:graph[j]){
                d[y.first]=min(d[y.first],d[j]+y.second);
            }
    }
}
