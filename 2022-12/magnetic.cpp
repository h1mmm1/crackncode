#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int pa[N];
bool chk[N];

int find(int v){
  if(pa[v]==v) return v;
  return pa[v]=find(pa[v]);
}

void U(int a,int b){
  a=find(a);
  b=find(b);
  if(a!=b){
    pa[a]=b;
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  string s;
  cin >> n >> m >> s;
  for(int i=0;i<=n;i++){
    pa[i]=i;
  }
  for(int i=0;i<s.size();i++){
    if(s[i]=='1'){
      int id=pa[i];
      for(int j=i+1;j<=i+m;j++){
        int k=j;
        if(k>=n) k-=n;
        if(s[k]=='0' && find(k)==k){
          U(k,i);
        }
        else if(s[k]=='0' && find(k)!=k){ 
          U(k,i);  
          break;
        }
        else if(s[k]=='1') break;
      }
      for(int j=i-1;j>=i-m;j--){
        int k=j;
        if(k<0) k+=n;
        if(s[k]=='0' && find(k)==k){
          U(k,i);
        }
        else if(s[k]=='0' && find(k)!=k){ 
          U(k,i);  
          break;
        }
        else if(s[k]=='1') break;
      }
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
    int v=find(i);
    if(chk[v]==false){
      chk[v]=true;
      ans++;
//      cout << v << "\n";
    }
  }
  cout << ans;
}

