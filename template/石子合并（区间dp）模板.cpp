//区间dp

#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[501];
int dp[501][501];
int s[501];
signed main()
{
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i] = s[i-1] + a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = 1e9;
		}
	}
	for(int i=1;i<=n;i++){
		dp[i][i] = 0;
	}
	for(int len=0;len<n;len++){    //枚举区间长度
		for(int i=1;i<=n-len;i++){  //枚举左端点
			int j = i + len;        //右端点
			for(int k=i;k<j;k++){
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + s[j]-s[i-1]);
			}
		}
	}
	printf("%lld",dp[1][n]);
	return 0;
}