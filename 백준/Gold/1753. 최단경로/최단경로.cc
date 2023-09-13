#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int ID;
    int cost;

    Node() 
        : ID(0), cost(0) {};
    Node(int ID, int cost)
        : ID(ID), cost(cost) {};
};

struct Compare
{
    bool operator()(const Node& lhs, const Node& rhs)
    {
        return lhs.cost > rhs.cost;
    }
};

vector<Node> graph[20001];
vector<int> dist(20001, INT_MAX);

void Dikjstra(Node node)
{
    priority_queue<Node, vector<Node>, Compare> q;
    q.push(node);

    dist[node.ID] = 0;

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
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int nodeCount, edgeCount, beginNode;
    cin >> nodeCount >> edgeCount >> beginNode;

    for (int i = 0; i < edgeCount; ++i)
    {
        int selectNode, targetNode, cost;
        cin >> selectNode >> targetNode >> cost;

        graph[selectNode].push_back({ targetNode, cost });
    }

    Dikjstra({ beginNode, 0 });

    for (int i = 1; i <= nodeCount; ++i)
    {
        if (dist[i] == INT_MAX)
            cout << "INF" << "\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
