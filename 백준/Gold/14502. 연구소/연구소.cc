#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

struct Pos
{
    int x;
    int y;
};

int board[10][10];
int board_copy[10][10];
bool visited[10][10];

int width, height, safe;

int x[4] = {  0, 0, -1, 1 };
int y[4] = { -1, 1,  0, 0 };

queue<Pos> virus;
vector<Pos> virusPos;

void CopyGraph()
{
    memcpy(board_copy, board, sizeof(board[0]) * 10);
}

void ResetState()
{
    memset(visited, 0, sizeof(visited[0]) * 10);

    for (auto e : virusPos)
    {
        Pos pos = e;
        virus.push(pos);
        visited[pos.y][pos.x] = true;
    }
}

void BFS()
{
    while (!virus.empty())
    {
        Pos cur = virus.front();
        virus.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = cur.x + x[i];
            int ny = cur.y + y[i];

            if (nx < 0 || ny < 0 || nx >= width || ny >= height)
                continue;

            if (board_copy[ny][nx] != 0)
                continue;

            if (visited[ny][nx])
                continue;

            visited[ny][nx] = true;
            board_copy[ny][nx] = 2;
            virus.push({ nx, ny });
        }
    }

    int count = 0;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (board_copy[i][j] == 0)
                count++;
        }
    }

    safe = count <= safe ? safe : count;
}

void SearchRecursive(int count, int i, int j)
{
    if (count >= 3)
    {
        CopyGraph();
        ResetState();
        BFS();
        return;
    }
    else
    {
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (board[i][j] == 0)
                {
                    board[i][j] = 1;
                    SearchRecursive(count + 1, i, j);
                    board[i][j] = 0;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> height >> width;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] == 2)
                virusPos.push_back({ j, i });
        }
    }

    SearchRecursive(0, 0, 0);

    cout << safe;

    return 0;
}