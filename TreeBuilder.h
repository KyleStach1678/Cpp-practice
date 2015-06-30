#ifndef TREEBUILDER_H
#define TREEBUILDER_H

#include <tuple>
#include <string>
#include <map>

#include "TreeSearcher.h"

class Tree;

class TreeBuilder {
private:
	typedef std::map<int, std::tuple<int, int, int, int>> ParsedMap;
	std::tuple<int,int> commaParse(std::string commaString);
public:
	std::tuple<Tree*, TreeSearcher> parse(std::string filename);
	TreeSearcher populate(Tree *tree, ParsedMap nodeMap, int src, int dest);
};

#endif
