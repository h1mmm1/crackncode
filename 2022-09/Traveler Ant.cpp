#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int d0[N];
int u0[N];
int d1[N];
int u1[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int mod=1e9+7;
  u0[1]=1;
  d1[1]=2;
  for(int i=2;i<N;i++){
    u0[i]=(d1[i-1])%mod;
    d1[i]=((d0[i-1]*2)%mod+d1[i-1])%mod;
    d0[i]=(u1[i-1])%mod;
    u1[i]=((u0[i-1]*2)%mod+u1[i-1])%mod;

  }
  int q;
  cin >> q;
  while(q--){
    int n;
    cin >> n;
    cout << (u0[n]+u1[n])%mod << "\n";
  }
}


