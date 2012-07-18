#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
int a[128][128];
int sum[128][128];
int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      sum[i+1][j+1]=-sum[i][j]+a[i][j]+sum[i+1][j]+sum[i][j+1];
    }
  }
  int ans=-999999999;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<=N;j++){
      for(int k=0;k<N;k++){
        for(int l=k+1;l<=N;l++){
          ans=max(ans,sum[j][l]-sum[i][l]-sum[j][k]+sum[i][k]);
        }
      }
    }
  }
  cout << ans << endl;
}
