#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e3+5;
vector<pair<int,int>> g[M];
int pa[M][N],sum[M],dp[M][N];
int n,m,k,mx=0;
vector<int> p;
priority_queue<int> q;

inline int find(int st,int v){
	if(pa[st][v]==v) return v;
	return pa[st][v]=find(st,pa[st][v]);
}

inline void U(int st1,int a,int st2,int b){
	a=find(st1,a);
	b=find(st2,b);
	if(a!=b){
		pa[st1][a]=b;
	}
}

inline void rec(int st,int x,int ans){
	if(dp[st][find(st,x)]!=-1) return;
	if(st>m) return;
	int cnt=0;
	for(int i=x;i<=n;i++){
		if(find(st,x)==find(st,i)){
			cnt++;	
		} 
	}
	for(int i=x;i<=n;i++){
		if(find(st,x)==find(st,i)){
//			for(int k=1;k+st<=m;k++){
			rec(st+1,i,cnt);
//			}
			sum[st]=max(sum[st],cnt);
		} 		
	}		
	dp[st][find(st,x)]=0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			pa[i][j]=j;
		}
	}
	for(int i=1;i<=m;i++){
		int a;
		cin >> a;
		for(int j=1;j<=a;j++){
			int u,v;
			cin >> u >> v;
			if(find(i,u)!=find(i,v)){
				U(i,u,i,v);
			}
		}
	}
	int o=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(find(1,1)==find(1,i)) o++;
		}
		cout << o;
		return 0;
	}
	memset(dp,-1,sizeof dp);
	rec(1,1,0);
	long long int cnt=sum[1];
	for(int i=2;i<=m;i++){
		q.push(sum[i]);
//		cout << sum[i] << "\n";
	}
	for(int i=1;i<=k;i++){
		cnt+=q.top();
		q.pop();
	}
	cout << cnt;
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			cout << pa[i][j] << ' ';
//		}
//		cout << "\n";
//	}
}
