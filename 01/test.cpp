#include "alloc.h"
#include <cassert>


void AllocBeforeMakeAllocator()
{
    Allocator exmpl;
    assert(nullptr == exmpl.alloc(10));
}

void TripleMakeAllocator()
{
    Allocator exmpl;
    exmpl.makeAllocator(10);
    assert(nullptr == exmpl.alloc(50));
    assert(nullptr != exmpl.alloc(10));

    exmpl.makeAllocator(150);
    assert(nullptr != exmpl.alloc(100));
    assert(nullptr == exmpl.alloc(250));
    assert(nullptr == exmpl.alloc(150));

    exmpl.makeAllocator(1000);
    assert(nullptr != exmpl.alloc(900));
    assert(nullptr == exmpl.alloc(1000));
    assert(nullptr != exmpl.alloc(100));

}

void CannotAllocMore()
{
    Allocator exmpl;
    exmpl.makeAllocator(50);
    assert(nullptr == exmpl.alloc(51));
    assert(nullptr != exmpl.alloc(25));
    assert(nullptr != exmpl.alloc(25));
    assert(nullptr == exmpl.alloc(1));
}


void CannotAllocMoreAndDoubleReset()
{
    Allocator exmpl;
    exmpl.makeAllocator(100);
    assert(nullptr != exmpl.alloc(10));
    assert(nullptr != exmpl.alloc(30));
    assert(nullptr == exmpl.alloc(70));
    exmpl.reset();
    assert(nullptr != exmpl.alloc(70));
    assert(nullptr == exmpl.alloc(40));
    exmpl.reset();
    assert(nullptr != exmpl.alloc(55));
    assert(nullptr == exmpl.alloc(55));
    assert(nullptr != exmpl.alloc(45));
}

void AllocZeroBytes()
{
    Allocator exmpl;
    exmpl.makeAllocator(10);
    assert(nullptr != exmpl.alloc(0));
}

int main() {
    AllocBeforeMakeAllocator();
    TripleMakeAllocator();
    CannotAllocMore();
    CannotAllocMoreAndDoubleReset();
    AllocZeroBytes();
    return 0;
}
