#include "matrix.h"
#include <cassert>


void GetRowsAndColumns()
{
    My_Matrix m1(10, 20);
    assert(m1.GetColumns() == 20);
    assert(m1.GetRows() == 10);
    My_Matrix m2(20, 10);
    assert(m2.GetColumns() == 10);
    assert(m2.GetRows() == 20);
}


void ErrorGetRowsAndColumns()
{

    My_Matrix m1(10, 20);
    assert(m1.GetColumns() != 100);
    assert(m1.GetRows() != 50);
    My_Matrix m2(20, 10);
    assert(m2.GetColumns() != 20);
    assert(m2.GetRows() != 10);
}


void ComparisonOfValues()
{
    My_Matrix m(10, 20, 1);
    assert(m[1][1] == 1);
    m[1][1] = 22;
    m[3][4] = 65;
    assert(m[1][1] == 22);
    assert(m[3][4] == 65);
    bool flag1 = false;
    bool flag2 = false;
    try{
        m[15][7];
    }
    catch(const std::out_of_range &e){
        flag1 = true;
    }
    try{
        m[7][25];
    }
    catch(const std::out_of_range &e){
        flag2 = true;
    }
    assert(flag1);
    assert(flag2);
}

void MultiplicationTesting()
{
    My_Matrix m(2, 2);
    for(size_t i = 0; i < m.GetRows(); i++)
        for(size_t j = 0; j < m.GetColumns(); j++)
            m[i][j] = i * m.GetColumns() + j + 1;
    m *= 4;
    assert(m[0][0] == 4);
    assert(m[1][0] == 12);
    assert(m[0][1] == 8);
    assert(m[1][1] == 16);
}

void EqualityTesting()
{
    My_Matrix m1(10, 20, 5), m2(10, 20, 4), m3(10, 20, 5), m4(11, 20, 5), m5(10, 21, 5);
    assert(m1 != m2);
    assert(m1 == m3);
    assert(m1 != m4);
    assert(m1 != m5);
}

void AdditionTesting()
{
    My_Matrix m1(10, 20, 5), m2(10, 20, 2), m3(10, 20, 3), m4(20, 10);
    assert(m2 + m3 == m1);
    assert(m1 + m2 != m3);
    bool flag = false;
    try{
        m4 + m1;
    }
    catch(const std::out_of_range &e){
        flag = true;
    }
    assert(flag);
}

void PrintTesting()
{
    My_Matrix m(5, 10);
    std::cout << "Start print test: " << std::endl;
    for(size_t i = 0; i < m.GetRows(); i++)
        for(size_t j = 0; j < m.GetColumns(); j++)
            m[i][j] = i * m.GetColumns() + j + 1;
    std::cout << m << std::endl;
}

void Matrix1on1()
{
    My_Matrix m1(1, 1, 0), m2(1, 1, -100), m3(1, 1, 999);
    assert(m1[1][1] == 0);
    assert(m2[1][1] == -100);
    assert(m3[1][1] == 999);

}



int main()
{
    void GetRowsAndColumns();
    void ErrorGetRowsAndColumns();
    void ComparisonOfValues();
    void MultiplicationTesting();
    void EqualityTesting();
    void AdditionTesting();
    void PrintTesting();
    void Matrix1on1();


    return 0;
}

