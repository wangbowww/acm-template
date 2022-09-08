//字符串匹配KMP

#include<bits/stdc++.h>
using namespace std;
int NEXT[1000009];
void get_next(char a[],int len){
	for(int i=1,j=0;i<len;i++){
		while(j&&a[i]!=a[j]) j=NEXT[j-1];
		if(a[i]==a[j]) j++;
		NEXT[i]=j;
	}
}
void KMP(char s[],char ss[]){
	int len1=strlen(s),len2=strlen(ss);
	get_next(ss,len2);
	int j=0;
	for(int i=0;i<len1;i++){
		while(j&&s[i]!=ss[j]) j=NEXT[j-1];
		if(s[i]==ss[j]) j++;
		if(j==len2){
			//match here
		}
	}
} 
int main()
{
	char c[1000006],d[1000006];
	cin >> c >> d;
	KMP(c,d);
	for(int i=0;i<strlen(d);i++){
		cout << NEXT[i] << " ";
	}
	return 0;
}
