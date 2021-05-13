#include "pool.h"

#include <iostream>
#include <cassert>

struct A
{
    int x = 3;
    int y = 4;
    int z = 5;
};

struct B
{
    int data = 3;
};


bool foo(const A& a)
{
    return ((a.x * a.x + a.y * a.y) == (a.z * a.z));
}


void foo2(const B& b)
{
    std::cout << b.data << std::endl;
}


void BaseTest()
{
    ThreadPool pool(std::thread::hardware_concurrency());

    auto task = pool.exec(foo, A());
    assert(task.get());
}

void TestingA()
{
    ThreadPool pool(std::thread::hardware_concurrency());

    std::vector<std::future<int>> ans;

    for(int i = 0; i < 100; i++)
        ans.push_back(pool.exec([](int a, int b){return a * b;}, i, 10));

    for(int i = 0; i < 100; i++)
        assert(ans[i].get() == i * 10);
}

void TestingB()
{
    ThreadPool pool(8);

    auto task1 = pool.exec(foo2, B());
    task1.get();

    auto task2 = pool.exec([]()
        {
            return 1;
        });

    std::cout << task2.get() << std::endl;

    std::cout << "\n";

    for (int i = 0; i <= 20; ++i)
    {
        std::cout << pool.exec([i]()
        {return i;}).get()<< "\n";
    }
}

int main()
{
    BaseTest();
    TestingA();
    TestingB();
    std::cout << "It's done!" << std::endl;
    return 0;
}

