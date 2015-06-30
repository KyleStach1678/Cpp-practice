#include "TreeBuilder.h"

#include <string>
#include <fstream>
#include <sstream>
#include "Tree.h"
#include <cstdlib>
#include <stack>
#include <cstring>
#include <iostream>

std::tuple<int,int> TreeBuilder::commaParse(std::string commaString) {
	int src;
	int dest;

	for (int i = 0; i < commaString.length(); i++) {
		if (commaString[i] == ',') {
			if (commaString[0] != 'n') {
				src = std::stoi(commaString.substr(0,i));
				dest = std::stoi(commaString.substr(i+1));
			}
			else {
				src = -1;
				dest = -1;
			}
		}
	}
	return std::make_tuple(src,dest);
}

std::tuple<Tree*, TreeSearcher> TreeBuilder::parse(std::string filename) {
	std::ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		std::cout << filename << "not found." << std::endl;
		exit(0);
	}
	std::string buf;
	std::getline(file, buf);
	int numNodes = std::stoi(buf);

	std::getline(file,buf);
	int src, dest; 
	std::tie(src,dest) = commaParse(buf);

	ParsedMap info;
	int rootname = -1;

	while(!file.eof()) {
		std::getline(file,buf);
		if (buf.length() < 1 ) break;

		int node = std::stoi(buf);
		if (rootname == -1) {
			rootname = node;
		}
		std::getline(file,buf);
		std::stringstream ss(buf);
		std::string leftChild, rightChild;
		ss >> leftChild >> rightChild;

		leftChild = leftChild.substr(1,leftChild.length()-2);
		rightChild = rightChild.substr(1, rightChild.length()-2);

		if (rightChild.length() < 1 || leftChild.length() < 1) break;
		int leftName, leftWeight, rightName, rightWeight;
		std::tie(leftName,leftWeight) = commaParse(leftChild);
		std::tie(rightName,rightWeight) = commaParse(rightChild);

		info[node] = std::make_tuple(leftName,leftWeight,rightName,rightWeight);
	}
	file.close();

	Tree* t = new Tree(rootname);
	TreeSearcher search = populate(t, info, src, dest);
	return std::make_tuple(t, search);
}

TreeSearcher TreeBuilder::populate(Tree *tree, ParsedMap nodeMap, int src, int dest) {
	std::stack<int> status;
	Node *currentNode = tree -> Root();
	status.push(0);
	TreeSearcher searcher;
	while (!status.empty()) {
		if (currentNode->Value() == src) {
			searcher.src = currentNode;
		}
		if (currentNode->Value() == dest) {
			searcher.dest = currentNode;
		}
		if (status.top() == 0) { // Initialize children
			status.top()++;
			auto it = nodeMap.find(currentNode->Value());
			if (it != nodeMap.end()) {
				int leftName, leftWeight, rightName, rightWeight;
				std::tie(leftName, leftWeight, rightName, rightWeight) = it->second;
				if (leftName != -1) {
					currentNode->Left(new Node(leftName, currentNode, leftWeight));
				}
				if (rightName != -1) {
					currentNode->Right(new Node(rightName, currentNode, rightWeight));
				}
				nodeMap.erase(it);
			}
		}
		else if (status.top() == 1) { // Populate left child
			status.top()++;
			if (currentNode->Left()) {
				status.push(0);
				currentNode = currentNode->Left();
			}
		}
		else if (status.top() == 2) { // Populate right child
			status.top()++;
			if (currentNode->Right()) {
				status.push(0);
				currentNode = currentNode->Right();
			}
		}
		else { // Finished, go up the tree
			status.pop();
			currentNode = currentNode->Parent();
		}
	}
	return searcher;
}