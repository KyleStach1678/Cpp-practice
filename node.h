#include <iostream>
#include <map>
#include <tuple>
#include <fstream>
#include <sstream>
#include <vector>

class Node {
public:
	static std::tuple<Node*,Node*,Node*,Node*> parse(std::string filename);
	typedef std::map<int, std::tuple<int, int, int, int>> ParsedMap;

	Node* left;
	Node* right;
	Node* parent;
	int node_name;
	int parent_weight;

	// Create a new node
	Node(int name, Node* p, int parent_weight);

	std::tuple<std::vector<int>,int> findPath(Node *src, Node *dest);

	// Search for a specific child node, returning the weight of the
	// path to the node or -1 if the node is not found
	int search_child_weight(int search_name);

	// Populate the node based on a map of values
	std::tuple<Node*,Node*,Node*> populate(Node::ParsedMap& node_map, int src_name, int dst_name);

	// Create a string representation of the node
	std::string to_string(int depth);

	// Find the shortest path between two nodes
	std::tuple<int, std::vector<int>> shortest_path(Node* targetNode);
};