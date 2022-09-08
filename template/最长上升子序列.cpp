//最长上升子序列nlogn

#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009];
int ans[100009];
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(ans[cnt-1]<a[i]){
			ans[cnt] = a[i];
			cnt++;
		}else{
			int l = 1,r = cnt-1,pot=0;
			while(l<=r){
				int mid = (l+r)/2;
				if(ans[mid]>=a[i]){
					pot = mid;
					r = mid-1;
				}else l = mid+1;
			}
			ans[pot] = a[i];
		}
	}
	cout << cnt-1 << endl;
	return 0;
}