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

int n;
vector <int> adj[N];
int f[N][2];

void dfs(int u, int p){
    f[u][0] = f[u][1] = 0;
    FOR(i, 0, SZ(adj[u]) - 1){
        int v = adj[u][i];
        if (v != p){
            dfs(v, u);
            if (f[v][0] + 1 > f[u][0]){
                f[u][1] = f[u][0];
                f[u][0] = f[v][0] + 1;
            }
            else f[u][1] = max(f[u][1], f[v][0] + 1);
        }
    }
}

void solve(){
    cin >> n;
    FOR(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    int res = 0;
    FOR(i, 1, n) res = max(res, f[i][0] + f[i][1]);
    cout << res;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
