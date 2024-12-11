#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int findMST(int V, vector<vector<pair<int, int>>>& adj) 
{
    // Priority queue to store {weight, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> inMST(V, false); // Tracks vertices already included in MST
    vector<int> key(V, INT_MAX); // Minimum weight to reach each vertex
    
    int mstWeight = 0; // Total weight of the MST
    
    // Start from vertex 0
    pq.push({0, 0}); // {weight, vertex}
    key[0] = 0;
    
    while (!pq.empty()) 
    {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        // Skip if the vertex is already in the MST
        if (inMST[u]) continue;
        
        // Include this vertex in the MST
        inMST[u] = true;
        mstWeight += weight;
        
        // Traverse all neighbors of vertex u
        for (auto it : adj[u]) 
        {
            int v = it.first;  // Neighboring vertex
            int w = it.second; // Edge weight
            
            // If vertex v is not in MST and weight of edge (u, v) is smaller
            if (!inMST[v] && key[v] > w) 
            {
                key[v] = w;
                pq.push({w, v}); // Push {weight, vertex} to the queue
            }
        }
    }
    
    return mstWeight;
}

int main() 
{
    int V = 3, E = 3;
    vector<vector<pair<int, int>>> adj(V);
    
    // Input edges
    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});
    
    int result = findMST(V, adj);
    cout << "Sum of weights of MST: " << result << endl;
    
    return 0;
}
