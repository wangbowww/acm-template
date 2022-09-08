//没有上司的舞会（树形dp模板题）

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int mod = 1000000007;
int n,a[6003];
int dp[6003][2];
vector<int>v[6003];
bool vis[6003];
void dfs(int i){ //dfs(i)表示确定以i为根的子树的最大快乐值，即确定dp[i][0]和dp[i][1];
    dp[i][1] = a[i];
    for(auto j:v[i]){ //扫一遍儿子结点
        dfs(j);       //先确定儿子结点
        dp[i][0] += max(dp[j][0],dp[j][1]); //用儿子结点更新当前结点
        dp[i][1] += dp[j][0];
    }
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){cin >>a[i];}
    for(int i=1;i<=n-1;i++){
        int l,k;
        cin >> l >> k;
        v[k].push_back(l);
        vis[l] = true;
    }
    int root=0;
    for(int i=1;i<=n;i++) if(!vis[i]) root = i;
    dfs(root);
    cout << max(dp[root][0],dp[root][1]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}