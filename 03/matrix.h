#include <iostream>
#include <cstddef>
#include <cassert>



class My_Matrix{
    int** matr;
    const size_t rows, cols;

    public:
        class ProxyRow
        {
            size_t num_cols;
            int* row;
            public:
            ProxyRow(size_t m_cols, int* r);
            int& operator[](size_t i);
            const int& operator[](size_t i) const;

        };
        My_Matrix(const size_t a, const size_t b);
        size_t getRows() const;
        size_t getColumns() const;
        ProxyRow operator[](size_t i);
        const ProxyRow operator[](size_t i) const;
        My_Matrix& operator*=(int n);
        bool operator==(const My_Matrix& other) const;
        bool operator!=(const My_Matrix& other) const;
        My_Matrix& operator +(const My_Matrix& other);
        My_Matrix& operator =(const My_Matrix& other);
        void print_matrix();
        ~My_Matrix();
};
