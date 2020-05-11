
#include <stdio.h>
#include <limits.h>


#define VERTEX 9


int min_dist(const int *dist, const bool *spt_set)
{
    int min = INT_MAX, min_idx = 0;

    for (unsigned i = 1; i < VERTEX; i++)
        if (spt_set[i] == false && min > dist[i]) {
            min     = dist[i];
            min_idx = i;
        }

    return min_idx;
}


void print_path(const int *parent, int v)
{

    if (parent[v] == -1) {
        printf("%d ", v);
        return ;
    }
    print_path(parent, parent[v]);
    printf("%d ", v);
}

void print_spt(const int *dist, int src, const int *parent)
{
    puts("  Vertex    Distance     Path");
    for (unsigned i = 0; i < VERTEX; i++) {
        printf(" %2d -> %2d      %2d         ", src, i, dist[i]);
        print_path(parent, i);
        putchar('\n');
    }
}

void dijkstra(const int graph[VERTEX][VERTEX], int src)
{
   
    int dist[VERTEX];
    bool spt_set[VERTEX];

    int parent[VERTEX];
    parent[src]  = -1;           

    for (unsigned i = 0; i < VERTEX; i++) {
        dist[i]    = INT_MAX;      
        spt_set[i] = false;         
    }

    dist[src] = 0;

    for (unsigned i = 0; i < VERTEX-1; i++) {
        int u = min_dist(dist, spt_set);

        spt_set[u] = true;
        if (dist[u] == INT_MAX) continue;

        for (unsigned v = 0; v < VERTEX; v++)
			
            if (graph[u][v] && spt_set[v] == false &&
                    dist[u] + graph[u][v] < dist[v])
            {
                dist[v]   = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }

    print_spt(dist, src, parent);
}

int main(void)
{

    int graph[VERTEX][VERTEX] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0},
    };

    puts("Dijkstra of vertex 0");
    dijkstra(graph, 0);

    return 0;
}
