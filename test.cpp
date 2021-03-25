#include "alloc.h"
#include <cassert>


void test1() {
    Allocator exmpl(15);
    assert(nullptr != exmpl.alloc(0));
    assert(nullptr == exmpl.alloc(16));
    exmpl.reset();
    assert(nullptr != exmpl.alloc(10));
    assert(nullptr != exmpl.alloc(5));
    assert(nullptr == exmpl.alloc(1));
}
void test2() {
    Allocator exmpl(50);
    assert(nullptr == exmpl.alloc(51));
    assert(nullptr != exmpl.alloc(25));
    assert(nullptr != exmpl.alloc(25));
    assert(nullptr == exmpl.alloc(1));
}

void test3() {
    Allocator exmpl(100);
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


int main() {
    test1();
    test2();
    test3();
    return 0;
}

