#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX_SIZE = 100001;

int curIndex, targetIndex;
vector<bool> visited(MAX_SIZE);

void BFS(int begin)
{
    visited[begin] = true;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0, begin });

    while (!q.empty())
    {
        int acc = q.top().first;
        int cur = q.top().second;
        q.pop();

        if (cur == targetIndex)
        {
            cout << acc;
            return;
        }

        if (cur * 2 < MAX_SIZE && !visited[cur * 2])
        {
            visited[cur * 2] = true;
            q.push({acc,  cur * 2 });
        }

        if (cur + 1 < MAX_SIZE && !visited[cur + 1])
        {
            visited[cur + 1] = true;
            q.push({ acc + 1, cur + 1 });
        }
        
        if (cur - 1 >= 0 && !visited[cur - 1])
        {
            visited[cur - 1] = true;
            q.push({ acc + 1, cur - 1 });
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> curIndex >> targetIndex;
    BFS(curIndex);

    return 0;
}