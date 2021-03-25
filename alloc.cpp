#include "alloc.h"



Allocator::Allocator(size_t MAXSIZE){
    Max_Size = MAXSIZE;
    offset = 0;
    memory = new char[Max_Size];
}

char* Allocator::alloc(size_t size) {
    if(offset + size > Max_Size) {
        return nullptr;
    }
    char* tmp = memory + offset;
    offset += size;
    return tmp;
}

void Allocator::reset(){
    offset = 0;
}

Allocator::~Allocator() {
    delete[] memory;
}

