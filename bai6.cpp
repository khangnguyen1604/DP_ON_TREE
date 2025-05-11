#define nametask ""
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(a) (int) a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

using namespace std;
typedef long long ll;
typedef pair <int, int> pi;
const int N = 1e5 + 5;

int n, k;
vector <int> adj[N];
int sz[N], cnt[N][10];
ll res = 0;

void dfs(int u, int p, int depth){
    sz[u] = 1;
    cnt[u][depth % k] = 1;
    FOR(i, 0, SZ(adj[u]) - 1){
        int v = adj[u][i];
        if (v != p){
            dfs(v, u, depth + 1);
            sz[u] += sz[v];
            FOR(j, 0, k - 1){
                FOR(j1, 0, k - 1){
                    int len = (((j + j1 - 2 * depth) % k) + k) % k;
                    int x = (k - len) % k;
                    res += x * cnt[u][j] * cnt[v][j1];
                }
            }
            FOR(j, 0, k - 1) cnt[u][j] += cnt[v][j];
        }
    }
    res += sz[u] * (n - sz[u]);
}

void solve(){
    cin >> n >> k;
    FOR(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0, 0);
    cout << (res / k);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);    
    solve();
    return 0;
}
