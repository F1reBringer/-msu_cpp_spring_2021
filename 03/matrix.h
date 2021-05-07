#ifndef matrix_h
#define matrix_h

#include <iostream>
#include <cstddef>


class Proxy{
private:
    int *data_;
    size_t cols_;
public:
    Proxy(int *data, size_t cols);
    int& operator[](size_t num);
    const int& operator[](size_t num) const;
};


class My_Matrix
{
private:
    int *data_;
    size_t rows_;
    size_t cols_;
public:
    My_Matrix(size_t rows, size_t cols, int val=0);
    size_t GetColumns() const;
    size_t GetRows() const;
    bool operator==(const My_Matrix& other) const;
    bool operator!=(const My_Matrix& other) const;
    My_Matrix& operator*=(int val);
    friend std::ostream& operator<<(std::ostream& out, const My_Matrix& m);
    My_Matrix operator+(const My_Matrix &other) const;
    Proxy operator[](size_t num);
    const Proxy operator[](size_t num) const;
    ~My_Matrix();
    void print_matrix();

};
#endif

