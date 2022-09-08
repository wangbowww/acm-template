#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ri register int
using namespace std;

const int maxn = 300010;
int n, m, tot, cnt[maxn], len[maxn], fail[maxn], last, son[maxn][27], cur;
string s;
int sig[maxn];
long long ans;
//��ӽڵ� 
inline int new_node(ri x)
{
	//����len��cnt 
	len[tot] = x; cnt[tot] = 0;
	return tot++;
}
//�ҵ����׺�ڵ� 
inline int get_fail(ri x, ri n)
{
	while(s[n-len[x]-1] != s[n]) x = fail[x];
	return x;
}
//
inline void init()
{
	int len=0;
	scanf("%d",&n);
	s = " ";
	string ss;
	cin >> ss;
	s += ss;
	//��ʼ���������ڵ� 
	new_node(0); new_node(-1);
	fail[0] = 1; last = 0;
}

int main()
{
	init();
	for(ri i=1;i<=n;i++){
		ri x = s[i] - 'a';
		cur = get_fail(last, i);//�ҵ����׺���Ĵ� 
		if(!son[cur][x]){//û�д˻��Ĵ� 
			ri nw = new_node(len[cur]+2);
			fail[nw] = son[get_fail(fail[cur],i)][x];
			son[cur][x] = nw;
		}
		last = son[cur][x];
		cnt[last]++;
		sig[last] = x;
	}
	for(int i=tot-1;i>=0;i--) cnt[fail[i]] += cnt[i];
	//���������cnt[i]��ʾi�ڵ�����Ӵ����ֵĴ��� 
	int cntk=0,cntf=0,cntc=0;
	for(int i=2;i<tot;i++) {
		if('k'-'a' == sig[i]){
			cntk+=cnt[i];
		}else if('f'-'a'==sig[i]){
			cntf+=cnt[i];
		}else if('c'-'a'==sig[i]){
			cntc+=cnt[i];
		}
	}
	cout<< cntk << " " << cntf << " " << cntc << endl;
	return 0;
}
