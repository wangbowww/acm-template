//逛画展（尺取法）

#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int b[2001];
int main()
{
	int n,m;
	int l=1,r=1;
	int anslen=1000002;
	int keyl=l,keyr=r,cnt=1;
	cin >> n >> m;
	for(int i=1;i<=m;i++) b[i]=0;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	b[a[1]]=1;
	while(l<=r&&r<=n){
		if(cnt==m){
			if(anslen>r-l+1){
				anslen=min(anslen,r-l+1);
				keyl=l;
				keyr=r;
			}
			b[a[l]]--;
			if(b[a[l]]==0) cnt--; 
			l++;
		}else{
			r++;
			b[a[r]]++;
			if(b[a[r]]==1) cnt++;
		}
	}
	printf("%d %d",keyl,keyr);
	return 0;
}
