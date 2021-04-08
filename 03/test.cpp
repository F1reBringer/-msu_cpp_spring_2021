#include "matrix.h"
#include <iostream>
#include <cassert>

void GetRowsAndColumns()
{
    const size_t rows = 10;
    const size_t cols = 12;

    My_Matrix m(rows, cols);

    assert(m.getRows() == 10);
    assert(m.getColumns() == 12);
}


void ErrorGetRowsAndColumns()
{
    const size_t rows = 12;
    const size_t cols = 15;

    My_Matrix m(rows, cols);
    assert(m.getRows() != 10);
    assert(m.getColumns() !=  5);


}

void ComparisonOfValues()
{
    const size_t rows = 12;
    const size_t cols = 15;
    My_Matrix m(rows, cols);
    m[3][4] = 3*4;
    m[8][7] = 8*7;
    m[11][2] = 11*2;
    double x = m[3][4];
    double y = m[8][7];
    double z = m[11][2];
    assert(x == 12);
    assert(y == 56);
    assert(x != 15);
    assert(z == 22);
}

void MultiplyingByANumberAndEquality()
{
    const size_t rows = 2;
    const size_t cols = 2;
    My_Matrix m1(rows, cols);
    My_Matrix m2(rows, cols);
    for(size_t i = 0; i < cols; i++)
        {
            for(size_t j = 0; j < rows; j++)
            {

                m1[i][j] = i ;
                m2[i][j] = m1[i][j];
            }
        }
    m1 *= 10;
    assert( (m1[1][1]) == 10);
}


void Multiplication_Table()
{
    const size_t rows = 10;
    const size_t cols = 10;
    My_Matrix m(rows, cols);
    for (size_t i=0;i < rows;i++)
    {
        for( size_t j=0; j< cols; j++)
        {
            m[i][j] = (i+1)*(j+1);
        }
    }
    m.print_matrix();
}


void MatrixAdditionAndPrint()
{
    const size_t rows = 10;
    const size_t cols = 10;
    My_Matrix m1(rows, cols);
    My_Matrix m2(rows, cols);
    for(size_t i = 0; i < cols; i++)
        {
            for(size_t j = 0; j < rows; j++)
            {
                m1[i][j] = i ;
                m2[i][j] = j ;
            }
        }
    My_Matrix m3(rows, cols);
    m3 = m1 + m2;
    assert(m3[1][2] == 3 );
    assert(m3[4][5] == 9 );
    assert(m3[7][8] == 15 );
    m1.print_matrix();
    std::cout<<std::endl;
    m2.print_matrix();
    std::cout<<std::endl;
    m3.print_matrix();
    std::cout<<std::endl;

}


int main() {
    GetRowsAndColumns();
    ErrorGetRowsAndColumns();
    ComparisonOfValues();
    MultiplyingByANumberAndEquality();
    Multiplication_Table();
    MatrixAdditionAndPrint();
    return 0;
}


