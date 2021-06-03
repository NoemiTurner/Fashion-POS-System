//----------------------------------------------------------------------
// Name: Noemi Turner
// File: fashion_project_tests.cpp
// Date: Summer 2021
// Desc: Unit tests for fashion business software project
//----------------------------------------------------------------------


#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "fashion_project.h"


using namespace std;


//----------------------------------------------------------------------
// Helper functions for testing
//----------------------------------------------------------------------

// void print_graph(const Graph& g)
// {
//   int n = g.vertex_count();
//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < n; ++j) {
//       if (g.has_edge(i,j)) {
//         int edge_label;
//         g.get_edge(i, j, edge_label);
//         cout << "(" << i << "," << edge_label << "," << j << ")" << endl;
//       }
//     }
//   }
// }


// void print_path(const list<int>& path)
// {
//   for (int v : path)
//     cout << v << " ";
//   cout << endl;
// }


// //----------------------------------------------------------------------
// // Adjacency List Tests
// //----------------------------------------------------------------------

// TEST(AdjacencyListTest, BasicRemoveEdge) {
//   AdjacencyList g(5);
//   g.set_edge(0, 0, 2);
//   g.set_edge(1, 0, 2);
//   g.set_edge(2, 0, 3);
//   g.set_edge(2, 0, 4);
//   ASSERT_EQ(4, g.edge_count());
//   g.remove_edge(2, 3);
//   ASSERT_EQ(3, g.edge_count());  
//   g.remove_edge(2, 4);
//   ASSERT_EQ(2, g.edge_count());  
//   std::list<int> vertices;
//   g.connected_to(2, vertices);
//   ASSERT_EQ(0, vertices.size());
//   g.connected_from(2, vertices);
//   ASSERT_EQ(2, vertices.size());
//   g.remove_edge(0, 2);
//   ASSERT_EQ(1, g.edge_count());
//   g.remove_edge(1, 2);
//   ASSERT_EQ(0, g.edge_count());
// }

// // Additional remove test #1
// TEST(AdjacencyListTest, RemoveEdgeWithCycles) {
//   AdjacencyList g(6);
//   g.set_edge(0, 0, 1);
//   g.set_edge(0, 0, 4);
//   g.set_edge(1, 0, 4);

//   g.set_edge(4, 0, 2);
//   g.set_edge(2, 0, 3);
//   g.set_edge(3, 0, 1);

//   ASSERT_EQ(6, g.edge_count());
//   g.remove_edge(2, 3);
//   ASSERT_EQ(5, g.edge_count());  
//   g.remove_edge(0, 1);
//   ASSERT_EQ(4, g.edge_count()); 

//   std::list<int> vertices1;
//   g.connected_to(4, vertices1);
//   ASSERT_EQ(1, vertices1.size());
//   std::list<int> vertices2;
//   g.connected_from(4, vertices2);
//   ASSERT_EQ(2, vertices2.size());

//   g.remove_edge(0, 4);
//   ASSERT_EQ(3, g.edge_count());
//   g.remove_edge(3, 1);
//   ASSERT_EQ(2, g.edge_count()); 
// }

// // Additional remove test #2
// TEST(AdjacencyListTest, RemoveEdgeWithSelfEdges) {
//   AdjacencyList g(4);
//   g.set_edge(0, 0, 1);
//   g.set_edge(0, 0, 2);
//   g.set_edge(2, 0, 1);
//   g.set_edge(2, 0, 2);
//   g.set_edge(2, 0, 3);
//   g.set_edge(3, 0, 3);
//   ASSERT_EQ(6, g.edge_count());

//   g.remove_edge(3, 3);
//   ASSERT_EQ(5, g.edge_count());  
//   g.remove_edge(0, 1);
//   ASSERT_EQ(4, g.edge_count());

