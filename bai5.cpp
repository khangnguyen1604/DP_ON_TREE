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
const int MOD = 1e9 + 7;

int n, k;
vector <int> adj[N];
int col[N];
int f[N][4];

void add(int &x, int y){
    x += y;
    if (x >= MOD) x -= MOD;
}

void dfs(int u, int p){
    if (col[u] > 0) f[u][col[u]] = 1;
    else f[u][1] = f[u][2] = f[u][3] = 1;
    FOR(i, 0, SZ(adj[u]) - 1){
        int v = adj[u][i];
        if (v != p){
            dfs(v, u);
            if (col[u] > 0){
                int sum = 0;
                FOR(j, 1, 3){
                    if (j != col[u]) add(sum, f[v][j]);
                }
                f[u][col[u]] = 1LL * f[u][col[u]] * sum % MOD;
            }
            else{
                FOR(j, 1, 3){
                    int sum = 0;
                    FOR(j1, 1, 3){
                        if (j != j1) add(sum, f[v][j1]);
                    }
                    f[u][j] = 1LL * f[u][j] * sum % MOD;
                }
            }
        }
    }
}

void solve(){
    cin >> n >> k;
    FOR(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(i, 1, k){
        int u, c;
        cin >> u >> c;
        col[u] = c;
    }
    dfs(1, 0);
    int res = 0;
    FOR(i, 1, 3) add(res, f[1][i]);
    cout << res;
    cerr << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);    
    solve();
    return 0;
}
