#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dfsResult) 
{
    // Mark the current node as visited
    visited[node] = true;
    dfsResult.push_back(node); // Add the node to the result
    
    // Visit all the neighbors of the current node
    for (int neighbor : adj[node]) 
    {
        if (!visited[neighbor]) 
        {
            dfsHelper(neighbor, adj, visited, dfsResult);
        }
    }
}

vector<int> dfsTraversal(int V, vector<vector<int>>& adj) 
{
    vector<int> dfsResult;        // Stores the DFS traversal result
    vector<bool> visited(V, false); // Tracks visited nodes
    
    // Start DFS from vertex 0
    dfsHelper(0, adj, visited, dfsResult);
    return dfsResult;
}

int main() 
{
    vector<vector<int>> adj = 
    {
        {1, 2},      // Neighbors of vertex 0
        {0, 2},      // Neighbors of vertex 1
        {0, 1, 3, 4}, // Neighbors of vertex 2
        {2},         // Neighbors of vertex 3
        {2}          // Neighbors of vertex 4
    };
    int V = adj.size(); // Number of vertices
    
    vector<int> result = dfsTraversal(V, adj);
    
    // Print the DFS traversal result
    for (int node : result) 
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
