#include "node.h"
#include <fstream>

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cout << "No file given" << std::endl;
		exit(0);
	}
	Node::ParsedMap info = {
		std::pair<int, std::tuple<int,int,int,int>>(1, std::tuple<int,int,int,int>(2,5,3,6)),
		std::pair<int, std::tuple<int,int,int,int>>(2, std::tuple<int,int,int,int>(4,7,5,8)),
		std::pair<int, std::tuple<int,int,int,int>>(3, std::tuple<int,int,int,int>(-1,-1,-1,-1)),
		std::pair<int, std::tuple<int,int,int,int>>(4, std::tuple<int,int,int,int>(6,2,7,3)),
		std::pair<int, std::tuple<int,int,int,int>>(5, std::tuple<int,int,int,int>(-1,-1,-1,-1)),
		std::pair<int, std::tuple<int,int,int,int>>(6, std::tuple<int,int,int,int>(-1,-1,-1,-1)),
		std::pair<int, std::tuple<int,int,int,int>>(7, std::tuple<int,int,int,int>(-1,-1,-1,-1)),
	};

	Node* node_root;
	Node* source, *destination, *common;
	std::tie(node_root, source, destination, common) = Node::parse(argv[1]);

	std::vector<int> path;
	int weight;
	std::tie(path, weight) = common->findPath(source, destination);

	std::cout << "Path is " << path[0];
	for (int i = 1; i < path.size(); i++) {
		std::cout << '-' << path[i];
	}
	std::cout << " and weight is " << weight << std::endl;
}