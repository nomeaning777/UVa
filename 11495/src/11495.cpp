#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> a;
int mergecount(vector<int> &a) {
	int count = 0;
	int n = a.size();
	if (n > 1) {
		vector<int> b(a.begin(), a.begin() + n/2);
		vector<int> c(a.begin() + n/2, a.end());
		count += mergecount(b)%2;
		count += mergecount(c)%2;
		for (int i = 0, j = 0, k = 0; i < n; ++i)
			if (k == c.size())       a[i] = b[j++];
			else if (j == b.size())  a[i] = c[k++];
			else if (b[j] <= c[k])   a[i] = b[j++];
			else                   { a[i] = c[k++]; count += (n/2 - j)%2; }
	}
	return count%2;
}
int main() {
	while(scanf("%d",&n),n){
		a=vector<int>(n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		if(mergecount(a)){
			puts("Marcelo");
		}else{
			puts("Carlos");
		}
	}
	return 0;
}
