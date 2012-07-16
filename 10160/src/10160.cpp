#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <vector>
using namespace std;
int N,M;
typedef int Weight;
struct Edge{
        int src,dst;
        Weight weight;
        Edge(int f, int t, Weight c):src(f),dst(t),weight(c){}
};
struct Node:public vector<Edge>{ //頂点の情報を記録する場合
};
bool operator<(const Edge &a,const Edge &b){
        return a.weight<b.weight;
}
bool operator>(const Edge &a,const Edge &b){return b<a;}

typedef vector<Node> Graph;

typedef vector<vector<Weight> > Matrix;

#define REP(i,x)for(int i=0;i<(int)x;i++)
Matrix G;
bool input(){
	cin>>N>>M;
	if(N==0)return false;
	G=Matrix(N,vector<Weight>(N));
	REP(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a][b]=G[b][a]=1;
	}
	return true;
}

typedef long long lli;
int dfs(int n,int k,lli G[],lli cover[], int ord[], lli now, int ans,int &bound){
	if(ans >= bound) return bound;
	if(now == (1LL << n) - 1){
		return bound = ans;
	}
	if(k >= n)return bound;
	if((now | cover[k]) != (1LL << n) - 1)return bound;

	int u = ord[k];
	if((now & G[u]) == G[u]) return dfs(n, k + 1, G ,cover, ord, now, ans, bound);
	return min(dfs(n, k + 1, G ,cover, ord, now | G[u], ans + 1, bound),
			   dfs(n, k + 1, G ,cover, ord, now, ans, bound));
}
int dominating_set(const Matrix &G){
	int N = G.size();
	lli M[N];
	memset(M,0,sizeof(M));
	int cnt[N];
	REP(i, N){
		M[i] = 1LL << i;
		cnt[i] = 1;
		REP(j, N){
			if(G[i][j]){
				M[i] |= 1LL << j;
				cnt[i]++;
			}
		}
	}
	int ord[N];
	REP(i,N)ord[i]=i;
	//sort
	REP(i,N)REP(j,N-1){
		if(cnt[ord[j]] < cnt[ord[j+1]]){
			swap(ord[j], ord[j+1]);
		}
	}
	lli cover[N+1];
	cover[N]=0;
	for(int i=N-1;i>=0;i--){
		cover[i] = cover[i+1] | M[ord[i]];
	}
	int bound = N;
	return dfs(N, 0, M, cover, ord, 0, 0, bound);
}
int main() {
	while(input()){

		cout << dominating_set(G) << endl;
	}
	return 0;
}
