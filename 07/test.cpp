#include <cassert>
#include <iostream>
#include "vector.h"


void ResizeEmptyAndIndexTesting()
{
    Vector<int> v;

    assert( v.empty() == true);

    v.resize(5);
    v[0] = 100;
    v[1] = -1000;
    v[3] = 5;
    assert(v[0] == 100);
    assert(v[1] == -1000);
    assert(v[3] == 5);
    assert(v[2] == 0);
    assert(v[4] == 0);

    std::cout<< "ResizeEmptyAndIndexTesting is Done!"<<std::endl;
}



void PushAndPopBackTesting()
{
    Vector <int> vec;

    assert( vec.empty() == true);
    assert( vec.size() == 0);

    vec.push_back(3);
    assert( vec.size() == 1);
    assert( vec.size() != 0);

    vec.push_back(7);
    vec.push_back(13);
    assert( vec.size() == 3);

    vec.pop_back();
    assert( vec.size() == 2);

    vec.push_back(100);

    vec.push_back(300);

    assert( vec[2] == 100);
    assert( vec[3] == 300);

    vec.pop_back();
    assert( vec.size() == 3);

    std::cout<< "PushAndPopBackTesting is Done!"<<std::endl;

}

void BeginAndEndTesting()
{
    Vector<int> vec;
    for( int i = 0; i <3; i++)
        vec.push_back(i);
    assert( vec.size() == 3);

    auto r = vec.begin();
    assert(r != vec.end());
    assert (*r == 0);

    ++r;
    assert(r != vec.end());
    assert(*r == 1);

    ++r;
    assert(r != vec.end());
    assert(*r == 2);

    ++r;
    assert(r == vec.end());

    std::cout<< "BeginAndEndTesting!"<<std::endl;
}

void RbeginAndRendTesting()
{
    Vector<int> vec;
    for( int i = 0; i <5; i++)
        vec.push_back(i);
    assert( vec.size() == 5);

    auto r = vec.rbegin();
    assert(r != vec.rend());
    assert (*r == 4);

    //r++;
    ++r;
    assert(r != vec.rend());
    assert(*r == 3);
    //r++;
    ++r;
    assert(r != vec.rend());
    assert(*r == 2);
    //r++;
    ++r;
    assert(r != vec.rend());
    assert(*r == 1);
    //r++;
    ++r;
    assert(r != vec.rend());
    assert(*r == 0);

    //r++;
    ++r;
    assert(r == vec.rend());

    std::cout<< "RbeginAndRendTesting!"<<std::endl;
}




void EmplaceBackTesting()
  {
    Vector<int> vec;
    vec.resize(6);
    assert( vec.size() == 6);
    std::vector <int> stdvec(6);
    for(int i=0; i < vec.size(); i++)
        vec[i] = i;
    for(int i=0; i < 6; i++)
        stdvec[i] = i;
    assert ( stdvec.size() == 6);

    vec.emplace_back(228);
    assert( vec.size() == 7);
    assert( vec[6] == 228);

    stdvec.emplace_back(228);
        assert( stdvec.size() == 7);
    assert( stdvec[6] == 228);

    assert( vec[6] == stdvec[6] );

    std::cout<<"EmplaceBackTesting is Done!"<<std::endl;
}


void ReserveAndCapacityTesting()
{
    Vector <double> vec;
    assert( vec.empty() == true);
    vec.push_back(3.5);
    vec.push_back(2.1);
    vec.push_back(1.0);
    assert( vec.size() == 3);
    vec.reserve(10000);
    assert( vec.size() == 3);
    assert ( vec.capacity() >= 10000);
    assert ( vec.capacity() >= 9999);
    std::cout<<"ReserveAndCapacityTesting is Done!"<<std::endl;
}


void ChangeTheValueTesting()
{
    Vector <int> vec;
    vec.resize(6);
    for( int i=0;i<vec.size();i++)
        vec[i] = i;
    assert( vec[2] == 2);
    vec[2] = 1300;
    assert( vec[2] == 1300);
    vec[4] = 12021;
    assert( vec[4] == 12021);

    std::cout<<"ChangeTheValueTesting is Done!"<<std::endl;
}

void OutOfRangeTesting()
{
    Vector<int> vec;
    vec.resize(5);
    try
    {
      vec[100] = 130;
    }
    catch (const std::out_of_range &)
    {
        std::cout<<"OutOfRange Detected!"<<std::endl;
    };
    std::cout<<"OutOfRangeTesting is Done!"<<std::endl;
}


int main()
{
    ResizeEmptyAndIndexTesting();
    PushAndPopBackTesting();
    BeginAndEndTesting();
    RbeginAndRendTesting();
    EmplaceBackTesting();
    ReserveAndCapacityTesting();
    ChangeTheValueTesting();
    OutOfRangeTesting();
    return 0;
}

