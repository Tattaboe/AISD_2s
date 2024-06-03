#ifndef GRAPH_INCLUDE_GRAPH_H
#define GRAPH_INCLUDE_GRAPH_H
#define EPSILON 1e-10
#define INFIN 1e9

#include <iostream>
#include <vector>
#include <unordered_map>

template<typename Vertex, typename Distance = double>
class Graph {
public:
    struct Edge {
        Vertex source;
        Vertex destination;
        Distance weight;
    };

private:
    std::vector<Vertex> _vertices;
    std::unordered_map<Vertex, std::vector<Edge>> _edges;

public:
    bool has_vertex(const Vertex& v) const {
        return std::find(_vertices.begin(), _vertices.end(), v) != _vertices.end();
    }

    void add_vertex(const Vertex& v) {
        if (has_vertex(v))
            throw std::invalid_argument("add_vertex");
        _vertices.push_back(v);
        _edges[v] = {};
    }

    bool remove_vertex(const Vertex& v) {
        auto it = std::find(_vertices.begin(), _vertices.end(), v);
        if (it == _vertices.end())
            return false;
        _vertices.erase(it);
        _edges.erase(v);
        for (auto& vertex : _vertices) {
            auto& edges = _edges.at(vertex);
            edges.erase(std::remove_if(edges.begin(), edges.end(), [v](const Edge& e) {return e.destination == v; }), edges.end());
        }
        return true;
    }

    std::vector<Vertex> vertices() const {
        return _vertices;
    }

    void add_edge(const Vertex& from, const Vertex& to, const Distance& d) {
        if (!has_vertex(from) || !has_vertex(to))
            return;
        _edges[from].push_back({ from, to, d });
    }

    bool remove_edge(const Vertex& from, const Vertex& to) {
        if (!has_edge(from, to))
            return false;
        auto& edges = _edges.at(from);

        edges.erase(std::remove_if(edges.begin(), edges.end(), [&](const Edge& e) { return (e.source == from) && (e.destination == to); }), edges.end());

        return true;
    }

    bool remove_edge(const Edge& e) {
        if (!has_edge(e))
            return false;
        auto& edges = _edges.at(e.source);

        edges.erase(std::remove_if(edges.begin(), edges.end(), [e](const Edge& edge)
            { return (e.source == edge.source) && (e.destination == edge.destination) && (e.weight == edge.weight); }), edges.end());

        return true;
    }

    bool has_edge(const Vertex& from, const Vertex& to) const {
        for (const auto& edges : _edges) {
            for (const auto& edge : edges.second) {
                if (edge.source == from && edge.destination == to) {
                    return true;
                }
            }
        }
        return false;
    }

    bool has_edge(const Edge& e) const {
        auto& edges = _edges.at(e.source);
        for (const auto& edge : edges)
            if (edge.destination == e.destination && abs(edge.weight - e.weight) < EPSILON)
                return true;
        return false;
    }

};

#endif