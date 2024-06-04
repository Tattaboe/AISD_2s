#include <iostream>
#include "../include/graph.h"
using namespace std;


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
    g.print_vertices();

    std::cout << std::endl;
    auto path = g.shortest_path(1, 5);
    std::cout << "Shortest path from 1 to 5: ";
    for (const auto& edge : path) {
        std::cout << "From: " << edge.from << " To: " << edge.to << " Weight: " << edge.weight << std::endl;
    }


    



    return 0;
}