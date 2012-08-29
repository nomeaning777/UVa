#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int primes[100],cnt;
int ret[100],c;
int count(int k,int p){
  int ret=0;
  while(k>0){
    ret+=k/p;
    k/=p;
  }
  return ret;
}
int main(){
  int i,j,ok;
  for(i=2;i<200;i++){
    ok=1;
    for(j=2;j<i;j++){
      if(i%j==0)ok=0;
    }
    if(ok)primes[cnt++]=i;
  }
  while(scanf("%d",&N),N){
    printf("%3d! =",N);
    c=0;
    for(i=0;;i++){
      int r=count(N,primes[i]);
      if(r==0)break;
      ret[c++]=r;
    }
    for(i=0;i<(c+14)/15;i++){
      if(i)printf("      ");
      for(j=0;j+i*15<c && j < 15;j++){
        printf("%3d",ret[j+i*15]);
      }
      printf("\n");
    }
  }
  return 0;
}
