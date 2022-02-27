#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> gr[N];
int sub[N]; // subtree size of i
int dp[N];  // sum of subtree size of all the node in its subtree

void dfs1(int cur, int par)
{

    sub[cur] = 1;
    dp[cur] = 0;

    for (auto& nbr : gr[cur])
    {

        if (nbr != par)
        {
            dfs1(nbr, cur);

            sub[cur] += sub[nbr];
            dp[cur] += dp[nbr];
        }
    }

    dp[cur] += sub[cur];
}

int ans = 0;

void dfs2(int cur, int par)
{

    // dp values are according to as cur is the root of the tree
    ans = max(ans, dp[cur]);
    // cout << cur << " " << dp[cur] << '\n';

    for (auto& nbr : gr[cur])
    {
        
        if(nbr != par){

        // Re Rooting start

        // first detach the nbr node from cur node

        dp[cur] -= dp[nbr];
        dp[cur] -= sub[nbr];
        sub[cur] -= sub[nbr];

        // attach the cur node to next node as its subtree;

        sub[nbr] += sub[cur];
        dp[nbr] += dp[cur];
        dp[nbr] += sub[cur];

        // now call dfs on nbr

        dfs2(nbr, cur);

        // come back from nbr
        // rollback to original tree state

        // detach the cur node from nbr node

        dp[nbr] -= dp[cur];
        dp[nbr] -= sub[cur];
        sub[nbr] -= sub[cur];

        // attach nbr to cur node as its subtree;

        sub[cur] += sub[nbr];
        dp[cur] += dp[nbr];
        dp[cur] += sub[nbr];
        }
    }
}

int main()
{

// file handling
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
// online submission
#endif

    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }


    // to calculate dp[i] and sub[i];
    dfs1(1, 0);

    // to do re-rooting;
    dfs2(1, 0);

    cout << ans << '\n';

    return 0;
}