//   std::list<int> vertices;
//   g.connected_to(2, vertices);
//   ASSERT_EQ(3, vertices.size());
//   g.connected_from(2, vertices);
//   ASSERT_EQ(5, vertices.size());
//   g.remove_edge(0, 2);
//   ASSERT_EQ(3, g.edge_count());
//   g.remove_edge(2, 3);
//   ASSERT_EQ(2, g.edge_count());
// }


// TEST(AdjacencyListTest, BasicStronglyConnectedComponents) {
//   AdjacencyList g(12);
//   g.set_edge(0, 0, 1);
//   g.set_edge(1, 0, 3);
//   g.set_edge(1, 0, 4);
//   g.set_edge(4, 0, 1);
//   g.set_edge(2, 0, 5);
//   g.set_edge(5, 0, 2);
//   g.set_edge(1, 0, 2);
//   g.set_edge(4, 0, 5);
//   g.set_edge(4, 0, 6);
//   g.set_edge(5, 0, 7);
//   g.set_edge(6, 0, 7);
//   g.set_edge(7, 0, 10);
//   g.set_edge(10, 0, 11);
//   g.set_edge(11, 0, 9);
//   g.set_edge(9, 0, 8);
//   g.set_edge(8, 0, 6);
//   g.set_edge(6, 0, 9);
//   Map components;
//   g.strongly_connected_components(components);
//   ASSERT_EQ(12, components.size());
//   int counts[5];
//   counts[0] = components[0];
//   counts[1] = components[3];
//   counts[2] = components[1];
//   counts[3] = components[2];
//   counts[4] = components[6];
//   // each count should be unique
//   for (int i = 0; i < 4; ++i)
//     for (int j = i + 1; j < 5; ++j)
//       ASSERT_NE(counts[i], counts[j]);
//   // check that the components are correct
//   ASSERT_EQ(counts[2], components[4]); 
//   ASSERT_EQ(counts[3], components[5]);
//   ASSERT_EQ(counts[4], components[7]);
//   ASSERT_EQ(counts[4], components[8]);
//   ASSERT_EQ(counts[4], components[9]);
//   ASSERT_EQ(counts[4], components[10]);
//   ASSERT_EQ(counts[4], components[11]);  
// }

// // Additional strongly connected components test #1
// TEST(AdjacencyListTest, TrickyStronglyConnectedComponents) {
//   AdjacencyList g(6);
//   g.set_edge(0, 0, 1);
//   g.set_edge(1, 0, 2);
//   g.set_edge(2, 0, 0);
//   g.set_edge(2, 0, 3);
//   g.set_edge(3, 0, 4);
//   g.set_edge(3, 0, 5);
//   g.set_edge(4, 0, 5);
//   g.set_edge(5, 0, 4);

//   Map components;
//   g.strongly_connected_components(components);
//   ASSERT_EQ(6, components.size());
//   int counts[3];
//   counts[0] = components[0];
//   counts[1] = components[3];
//   counts[2] = components[4];
//   // each count should be unique
//   for (int i = 0; i < 3; ++i)
//     for (int j = i + 1; j < 4; ++j)
//       ASSERT_NE(counts[i], counts[j]);
//   // check that the components are correct
//   ASSERT_EQ(counts[0], components[0]); 
//   ASSERT_EQ(counts[0], components[1]);
//   ASSERT_EQ(counts[0], components[2]);
//   ASSERT_EQ(counts[1], components[3]); 
//   ASSERT_EQ(counts[2], components[4]);
//   ASSERT_EQ(counts[2], components[5]);
// }


// // Additional strongly connected components test #2
// TEST(AdjacencyListTest, TrivialStronglyConnectedComponents) {
//   AdjacencyList g(6);

