#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>

// DFS로 푸는게 편하긴하다.

using namespace std;

int familyCount;
int depth[101];

vector<int> family[101];
bool visited[101];

void BFS(int& begin, int& target)
{
    queue<int> q;
    q.push(begin);

    visited[begin] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (size_t i = 0; i < family[cur].size(); ++i)
        {
            int next = family[cur][i];

            if (visited[next])
                continue;

            depth[next] = depth[cur] + 1;
            visited[next] = true;
            q.push(next);

            if (next == target)
            {
                cout << depth[target];
                return;
            }
        }
    }

    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int count, select, target;

    cin >> familyCount;
    cin >> select >> target;
    cin >> count;

    for (int i = 0; i < count; ++i)
    {
        int src, des;
        cin >> src >> des;

        family[src].push_back(des);
        family[des].push_back(src);
    }

    BFS(select, target);

    return 0;
}