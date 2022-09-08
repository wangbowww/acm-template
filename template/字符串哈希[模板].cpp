//字符串hash
//s1 和 s11     s2 和 s22   是双模hash   且包括正反hash
#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n,q;
int base1 = 31,base2 = 137;
int p1 = 1e9 + 7 , p2 = 9999971;
int s1[1000009],s2[1000009],s11[1000009],s22[1000009];
int po1[1000009],po2[1000009];
int calc1(int l,int r){
    return (s1[r] - s1[l-1]*po1[r-l+1]%p1 + p1) % p1;
}
int calc2(int l,int r){
    return (s2[r] - s2[l-1]*po2[r-l+1]%p2 + p2) % p2;
}
int calc11(int l,int r){
    return (s11[n-l+1] - s11[n-r]*po1[r-l+1]%p1 + p1) % p1;
}
int calc22(int l,int r){
    return (s22[n-l+1] - s22[n-r]*po2[r-l+1]%p2 + p2) % p2;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin >> n >> q;
    string s=" ";
    string ssssss;
    cin >> ssssss;
    s += ssssss;
    po1[0] = 1;
    po2[0] = 1;
    for(int i=1;i<=n;i++){
        po1[i] = po1[i-1]*base1 % p1;
        po2[i] = po2[i-1]*base2 % p2;
    }
    for(int i=1;i<=n;i++){
        s1[i] = (s1[i-1]*base1 + (s[i]-'a') ) % p1;
        s2[i] = (s2[i-1]*base2 + (s[i]-'a') ) % p2;
        s11[i] = (s11[i-1]*base1 + (s[n-i+1]-'a') ) % p1;
        s22[i] = (s22[i-1]*base2 + (s[n-i+1]-'a') ) % p2;
    }
    return 0;
}