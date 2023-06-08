#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define inf 9999

void prims(vector<vector<int>> graph, int source) {

    int n = graph.size();
    
    vector<vector<int>> MST;
    
    int key[n];
    bool visited[n];
    int parent[n];

    for (int i = 0; i < n; i++) {
        key[i] = inf;
        visited[i] = false;
    }

    key[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        pq.push({key[i], i});
    }

    while (!pq.empty()) {
        int currentmin = pq.top().second;
        pq.pop();

        if (visited[currentmin])
            continue;

        visited[currentmin] = true;
        
        for (int i = 0; i < n; i++) {
            if (graph[currentmin][i] != 0 && graph[currentmin][i] < key[i] && !visited[i]) {
                key[i] = graph[currentmin][i];
                parent[i] = currentmin;
                pq.push({key[i], i});
            }
        }
    }
    
    cout<<"Edge   :   Weight"<<endl;

    for (int i =1; i<n; i++) {
        cout << parent[i]<<" - "<<i<< "   :   "<<key[i]<<endl;
    }

    int totalCost =0;
    
    for(int x=1; x < n ; x++){
        totalCost += key[x];
    }
    cout<<"Minimum Cost : "<<totalCost<<endl;
}

int main() {

    vector<vector<int>> adjMatrix = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    prims(adjMatrix, 0);

    return 0;
}
