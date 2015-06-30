#include "TreeSearcher.h"

#include "Node.h"
#include "NodePath.h"

#include <deque>
#include <stack>

NodePath TreeSearcher::FindPath() {
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
	while(srcQueue.back() == destStack.top()) {
		srcQueue.pop_back();
		destStack.pop();
	}
	for(Node *node : srcQueue) {
		path.AddPathNode(node);
	}
	path.AddPathNode(destStack.top()->Parent());
	while (!destStack.empty()) {
		path.AddPathNode(destStack.top());
		destStack.pop();
	}
	return path;
}