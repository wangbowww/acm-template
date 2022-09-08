//树状数组

#include<bits/stdc++.h>
using namespace std;
int a[500009],n,m;//a为树状数组 原数组下标为1-n
int lowbit(int x){
	return x & (-x);
} 
void revise(int x,int y){//原数组x位加上y
	for(int i=x;i<=n;i+=lowbit(i)){
		a[i] += y;
	}
}
int question(int x){// 1-x的前缀和
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i)){
		sum += a[i];
	} 
	return sum;
}
int main()
{
	return 0;
}
