// id: 322353780 mail:talyape123@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept>
#include <iostream>

namespace ariel
{

    class Graph
    {
    public:
        Graph();
        void loadGraph(const std::vector<std::vector<int>> &graph_matrix);
        void printGraph() const;
        int countEdges() const;
        bool isDirected() const;
        int isWeighted() const;
        const std::vector<std::vector<int>> &getGraphMatrix() const;

        // Arithmetic operators
        Graph operator+(const Graph &other) const;
        Graph &operator+=(const Graph &other);
        Graph operator-(const Graph &other) const;
        Graph &operator-=(const Graph &other);
        Graph operator+() const; // Unary plus
        Graph operator-() const; // Unary minus

        // Relational operators
        bool operator==(const Graph &other) const;
        bool operator!=(const Graph &other) const;
        bool operator<(const Graph &other) const;
        bool operator<=(const Graph &other) const;
        bool operator>(const Graph &other) const;
        bool operator>=(const Graph &other) const;

bool isSubMatrix(const Graph &other) const;   
        // Pre-increment operator
        Graph& operator++();

        // Post-increment operator
        Graph operator++(int);

        // Pre-decrement operator
        Graph& operator--();

        // Post-decrement operator
        Graph operator--(int);


        Graph& operator*(int num);
        Graph operator*(const Graph& other) const;

        friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

    private:
        std::vector<std::vector<int>> graph_matrix;
    };

}

#endif
