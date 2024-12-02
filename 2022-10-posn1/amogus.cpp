#define __USE_MINGW_ANSI_STDIO 0
#include<stdio.h>
#include<string.h>
char a[10000][100];
void draw1(int n,int x,int y){
	for(int i=1;i<=n/4+1;i++){
		for(int j=1;j<=n/2+1;j++){
			if(i+j>=n/4+2 && j-i<=n/4) a[i+x][j+y]='#';
		}
	}
}
void draw2(int n,int x,int y){
	for(int i=1;i<=n/4+1;i++){
		for(int j=1;j<=n/2+1;j++){
			if(i+j>=n/4+2 && j-i<=n/4+1) a[i+x][j+y]='#';
		}
	}
}
void tri(int n,int x,int y){
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=n;j++){
			if(i<=j && j+i<=n-1) a[i+x][j+y]='#';
		}
	}
}
void print(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	
	int c;
	scanf("%d",&c);
	while(c--){
		memset(a,'.',sizeof a);
		int n;
		scanf("%d",&n);
		if(n%4==1){
			draw1(n,0,0);
			draw1(n,0,n/2);
			tri(n,n/4+1,1);
			print(3*n/4+1,n);
		}
		else{
			draw2(n,0,0);
			draw2(n,0,n/2);
			tri(n,n/4+1,1);
			print(3*n/4,n);
		}
	}
}
