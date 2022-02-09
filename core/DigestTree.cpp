#include <iostream>
#include "DigestTree.h"

DigestTree::DigestTree(int levels, int level_multipliers[])
{
	_init_tree_buffer(levels, level_multipliers);
}

DigestTree::~DigestTree()
{
	free(tree_buffer[0]);
	std::cout<<"DigestTree was deallocated"<<std::endl;
}

void DigestTree::_init_tree_buffer(int levels, int level_multipliers[])
{
	unsigned int size_of_tree_level = 1; //in _elements_, not bytes
	unsigned long int tree_buffer_size = 0;  // this too in elements

	for(int i=0; i<levels; i++){
		size_of_tree_level *= level_multipliers[i];
		tree_buffer_size += size_of_tree_level;
	}
	
	tree_buffer.resize(levels);
	tree_buffer[0] = (uint64_t *) calloc(sizeof(uint64_t *), tree_buffer_size);

	size_of_tree_level = level_multipliers[0];
	for(int i=1; i<levels; i++){
		tree_buffer[i] = tree_buffer[i-1] + size_of_tree_level;
		size_of_tree_level *= level_multipliers[i];
	}
	
	std::cout<<"Full size of the DigestTree: "<<tree_buffer_size<<" elements,  "<<(tree_buffer_size*sizeof(uint64_t)/1024.0)<<" kb, "<<(tree_buffer_size*sizeof(uint64_t)/1024.0/1024.0)<<" mb"<<std::endl;
}

digest_t DigestTree::get(int level, int entry)
{
	return tree_buffer[level][entry];
}

void DigestTree::put(int level, int entry, digest_t value)
{
	tree_buffer[level][entry] = value;
	//TODO: update upper values of my branch of the tree
}
