#include <iostream>
#include <vector>
using namespace std;

//Turns out I did not need to make all this

void addEdge(vector<vector<int>> &graph, int vertex1, int vertex2) {
    //Add vertices to the adjacency list for each vertex
    graph[vertex1].push_back(vertex2);
    graph[vertex2].push_back(vertex1);
}

void printAdjList(vector<vector<int>> graph) {
    //Top level vector, print the index representing the vertex
    for (int i = 0; i < graph.size(); i++) {
        cout << i << "-->";
        //Sub level vector, print each vertex that vertex i shares an edge with
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << "-->";
        }
        cout << endl;
    }
    cout << endl;
}


void vertexCover(vector<vector<int>> graph, int edges) {
    //Get the number of vertices from the graph
    int n = graph.size();

    //vars
    vector<vector<int>> combinationsScanned;
    vector<int> combination;
    vector<vector<int>> edgesMarked;
    int edgesCovered = 0;

    //For the n vertices
    for (int i = 1; i < n; i++) {

        //Subset size
        int subsetSize = i;


        //Get every possible subset for that size
        for (int j = 0; j < i; j++) {
            //If first case
            if (subsetSize == 1) {
                combination = {i};
            }

            //After first
            else {
                int a = 0;
                int b = 1;

                //For every a
                for (int k = 0; k < n; k++) {

                    //And every b
                    for (int l = 0; l < n; l++) {
                        if (a != b) {

                        }
                    }
                }
            }

        }
    }
}

int main() {

    //Graph 1
    //Establish an adjacency list to represent an undirected graph
    vector<vector<int>> graph1 = {{}, {}, {}};

    //Add vertices (visual will be shown in post)
    addEdge(graph1, 0, 1);
    addEdge(graph1, 1, 2);

    //Print the graph's adj. list to make sure it worked
    cout << "Graph 1:" << endl;
    printAdjList(graph1);


    //Graph 2
    //Establish an adjacency list to represent an undirected graph
    vector<vector<int>> graph2 = {{}, {}, {}, {}, {}};

    //Add vertices (visual will be shown in post)
    addEdge(graph2, 0, 1);
    addEdge(graph2, 0, 2);
    addEdge(graph2, 1, 2);
    addEdge(graph2, 1, 3);
    addEdge(graph2, 1, 4);

    //Print the graph's adj. list to make sure it worked
    cout << "Graph 2:" << endl;
    printAdjList(graph2);


    //Graph 3
    //Establish an adjacency list to represent an undirected graph
    vector<vector<int>> graph3 = {{}, {}, {}, {}, {}};

    //Add vertices (visual will be shown in post)
    addEdge(graph3, 2, 0);
    addEdge(graph3, 2, 1);
    addEdge(graph3, 2, 3);
    addEdge(graph3, 4, 3);
    addEdge(graph3, 4, 1);

    //Print the graph's adj. list to make sure it worked
    cout << "Graph 3:" << endl;
    printAdjList(graph3);

    //Vertex Cover
    vertexCover(graph3, 5);

    return 0;
}