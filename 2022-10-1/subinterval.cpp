#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=a[i-1];
	}
	while(m--){
		int l,r;
		long long int ans=0;
		cin >> l >> r;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				ans+=a[j]-a[i-1];
//				cout << i << ' ' << j << "\n";
			}
		}
		cout << ans << "\n";
	}
}
