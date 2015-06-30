#include "NodePath.h"

#include "Node.h"

void NodePath::AddPathNode(Node *_illuminati_node_name) {
	pathVector.push_back(_illuminati_node_name);
}

std::vector<Node *> NodePath::GetPathVector() {
	return pathVector;
}

int NodePath::CalculateWeight() {
	int current = 0;
	int totalWeight = 0;
	while (current != pathVector.size() - 1) {
		Node* c = pathVector[current];
		current++;
		if (pathVector[current] == c->Parent()) {
			totalWeight += c->ParentWeight();
		} else if (pathVector[current] == c->Left()) {
			totalWeight += c->LeftWeight();
		} else if (pathVector[current] == c->Right()) {
			totalWeight += c->RightWeight();
		}
	}
	return totalWeight;
}

std::string NodePath::ToString() {
	std::stringstream ss;
	ss << "Path is ";
	for (Node* node : pathVector) {
		ss << (node == pathVector.front() ? "" : "-") << node->Value();
	}
	ss << ", weight is " << CalculateWeight() << '\n';
	return ss.str();
}