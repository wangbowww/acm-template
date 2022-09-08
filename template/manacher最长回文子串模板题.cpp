//马拉车求最长回文子串

#include<bits/stdc++.h>
using namespace std;
int n;
int c[100001];
int a[200009];
int cnt[200009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=2*n+1;i++){
		if(i%2==0){
			a[i] = c[i/2];
		}else a[i] = 1001;
	}
	int maxr=0,pos=0;
	a[0] = 1002;
	for(int i=1;i<=2*n+1;i++){
		if(maxr > i){
			cnt[i] = min(cnt[2*pos-i],maxr - i);
		}else cnt[i] = 1;
		while(a[i-cnt[i]]==a[i+cnt[i]]) cnt[i]++;
		if(cnt[i]>maxr-pos){
			maxr = i+cnt[i];
			pos = i;
		}
	}
	cout << maxr - pos - 1<< endl;
	return 0;
}