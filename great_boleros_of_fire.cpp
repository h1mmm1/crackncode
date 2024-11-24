#include<bits/stdc++.h>
using namespace std;
const int N=10,M=1e5+5;
int a[M],dp[N][M];

bool chk(int i,int l){
//	cout << i << ' ' << l << "\n";
	for(int j=1;j<=7;j++){
		if(dp[j][l]-dp[j][i-1]<a[j]) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,l=1,ans=1e9;
	string s;
	cin >> n>> s;
	for(int i=1;i<=n;i++){
		dp[s[i-1]-'a'+1][i]++;
		for(int j=1;j<=7;j++){
			dp[j][i]+=dp[j][i-1];
		}
	}
//	for(int i=1;i<=7;i++){
//		for(int j=1;j<=n;j++){
//			cout << dp[i][j] << ' ';
//		}
//		cout << "\n"
//	}
	int sum=0;
	for(int i=1;i<=7;i++){
		cin >> a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		while(l<=n && !chk(i,l)) l++;
		if(chk(i,l)){
			ans=min(ans,l-i+1-sum);
			
		}
//		cout << i << " " << l << "\n";
	}
	cout << ans;
}
