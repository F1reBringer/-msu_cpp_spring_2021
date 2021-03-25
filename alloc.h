#include <cstddef>

class Allocator {
	size_t  offset, Max_Size;
	char* memory;
public:
	Allocator(size_t MAXSIZE);
	char* alloc(size_t size);
	void reset();
	~Allocator();
};
