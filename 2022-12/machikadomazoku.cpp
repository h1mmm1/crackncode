#include<bits/stdc++.h>
using namespace std;
const int N=505;
int g[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			g[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		g[a][b]=g[b][a]=c;
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	int d,cnt=0;
	cin >> d;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(g[i][j]<=d) cnt++;
		}
	}
	if(cnt==0) cout << "0/1";
	else{
		int x=(n*(n-1))/2;
		int gd=__gcd(x,cnt);
		cout << cnt/gd << "/" << x/gd; 
	}
}
