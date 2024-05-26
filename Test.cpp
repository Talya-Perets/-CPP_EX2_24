#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
        ariel::Graph g4;

    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};

     g4.loadGraph(expectedGraph);
    CHECK(g3 == g4);
}

TEST_CASE("Test graph sub")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
        ariel::Graph g4;

    vector<vector<int>> expectedGraph1 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

     g4.loadGraph(expectedGraph1);

      ariel::Graph g5;
    vector<vector<int>> graphh = {
        {0, 2, 2, 1},
        {1, 0, 5, 0},
        {-1, 1, 0, 5},
         {1, 0, 2, 0}};
    g5.loadGraph(graphh);
    ariel::Graph g6;
    vector<vector<int>> weightedGraphh = {
        {0, 2, 1, -1},
        {2, 0, 1, 0},
        {3, 1, 0, 1},
        {1, 0, 2, 0}};
    g6.loadGraph(weightedGraphh);
    ariel::Graph g7 = g5 - g6;
        ariel::Graph g8;

    vector<vector<int>> expectedGraph2 = {
       {0, 0, 1, 2},
        {-1, 0, 4, 0},
        {-4, 0, 0, 4},
        {0, 0, 0, 0}};

     g8.loadGraph(expectedGraph2);
    
    CHECK(g3 == g4);
    CHECK(g7 == g8);


}

TEST_CASE("Test graph addition assignment") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0, 3},
        {1, 0, 1, 4},
        {0, 1, 0, 2},
        {3, 4, 2, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 2, 1, 0},
        {2, 0, 3, 1},
        {1, 3, 0, 4},
        {0, 1, 4, 0}
    };
    g2.loadGraph(graph2);

    g1 += g2;
        ariel::Graph g3;

    std::vector<std::vector<int>> expectedGraph = {
        {0, 3, 1, 3},
        {3, 0, 4, 5},
        {1, 4, 0, 6},
        {3, 5, 6, 0}
        };
    g3.loadGraph(expectedGraph);


    CHECK(g1==g3);
}

TEST_CASE("Test graph subtraction assignment") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 3, 1, 3},
        {3, 0, 4, 5},
        {1, 4, 0, 6},
        {3, 5, 6, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 2, 1, 0},
        {2, 0, 3, 1},
        {1, 3, 0, 4},
        {0, 1, 4, 0}
    };
    g2.loadGraph(graph2);

    g1 -= g2;
   ariel::Graph g3;

    std::vector<std::vector<int>> expectedGraph = {
        {0, 1, 0, 3},
        {1, 0, 1, 4},
        {0, 1, 0, 2},
        {3, 4, 2, 0}
    };
        g3.loadGraph(expectedGraph);

    CHECK(g1==g3);
}


TEST_CASE("Test unary plus operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0, 3},
        {1, 0, 1, 4},
        {0, 1, 0, 2},
        {3, 4, 2, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2 = +g1;
     ariel::Graph g3;
    std::vector<std::vector<int>> expectedGraph = {
        {0, 1, 0, 3},
        {1, 0, 1, 4},
        {0, 1, 0, 2},
        {3, 4, 2, 0}
    };
        g3.loadGraph(expectedGraph);

    CHECK(g2==g3);
}

TEST_CASE("Test unary minus operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0, 3},
        {1, 0, 1, 4},
        {0, 1, 0, 2},
        {3, 4, 2, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2 = -g1;
    ariel::Graph g3;

    std::vector<std::vector<int>> expectedGraph = {
        {0, -1, 0, -3},
        {-1, 0, -1, -4},
        {0, -1, 0, -2},
        {-3, -4, -2, 0}
    };
        g3.loadGraph(expectedGraph);

    CHECK(g2==g3);
}
TEST_CASE("Larger graph with sub-matrix relationship") {
  ariel::Graph g1;
      std::vector<std::vector<int>> graph1 = {

  {0, 2, 3}, {1, 0, 3}, {4, 5, 0}
  };
  g1.loadGraph(graph1);

  ariel::Graph g2;
   std::vector<std::vector<int>> graph2 = 
  {
    { 0 , 2}, {1, 0}};
    g2.loadGraph(graph2);
  REQUIRE(g1 > g2);
}

TEST_CASE("Test < that no sub namtrix ant same size ") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };        
    
    g1.loadGraph(graph1);

    ariel::Graph g2 ;
  

    std::vector<std::vector<int>> graph2 = {
         {0, 0, 1},
        {0, 0, 0},
        {1, 0, 0}
    };  
   g2.loadGraph(graph2);
    REQUIRE(g1 > g2); 
    REQUIRE(g1 >= g2); 

    ariel::Graph g3 ;

    std::vector<std::vector<int>> graph3 = {
         {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };  
    g3.loadGraph(graph3);
    REQUIRE(g2> g3); 


   
}

TEST_CASE("Smaller graph is not greater") {
   ariel::Graph g1;
      std::vector<std::vector<int>> graph1 = {
        {0, 2}, {1, 0}};
  g1.loadGraph(graph1);

  ariel::Graph g2;
   std::vector<std::vector<int>> graph2 = 
  {{0, 2, 3}, {1, 0, 3}, {4, 5, 0}};
    g2.loadGraph(graph2);
REQUIRE(!(g1 > g2));
REQUIRE(!(g1 >= g2));
REQUIRE(g1 < g2); // g2 is bigger matrix then g1
REQUIRE(g1 <= g2);

}

TEST_CASE("kkkSmaller graph is not greater") {

ariel::Graph g1;
   std::vector<std::vector<int>> graph1 = 
  {{0, 2, 3 ,4,5}, 
  {1, 0, 3 , 4,5}, 
  {4, 5, 0, 3,5},
   {4, 5, 0, 0,0},
   {1, 5, 2, 0,0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
      std::vector<std::vector<int>> graph2 = {
        {0, 3}, {5, 0}};
  g2.loadGraph(graph2);
 REQUIRE(g1 > g2) ;
  REQUIRE(g1 >= g2) ;
  REQUIRE(!(g1 < g2)) ;
REQUIRE(!(g1 <= g2));

}

TEST_CASE("Test pre-increment and post-increment operators") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ++g1;
    ariel::Graph g2;
    std::vector<std::vector<int>> expectedGraph1 = {
        {0, 2, 1},
        {2, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(expectedGraph1);

    CHECK(g1 == g2);

    g1++;
    ariel::Graph g3;
    std::vector<std::vector<int>> expectedGraph2 = {
        {0, 3, 2},
        {3, 0, 3},
        {2, 3, 0}
    };
    g3.loadGraph(expectedGraph2);

    CHECK(g1 == g3);
}

TEST_CASE("Test pre-decrement and post-decrement operators") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 3, 2},
        {3, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);

    --g1;
    ariel::Graph g2;
    std::vector<std::vector<int>> expectedGraph1 = {
        {0, 2, 1},
        {2, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(expectedGraph1);

    CHECK(g1 == g2);

    g1--;
    ariel::Graph g3;
    std::vector<std::vector<int>> expectedGraph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g3.loadGraph(expectedGraph2);

    CHECK(g1 == g3);
}


TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;

    ariel::Graph g3;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
     g3.loadGraph(expectedGraph);
  
    CHECK(g4==g3);
}



