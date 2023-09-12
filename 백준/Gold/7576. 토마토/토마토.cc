#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

struct Pos
{
    int x;
    int y;
    
    Pos() : x(0), y(0) {};
    Pos(int x, int y) : x(x), y(y) {};
};

int width, height;
int board[1001][1001];
bool visited[1001][1001];

int x[4] = {  0, 0, -1, 1 };
int y[4] = { -1, 1,  0, 0 };

int days;

queue<Pos> q;
void bfs()
{
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

            if (board[ny][nx] == -1)
                continue;

            visited[ny][nx] = true;
            board[ny][nx] = board[cur.y][cur.x] + 1;
            days = max(board[ny][nx], days);
            q.push({ nx, ny });
        }
    }

    days--;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> width >> height;

    bool check = true;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)
            {
                visited[i][j] = true;
                q.push(Pos(j, i));
            }
            else if (board[i][j] == 0)
            {
                check = false;
            }
        }
    }

    if (check)
    {
        cout << 0;
    }
    else
    {
        bfs();

        bool valied = true;
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (board[i][j] == 0)
                {
                    valied = false;
                    break;
                }
            }
        }

        if (valied)
            cout << days;
        else
            cout << -1;
    }

    return 0;
}
