#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define F first
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
#define cin(v, n)                    \
    for (int i = 0; i < (int)n; i++) \
        cin >> v[i];
#define cout(v, n)                   \
    for (int i = 0; i < (int)n; i++) \
        cout << v[i] << (i == n - 1 ? "\n" : " ");
#define WL(t) while (t--)
#define S second
#define PB push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define runtime() cerr << ((double)clock() / CLOCKS_PER_SEC) << endl;
#define MP make_pair
#define llu unsigned long long
#define ret return
#define endl "\n"
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

ll n;
vector<ll> dp;

ll sol(ll x, vector<int> &v)
{
    if (x >= n)
        return 0;
    if (dp[x] != -1)
        return dp[x];
    dp[x] = v[x] + sol(x + 2, v);
    dp[x] = min(sol(x + 1, v) + v[x], dp[x]);
    return dp[x];
}

ll solve(vl &v)
{
    dp.resize(n + 10);
    dp[n] = v[n - 1];
    for (int i = n - 1; i >= 1; i--)
    {
        dp[i] = v[i - 1] + min(dp[i + 1], (i + 2 > n ? 0 : dp[i + 2]));
    }
    ret min(dp[1], dp[2]);
}

signed main()
{
    fast;
    int t = 1;
    // cin >> t;
    WL(t)
    {
        cin >> n;
        vl v(n);
        cin(v, n);
        cout << solve(v);
    }
    runtime();
    return 0;
}
