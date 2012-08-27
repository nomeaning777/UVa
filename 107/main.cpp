#include <iostream>
#include <cmath>
using namespace std;
typedef long long lli;
lli a,b;
lli powint(lli a,lli b){
  lli res=1;
  for(int i=0;i<b;i++)res*=a;
  return res;
}
int main(){
  while(cin>>a>>b){
    if(a==0&&b==0)break;
    /*
      (n+1)^k = a
      n^k = b
      になるような、n,kが与えられた時、答えは
      SUM(0<=i<=k-1) n^i
      SUM(0<=i<=k) n^i * (n+1)^(k-i)
      で計算出来る。
    */
    if(a == 1 && b == 1){
      // k = 0
      cout << 0 << " " << 1 << endl;
    }else{
      int k;
      for(k=0;;k++){
        lli n = pow((long double)a, (long double)1.0/k)+1e-8;
        n--;
        if(powint(n,k) == b && powint(n+1,k) == a){
          // cerr << n << "," << k << endl;
          lli ans1=0,ans2=0;
          for(int i=0;i<k;i++){
            ans1+=powint(n,i);
          }
          for(int i=0;i<=k;i++){
            ans2+=powint(n,i)*powint(n+1,k-i);
          }
          cout<<ans1<<" "<<ans2<<endl;
          break;
        }
      }
    }
  }
}
