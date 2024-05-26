// id: 322353780 mail:talyape123@gmail.com

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

namespace ariel
{

    Graph::Graph() {}

    void Graph::loadGraph(const std::vector<std::vector<int>> &graph_matrix)
    {

        if (graph_matrix.empty() || graph_matrix[0].empty())
        {
            throw std::invalid_argument("Invalid graph: The graph matrix is empty.");
        }
        // Check if diagonal elements are all zero
        for (size_t i = 0; i < graph_matrix.size(); ++i)
        {
            if (graph_matrix[i][i] != 0)
            {
                throw std::invalid_argument("Invalid graph: Diagonal elements must be zero.");
            }
        }
        if (graph_matrix.size() != graph_matrix[0].size())
        {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        // Copies the graph matrix
        this->graph_matrix = graph_matrix;
    }

    void Graph::printGraph() const
    {
        std::cout << "Graph with " << graph_matrix.size() << " vertices and " << countEdges() << " edges." << std::endl;

        // Prints the adjacency matrix
        for (const std::vector<int> &row : graph_matrix)
        {
            for (int element : row)
            {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
    }

    bool Graph::isDirected() const
    {
        // Checks if the graph matrix represents a directed graph
        for (size_t i = 0; i < graph_matrix.size(); ++i)
        {
            for (size_t j = 0; j < graph_matrix.size(); ++j)
            {
                if (graph_matrix[i][j] != graph_matrix[j][i])
                {
                    return true; // There is an edge from i to j but not from j to i - the graph is directed
                }
            }
        }

        return false; // If there are no differing edges, the graph is undirected
    }

    int Graph::countEdges() const
    {
        int edges_count = 0;

        // Check if the graph is directed
        bool directed = isDirected();

        for (size_t i = 0; i < graph_matrix.size(); ++i)
        {
            for (size_t j = 0; j < graph_matrix.size(); ++j)
            {
                // For directed graph, count only if there's an edge from i to j
                // For undirected graph, count if there's any edge between i and j
                if ((graph_matrix[i][j] > 0) && (!directed || (directed && graph_matrix[j][i] > 0)))
                {
                    edges_count++;
                }
            }
        }

        return edges_count;
    }

    int Graph::isWeighted() const
    {
        // Checks if the graph is weighted and if it contains negative edges
        for (const std::vector<int> &row : graph_matrix)
        {
            for (int element : row)
            {
                if (element < 0)
                {
                    return -1; // The graph contains negative edges
                }
                if (element != 0 && element != 1)
                {
                    return 1; // The graph is weighted
                }
            }
        }

        return 0; // The graph is unweighted and contains no negative edges
    }

    const std::vector<std::vector<int>> &Graph::getGraphMatrix() const
    {
        return graph_matrix;
    }


 // Arithmetic operators

    Graph Graph::operator+(const Graph &other) const
    {
        // Verify that the matrices have the same size
        if (graph_matrix.size() != other.graph_matrix.size())
        {
            throw std::invalid_argument("Graphs have different sizes");
        }

        // Create a new graph to store the result
        Graph result;

        // Copy the size of the graph matrix
        result.loadGraph(graph_matrix);

        // Perform element-wise addition
        for (size_t i = 0; i < graph_matrix.size(); ++i)
        {
            for (size_t j = 0; j < graph_matrix[i].size(); ++j)
            {
                result.graph_matrix[i][j] += other.graph_matrix[i][j];
            }
        }

        return result;
    }
Graph&  Graph::operator+=(const Graph& other) {
        *this = *this + other;
        return *this;
    }
 // Unary plus
    Graph Graph::operator+() const
    {
        // Create a copy of the current graph
        Graph result(*this);
        return result;
    }
    
    Graph Graph::operator-(const Graph &other) const
    {
        // Verify that the matrices have the same size
        if (graph_matrix.size() != other.graph_matrix.size())
        {
            throw std::invalid_argument("Graphs have different sizes");
        }

        // Create a new graph to store the result
        Graph result;

        // Copy the size of the graph matrix
        result.loadGraph(graph_matrix);

        // Perform element-wise addition
        for (size_t i = 0; i < graph_matrix.size(); ++i)
        {
            for (size_t j = 0; j < graph_matrix[i].size(); ++j)
            {
                result.graph_matrix[i][j] -= other.graph_matrix[i][j];
            }
        }

        return result;
    }

    Graph &Graph::operator-=(const Graph &other)
    {
       *this = *this -other;
        return *this;
    }
  // Unary minus
    Graph Graph::operator-() const
    {
        // Create a copy of the current graph
        Graph result(*this);

        // Negate all the weights in the graph
        for (size_t i = 0; i < result.graph_matrix.size(); ++i)
        {
            for (size_t j = 0; j < result.graph_matrix[i].size(); ++j)
            {
                // Negate the weight
                result.graph_matrix[i][j] = -result.graph_matrix[i][j];
            }
        }

        return result;
    }

   
   bool Graph::isSubMatrix(const Graph &other) const
{
    size_t numRows = graph_matrix.size();
    size_t numCols = graph_matrix[0].size();
    size_t otherRows = other.graph_matrix.size();
    size_t otherCols = other.graph_matrix[0].size();

    if (numRows > otherRows || numCols > otherCols) {
        return false; // If the current matrix is larger than the other, it cannot be a sub-matrix
    }

    // Check each possible starting position in the other graph
    for (size_t i = 0; i <= otherRows - numRows; ++i) {
        for (size_t j = 0; j <= otherCols - numCols; ++j) {
            // Early termination check
            if (graph_matrix[0][0] != 0 && graph_matrix[0][0] != other.graph_matrix[i][j]) {
                continue; // No match in this column, skip to the next
            }

            // Sliding window check
            bool match = true;
            for (size_t x = 0; x < numRows; ++x) {
                for (size_t y = 0; y < numCols; ++y) {
                    if (graph_matrix[x][y] != 0 && graph_matrix[x][y] != other.graph_matrix[i + x][j + y]) {
                        match = false;
                        break;
                    }
                }
                if (!match) {
                    break;
                }
            }
            if (match) {
                return true; // Found a matching sub-matrix
            }
        }
    }

    return false; // No matching sub-matrix found
}
    // Relational operators

    bool Graph::operator==(const Graph &other) const
    {
        // // Compare the sizes of the matrices
        // if (graph_matrix.size() != other.graph_matrix.size())
        // {
        //     return false; // If the sizes are different, the graphs are different
        // }

        // // Compare the contents of the matrices
        // for (size_t i = 0; i < graph_matrix.size(); ++i)
        // {
        //     for (size_t j = 0; j < graph_matrix[i].size(); ++j)
        //     {
        //         if (graph_matrix[i][j] != other.graph_matrix[i][j])
        //         {
        //             return false; // If there is a different value between the matrices, the graphs are different
        //         }
        //     }
        // }

        // // If we reach here, all values are equal - the graphs are identical
        // return true;
        return graph_matrix ==other.graph_matrix;
    }

    bool Graph::operator!=(const Graph &other) const
    {
        // // Compare the sizes of the matrices
        // if (graph_matrix.size() != other.graph_matrix.size())
        // {
        //     return true; // If the sizes are different, the graphs are different
        // }

        // // Compare the contents of the matrices
        // for (size_t i = 0; i < graph_matrix.size(); ++i)
        // {
        //     for (size_t j = 0; j < graph_matrix[i].size(); ++j)
        //     {
        //         if (graph_matrix[i][j] != other.graph_matrix[i][j])
        //         {
        //             return true; // If there is a different value between the matrices, the graphs are different
        //         }
        //     }
        // }

        // // If we reach here, all values are equal - the graphs are identical
        // return false;
        return graph_matrix!=other.graph_matrix;
    }

  
  bool Graph::operator<(const Graph &other) const
{
    if (this->isSubMatrix(other)) {
        return true;
    }
    if (this->countEdges() < other.countEdges()) {
        return true;
    }
    if (graph_matrix.size() < other.graph_matrix.size()) {
        return true;
    }
    return false;
}

  bool Graph::operator<=(const Graph &other) const
{
    if (*this == other || *this < other) {
        return true;
    }
    return false;
}

 bool Graph::operator>(const Graph &other) const
{
    if (other.isSubMatrix(*this)) {
        return true;
    }
    if (this->countEdges() > other.countEdges()) {
        return true;
    }
    if (graph_matrix.size() > other.graph_matrix.size()) {
        return true;
    }
    return false;
}

bool Graph::operator>=(const Graph &other) const{
    if (*this == other || *this > other) {
        return true;
    }
    return false;
}

    std::ostream &operator<<(std::ostream &os, const Graph &graph)
    {
        // Print the number of vertices and edges
        os << "Graph with " << graph.graph_matrix.size() << " vertices and " << graph.countEdges() << " edges." << std::endl;

        // Print the adjacency matrix
        for (const auto &row : graph.graph_matrix)
        {
            os << "[";
            for (const auto &element : row)
            {
                os << element << " ";
            }

            os << "]" << std::endl;
        }

        return os;
    }
    // Pre-increment: Increase the weight of all edges by 1
    Graph& Graph::operator++() {
        for (size_t i = 0; i < graph_matrix.size(); ++i) {
            for (size_t j = 0; j < graph_matrix[i].size(); ++j) {
                if(i!=j){
                ++graph_matrix[i][j];}
            }
        }
        return *this;
    }

    // Post-increment operator
    Graph Graph::operator++(int) {
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    // Pre-decrement operator
    Graph& Graph::operator--() {
        for (size_t i = 0; i < graph_matrix.size(); ++i) {
            for (size_t j = 0; j < graph_matrix[i].size(); ++j) {
                if(i!=j){
                --graph_matrix[i][j];}
            }
        }
        return *this;
    }

    // Post-decrement operator
    Graph Graph::operator--(int) {
        Graph temp = *this;
        --(*this);
        return temp;
    }
    Graph& Graph::operator*(int num)
    {
        for (size_t i = 0; i < graph_matrix.size(); ++i)
        {
            for (size_t j = 0; j < graph_matrix[i].size(); ++j)
            {

                graph_matrix[i][j] *= num;
            }
        }
        return *this;
    }

    Graph Graph::operator*(const Graph &other) const
    {
        // Verify that the matrices have the same size
        if (graph_matrix.size() != other.graph_matrix.size())
        {
            throw std::invalid_argument("Graphs have different sizes");
        }

        // Create a new graph to store the result
        Graph result;

        // Resize the result matrix to match the size of the input graphs
        result.graph_matrix.resize(graph_matrix.size(), std::vector<int>(graph_matrix.size(), 0));

        // Perform matrix multiplication
        for (size_t i = 0; i < graph_matrix.size(); ++i)
        {
            for (size_t j = 0; j < graph_matrix[i].size(); ++j)
            {

                int sum = 0;

                for (size_t k = 0; k < graph_matrix.size(); ++k)
                {
                    sum += graph_matrix[i][k] * other.graph_matrix[k][j];
                }

                result.graph_matrix[i][j] = sum;
                if (i == j)
                {
                    result.graph_matrix[i][j] = 0;
                }
            }
        }

        return result;
    }

 
}