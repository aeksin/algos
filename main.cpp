#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;
#define ll  long long
#define ull unsigned long long
#define ld long double
#define EPS 1e-16
double f(double x){
    return x*x;
}
int main(int argc,char* argv[]){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    double l,r;
    cin>>l>>r;
    while (r-l>EPS){
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        if (f(m1)>f(m2)){
            l=m1;
        }
        else{
            r=m2;
        }
    }
    cout<<setprecision(2)<<l;
}
