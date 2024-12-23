#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void dfs(int graph[MAX][MAX], int n, int node, int visited[MAX]) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, n, i, visited);
        }
    }
}

int main() {
    int n, e, u, v;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    int graph[MAX][MAX] = {0};
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int visited[MAX] = {0};
    int start;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(graph, n, start, visited);

    return 0;
}