//   Map components;
//   g.strongly_connected_components(components);
//   ASSERT_EQ(6, components.size());
//   int counts[6];
//   counts[0] = components[0];
//   counts[1] = components[1];
//   counts[2] = components[2];
//   counts[3] = components[3];
//   counts[4] = components[4];
//   counts[5] = components[5];
//   // each count should be unique
//   for (int i = 0; i < 6; ++i)
//     for (int j = i + 1; j < 7; ++j)
//       ASSERT_NE(counts[i], counts[j]);
//   // // check that the components are correct
//   ASSERT_EQ(counts[0], components[0]); 
//   ASSERT_EQ(counts[1], components[1]);
//   ASSERT_EQ(counts[2], components[2]);
//   ASSERT_EQ(counts[3], components[3]); 
//   ASSERT_EQ(counts[4], components[4]);
//   ASSERT_EQ(counts[5], components[5]);
// }


// TEST(AdjacencyListTest, BasicTransitiveReduction) {
//   AdjacencyList g(5);
//   g.set_edge(0, 0, 1);
//   g.set_edge(1, 0, 0);
//   g.set_edge(1, 0, 2);
//   g.set_edge(2, 0, 1);
//   g.set_edge(2, 0, 0);
//   g.set_edge(0, 0, 2);
//   g.set_edge(1, 0, 3);
//   g.set_edge(1, 0, 4);
//   g.set_edge(2, 0, 3);
//   g.set_edge(3, 0, 4);
//   g.set_edge(4, 0, 3);
//   AdjacencyList tr_g(5);
//   g.transitive_reduction(tr_g);
//   print_graph(tr_g);
//   ASSERT_EQ(6, tr_g.edge_count());
//   ASSERT_EQ(true, tr_g.has_edge(0, 1) xor tr_g.has_edge(1, 0));
//   ASSERT_EQ(true, tr_g.has_edge(1, 2) xor tr_g.has_edge(2, 1));
//   ASSERT_EQ(true, tr_g.has_edge(2, 0) xor tr_g.has_edge(0, 2));  
//   ASSERT_EQ(true, tr_g.has_edge(3, 4) and tr_g.has_edge(4, 3));
// }


// // Additional Transitive Reduction Test #1
// TEST(AdjacencyListTest, MoreComplexTransitiveReduction) {
//   AdjacencyList g(7);
//   g.set_edge(0, 0, 1);
//   g.set_edge(1, 0, 0);
//   g.set_edge(0, 0, 2);
//   g.set_edge(2, 0, 0);
//   g.set_edge(2, 0, 1);
//   g.set_edge(1, 0, 4);
//   g.set_edge(1, 0, 5);
//   g.set_edge(5, 0, 1);
//   g.set_edge(5, 0, 3);
//   g.set_edge(3, 0, 5);
//   g.set_edge(3, 0, 4);
//   g.set_edge(4, 0, 3);
//   g.set_edge(4, 0, 6);
//   g.set_edge(5, 0, 4);
//   g.set_edge(0, 0, 5);
//   g.set_edge(0, 0, 6);
//   AdjacencyList tr_g(7);
//   g.transitive_reduction(tr_g);
//   ASSERT_EQ(6, tr_g.edge_count());
//   ASSERT_EQ(true, tr_g.has_edge(0, 1) xor tr_g.has_edge(1, 0));
//   ASSERT_EQ(true, tr_g.has_edge(0, 2) xor tr_g.has_edge(2, 0));
//   ASSERT_EQ(true, tr_g.has_edge(1, 5) xor tr_g.has_edge(5, 1));  
//   ASSERT_EQ(true, tr_g.has_edge(3, 4) and tr_g.has_edge(4, 3));
//   ASSERT_EQ(true, tr_g.has_edge(5, 3) and tr_g.has_edge(3, 5));
//   ASSERT_EQ(true, tr_g.has_edge(4, 6) and tr_g.has_edge(0, 6));
// }

// // Additional Transitive Reduction Test #2
// TEST(AdjacencyListTest, IrreducibleTransitiveReduction) {
//   AdjacencyList g(7);
//   g.set_edge(0, 0, 1);
//   g.set_edge(0, 0, 2);
//   g.set_edge(1, 0, 3);
//   g.set_edge(3, 0, 5);
//   g.set_edge(5, 0, 4);
//   g.set_edge(5, 0, 6);
//   g.set_edge(4, 0, 6);
//   AdjacencyList tr_g(5);
//   g.transitive_reduction(tr_g);
//   ASSERT_EQ(7, tr_g.edge_count());
// }


