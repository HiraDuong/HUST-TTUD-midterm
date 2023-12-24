#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;
const int INF = 1e9 + 7;
typedef pair<int, int> pii;
int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};
int n, m, a[MAX][MAX], dist[MAX][MAX];
bool visited[MAX][MAX];
bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != 0;
}

int shortestPath()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = INF;
            visited[i][j] = false;
        }
    dist[0][0] = 0;
    queue<pii> q;
    q.push({0, 0});
    while (!q.empty())
    {
        pii u = q.front();
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            int nx = u.first + dx[i], ny = u.second + dy[i];

            if (isValid(nx, ny) && !visited[nx][ny])
            {
                dist[nx][ny] = min(dist[u.first][u.second] + a[nx][ny], dist[nx][ny]);
                q.push({nx, ny});
                visited[nx][ny] = true; 
            }
        }
    }
    return dist[n - 1][m - 1] == INF ? -1 : dist[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cout << (shortestPath()) << "\n";
    return 0;
}