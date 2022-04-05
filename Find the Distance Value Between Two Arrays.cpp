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

int low(int x, vector<int> &v)
{
    int l = 0, r = v.size() - 1, m, ans = -1;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (v[m] >= x)
            ans = m, r = m - 1;
        else
            l = m + 1;
    }
    return ans;
}

int high(int x, vector<int> &v)
{
    int l = 0, r = v.size() - 1, m, ans = -1;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (v[m] <= x)
            ans = m, l = m + 1;
        else
            r = m - 1;
    }
    return ans;
}

int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    int c = 0;
    sort(arr2.begin(), arr2.end());
    for (int i = 0; i < arr1.size(); i++)
    {
        int res = low(arr1[i], arr2);
        int res2 = high(arr1[i], arr2);
        //cout << arr1[i] << " " << arr2[res] << " " << arr2[res2] << endl;
        if ((res == -1 || (abs(arr2[res] - arr1[i]) > d)) && (res2 == -1 || (abs(arr2[res2] - arr1[i]) > d)))
            c++;
        cout << c << endl;
    }
    return c;
}
signed main()
{
    fast;
    int t = 1;
    //cin >> t;
    WL(t)
    {
        int n, m;
        cin >> n;
        vi v(n);
        cin(v, n);
        cin >> m;
        vi v2(m);
        cin(v2, m);
        cout << findTheDistanceValue(v, v2, 3) << endl;
    }
    runtime();
    return 0;
}
