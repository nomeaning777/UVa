#include <iostream>
using namespace std;
long long H(int n){

      long long res = 0;
      int min=0;
     for( int i = 1; (long long)i*i <= n; i++ ){
            res = (res + n/i);
            min=n/i;
      }
     int back=n;
     for(int i=1;i<min;i++){
    	 res+=(long long)(i)*(back-n/(i+1));
    	 back=n/(i+1);
     }
     return res;

}
int main() {
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cout<<H(n)<<endl;
	}
	return 0;
}
