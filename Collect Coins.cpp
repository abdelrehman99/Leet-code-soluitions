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

void solve()
{
    ll n, k;
    cin >> n >> k;
    vl pos, neg;
    ll idx = 0, jdx = 0, mn = INT_MAX;
    FOR (i, n)
    {
        ll x;
        cin >> x;
        if (x < 0) neg.PB(abs(x)), idx++;
        else pos.PB(x), jdx++;
    }
    neg.resize(idx);
    pos.resize(jdx);
    sort(all(pos));
    sort(all(neg));
    if (jdx == 0)
    {
        cout << neg[k - 1] << endl;
        ret;
    }
    else if (idx == 0)
    {
        cout << pos[k - 1] << endl;
        ret;
    }
    /* FOR (i, idx) cout << neg[i] << " ";
    cout << endl;
    FOR(i, jdx) cout << pos[i] << " ";
    cout << endl; */
    if (idx >= k) mn = min(mn, neg[k - 1]);
    if (jdx >= k) mn = min(mn, pos[k - 1]);
    mn = min(mn, (2 * min(pos[jdx - 1], neg[idx - 1])) + max(pos[jdx - 1], neg[idx - 1]));
    //idx--, jdx--;
    //cout << mn << endl;
    //cout << idx << " " << jdx << endl;
    //if (neg.size() > pos.size()) swap(neg, pos);
    /* FOR(i, idx)
        cout << neg[i] << " ";
    cout << endl;
    FOR(i, jdx)
        cout << pos[i] << " ";
    cout << endl; */
    ll l = min(k - 1, ((ll)pos.size()) - 1), r = k - l - 2;
    idx = pos.size(), jdx = neg.size();
    while (l + r + 2 <= k && (0 <= l && jdx > r))
    {
        mn = min(mn, (2 * min(pos[l], neg[r])) + max(pos[l], neg[r]));
        l--, r++;
        //cout << mn << endl;
    }
    l = min(k - 1, ((ll)neg.size()) - 1), r = k - l - 2;
    idx = neg.size(), jdx = pos.size();
    while (l + r + 2 <= k && (0 <= l && jdx > r))
    {
        //cout << l << " " << r << " " << mn << endl;
        mn = min(mn, (2 * min(pos[r], neg[l])) + max(pos[r], neg[l]));
        l--, r++;
    }
    //cout << l << " " << r << endl;
    //cout << pos[l] << " " << neg[r] << endl;
    //mn = min(mn, (2 * min(pos[l], neg[r])) + max(pos[l], neg[r]));
    cout << mn << endl;
}

signed main()
{
    fast;
    int t = 1;
    //cin >> t;
    WL(t)
    {
        solve();
    }
    runtime();
    return 0;
}
