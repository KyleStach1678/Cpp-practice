#ifndef TREE_H
#define TREE_H

#include <memory>
#include <string>
#include "Node.h"

class Tree {
public:
  Tree(int root);
  Node *Root();
  Node *FindNode(int node);
  Node *AddNode(int child_name, int path_weight, Node *parent = nullptr);
  Node *AddNode(int child_name, int path_weight, int parent);
  Node *RemoveNode(Node *node);
  Node *RemoveNode(int node_value);
  std::string ToString();

private:
  Node *_root;
  int tree_depth;
};

#endif
