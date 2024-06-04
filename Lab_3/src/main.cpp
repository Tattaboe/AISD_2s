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
    std::cout << "The degree of the vertex 4: " << g.degree(4) << std::endl;
    std::cout << "The order of the graph: " << g.order() << std::endl;

    std::cout << std::endl;
    auto path = g.shortest_path(1, 5);
    std::cout << "Shortest path from 1 to 5: ";
    for (const auto& edge : path) {
        std::cout << "From: " << edge.from << " To: " << edge.to << " Weight: " << edge.weight << std::endl;
    }


    std::cout << "Graph traversal: ";
    std::vector<int> visited;
    g.walk(1, [&visited](const int vertex) { visited.push_back(vertex); });
    for (int v : visited)
        std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "Center: " << g.find_optimal_warehouse_location() << std::endl;



    return 0;
}