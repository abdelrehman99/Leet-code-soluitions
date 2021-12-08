#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define cin(v) for (auto &i : v) cin >> i;
#define cout(v) for (auto &i : v) cout << i << " ";
#define WL(t) while(t --)
#define S second
#define PB push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define runtime() cerr << ((double)clock() / CLOCKS_PER_SEC) << endl;
#define MP make_pair
#define llu unsigned long long
typedef long long ll;typedef long double ld;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}




vi solve()
{ 
    int n, target;
    cin >> n >> target;
    vi v(n), v2;
    FOR (i, n) cin >> v[i];
    int l = 0, r = v.size() - 1, m;
    if (v.empty())
    {
        v2.push_back(-1);
        v2.push_back(-1);
        return v2;
    }
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (v[m] == target) break;
        if (v[m] > target) r = m - 1;
        else l = m + 1;
    }
    if (v[m] != target) v2.push_back(-1), v2.push_back(-1);
    else 
    {
        int c = m;
        while (c > -1 && v[c] == target) c--;
        v2.PB(c + 1), c = m;
        while (c < v.size() && v[c] == target) c++;
        v2.push_back(c - 1);
    }
    return v2;
}




signed main(){
    fast;
    int t = 1;
    //cin >> t;
    WL(t){
    	cout(solve());
    }
    runtime();
    return 0;
}
