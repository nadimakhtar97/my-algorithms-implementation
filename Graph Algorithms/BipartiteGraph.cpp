#include <bits/stdc++.h>

#define int long long int
#define f first
#define s second
#define pb push_back
#define MAX 1000000007
#define MOD 998244353
#define endl "\n"
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

int n, m;
vector<vector<int>> gr;
vector<bool> vis;
vector<int> color;

bool dfs(int u, int c, int par)
{   
    vis[u] = true;
    color[u] = c;

    for (auto nbr : gr[u])
    {

        if (nbr == par)
            continue;

        if (color[nbr] == 0)
        {
            if (!dfs(nbr, (color[u] ^ 3), u))
            {
                return false;
            }
        }

        if (color[nbr] == color[u])
            return false;
    }

    return true;
}

bool color_all()
{
    for (int i = 1; i < n+1; i++)
    {
        if (!vis[i])
        {
            if (!dfs(i, 1, -1))
                return false;
        }
    }
    return true;
}

int32_t main()
{

    FIO;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n >> m;

    gr.resize(n + 1);
    vis.resize(n + 1);
    color.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    bool ans = color_all();

    if (!ans)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 1; i < n + 1; i++)
        {
            cout << color[i] << " ";
        }
    }

    return 0;
}