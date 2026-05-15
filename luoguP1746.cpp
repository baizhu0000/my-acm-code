#include <bits/stdc++.h>
using namespace std;
int n;
char a[1005][1005];
int dist[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct Node
{
    int x, y;
};
int bfs(int sx, int sy, int ex, int ey)
{
    memset(dist, -1, sizeof(dist));
    queue<Node> q;
    Node start;
    start.x = sx;
    start.y = sy;
    q.push(start);
    dist[sx][sy] = 0;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.x == ex && cur.y == ey)
        {
            return dist[cur.x][cur.y];
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1 && a[nx][ny] != '1')
            {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                Node nxt;
                nxt.x = nx;
                nxt.y = ny;
                q.push(nxt);
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << bfs(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << "\n";
    return 0;
}