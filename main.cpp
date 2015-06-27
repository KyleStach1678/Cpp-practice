#include <iostream>
#include "Node.h"
#include "Tree.h"

int main() {
  Tree *t = new Tree(1);
  t->AddNode(11, 4);
  t->AddNode(8, 4);
  t->AddNode(9, 5);
  t->AddNode(4, 9);
  t->AddNode(6, 3);
  t->AddNode(5, 2);
  t->AddNode(12, 5);
  t->AddNode(7, 7);
  t->AddNode(10, 7);
  t->AddNode(2, 4);
  t->AddNode(3, 1);
  delete t->RemoveNode(11);
  std::cout << t->ToString() << std::endl;
  return 0;
}
