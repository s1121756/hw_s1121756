#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(int V, vector<vector<int>>& adj) 
{
    vector<int> bfsResult;         // Stores the BFS traversal result
    vector<bool> visited(V, false); // Tracks visited nodes
    
    queue<int> q;                 // Queue for BFS
    q.push(0);                    // Start BFS from vertex 0
    visited[0] = true;            // Mark vertex 0 as visited
    
    while (!q.empty()) 
    {
        int node = q.front();     // Get the front node from the queue
        q.pop();
        bfsResult.push_back(node); // Add the node to the result
        
        // Traverse all neighbors of the current node
        for (int neighbor : adj[node]) 
        {
            if (!visited[neighbor]) 
            {
                visited[neighbor] = true; // Mark the neighbor as visited
                q.push(neighbor);         // Push the neighbor to the queue
            }
        }
    }
    return bfsResult;
}

int main() 
{
    vector<vector<int>> adj = 
    {
        {2, 3, 1}, // Neighbors of vertex 0
        {0},       // Neighbors of vertex 1
        {0, 4},    // Neighbors of vertex 2
        {0},       // Neighbors of vertex 3
        {2}        // Neighbors of vertex 4
    };
    int V = adj.size(); // Number of vertices
    
    vector<int> result = bfsTraversal(V, adj);
    
    // Print the BFS traversal result
    for (int node : result) 
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
