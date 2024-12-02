#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pi=pair<int,int>;
using pii=pair<pair<int,bool>,pi>;
const int N=1e6+1;
int pa[N],sz[N],chk[N];
vector<pii> p;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int find(int x){
  if(pa[x]==x) return x;
  return pa[x]=find(pa[x]);
}

void U(int a,int b){
  a=find(a);
  b=find(b);
  if(a!=b){
    if(sz[a]<sz[b]) swap(a,b);
    pa[b]=a;
    sz[a]+=sz[b];
  }
}

//https://cp-algorithms.com/data_structures/disjoint_set_union.html

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,k;
  cin >> n >> m >> k;
  int a[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
      p.push_back({{a[i][j],true},{i,j}});
      if(k!=0) p.push_back({{a[i][j]+k,false},{i,j}});      
    }
  }
  for(int i=0;i<n*m;i++) pa[i]=i,sz[i]=1;
  
  sort(p.begin(),p.end(),greater<pii>());
  ll mx=0,it=0;
  for(auto e:p){
    ll l=e.first.first;
    bool ok=e.first.second;
    int x=e.second.first;
    int y=e.second.second;
    if(ok==true){
	    for(int i=0;i<4;i++){
	      int xx=x+dx[i];
	      int yy=y+dy[i];
	      if(xx<0 || yy<0 || xx>=n || yy>=m) continue;
	      if(a[xx][yy]>=l){
	        U(x*m+y,xx*m+yy);
	      }
	    }
	    int p=find(x*m+y);
	    ll s=sz[p];
	    mx=max(mx,s*l);	
//		cout << x << ' ' << y << ' ' << s*l << " false\n";	    	
	}
	else{
		ll sum=0;
		for(int i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
	        if(xx<0 || yy<0 || xx>=n || yy>=m) continue;
	        if(a[xx][yy]>=l){
		        int p=find(xx*m+yy);
				if(chk[p]==it) continue;
				sum+=sz[p];
				chk[p]=it;
//				cout << sz[p] << ' ';       	
			}
		}
		mx=max(mx,(sum+1)*l);
//		cout << x << ' ' << y << ' ' << sum*l << " true" << "\n";
	}
	it++;
  }
  cout << mx;
}
