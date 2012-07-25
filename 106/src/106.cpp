#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Tuple{
	int a,b,c;
	Tuple(){}
	Tuple(int a,int b,int c){
		this->c=c;
		this->a=min(a,b);
		this->b=max(a,b);
	}
	Tuple(int m,int n){
		*this=Tuple(m*m-n*n,2*m*n,m*m+n*n);
	}

};
const bool operator<(const Tuple &a,const Tuple &b){
	return a.c<b.c;
}
int cnt=0,cnt2=0;
Tuple tuples[1000001];
Tuple tuples2[1000001];
const int MAX=1000001;

int has[2][MAX];
int ans[2][MAX+1];
void init(){
	for(int m=1;m<=1000;m++){
		for(int n=1;n<m;n++){
			if(__gcd(m,n)==1&&(m-n)%2==1){
				tuples[cnt++]=Tuple(m,n);
			}
		}
	}
	for(int i=0;i<cnt;i++){
		//cout<<tuples[i].a<<","<<tuples[i].b<<":"<<tuples[i].c<<endl;
		has[0][tuples[i].c]++;
	}
	stable_sort(tuples,tuples+cnt);
	for(int i=0;i<MAX;i++){
		for(int j=0;j<2;j++)
			ans[j][i+1]=ans[j][i]+has[j][i];
	}
}
bool ac[2000001];
int solve(int N){
	int ans=N;
	memset(ac,0,sizeof(bool)*(N+1));
	for(int i=0;;i++){
		if(tuples[i].c>N)break;
		//cout<<tuples[i].a<<","<<tuples[i].b<<","<<tuples[i].c<<endl;
		// 作業する
		for(int j=0;j<3;j++){
			int t=tuples[i].a;
			if(j==1)t=tuples[i].b;
			if(j==2)t=tuples[i].c;
			int max=N/tuples[i].c;
			//if(i<1||(t%3!=0&&t%4!=0&&t%5!=0)){
				for(int k=t;k<=max*t;k+=t){
					if(!ac[k]){
						//cout<<k<<endl;
						ac[k]=true;
						ans--;
					}
				}
			//}
		}

	}
	return ans;
}
int main() {
	init();
	int N;
	while(cin>>N){
		cout<<ans[0][N+1];
		cout<<" ";
		cout<<solve(N);
		cout<<endl;
	}
	return 0;
}
