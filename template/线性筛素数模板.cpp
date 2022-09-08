//欧拉筛素数

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e8+1;
bool isprime[maxn];
int prime[maxn];
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	memset(isprime,1,sizeof(isprime));
	isprime[1]=0;
	for(int i=2;i<=n;i++){
		if(isprime[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			isprime[i*prime[j]]=0;
			if(i%prime[j]==0) break;
		} 
	}
	return 0;
}
