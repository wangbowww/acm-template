//双源最短路Floyd

#include<bits/stdc++.h>
using namespace std;
int dis[201][201];
int n,x[201],y[201];
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x[i] >> y[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return 0;
}
