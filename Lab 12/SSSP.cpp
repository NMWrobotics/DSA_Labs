#include <iostream>
#include <vector>

using namespace std;

int infinity = 9999; 

//function to find the node with minimum distance from the unvisited nodes
int minDistance(vector<int>& distance, vector<bool>& visited){

    int minDistance = infinity;
    int minIndex = -1;
    int n = 6;

    for(int i = 0; i < n; i++){
        if(!visited[i] && distance[i] < minDistance){
            minDistance = distance[i];
            minIndex = i;
        }
    }

    return minIndex;
}

//dijkstra's algorithm to find the shortest distance from souce node to every other node
void dijkstras(vector<vector<int>>& graph, int source, vector<int>& distance){

    int n = 6;

    //initlaizing  all nodes as unvisited
    vector<bool> visited(n, false);

    //intializing the distance of all nodes to infinity
    for(int i = 0; i < n; i++){
        distance[i] = infinity;
    }

    //set the distance of source node to 0
    distance[source] = 0;


    for(int i = 0; i < n - 1; i++){
        int u = minDistance(distance, visited);

        visited[u] = true;

        //relaxation
        for(int j = 0; j < n; j++){
            if(!visited[j] && graph[u][j] && distance[u] != infinity && (distance[u] + graph[u][j] < distance[j])){
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }
}

//function to calculate average distance 
double average(vector<int> distance){
    double total = 0;
    for(auto x : distance) total += x;
    double average = total/(distance.size()-1);
    return average;
}

int main(){

    //storing the graph as an adjacency matrix
    vector<vector<int>> adjMatrix = {
        { 0, 10,  0,  0, 15,  5},
        {10,  0, 10, 30,  0,  0},
        { 0, 10,  0, 12,  5,  0},
        { 0, 30, 12,  0,  0, 20},
        {15,  0,  5,  0,  0,  0},
        { 5,  0,  0, 20,  0,  0}
    };

    vector<int> distance(6);
    
    for(int source = 0; source < 6;source ++){

        dijkstras(adjMatrix, source, distance);

        cout << "source city : "<< source <<endl;

        for (int i = 0; i < 6; ++i) {
            cout << "     city " << i << " : " << distance[i] << std::endl;
        }

    cout<<"     average : "<< average(distance)<<"\n\n"<<endl;

    }

}
