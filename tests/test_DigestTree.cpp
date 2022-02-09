#include <iostream>
#include <cstring>
#include "../core/DigestTree.h"

using namespace std;

int main(int argc, char** argv){
	int level_multipliers[5] = {16, 15, 18, 20};
	DigestTree* digestTree = new DigestTree(5, level_multipliers);
	
	cout<<hex;
	digestTree->put(1,1,0x111122);
	cout<<"digestTree[1,1]: "<<(digestTree->get(1,1))<<endl;
	cout<<"digestTree[1,0]: "<<(digestTree->get(1,0))<<endl;
	
	delete digestTree;
}
