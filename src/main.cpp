#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/range/algorithm.hpp>

#include <fstream>
#include <iostream>

struct Node {
  int id;
  std::string info;
};

using DirectedSimpleGraph =
    boost::adjacency_list<boost::vecS,      // OutEdgeList stored as a vector
                          boost::vecS,      // VertexList stored as a vector
                          boost::directedS, // Directed
                          Node, boost::no_property>;

int main() {
  DirectedSimpleGraph graph;
  boost::dynamic_properties dp;
  dp.property("node_id", boost::get(&Node::id, graph));
  dp.property("label", boost::get(&Node::info, graph));

  // Read graph from a .gv file
  std::ifstream graph_file("../data/simple.gv");
  boost::read_graphviz(graph_file, graph, dp);

  // Print all the vertices
  for (auto [it, it_end] = boost::vertices(graph); it != it_end; ++it) {
    std::cout << "Vertex #" << *it << " id : " << graph[*it].id
              << " info : " << graph[*it].info << std::endl;
  }

  // Find a vertex with given "info" field
  auto [it, it_end] = boost::vertices(graph);
  std::string target_info = "Three";
  auto it_found = boost::range::find_if(boost::vertices(graph), [&](auto it) {
    return graph[it].info == target_info;
  });
  if (it_found != it_end) {
    std::cout << "Found node with info = " << graph[*it_found].info;
  }

  // Write graph to stdout
  boost::write_graphviz_dp(std::cout, graph, dp);

  // Write graph to file
  std::ofstream graph_file_out("./out.gv");
  boost::write_graphviz_dp(graph_file_out, graph, dp);
}