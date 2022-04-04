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

struct ListNode
{
    int data;
    ListNode *next;
};

class List
{
    // Head pointer
    public : ListNode *head;

public:
    // default constructor. Initializing head pointer
    List()
    {
        head = NULL;
    }

    // inserting elements (At start of the list)
    void insert(int val)
    {
        // make a new node
        ListNode *new_node = new ListNode;
        new_node->data = val;
        new_node->next = NULL;

        // If list is empty, make the new node, the head
        if (head == NULL)
            head = new_node;
        // else, make the new_node the head and its next, the previous
        // head
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }

    void display()
    {
        ListNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int e = 1;
ListNode *i = NULL;

void solve(ListNode *head, int k, int s)
{
    if (head == NULL)
    {
        return;
    }   
    if (s == k)
        i = head;
    solve(head->next, k, s + 1);
    //cout << e << endl;
    if (e == k)
    {
        //cout << e << endl;
        int temp = i->data;
        i->data = head->data;
        head->data = temp;
    }
    e++;
}

ListNode *swapNodes(ListNode *head, int k)
{
    solve(head, k, 1);
    return head;
}

signed main()
{
    fast;
    int t = 1;
    //cin >> t;
    WL(t)
    {
        List n;
        n.insert(100);
        n.insert(90);
        n.display();
        ListNode *p = swapNodes(n.head, 2);
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    runtime();
    return 0;
}
