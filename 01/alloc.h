#include <cstddef>


class Allocator
{
	size_t  offset = 0, Max_Size = 0;
	char* memory = nullptr;
public:
    void makeAllocator(size_t maxSize);
	Allocator() = default;
	char* alloc(size_t size);
	void reset();
	~Allocator();
};

