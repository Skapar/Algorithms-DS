#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int> > graph(10000); // A vector of vectors for adjacency list
bool used[100000] = {false}; // Initialize all elements to false

int main() {
    int n, m, a, b;
    cin >> n >> m; // Reading number of nodes (n) and edges (m)

    // Building the graph
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b); // Assuming a directed graph
        // If undirected, add graph[b].push_back(a);
    }

    queue<int> q;
    q.push(0); // Start BFS from node 0
    used[0] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur + 1 << " "; // Output the current node (1-indexed)

        for(int i = 0; i < graph[cur].size(); i++) {
            int neigh = graph[cur][i];
            if(!used[neigh]) {
                q.push(neigh);
                used[neigh] = true;
            }
        }
    }
    return 0;
}
