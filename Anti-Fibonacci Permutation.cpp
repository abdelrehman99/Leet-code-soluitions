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


bool isfib(vl &v, ll n)
{
    for (ll i = 2; i < n; i ++)
    {
        if (v[i] == v[i - 1] + v[i - 2]) return false;
    }
    return true;
}


void solve()
{ 
    ll n;
    cin >> n;
    if (n == 3)
    {
        cout << "3 2 1" << endl;
        cout << "1 3 2" << endl;
        cout << "3 1 2" << endl;
        return;
    }
    vl v(n);
    set <vl> v2;
    for (ll i = n, j = 0; i >= 1; i--, j++)
    {
        v[j] = j + 1;
    }
    //v2.insert(v);
    //v2.insert(v);
    for (ll i = 0; i < n; i++)
    {
        for (ll k = 0; k < n - 1; k++)
        {
            swap(v[k], v[k + 1]);
            if (isfib(v, n))
            {
                v2.insert(v);
                // break;
            }
        }
        /*i %= n;
        for (ll j = n - 1; j >= 0; j--)
        {
            if (i == j) continue;
            
        } */
    }
    while (v2.size() > n) v2.erase(v2.begin());
    //cout << v2.size() << endl;
    for (auto &i : v2)
    {
        for (auto &j : i) cout << j << " ";
        cout << endl;
    }
}




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
