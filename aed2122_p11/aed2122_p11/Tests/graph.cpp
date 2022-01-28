// AED 2021/2022 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [17/01/2022]

#include "graph.h"
#include <climits>

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}


// ----------------------------------------------------------
// 1) Algoritmo de Dijkstra e caminhos mais curtos
// ----------------------------------------------------------

// ..............................
// a) Distância entre dois nós
// TODO
int Graph::dijkstra_distance(int a, int b) {
    MinHeap<int, int> heap(nodes.size(), -1);
    for(int i = 1; i < nodes.size(); i++){
        nodes[i].dist = INT_MAX;
        nodes[i].visited = false;
        heap.insert(i, INT_MAX);
    }
    nodes[a].dist = 0;
    nodes[a].pred = a;
    heap.decreaseKey(a, 0);
    while(heap.getSize() != 0){
        int u = heap.removeMin();
        nodes[u].visited = true;
        for(auto edge : nodes[u].adj){
            int v = edge.dest;
            if(!nodes[v].visited && nodes[u].dist + edge.weight < nodes[v].dist) {
                int newWeight = nodes[u].dist + edge.weight;
                nodes[v].dist = newWeight;
                nodes[v].pred = u;
                heap.decreaseKey(v, newWeight);
            }
        }
    }
    if(nodes[b].dist == INT_MAX) return -1;
    else return nodes[b].dist;
}

// ..............................
// b) Caminho mais curto entre dois nós
// TODO
list<int> Graph::dijkstra_path(int a, int b) {
    list<int> path;
    dijkstra_distance(a, b);
    path.push_front(b);
    do{
        if(nodes[b].pred == b) {
            path.clear();
            break;
        }
        b = nodes[b].pred;
        path.push_front(b);
    }while(b != a);
    return path;
}
