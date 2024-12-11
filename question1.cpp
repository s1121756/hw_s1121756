# hw_s1121756
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createAdjacencyList(int V, vector<pair<int, int>> edges) 
{
    // 初始化一个包含 V 个空向量的邻接表
    vector<vector<int>> adjacencyList(V);

    // 填充邻接表
    for (auto edge : edges) 
    {
        int u = edge.first;
        int v = edge.second;
        adjacencyList[u].push_back(v); // 添加边 u -> v
        adjacencyList[v].push_back(u); // 添加边 v -> u（无向图）
    }

    return adjacencyList;
}

int main() 
{
    int V = 5, E = 7;
    vector<pair<int, int>> edges = 
    {
        {0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}
    };

    // 创建邻接表
    vector<vector<int>> adjacencyList = createAdjacencyList(V, edges);

    // 输出邻接表
    for (int i = 0; i < adjacencyList.size(); i++) 
    {
        cout << i << ": ";
        for (int node : adjacencyList[i]) 
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
