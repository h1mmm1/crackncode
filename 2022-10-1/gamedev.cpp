#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=2e5+5;
ll a[N],b[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=a[i];
		a[i]+=a[i-1];
//		cout << a[i] << " ";
	}
//	cout << '\n';
	ll mx=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			mx=max(mx,b[r]*(r-l+1)-(a[r]-a[l-1]));
//			cout << l << ' ' <<r << ' ' << b[r]*(r-l) << ' ' << a[r]<< ' '  <<a[l-1]<< "\n";
		}
	}
	cout << mx;
}
