#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;
#define ll  long long
#define ull unsigned long long
#define ld long double
void update(int pos,int elem,vector<int> &tree,int c){
    pos+=c;
    tree[pos]=elem;
    for (pos/=2;pos>=1;pos/=2){
        tree[pos] = tree[pos*2]+tree[pos*2+1];
    }
}
ll get(int l,int r,vector<int> &tree,int c){
    l+=c;
    r+=c;
    ll sum = 0;
    while (l<=r){
        if (l%2==1) sum+=tree[l++];
        if (r%2==0) sum+=tree[r--];
        l/=2;
        r/=2;
    }
    return sum;
}
int main(int argc,char* argv[]){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &x:a){
        cin>>x;
    }
    int c=1;
    while (c<n){
        c*=2;
    }
    vector<int> tree(c);
    for (int i=0;i<n;i++){
        update(i,a[i],tree,c);
    }
    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        int task;
        cin>>task;
        if (task==0){
            int left,right;
            cin>>left>>right;
            if (left>right){
                swap(left,right);
            }
            cout<<get(left,right,tree,c)<<"\n";
        }
        else if (task==1){
            int pos,new_elem;
            cin>>pos>>new_elem;
            update(pos,new_elem,tree,c);
        }
    }
}
