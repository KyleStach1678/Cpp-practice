#ifndef NODEPATH_H
#define NODEPATH_H

#include <vector>
#include <string>

class Node;

class NodePath {
public:
	void AddPathNode(Node *pathNode);
	std::vector<Node *> GetPathVector();
	int CalculateWeight();
	std::string ToString();

private:
	std::vector<Node *> pathVector;
};


#endif