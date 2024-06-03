#include <iostream>
#include "../include/graph.h"



int main() {
    
    Graph<int, int> g;
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);
    g.add_vertex(5);

   
    g.add_edge(1, 5, 4);
    g.add_edge(1, 3, 6);
    g.add_edge(2, 3, 2);
    g.add_edge(2, 5, 1);
    g.add_edge(3, 5, 3);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 2, 7);
    g.add_edge(4, 5, 5);
    g.add_edge(5, 1, 2);

    g.print_edges();

    return 0;
}