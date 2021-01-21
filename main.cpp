#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ctime>
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

void PossibleSubSet(vector<int> a, int reqLen, int s, int currLen, vector<bool> check, int l, int &ct)
//Code taken from: https://www.tutorialspoint.com/cplusplus-program-to-generate-all-possible-subsets-with-exactly-k-elements-in-each-subset
//print the all possible combination of given array set
{
    if(currLen > reqLen)
        return;
    else if (currLen == reqLen) {
        //cout<<"\t";
        for (int i = 0; i < l; i++) {
            if (check[i] == true) {
                //cout<<a[i]<<" ";
                //iterate count
                ct++;
            }
        }
        //cout<<"\n";
        return;
    }
    if (s == l) {
        return;
    }
    check[s] = true;
    PossibleSubSet(a, reqLen, s + 1, currLen + 1, check, l, ct);
    //recursively call PossibleSubSet() with incremented value of ‘currLen’ and ‘s’.
    check[s] = false;
    PossibleSubSet(a, reqLen, s + 1, currLen, check, l, ct);
    //recursively call PossibleSubSet() with only incremented value of ‘s’.
}

void vertexCover(vector<vector<int>> graph) {
    //Get the number of vertices from the graph
    int n = graph.size();

    //combo count
    int ct = 0;

    vector<bool> check(n);
    vector<int> a(n);

    clock_t start;
    start = clock();

    //init
    for(int i = 0; i < n; i++) {
        a[i] = i;
        check[i] = false;
    }

    //For the n vertices
    for (int i = 1; i < n; i++) {
        //i is subset size
        PossibleSubSet(a, i, 0, 0, check, n, ct);
    }

    //print count
    cout << ct << " permutations." << endl;

    double duration = 100*(( clock() - start ) / (double) CLOCKS_PER_SEC);
    cout << fixed << setprecision(2);
    cout << "duration: " << duration << "ms" << endl << endl;
}

int main() {

    //Graph 1
    //Establish an adjacency list to represent an undirected graph
    vector<vector<int>> graph1(3);

    //Add vertices
    addEdge(graph1, 0, 1);
    addEdge(graph1, 1, 2);

    //Print the graph's adj. list to make sure it worked
    cout << "Graph 1:" << endl;
    printAdjList(graph1);

    //Vertex Cover
    vertexCover(graph1);


    //Graph 2
    //Establish an adjacency list to represent an undirected graph
    vector<vector<int>> graph2(5);

    //Add vertices
    addEdge(graph2, 0, 1);
    addEdge(graph2, 0, 2);
    addEdge(graph2, 1, 2);
    addEdge(graph2, 1, 3);
    addEdge(graph2, 1, 4);

    //Print the graph's adj. list to make sure it worked
    cout << "Graph 2:" << endl;
    printAdjList(graph2);

    //Vertex Cover
    vertexCover(graph2);


    //Graph 3
    //Establish an adjacency list to represent an undirected graph
    vector<vector<int>> graph3(5);

    //Add vertices
    addEdge(graph3, 2, 0);
    addEdge(graph3, 2, 1);
    addEdge(graph3, 2, 3);
    addEdge(graph3, 4, 3);
    addEdge(graph3, 4, 1);

    //Print the graph's adj. list to make sure it worked
    cout << "Graph 3:" << endl;
    printAdjList(graph3);

    //Vertex Cover
    vertexCover(graph3);



    //Graph 4
    //Establish an adjacency list to represent an undirected graph
    vector<vector<int>> graph4(9);

    //Add vertices
    addEdge(graph4, 1, 2);
    addEdge(graph4, 0, 2);
    addEdge(graph4, 3, 5);
    addEdge(graph4, 2, 3);
    addEdge(graph4, 4, 1);
    addEdge(graph4, 6, 3);
    addEdge(graph4, 7, 4);
    addEdge(graph4, 7, 8);
    addEdge(graph4, 6, 8);

    //Print the graph's adj. list to make sure it worked
    cout << "Graph 4:" << endl;
    printAdjList(graph4);

    //Vertex Cover
    vertexCover(graph4);

    return 0;
}