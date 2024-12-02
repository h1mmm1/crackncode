#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool b[1000005];

int find(int v){
  if(a[v]==v) return v;
  return a[v]=find(a[v]); 
}

void u(int b,int c){
  b=find(b);
  c=find(c);
  if(b!=c){
    a[b]=c;
  }
}

int main(){
   ios::sync_with_stdio(0); cin.tie(0);
   int n,cnt=0;
  cin >> n;
  for(int i=1;i<=n;i++){
    a[i]=i;
  }
  for(int i=1;i<=n;i++){
    int x;
    cin >> x;
    u(i,x);
  }
  for(int i=1;i<=n;i++){
    if(b[find(i)]==false) {
      cnt++;
      b[find(i)]=true;
    }

      
  }
  cout << cnt;
}

