//多重背包（二进制分解）

#include<bits/stdc++.h>
using namespace std;
int a[2001],b[2001],c[2001];
int N,n=1,m;
int v[26001],w[26001];
int dp[2001];
int main()
{
	cin >> N >> m;
	for(int i=1;i<=N;i++){
		cin >> a[i] >> b[i] >> c[i];
	} 
	for(int i=1;i<=N;i++){
		int temp = c[i];
		int s = 1;
		while(temp>s){
			v[n] = s*a[i] , w[n] = s*b[i];
			n++;
			temp -= s;
			s *= 2;
		}
		if(temp>0){
			v[n] = temp*a[i] , w[n] = temp*b[i];
			n++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=v[i];j--){
			dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	cout << dp[m];
	return 0;
} 