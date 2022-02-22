#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define F first
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
#define cin(v)        \
    for (auto &i : v) \
        cin >> i;
#define cout(v)       \
    for (auto &i : v) \
        cout >> i;
#define WL(t) while (t--)
#define S second
#define PB push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define runtime() cerr << ((double)clock() / CLOCKS_PER_SEC) << endl;
#define MP make_pair
#define llu unsigned long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const ll mod = 1e9 + 7, N = 2e6 + 7, M = 2e6 + 7, INF = INT_MAX / 10;
ll powe(ll x, ll y)
{
    x = x % mod, y = y % (mod - 1);
    ll ans = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            ans = (1ll * x * ans) % mod;
        }
        y >>= 1;
        x = (1ll * x * x) % mod;
    }
    return ans;
}

bool check(vl &v, map<ll, ll> &mp, ll n)
{
    FOR(i, n)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (mp[abs(v[i] - v[j])] == 0)
                return false;
        }
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    vl v(300);
    map<ll, ll> mp;
    FOR(i, n)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    // for (auto &i : v) cout << i << " ";
    FOR(i, n)
    {
        for (ll j = 0; j < n; j++)
        {
            if (mp[abs(v[i] - v[j])] || i == j)
                continue;
            // cout << v[i] << " " << v[j] << endl;
            v[n++] = abs(v[i] - v[j]);
            mp[abs(v[i] - v[j])]++;
            bool f = check(v, mp, n);
            if (n == 300 && !f)
            {
                cout << "NO" << endl;
                return;
            }
            if (f)
            {
                // cout << v[i] << " " << v[j] << endl;
                break;
            }
        }
    }
    // cout << v.size() << endl;
    cout << "YES" << endl;
    cout << n << endl;
    FOR(i, n)
        cout << v[i] << " ";
    cout << endl;
}

signed main()
{
    fast;
    int t = 1;
    cin >> t;
    WL(t)
    {
        solve();
    }
    runtime();
    return 0;
}