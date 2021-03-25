#include "alloc.h"


void Allocator::makeAllocator (size_t maxSize)
{
    if(Max_Size != 0)
        delete[] memory;
    Max_Size = maxSize;
    offset = 0;
    memory = new char[Max_Size];
}

char* Allocator::alloc(size_t size)
{
    if(offset + size > Max_Size)
        return nullptr;
    char* tmp = memory + offset;
    offset += size;
    return tmp;
}

void Allocator::reset()
{
    offset = 0;
}

Allocator::~Allocator()
{
    delete[] memory;
}
