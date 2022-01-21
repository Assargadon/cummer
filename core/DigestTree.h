#include <cstdint>
#include <vector>

class DigestTree
{
public:
	DigestTree(int levels, int level_multipliers[]);
	~DigestTree();

private:
	std::vector<uint64_t *> tree_buffer;
	void _init_tree_buffer(int levels, int level_multipliers[]);
};
