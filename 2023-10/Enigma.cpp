
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int up[200005];
int ans[30];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int mx=0;
	string s;
	cin >> s;
	
	for(int i=0;i<s.size();i++){
		up[i]=s[i]-'A';
	}
	for(int i=0;i<s.size();i++){
		cin >> a[i];
	}
	for(int j=1;j<=26;j++){	
		for(int i=0;i<s.size();i++){
			if(up[i]+a[i]<26){
				up[i]+=a[i];
				ans[up[i]]++;
			}
			else{
				up[i]+=a[i]-26;
				ans[up[i]]++;
			}						
		}
		for(int i=0;i<26;i++){
			mx=max(ans[i],mx);
			ans[i]=0;
		}
	}
//	for(int i=0;i<26;i++){
//		cout << ans[i] << ' ';
//	}
	cout << mx;
}

