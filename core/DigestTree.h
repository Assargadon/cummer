#include <cstdint>
#include <vector>

typedef uint64_t digest_t;

class DigestTree
{
public:
	DigestTree(int levels, int level_multipliers[]);
	~DigestTree();
	
	void put(int level, int entry, digest_t value);
	digest_t get(int level, int entry);

private:
	std::vector<uint64_t *> tree_buffer;
	void _init_tree_buffer(int levels, int level_multipliers[]);
};
