#include <iostream>
#include <cstring>
#include "../core/DigestTree.h"

int main(int argc, char** argv){
	int level_multipliers[5] = {16, 15, 18, 20};
	DigestTree* digestTree = new DigestTree(5, level_multipliers);
	delete digestTree;
}
