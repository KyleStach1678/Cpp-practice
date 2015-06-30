#include "TreeSearcher.h"

#include "Node.h"
#include "NodePath.h"

#include <deque>
#include <stack>

NodePath TreeSearcher::FindPath(Node* src, Node* dest) {
	src = src ? src : this->src;
	dest = dest ? dest : this->dest;
	std::deque<Node *> srcQueue;
	std::stack<Node *> destStack;
	NodePath path;
	Node *currentNode = src;
	while (currentNode) {
		srcQueue.push_back(currentNode);
		currentNode = currentNode -> Parent();
	}

	currentNode = dest;
	while(currentNode) {
		destStack.push(currentNode);
		currentNode = currentNode -> Parent();
	}

	Node* common;
	while(srcQueue.size() > 1 && destStack.size() > 1 && srcQueue.back() == destStack.top()) {
		common = destStack.top();
		srcQueue.pop_back();
		destStack.pop();
	}

	if (srcQueue.back() == destStack.top()) {
		common = destStack.top();
		if (srcQueue.size() > 1)
			srcQueue.pop_back();
		else if (destStack.size() > 1)
			destStack.pop();
	}

	for(Node *node : srcQueue) {
		path.AddPathNode(node);
	}

	if (common != src && common != dest)
		path.AddPathNode(common);

	while (!destStack.empty()) {
		path.AddPathNode(destStack.top());
		destStack.pop();
	}
	return path;
}