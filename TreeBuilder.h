#ifndef TREEBUILDER_H
#define TREEBUILDER_H

class TreeBuilder {
private:
  typedef std::map<int, std::tuple<int, int, int, int>> ParsedMap;
public:
	std::tuple<Tree*, TreeSearcher> parse(std::string filename);
};

#endif
