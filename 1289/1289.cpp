#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define REP(i,x)for(int i=0;i<(int)x;i++)
typedef vector<int> Array;
vector<Array> plates;
vector<int> cntPlates; // ある高さにあるプレートの数
vector<Array> hasH; // あるプレートがある高さを含んでいるか
vector<Array> hasI; // ある高さにあるプレートの種類
int H; // 高さ

// 入力 計算量はO(N^3)
bool input(){
	int n;
	if(!(cin>>n))return false;
	plates=vector<Array>(n);
	vector<int> hs;
	REP(i,n){
		int k;
		cin>>k;
		int t;
		REP(j,k){
			cin>>t;
			if(plates[i].empty()==false&&plates[i].back()==t)continue;
			plates[i].push_back(t);
			hs.push_back(t);
		}
	}
	sort(hs.begin(),hs.end());
	hs.erase(unique(hs.begin(),hs.end()),hs.end());
	REP(i,n){
		REP(j,plates[i].size()){
			plates[i][j]=lower_bound(hs.begin(), hs.end(), plates[i][j])-hs.begin();
		}
	}
	H=hs.size();
	hasH = vector<Array>(n);
	REP(i,n){
		hasH[i] = Array(H+1);
		REP(j,plates[i].size()){
			hasH[i][plates[i][j]]=1;
		}
	}
	cntPlates=vector<int>(H+1);
	hasI=vector<Array>(H+1);
	REP(i,H+1){
		REP(j,n){
			if(hasH[j][i]){
				cntPlates[i]++;
				hasI[i].push_back(j);
			}
		}
	}
	return true;
}
int dp[52][2502];
// 一回毎の計算量はO(N)
// 各種類の個数をxiとする
// 内部ループがxiで、
// DPテーブルの利用量はO(sum(xi)*N) = O(N^2) 均等にある場合xi=Nでこれが最悪ケースなのでは？
// 全体の計算量はO(N^3)
int dfs(int back,int h){
	if(h==H)return 0;
	// back=plates.size();
	if(dp[back][h]>=0)return dp[back][h];
	// 同じ高さが何枚あるか
	int cntSplit=0, cntStack=0, ret=99999999;
	REP(k,hasI[h].size()){
		int i=hasI[h][k];
		if(i==back)continue;
		if(hasH[i][h]){
			cntStack++;
			// 分割しないといけない場合最後はその数以外
			if(plates[i].back() == h)continue;
			cntSplit++;
		}
	}
	// 次にどれを選ぶか
	REP(k,hasI[h].size()){
		int i=hasI[h][k];
		if(i==back)continue;
		if(hasH[i][h]){
			// 出来るだけ進める
			int nh=h+1;
			while(cntPlates[nh]==1&&hasH[i][nh])nh++;
			int d=0; // 選択した数の分割が不要かどうか
			if(plates[i].back() == nh-1 && nh-1 != h) d = -1;
			if(plates[i].back() == nh && cntPlates[nh]>1) d = -1;
			ret=min(ret, dfs(i,nh) + cntSplit + cntStack + d);
		}
	}
	return dp[back][h]=ret;
}

void solve(){
	memset(dp,-1,sizeof(dp));
	cout<< dfs(plates.size(),0) - 1 <<endl;
}
int main() {
	for(int testCase=1;input();testCase++){
		cout<<"Case "<<testCase<<": ";
		solve();
	}
	return 0;
}
