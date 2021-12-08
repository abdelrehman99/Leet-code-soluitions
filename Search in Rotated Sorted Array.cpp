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




int solve()
{
    ll n, target;
    cin >> n >> target;
    vl nums(n);
    FOR (i, n) cin >> nums[i]; 
    long r = nums.size() - 1, l = 0, mid, temp;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] >= nums[0]) l = mid + 1, temp = l;
        else r = mid - 1;
    }
    ll start = temp;
    if (temp == nums.size()) start = 0; 
    cout << start << endl;
    if (nums[nums.size() - 1] >= target) l = start, r = nums.size() - 1;
    else l = 0, r = start - 1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return - 1;
}




signed main(){
    fast;
    int t = 1;
    //cin >> t;
    WL(t){
    	cout << solve() << endl;
    }
    runtime();
    return 0;
}
