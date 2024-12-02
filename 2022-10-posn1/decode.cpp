#include<stdio.h>
#include<string.h>
int dp[1000005][15];
int a[1000005][15];
char s[15];

int main(){
	
	int c,mod=1e9+7;
	scanf("%d%s",&c,&s);
	int x=strlen(s);
	for(int i=2;i<x;i++){
		int hs=(s[i-2]-'0')*4+(s[i-1]-'0')*2+s[i]-'0';
		dp[0][hs]++;
	}
	for(int i=0;i<=7;i++) a[0][i]=dp[0][i];
	for(int i=1;i<=1000000;i++){
		for(int j=0;j<=7;j++){
		dp[i][j]=a[i-1][j]*2;
		dp[i][j]%=mod;
		}
		if(i%2==1){
			int hs=(s[x-2]-'0')*4+(s[x-1]-'0')*2;
			dp[i][hs]++;
			hs=(s[x-1]-'0')*4+s[0]-'0';
			dp[i][hs]++;
			hs=(s[0]-'0')*2+s[1]-'0';
			dp[i][hs]++;								
		}
		else{
			int hs=(s[x-2]-'0')*4+(s[x-1]-'0')*2+1;
			dp[i][hs]++;
			hs=(s[x-1]-'0')*4+2+s[0]-'0';
			dp[i][hs]++;
			hs=4+(s[0]-'0')*2+s[1]-'0';
			dp[i][hs]++;								
		}
		for(int j=0;j<=7;j++){
			a[i][j]=dp[i][j]+a[i-1][j];
			a[i][j]%=mod;
		}
		int t=(s[x-1]-'0')*4+(s[0]-'0')*2+(s[1]-'0');
		a[i][t]++;
		t=(s[x-2]-'0')*4+(s[x-1]-'0')*2+(s[0]-'0');
		a[i][t]++;		
	}
	while(c--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<=7;i++){
			printf("%d ",dp[n][i]);
		}
		printf("\n");
	}
}
