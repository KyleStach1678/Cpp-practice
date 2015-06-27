#include "Tree.h"

#include <sstream>
#include <iostream>
#include <stack>
#include <tuple>

Tree::Tree(int rootval) {
  _root = new Node(rootval, nullptr, -1);
  tree_depth = 0;
}

Node *Tree::Root() { return _root; }

Node *Tree::FindNode(int node) {
  Node *currentNode = _root;
  std::stack<short> completed;
  completed.push(0);
  while (currentNode->Value() != node && !completed.empty()) {
    if (completed.top() == 0) {
      // Search the left side for the node
      if (currentNode->Left() != nullptr) {
        currentNode = currentNode->Left();
        completed.push(0);
      } else {
        completed.top()++;
      }
    } else if (completed.top() == 1) {
      // Search the right side for the node
      if (currentNode->Right() != nullptr) {
        currentNode = currentNode->Right();
        completed.push(false);
      } else {
        completed.pop();
        completed.top()++;
        currentNode = currentNode->Parent();
      }
    } else {
      completed.pop();
    }
  }
  return currentNode;
}

Node *Tree::AddNode(int child_name, int path_weight, Node *parent) {
  if (parent == nullptr) {
    while (_root->AddChild(child_name, path_weight, tree_depth) == nullptr) {
      tree_depth++;
    }
  }
}

Node *Tree::AddNode(int child_name, int path_weight, int parent) {
  return AddNode(child_name, path_weight, FindNode(parent));
}

Node *Tree::RemoveNode(Node *node) {
  node->Parent()->RemoveChild(node->Value());
}

Node *Tree::RemoveNode(int node_value) { RemoveNode(FindNode(node_value)); }

std::string Tree::ToString() {
  std::stringstream out;
  Node *currentNode = _root;
  std::stack<short> completed;
  completed.push(0);
  while (!completed.empty()) {
    if (completed.top() == 0) {
      for (int i = 0; i < completed.size(); i++) {
        out << "  ";
      }
      out << currentNode->Value() << '\n';
    }

    if (completed.top() == 0) {
      if (currentNode->Left() == nullptr) {
        completed.top()++;
      } else {
        currentNode = currentNode->Left();
        completed.top()++;
        completed.push(0);
      }
    } else if (completed.top() == 1) {
      if (currentNode->Right() == nullptr) {
        completed.top()++;
      } else {
        currentNode = currentNode->Right();
        completed.top()++;
        completed.push(0);
      }
    } else {
      currentNode = currentNode->Parent();
      completed.pop();
    }
  }
  return out.str();
}
