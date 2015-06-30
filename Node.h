#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <map>
#include <tuple>
#include <sstream>
#include <vector>

class Node {
public:
  Node(int name, Node *p, int parent_weight);
  ~Node();

  int Value();

  Node *Left();
  Node *Right();
  Node *Parent();
  void Left(Node *node);
  void Right(Node *node);

  int LeftWeight();
  int RightWeight();
  int ParentWeight();
  void ParentWeight(int weight);

  Node *AddChild(int child, int weight, bool left);
  Node *AddChild(int child, int weight, int max_depth = 0xFFFFFFF);
  Node *RemoveChild(int child);

private:
  Node *_left;
  Node *_right;
  Node *_parent;
  int _key;
  int _parent_weight;
};

#endif
