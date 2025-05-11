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
    f[u][1] = 1;
    FOR(i, 0, SZ(adj[u]) - 1){
        int v = adj[u][i];
        if (v != p){
            dfs(v, u);
            f[u][0] += f[v][1];
            f[u][1] += min(f[v][0], f[v][1]);
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
    cout << min(f[1][0], f[1][1]);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
