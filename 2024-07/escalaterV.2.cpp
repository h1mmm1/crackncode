#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
priority_queue<int,vector<int>,greater<int>> mx[N],q;
int ans;

inline void rec(int x,int a){
	if(x==0) return;
	for(int i=ans;i>=a;i--){
		if(!mx[i].empty()){
			ans=max(ans,mx[i].top());		
		}				
	}	
	rec(x-1,a);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,t;
	cin >> n >> t;
	for(int i=1;i<=t;i++){
		int x;
		cin >> x;
		if(x==1){
			int a,b;
			cin >> a >> b;
			mx[a].push(b);
		}
		else if(x==2){
			int a;
			cin >> a;
			ans=a;
			for(int i=a;i>=0;i--){
				if(!mx[i].empty()){
					ans=max(ans,mx[i].top());		
				}
			}
			rec(2500,a);
			cout << ans << "\n";
		}
		else{
			int a,b;
			cin >> a >> b;
			while(!q.empty()) q.pop();
			while(!mx[a].empty()){
				if(mx[a].top()!=b){
					q.push(mx[a].top());
					
				}
				mx[a].pop();
//				cout << mx[a].top() << '\n';
			}
			mx[a]=q;
		}
	}
}
