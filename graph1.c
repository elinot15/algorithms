#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GENERATE_PROBABILITY 0.2


typedef struct Node{
    struct Node *next;
    int value;
} Node;

Node *list_create();
Node *list_insert(Node *list, int value);
void list_print(Node *list);
void list_free(Node *list);

Node *list_create(){
    return NULL;
}

Node *list_insert(Node *list, int value){
    Node *new = malloc(sizeof(Node));
    new->next = list;
    new->value = value;

    return new;
}

void list_print(Node *list){
    while(list){
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

void list_free(Node *list){
    if( list != NULL ){
        Node *n;
        while(list){
            n = list->next;
            free(list);
            list = n;
        }
    }
}

typedef struct Queue{
    Node *head;
} Queue;

Queue *queue_create();
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int queue_empty(Queue *queue);
void queue_free(Queue *queue);


Queue *queue_create(){
    Queue *q = malloc(sizeof(Queue));
    q->head = list_create();

    return q;
}

void enqueue(Queue *queue, int value){
    Node *new = malloc(sizeof(Node));
    new->next = NULL;
    new->value = value;

    if( queue->head == NULL ){
        queue->head = new;
    } else {
        Node *head = queue->head;
        while( head->next ){
            head = head->next;
        }
        head->next = new;
    }
}

int dequeue(Queue *queue){
    if( queue->head ){
        Node *e = queue->head;
        queue->head = queue->head->next;
        int x = e->value;
        free(e);
        return x;
    }

    return -1;
}

int queue_empty(Queue *queue){
    return queue->head == NULL;
}

void queue_free(Queue *queue){
    if( queue ){
        list_free(queue->head);
        free(queue);
    }
}

typedef struct Graph{
    int vertices;
    int edges;
    Node **V;
} Graph;

Graph *graph_create(int vertices);
void graph_free(Graph *g);
void graph_print(Graph *g);
void graph_edge_insert(Graph *g, int v, int w);
void graph_generate(Graph *g, double probability);
int vertex_degree(Graph *g, int vertex);
void graph_dfs(Graph *g, int start, int *aux);
int graph_path_exists(Graph *g, int v, int w);
Graph *graph_spanning_tree(Graph *g, int vertex_start);

int graph_bipartite_bfs(Graph *g);
int graph_bipartite(Graph *g);
int graph_bipartite_dfs(Graph *g, int v, int *aux);

int graph_has_cycles(Graph *g);
int graph_cycle(Graph *g, int start, int *visited, int *path);


Graph *graph_create(int vertices){
    Graph *g = malloc(sizeof(Graph));
    g->vertices = vertices;
    g->edges = 0;
    g->V = malloc(sizeof(Node*) * vertices);
    for(int i = 0; i < vertices; i++){
        g->V[i] = list_create();
    }

    return g;
}

void graph_free(Graph *g){
    for(int i = 0; i < g->vertices; i++){
        list_free(g->V[i]);
    }
    free(g);
}

void graph_print(Graph *g){
    printf("Vertices: %d\tEdges: %d\n", g->vertices, g->edges);
    for(int i = 0; i < g->vertices; i++){
        printf("%d: ", i);
        list_print(g->V[i]);
    }
}

void graph_edge_insert(Graph *g, int v, int w){
    // Controllo che 'w' non ci sia gia' nella lista di 'v'
    Node *head = g->V[v];
    while( head ){
        if( head->value == w ){
            return;
        }
        head = head->next;
    }

    g->V[v] = list_insert(g->V[v], w);
    g->edges++;
}

void graph_generate(Graph *g, double probability){
    for(int i = 0; i < g->vertices; i++){
        for(int j = 0; j < g->vertices; j++){
            if( i != j ){
                double chance = (rand() % 1000) / 1000.0;
                if( chance < probability ){
                    graph_edge_insert(g, i, j);
                }
            }
        }
    }
}

int vertex_degree(Graph *g, int vertex){
    int degree = 0;
    Node *head = g->V[vertex];
    while( head ){
        degree++;
        head = head->next;
    }

    return degree;
}

void graph_dfs(Graph *g, int start, int *aux){
    if( !aux[start] ){
        aux[start] = 1;
        Node *head = g->V[start];
        while(head){
            if( !aux[head->value] ){
                graph_dfs(g, head->value, aux);
            }
            head = head->next;
        }
    }
}

int graph_path_exists(Graph *g, int v, int w){
    int *aux = calloc(g->vertices, sizeof(int));
    graph_dfs(g, v, aux);
    if( aux[w] ){
        free(aux);
        return 1;
    } else {
        free(aux);
        return 0;
    }
}

int graph_connected_components(Graph *g){
    int ccc = 0;
    int *aux = calloc(g->vertices, sizeof(int));
    for(int i = 0; i < g->vertices; i++){
        if( !aux[i] ){
            ccc++;
            graph_dfs(g, i, aux);
        }
    }
    free(aux);

    return ccc;
}

void graph_print_connected_component(Graph *g, int vertex){
    int *aux = calloc(g->vertices, sizeof(int));
    graph_dfs(g, vertex, aux);
    for(int i = 0; i < g->vertices; i++){
        if( aux[i] ){
            printf("%d ", i);
        }
    }
    printf("\n");
    free(aux);
}

Graph *graph_spanning_tree(Graph *g, int vertex_start){
    int *aux = calloc(g->vertices, sizeof(int));
    Graph *tree = graph_create(g->vertices);
    Queue *q = queue_create();
    enqueue(q, vertex_start);
    aux[vertex_start] = 1;
    while( !queue_empty(q) ){
        int v = dequeue(q);
        Node *head = g->V[v];
        while(head){
            if( !aux[head->value] ){
                enqueue(q, head->value);
                graph_edge_insert(tree, v, head->value);
                aux[head->value] = 1;
            }
            head = head->next;
        }
    }
    queue_free(q);

    return tree;
}

int graph_shortest_path_weigth(Graph *g, int v, int w){
    Queue *q = queue_create();
    int *aux = malloc(g->vertices * sizeof(int));
    for(int i = 0; i < g->vertices; i++){
        aux[i] = -1;
    }
    aux[v] = 0;
    enqueue(q, v);
    while(!queue_empty(q)){
        int x = dequeue(q);
        Node *head = g->V[x];
        while(head){
            if( aux[head->value] == -1 ){
                enqueue(q, head->value);
                aux[head->value] = aux[x] + 1;
            }
            head = head->next;
        }
    }
    queue_free(q);

    return aux[w];
}

Node *graph_shortest_path(Graph *g, int v, int w){
    Queue *q = queue_create();
    int *visited = malloc(g->vertices * sizeof(int));
    int *before = malloc(g->vertices * sizeof(int));
    for(int i = 0; i < g->vertices; i++){
        visited[i] = 0;
        before[i] = -1;
    }
    visited[v] = 1;
    before[v] = v;
    enqueue(q, v);
    while(!queue_empty(q)){
        int x = dequeue(q);
        Node *head = g->V[x];
        while(head){
            if( !visited[head->value] ){
                visited[head->value] = 1;
                before[head->value] = x;
                enqueue(q, head->value);
            }
            head = head->next;
        }
    }

    Node *path = list_create();
    int position = w;
    while( position != v ){
        path = list_insert(path, position);
        position = before[position];
    }

    return path;
}

int graph_bipartite_bfs(Graph *g){
    int bipartite = 1;
    // Usiamo 1 per il nero, 0 per il bianco. -1 per non colorato
    int *aux = calloc(g->vertices, sizeof(int));
    for(int i = 0; i < g->vertices; i++){
        aux[i] = -1;
    }

    for(int i = 0; i < g->vertices && bipartite; i++){
        if( aux[i] == -1 ){
            Queue *queue = queue_create();
            aux[i] = 1; // Coloro l'inizio
            enqueue(queue, i);
            while( !queue_empty(queue) && bipartite ){
                int x = dequeue(queue);
                Node *head = g->V[x];
                
                int color;
                if( aux[x] == 1){
                    color = 0;
                } else {
                    color = 1;
                }
                while(head && bipartite){
                    // Se troviamo che ci sono 2 nodi collegati gia' 
                    // colorati con lo stesso colore non e' bipartito il grafo
                    if( aux[head->value] == aux[x] ){
                        bipartite = 0;
                    } else if ( aux[head->value] == -1 ){
                        aux[head->value] = color;
                        enqueue(queue, head->value);
                    }
                    head = head->next;
                }
            }
            queue_free(queue);
        }
    }

    return bipartite;
}

int graph_bipartite(Graph *g){
    int *aux = malloc(g->vertices * sizeof(int));
    for(int i = 0; i < g->vertices; i++){
        aux[i] = -1;
    }
    for(int i = 0; i < g->vertices; i++){
        if( aux[i] == -1 ){
            aux[i] = 1;
            if( graph_bipartite_dfs(g, i, aux) == 0 ){
                free(aux);
                return 0;
            }
        }
    }

    free(aux);
    return 1;
}

int graph_bipartite_dfs(Graph *g, int v, int *aux){
    Node *head = g->V[v];
    while( head ){
        // Il grafo non e' bipartito
        if( aux[head->value] == aux[v] ){
            return 0;
        } else if ( aux[head->value] == -1 ){
            aux[head->value] = 1 - aux[v]; // Coloriamo opposto
            if( graph_bipartite_dfs(g, head->value, aux) == 0 ){
                return 0;
            }
        }
        head = head->next;
    }

    return 1;
}

int graph_has_cycles(Graph *g){
    int *visited, *path;
    visited = calloc(g->vertices, sizeof(int));
    path = calloc(g->vertices, sizeof(int));
    for(int i = 0; i < g->vertices; i++){
        if( visited[i] == 0 ){
            if( graph_cycle(g, i, visited, path) ){
                free(visited);
                free(path);
                return 1;
            }
        }
    }

    free(visited);
    free(path);
    return 0;
}

int graph_cycle(Graph *g, int start, int *visited, int *path){
    path[start] = 1;
    visited[start] = 1;
    Node *head = g->V[start];
    while(head){
        if( path[head->value] ){
            return 1;
        }
        if( visited[head->value] == 0 ){
            if( graph_cycle(g, head->value, visited, path) ){
                return 1;
            }
        }
        head = head->next;
    }
    path[start] = 0;
    
    return 0;
}

int main(int argc, char *argv[]){
    srand(time(NULL));

    int vertices;
    printf("How many vertices: ");
    scanf("%d", &vertices);
    Graph *g = graph_create(vertices);

    char c;
    printf("Generate graph(y)?");
    scanf(" %c", &c);
    if( c == 'y' ){
        graph_generate(g, GENERATE_PROBABILITY);
    } else {
        int edges, v, w;
        printf("How many edges: ");
        scanf("%d", &edges);
        for(int i = 0; i < edges; i++){
            scanf("%d %d", &v, &w);
            graph_edge_insert(g, v, w);
        }
    }

    graph_print(g);
    
    int random_vertex = rand() % g->vertices;
    printf("The vertex %d has degree %d\n", random_vertex, vertex_degree(g, random_vertex));
    
    int random_vertex2 = rand() % g->vertices;
    if( graph_path_exists(g, random_vertex, random_vertex2) ){
        printf("A path exists between %d and %d\n", random_vertex, random_vertex2);
    } else {
        printf("A path doesn't exists between %d and %d\n", random_vertex, random_vertex2);
    }

    printf("The graph has %d connected components\n", graph_connected_components(g));
    printf("The connected component of vertex %d is: ", random_vertex);
    graph_print_connected_component(g, random_vertex);

    printf("The minimum spanning tree from %d is:\n", random_vertex);
    Graph *spanning_tree = graph_spanning_tree(g, random_vertex);
    graph_print(spanning_tree);
    graph_free(spanning_tree);

    printf("The shortest path between %d and %d weights %d\n", 
        random_vertex, 
        random_vertex2, 
        graph_shortest_path_weigth(g, random_vertex, random_vertex2)
    );

    printf("The shortest path between %d and %d is: ", random_vertex, random_vertex2);
    Node *path = graph_shortest_path(g, random_vertex, random_vertex2);
    list_print(path);
    list_free(path);

    if( graph_bipartite(g) ){
        printf("The graph is bipartite, therefore has no odd cycles\n");
    } else {
        printf("The graph is NOT bipartite, therefore has odd cycles\n");
    }

    if( graph_has_cycles(g) ){
        printf("The graph has cycles in it");
    } else {
        printf("The graph does NOT have cycles in it\n");
    }
    return 0;
}
