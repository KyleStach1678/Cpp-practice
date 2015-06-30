#ifndef TREESEARCHER_H
#define TREESEARCHER_H

class Node;
class NodePath;

class TreeSearcher {
public:
	Node* src;
	Node* dest;
	NodePath FindPath(Node* p_src = nullptr, Node* p_dest = nullptr);
};

#endif