#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int parent[N];
int Rank[N];

void makeSet(int u)
{
    parent[u] = u;
    Rank[u] = 0;
}

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

void Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        if (Rank[u] < Rank[v])
        {
            parent[u] = v;
        }
        else if (Rank[u] > Rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            Rank[u]++;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int k;
        cin >> n >> k;
        vector<pair<int, pair<int, int>>> e;
        for (int i = 0; i < k; i++)
        {
            int weight;
            int u, v;
            cin >> u >> v >> weight;
            e.push_back({weight, {u, v}});
        }
        cout << "ans" << endl;
        sort(e.begin(), e.end());
        for (int i = 1; i <= n; i++)
        {
            makeSet(i);
        }
        int cost = 0;
        for (int i = 0; i < e.size(); i++)
        {
            int weight = e[i].first;
            int u = e[i].second.first;
            int v = e[i].second.second;
            if (find(u) != find(v))
            {
                Union(u, v);
                cost += weight;
                cout << u << " " << v << " " << weight << endl;
            }
        }
        cout << cost << endl;
    }
}