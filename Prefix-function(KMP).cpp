#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;
#define ll  long long
#define ull unsigned long long
#define ld long double

int main(int argc,char* argv[]){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    string a,b;
    cin>>a>>b;
    string s = a+'#'+b;
    vector<int> pi(s.size(),0);
    for (int i=1;i<pi.size();i++){
        int j= pi[i-1];
        while (j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if (s[i]==s[j]) j++;
        pi[i]=j;
    }

    for (int i=a.size();i<s.size();i++){
        if (pi[i]==a.size()){
            cout<<i-2*a.size()+1<<" ";
        }
    }
}
