#include<bits/stdc++.h> 
#define int long long
#define endl "\n"
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
set< pair<int, int > > a;
set< pair<int, int > > ::iterator it;
signed main()
{
    sync;
    int n,h,m,q;
    cin >> n >> h >> m >> q;
    int l, r;
    a.clear();
    a.insert(make_pair(h*m,0));
    while (n--) {
        int x,y,k,z;
        cin >> x >> y >> k >> z;
        l = x*m+y;
        r = k*m+z;
        it = a.lower_bound(make_pair(l, 0));
        while (it != a.end() && r >= it->second) {
            if (it->first <= r && it->second >= l) {
                a.erase(make_pair(it->first, it->second));
            }
            else  if (it->first >= r && it->second <= l) {
                if (it->first == r && it->second < l) {
                    a.insert(make_pair(l - 1, it->second));
                }
                else if (it->second == l && it->first > r) {
                    a.insert(make_pair(it->first, r + 1));
                }
                else {
                    a.insert(make_pair(it->first, r + 1));
                    a.insert(make_pair(l - 1, it->second));
                }
                a.erase(make_pair(it->first, it->second));
            }
            else if (it->first >= l && it->second < l) {
                a.insert(make_pair(l - 1, it->second));
                a.erase(make_pair(it->first, it->second));
            }
            else if (it->first > r && it->second <= r) {
                a.insert(make_pair(it->first, r + 1));
                a.erase(make_pair(it->first, it->second));
            }
            it = a.lower_bound(make_pair(l, 0));
        }
    }
    for(int i=1;i<=q;++i){
        int x,y;
        cin >> x >> y;
        x = x*m+y;
        //如果在集合中，说明yes
        it = a.lower_bound({x,0});
        if(it->second<=x){
            cout << "Yes" << endl;
        }else cout << "No" << endl;
        
    }
    return 0;
}