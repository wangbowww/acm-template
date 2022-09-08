//1-n的全排列（递归写法）

#include<stdio.h>
void A(int *a,int N);
int n;
int main()
{
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++){
		a[i]=i+1;
	}
	A(a,n);
	return 0;
}
void A(int *a,int N){
	if(N==1){
		int i;
		for(i=0;i<n;i++){
			printf("%d",a[i]);
		}
		printf("\n");
	}else{
		int i;
		for(i=0;i<N;i++){
			int temp=a[n-N];
			a[n-N]=a[n-N+i];
			a[n-N+i]=temp;
			A(a,N-1);
			temp=a[n-N];
			a[n-N]=a[n-N+i];
			a[n-N+i]=temp;
		}
	}
}
