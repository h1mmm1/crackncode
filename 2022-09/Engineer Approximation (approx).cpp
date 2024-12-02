#include<bits/stdc++.h>
using namespace std;
int a[1000005];

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
   int n,r,p;
   cin >> n >> r >> p;
  for(int i=1;i<=n;i++){
    a[i]=i;
  }
  for(int i=1;i<=r;i++){
    int b,c;
    cin >> b >> c;
    u(b,c);
  }
  for(int i=1;i<=p;i++){
    int b,c;
    cin >>  b >> c;
    if(find(b)==find(c)) cout << "Y" << "\n";
    else cout << "N" << "\n";
  }
}

//DSU

/*
spacegoat
https://www.hackerrank.com/contests/crack-n-code-january-2022/challenges/scapegoat


A
https://crackncode.contest.codeforces.com/group/rn8uJP8lA7/contest/412635
*/

