/*
Given N and a square matrix adj[ ][ ] of size N*N, you have to find whether it is possible to construct a undirected weighted graph of N nodes numbered from 0 to N-1 such that minimum distance between ith and jth node is given by adj[i][j].
Note:
adj[i][i] = 0 for every i.
adj[i][j] = adj[j][i]

Example 1: 
Input:
N = 2
adj[] = {{0, 8},
         {8, 0}}
Output:
Yes
Explanation: 
Constructed graph:
              0 
              |(8)
              1 
Example 2: 

Input:
N = 3
par[] = {{0, 1, 3},
         {1, 0, 1},
         {3, 1, 0}}
Output:
No
Explanation: 
Graph cannot be constructed because shortest distance from node 0 to node 1  is 1 and shortest distance from node 1 to node 2 is 1 
which means that possible distance from node 0 to node 2 via node 1 can be 2 but given shortest distance from  node 0 to node 2 is 3.

  */

class Solution {
public:
    bool graph(int N, vector<vector<int>> adj) {
        // Initialize a matrix to store distances between nodes (adjacency matrix)
        vector<vector<int>> dist(N, vector<int>(N, 0));

        // Copy the adjacency matrix to the dist matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = adj[i][j];
            }
        }

        // Apply Floyd-Warshall algorithm to find shortest paths between all pairs of nodes
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    // Update the distance matrix with the shortest path
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Compare the calculated shortest paths with the original adjacency matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // If the calculated distance differs from the original adjacency value, return false
                if (dist[i][j] != adj[i][j]) {
                    return false;
                }
            }
        }

        // If all distances match, the graph is consistent with the Floyd-Warshall algorithm
        return true;
    }
};
