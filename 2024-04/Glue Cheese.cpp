#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<int,int>;
using ppi=pair<ll,pii>;
const int N=1005;
ll a[N][N];
ll dis[N][N],ans[N][N];
bool vis[N][N];
priority_queue<ppi,vector<ppi>,greater<ppi>> q;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,st,tp;
	cin >> n >> m >> st >> tp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			dis[i][j]=1e18;
		}
	}
	dis[st][tp]=0;
	q.push({dis[st][tp],{st,tp}});
	while(!q.empty()){
		int l=q.top().first;
		int x=q.top().second.first;
		int y=q.top().second.second;
		q.pop();
		if(vis[x][y]) continue;
		vis[x][y]=true;
		for(int i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(vis[xx][yy] || xx<1 || yy<1 ||xx>n || yy>m) continue;
			if(dis[xx][yy]>dis[x][y]+a[xx][yy]){
				dis[xx][yy]=dis[x][y]+a[xx][yy];
				q.push({dis[xx][yy],{xx,yy}});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << dis[i][j]+a[st][tp]+min({dis[1][1],dis[1][m],dis[n][1],dis[n][m]}) << ' ';
		}
		cout << "\n";
	}
//	cout << min({dis[1][n],dis[1][m],dis[n][1],dis[n][m]});
//	cout << "------\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout << dis[i][j] << ' ';
//		}
//		cout << "\n";
//	}	
}
/*
5 6 2 5
9 4 3 0 6 4
8 1 14 4 13 15
0 11 11 13 15 8
0 2 5 10 14 9
11 7 11 15 3 6

*/
