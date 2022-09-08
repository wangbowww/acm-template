//数据离散化模板

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[5];
	int b[5];
	int temp[5];
	for(int i=0;i<5;i++){
		cin >> a[i];
		temp[i]=a[i];
	}
	sort(temp,temp+5);
	int len=unique(temp,temp+5)-temp;
	for(int i=0;i<5;i++){
		b[i]=lower_bound(temp,temp+len,a[i]+1)-temp;
	}
	for(int i=0;i<5;i++) cout << b[i] << " ";
	return 0;
} 
