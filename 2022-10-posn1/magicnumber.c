#include<stdio.h>
#include<stdbool.h>
#define __USE_MINGW_ANSI_STDIO 0
bool a[15485864];
int num[1000000];
int main(){
    //printf("asdfasdf");
    //*
  int cnt=0;
	for(int i=2;i<=15485863;i++){
    if(a[i]==false){
      num[cnt++]=i;
      for(int j=2;i*j<=15485863;j++){
        a[i*j]=true;
      }
    } 
  }
  //*/
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    int m;
    scanf("%d",&m);
    long long int x=1ll*num[m-1]*num[m-1];
    printf("%lld\n",x);
  }
  //*/
}

