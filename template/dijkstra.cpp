//dij模板（set）写法

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int y,z;
	node(int yy,int zz){y = yy,z = zz;}
};
int n,m,q;
std::vector<node> v[100001];
int dis[100001];
set < pair<int,int> > s;
inline int read(){
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x;
}
void write(int x){
    if(x > 9) write(x / 10);
    putchar((x%10) | '0');
}
void dij(int start,int to){
	memset(dis,127,sizeof(dis));
	dis[start] = 0;
	s.clear();
	for(int i=1;i<=n;i++){
		s.insert({dis[i],i});
	}
	while(!s.empty()){
		int x = s.begin() -> second;
		s.erase(s.begin());
		if((x==to)||dis[x] > 1<<30) break;
		for(auto i:v[x]){
			if(dis[x] + i.z < dis[i.y]){
				s.erase({dis[i.y],i.y});
				dis[i.y] = dis[x] + i.z;
				s.insert({dis[i.y],i.y});
			}
		}
	}
	if(dis[to] < 1 << 30) write(dis[to]) , putchar('\n');
	else putchar('-') ,putchar('1'), putchar('\n');
}
signed main()
{
	n = read(),m=read(),q=read();
	for(int i=1;i<=m;i++){
		int x,y,z;
		x=read(),y=read(),z=read();
		v[x].push_back(node(y,z));
	}
	for(int i=1;i<=q;i++){
		int a,b;
		a=read(),b=read();
		dij(a,b);
	}
	
	return 0;
}