//dij （优先队列写法）

#include<bits/stdc++.h>
using namespace std;
bool operator < (struct node a,struct node b);//化大根堆为小根堆 
struct edge{
	int v,w;
};
struct node{
	int to,road;
};
int n,m,k;
bool vis[100009];//表示i号点的最短路是否已经被确定
int dis[100009];//表示到i号点的最短路长度
vector <struct edge> g[200009]; 
int main()
{
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back((struct edge){b,c});
		g[b].push_back((struct edge){a,c});
	}
	for(int q=1;q<=k;q++){
		int t,s;
		cin >> s >> t;
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++) dis[i]=1e9+1;//初始化为无穷大
		priority_queue <struct node> Q;
		Q.push((struct node){s,0});//初始位置入队
		while(!Q.empty()){
			struct node q=Q.top();
			Q.pop();
			if(vis[q.to]) continue;
			//如果已经确定，跳过
			//因为他在队列中时就可能被其他点确定了他的最短路，这样这个取出来的信息就无用了（不是最短的）
			dis[q.to]=q.road,vis[q.to]=1;//确定最短路
			//以q.to为起点松弛
			for(int i=0;i<(int)g[q.to].size();i++){
				if(!vis[g[q.to][i].v]){
					dis[g[q.to][i].v]=min(dis[g[q.to][i].v],dis[q.to]+g[q.to][i].w);
					Q.push((struct node){g[q.to][i].v,dis[g[q.to][i].v]});
				}
			} 
		}
		if(dis[t] < 1e9) cout << dis[t] << endl;
		else cout << -1 <<endl;
	} 
	return 0;
}
bool operator < (struct node a,struct node b){
	return a.road > b.road;
}
