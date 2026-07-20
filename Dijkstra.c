#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int vertex, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {

    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(struct Graph* graph, int source) {

    int V = graph->numVertices;

    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, visited, V);

        if (u == -1)
            break;

        visited[u] = 1;

        struct Node* temp = graph->adjLists[u];

        while (temp != NULL) {

            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] &&
                dist[u] != INT_MAX &&
                dist[u] + weight < dist[v]) {

                dist[v] = dist[u] + weight;
            }

            temp = temp->next;
        }
    }

    printf("\nShortest distances from vertex %d:\n\n", source);

    for (int i = 0; i < V; i++) {
        printf("%d -> %d = ", source, i);

        if (dist[i] == INT_MAX)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];

        while (temp != NULL) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(graph->adjLists);
    free(graph);
}

int main() {

    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 8);
    addEdge(graph, 2, 4, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 3, 5, 6);
    addEdge(graph, 4, 5, 3);

    dijkstra(graph, 0);

    freeGraph(graph);

    return 0;
}