// TEST(AdjacencyListTest, BasicEulerianPath) {
//   AdjacencyList g(5);
//   g.set_edge(0, 0, 2);
//   g.set_edge(1, 0, 0);
//   g.set_edge(1, 0, 3);
//   g.set_edge(2, 0, 1);
//   g.set_edge(2, 0, 3);
//   g.set_edge(3, 0, 1);
//   g.set_edge(3, 0, 4);  
//   list<int> path;
//   ASSERT_EQ(true, g.directed_eulerian_path(path));
//   print_path(path);
//   ASSERT_EQ(g.edge_count() + 1, path.size());
//   // check for actual edges
//   vector<int> vpath(path.begin(), path.end());
//   for (int i = 0; i < g.edge_count(); ++i) {
//     ASSERT_EQ(true, g.has_edge(vpath[i], vpath[i+1]));
//   }
//   // check for duplicate edges
//   for (int i = 0; i < g.edge_count() - 1; ++i) {
//     int u = vpath[i];
//     int v = vpath[i + 1];
//     for (int j = i + 1; j < g.edge_count(); ++j) {
//       if (vpath[j] == u)
//         ASSERT_NE(v, vpath[j + 1]);
//     }
//   }
//   g.set_edge(2, 0, 4);
//   path.clear();
//   ASSERT_EQ(false, g.directed_eulerian_path(path));
// }


// // Additional Eulerian Path Test #1
// TEST(AdjacencyListTest, NonEulerianPath) {
//   AdjacencyList g(5);
//   g.set_edge(0, 0, 1);
//   g.set_edge(1, 0, 2);
//   g.set_edge(0, 0, 2);
//   g.set_edge(1, 0, 3);
//   g.set_edge(4, 0, 3); 
//   list<int> path;
//   ASSERT_EQ(false, g.directed_eulerian_path(path));
//   path.clear();
//   ASSERT_EQ(false, g.directed_eulerian_path(path));
// }

// // Additional Eulerian Path Test #2
// TEST(AdjacencyListTest, LargerEulerianPath) {
//   AdjacencyList g(10);
//   g.set_edge(0, 0, 1);
//   g.set_edge(1, 0, 2);
//   g.set_edge(2, 0, 3);
//   g.set_edge(3, 0, 4);
//   g.set_edge(1, 0, 4);
//   g.set_edge(4, 0, 1);
//   g.set_edge(4, 0, 5);
//   g.set_edge(5, 0, 6);
//   g.set_edge(6, 0, 5);
//   g.set_edge(5, 0, 7);
//   g.set_edge(7, 0, 8);
//   g.set_edge(8, 0, 9);
//   g.set_edge(9, 0, 7);
 
//   list<int> path;
//   ASSERT_EQ(true, g.directed_eulerian_path(path));
//   ASSERT_EQ(g.edge_count() + 1, path.size());
//   // check for actual edges
//   vector<int> vpath(path.begin(), path.end());
//   for (int i = 0; i < g.edge_count(); ++i) {
//     ASSERT_EQ(true, g.has_edge(vpath[i], vpath[i+1]));
//   }
//   // check for duplicate edges
//   for (int i = 0; i < g.edge_count() - 1; ++i) {
//     int u = vpath[i];
//     int v = vpath[i + 1];
//     for (int j = i + 1; j < g.edge_count(); ++j) {
//       if (vpath[j] == u)
//         ASSERT_NE(v, vpath[j + 1]);
//     }
//   }
//   g.set_edge(2, 0, 7);
//   path.clear();
//   ASSERT_EQ(false, g.directed_eulerian_path(path));
// }

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

