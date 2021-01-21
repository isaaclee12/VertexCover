#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>> graph, int vertex1, int vertex2) {
    //Add vertices to the adjacency list for each vertex
    graph[vertex1].push_back(vertex2);
    graph[vertex2].push_back(vertex2);
}

int main() {
    //Establish an adjacency list to represent an undirected graph
    vector<vector<int>> graph1;

    //Add vertices (visual will be shown in post)
    addEdge(graph1, 0, 1);
    addEdge(graph1, 0, 2);
    addEdge(graph1, 1, 2);
    addEdge(graph1, 1, 4);
    addEdge(graph1, 1, 3);

    //Print the graph's adj. list to make sure it worked
    printAdjList(graph1);
    
    return 0;
}