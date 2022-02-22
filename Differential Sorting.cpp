#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define cin(v) for (auto &i : v) cin >> i;
#define cout(v) for (auto &i : v) cout >> i;
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




void solve()
{ 
    ll n;
    cin >> n;
    vl v(n + 1);
    bool flag = false;
    for (ll i = 1; i <= n; i++) cin >> v[i];
    for (ll i = 1; i < n; i++)
    {
        if (v[i] > v[i + 1])
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << 0 << endl;
        return;
    }
    if (v[n - 1] > v[n] || v[n - 1] < v[n - 1] - v[n])
    {
        cout << -1 << endl;
        return;
    }
    cout << n - 2 << endl;
    for (ll i = 1; i <= n - 2; i++)
    {
        cout << i << " " << n - 1 << " " << n << endl;
    }
    /*cout << n - 2 << endl;
    vector < pair <ll, pair <ll, ll> > > v3;
    for (ll i = n - 2; i > 0; i--)
    {
        if (i < n - 1 && v[i] > mn - mx)
        {
            v3.PB({i, {mni, mxi}});
            //cout << i << " " << mni << " " << mxi << endl;
        }
        if (v[i] < mn && i < mxi) mn = v[i], mni = i;
        else if (v[i] > mx && i > mni) mx = v[i], mxi = i;
    }
    cout << v3.size() << endl;
    for (auto &i : v3)
    {
        cout << i.F << " " << i.S.F << " " << i.S.S << endl;
    }
    cout << 1 << " " << mni << " " << mxi << endl; */
}

/* 5
1 6 7
2 6 7
3 6 7
4 6 7
5 6 7
*/


signed main(){
    fast;
    int t = 1;
    cin >> t;
    WL(t){
    	solve();
    }
    runtime();
    return 0;
}
