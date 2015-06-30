#include "Node.h"
#include <cstdlib>
#include <cstring>
#include <stack>

Node::Node(int key, Node *p, int parent_weight) {
  _key = key;
  _parent = p;
  _parent_weight = parent_weight;
  Left(nullptr);
  Right(nullptr);
}

Node::~Node() {
  if (Left() != nullptr) {
    delete Left();
  }
  if (Right() != nullptr) {
    delete Right();
  }
}

int Node::Value() { return _key; }

Node *Node::Left() { return _left; }
Node *Node::Right() { return _right; }
Node *Node::Parent() { return _parent; }
void Node::Left(Node *node) { _left = node; }
void Node::Right(Node *node) { _right = node; }

int Node::LeftWeight() { return Left()->ParentWeight(); }
int Node::RightWeight() { return Right()->ParentWeight(); }
int Node::ParentWeight() { return _parent_weight; }
void Node::ParentWeight(int weight) { _parent_weight = weight; }

Node *Node::AddChild(int child_val, int weight, bool left) {
  Node *child = new Node(child_val, this, weight);
  if (left && Left() == nullptr) {
    this->Left(child);
  } else if (!left && this->Right() == nullptr) {
    this->Right(child);
  }
  return child;
}

Node *Node::AddChild(int child_val, int weight, int max_depth) {
  Node *child = nullptr;

  if (Left() == nullptr) {
    child = new Node(child_val, this, weight);
    Left(child);
  } else if (Right() == nullptr) {
    child = new Node(child_val, this, weight);
    Right(child);
  } else if (max_depth > 1) {
    if (child == nullptr)
      child = Left()->AddChild(child_val, weight, max_depth - 1);
    if (child == nullptr)
      child = Right()->AddChild(child_val, weight, max_depth - 1);
  } else {
    child = nullptr;
  }
  return child;
}

Node *Node::RemoveChild(int child) {
  Node *foundNode = nullptr;
  if (Left() != nullptr) {
    if (Left()->Value() == child) {
      foundNode = Left();
      Left(nullptr);
    } else {
      foundNode = Left()->RemoveChild(child);
    }
  } else if (Right() != nullptr) {
    if (Right()->Value() == child) {
      foundNode = Right();
      Right(nullptr);
    } else {
      foundNode =
          (foundNode == nullptr) ? Right()->RemoveChild(child) : foundNode;
    }
  }
  return foundNode;
}
