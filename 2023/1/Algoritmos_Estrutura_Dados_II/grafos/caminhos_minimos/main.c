#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define MAX_VERTICES 100
#define MAX_NAME_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    double distance;
} Vertex;

typedef struct {
    int numVertices;
    Vertex vertices[MAX_VERTICES];
    double weights[MAX_VERTICES][MAX_VERTICES];
} Graph;

int getVertexIndex(Graph *graph, const char *name) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (strcmp(graph->vertices[i].name, name) == 0) {
            return i;
        }
    }
    return -1;  // Vertex not found
}

void dijkstra(Graph *graph, int startVertex, double *distances) {
    int numVertices = graph->numVertices;
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < numVertices; i++) {
        distances[i] = DBL_MAX;
    }
    distances[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = -1;
        double minDistance = DBL_MAX;

        // Find the vertex with the minimum distance
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i] && distances[i] < minDistance) {
                minDistance = distances[i];
                u = i;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = 1;

        // Update distances of the adjacent vertices
        for (int v = 0; v < numVertices; v++) {
            double weight = graph->weights[u][v];
            if (weight > 0 && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }
}

double calculateDeliveryCost(double distance) {
    return 1.50 + 0.2 * distance;
}

int main() {
    Graph graph;
    int m, q;
    char customer[MAX_NAME_SIZE];

    // Read the number of vertices
    scanf("%d", &graph.numVertices);

    // Read the vertices
    for (int i = 0; i < graph.numVertices; i++) {
        scanf("%s", graph.vertices[i].name);
    }

    // Initialize the weights matrix
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph.weights[i][j] = 0;
        }
    }

    // Read the number of edges
    scanf("%d", &m);

    // Read the edges and weights
    for (int i = 0; i < m; i++) {
        char source[MAX_NAME_SIZE];
        char destination[MAX_NAME_SIZE];
        double weight;
        int sourceIndex, destinationIndex;

        scanf("%s %s %lf", source, destination, &weight);

        sourceIndex = getVertexIndex(&graph, source);
        destinationIndex = getVertexIndex(&graph, destination);

        graph.weights[sourceIndex][destinationIndex] = weight;
        graph.weights[destinationIndex][sourceIndex] = weight;
    }

    // Read the number of queries
    scanf("%d", &q);

    // Process the queries
    for (int i = 0; i < q; i++) {
        double distances[MAX_VERTICES];
        int customerIndex;

        scanf("%s", customer);

        customerIndex = getVertexIndex(&graph, customer);

        dijkstra(&graph, 0, distances);
        double deliveryCost = calculateDeliveryCost(distances[customerIndex]);

        printf("%.2f\n", deliveryCost);
    }

    return 0;
}
