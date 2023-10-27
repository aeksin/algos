#include <bits/stdc++.h>

using namespace std;
const long long INF = 1e9+7;
const double PI = 3.141529;
#define ll long long
typedef complex<double> base;
void fft(vector<base> &a,bool invert){
    int n = (int)a.size();
    if (n==1){
        return;
    }
    vector<base> a0(n/2),a1(n/2);
    for (int i =0,j=0;i<n;i+=2,++j){ // четные в одну, нечётные в другую
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft(a0,invert);
    fft(a1,invert);
    double ang = 2*PI/n * (invert ? -1:1);
    base w(1),wn(cos(ang),sin(ang)); //wn, и w, cодержащая текущую стерень wn
    for (int i=0;i<n/2;i++){
        a[i] = a0[i]+ w*a1[i];
        a[i+n/2] = a0[i] - w*a1[i];
        if (invert){
            a[i]/=2,a[i+n/2]/=2; // на каждом шаге в рекурсии делим на 2, суммарно получается n раз
        }
        w*=wn;
    }
}
void multiply(vector<int> &a,vector<int> &b,vector<int> &res){
    vector<base> fa(a.begin(),a.end());
    vector<base> fb(b.begin(),b.end());
    size_t n =1;
    while (n<max(a.size(),b.size())) n<<=1;
    n<<=1;
    fa.resize(n),fb.resize(n);


    fft(fa,false);

    fft(fb,false);
    for (size_t i=0;i<n;i++){
        fa[i]*=fb[i];
    }
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++){
        res[i] = int(fa[i].real()+0.5);
    }
    int carry=0;
    for (size_t i=0;i<n;i++){
        res[i] +=carry;
        carry = res[i]/10;
        res[i]%=10;
    }

}

int main(){
    std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> a = {1,2,5};
    vector<int> b = {2,5};
    vector<int> res;

    multiply(a,b,res);
    for (auto i=res.rbegin();i!=res.rend();i++){
        cout<<*i<<" ";
    }
}
