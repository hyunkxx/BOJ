#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
    int ID;
    int cost;

    Node() 
        : ID(0), cost(0) {};

    Node(int ID, int cost) 
        : ID(ID), cost(cost) {};

    bool operator()(const Node& lhs, const Node& rhs)
    {
        return lhs.cost > rhs.cost;
    }
};

vector<Node> graph[801];
vector<int> dist(801, INT_MAX);
int checkPoint[2]; // 체크 포인트
bool valied;

int PathFinder(Node begin, int end)
{
    fill(dist.begin(), dist.end(), INT_MAX);

    priority_queue<Node, vector<Node>, Node> q;
    q.push(begin);

    dist[begin.ID] = 0;

    while (!q.empty())
    {
        Node cur = q.top();
        q.pop();

        for (size_t i = 0; i < graph[cur.ID].size(); ++i)
        {
            Node nextNode = graph[cur.ID][i];
            int cost = nextNode.cost + cur.cost;

            if (dist[nextNode.ID] > cost)
            {
                nextNode.cost = cost;
                dist[nextNode.ID] = cost;
                q.push(nextNode);
            }
        }
    }

    if (dist[end] == INT_MAX)
    {
        valied = true;
        return 0;
    }

    return dist[end];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int nodeCount, edgeCount;
    cin >> nodeCount >> edgeCount;

    for (int i = 0; i < edgeCount ; ++i)
    {
        int selectNode, targetNode, weight;
        cin >> selectNode >> targetNode >> weight;

        graph[selectNode].push_back({ targetNode, weight });
        graph[targetNode].push_back({ selectNode, weight });
    }

    cin >> checkPoint[0] >> checkPoint[1];

    vector<int> path[2];
    path[0].push_back(PathFinder({ 1, 0 }, checkPoint[0]));
    path[0].push_back(PathFinder({ checkPoint[0], 0 }, checkPoint[1]));
    path[0].push_back(PathFinder({ checkPoint[1], 0 }, nodeCount));

    path[1].push_back(PathFinder({ 1, 0 }, checkPoint[1]));
    path[1].push_back(PathFinder({ checkPoint[1], 0 }, checkPoint[0]));
    path[1].push_back(PathFinder({ checkPoint[0], 0 }, nodeCount));

    if (valied)
    {
        cout << -1;
        return 0;
    }

    int pathDist[2] = { 0 };

    for (auto e : path[0])
        pathDist[0] += e;

    for (auto e : path[1])
        pathDist[1] += e;

    if (pathDist[0] < pathDist[1])
        cout << pathDist[0];
    else
        cout << pathDist[1];

    return 0;
}
