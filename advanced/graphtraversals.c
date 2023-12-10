#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the adjacency list
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure for the adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure for the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* createNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));
    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // For undirected graphs, add the reverse edge as well
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform BFS traversal of the graph
void BFS(struct Graph* graph, int startVertex) {
    // Create a queue for BFS
    int queue[graph->numVertices];
    int front = 0, rear = 0;

    // Create an array to keep track of visited vertices
    bool visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = false;
    }

    // Enqueue the starting vertex and mark it as visited
    queue[rear++] = startVertex;
    visited[startVertex] = true;

    printf("Breadth-First Traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Explore adjacent vertices
        struct AdjListNode* temp = graph->array[currentVertex].head;
        while (temp != NULL) {
            int adjacentVertex = temp->dest;
            if (!visited[adjacentVertex]) {
                queue[rear++] = adjacentVertex;
                visited[adjacentVertex] = true;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Recursive function for DFS traversal
void DFSUtil(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct AdjListNode* temp = graph->array[vertex].head;
    while (temp != NULL) {
        int adjacentVertex = temp->dest;
        if (!visited[adjacentVertex]) {
            DFSUtil(graph, adjacentVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal of the graph
void DFS(struct Graph* graph, int startVertex) {
    // Create an array to keep track of visited vertices
    bool visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = false;
    }

    printf("Depth-First Traversal starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}


int main() {
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    BFS(graph, 0);
    DFS(graph, 0);

    return 0;
}
