#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos
{
    int x;
    int y;
};

int height, width;
int board[1001][1001];
bool visited[1001][1001];

int x[4] = {  0, 0, -1, 1 };
int y[4] = { -1, 1,  0, 0 };

void BFS(Pos begin)
{
    queue<Pos> q;
    board[begin.y] [begin.x] = 0;
    visited[begin.y][begin.x] = true;
    q.push(begin);

    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = cur.x + x[i];
            int ny = cur.y + y[i];

            if (nx < 0 || ny < 0 || nx >= width || ny >= height)
                continue;

            if (visited[ny][nx])
                continue;

            if (board[ny][nx] == 0)
                continue;

            visited[ny][nx] = true;
            board[ny][nx] = board[cur.y][cur.x] + 1;
            q.push({ nx, ny });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Pos target = { 0, 0 };
    cin >> height >> width;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)
                board[i][j] = -1;
            else if (board[i][j] == 2)
                target = { j, i };
        }
    }

    BFS(target);

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
            cout << board[i][j] << " ";

        cout << "\n";
    }

    return 0;
}