#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=2e3+1;
ll dp[N],sum[N];
int a[N];
bool qs[N*N];

// https://open.kattis.com/problems/balanceddiet

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,q;
  cin >> n >> q;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    dp[i]=sum[i-1]*a[i]+dp[i-1];    
    sum[i]=sum[i-1]+a[i];
  }
  if(q==0) cout << dp[n];
  else{
    qs[0]=1;
    ll x=sum[n]/2;
    for(int i=1;i<=n;i++){  
      ll mn=min(x,sum[i]);
      for(int j=mn;j>=a[i];j--){
        qs[j]|=qs[j-a[i]];
      }
    }
    for(int i=x;i>=0;i--){
      if(qs[i]==1){
        cout << dp[n]-(i*(sum[n]-i));
        return 0;
      }
    }
  }
} 
