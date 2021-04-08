#include "matrix.h"



My_Matrix::ProxyRow::ProxyRow(size_t m_cols, int* r) : num_cols(m_cols) , row(r){}

int& My_Matrix::ProxyRow::operator[](size_t i)
{
    if(i >= num_cols)
    {
        throw std::out_of_range("");
    }
    return row[i];
}

const int& My_Matrix::ProxyRow::operator[](size_t i) const
{
    if(i >= num_cols)
    {
        throw std::out_of_range("");
    }
    return row[i];
}

My_Matrix::ProxyRow My_Matrix::operator[](size_t i)
{
    if(i >= this->rows)
    {
        throw std::out_of_range("");
    }
    return ProxyRow(this->cols, matr[i]);
}

const My_Matrix::ProxyRow My_Matrix::operator[](size_t i) const
{
    if(i >= this->rows)
    {
        throw std::out_of_range("");
    }
    return ProxyRow(this->cols, matr[i]);
}

My_Matrix::My_Matrix(const size_t a, const size_t b) : rows(a), cols(b)
{
    matr = new int*[rows];
    for(size_t i=0; i<cols; i++)
    {
        matr[i] = new int[cols];
    }
}

My_Matrix::~My_Matrix()
    {
    for(size_t i = 0; i < this->cols; i++)
    {
        delete[] matr[i];
    }
    delete[] matr;
}

size_t My_Matrix::getRows() const
{
    return this->rows;
}

size_t My_Matrix::getColumns() const
{
    return this->cols;
}

bool My_Matrix::operator==(const My_Matrix& other) const
{
    if (this == &other)
        return true;

    if ((this->cols != other.getColumns()) || (this->rows != other.getRows()))
        return false;

    for (size_t i = 0; i < this->rows; i++)
    {
        for(size_t j = 0; j < this->cols; j++)
        {
            if(matr[i][j]!=other.matr[i][j])
                return false;
        }
    }
    return true;
}

bool My_Matrix::operator!=(const My_Matrix& other) const
{
    return !(*this == other);
}

My_Matrix& My_Matrix::operator*=(int n)
{
    for(size_t i = 0; i < this->rows; i++)
        {
            for(size_t j = 0; j < this->cols; j++)
            {
                matr[i][j] *= n;
            }
    }
    return *this;
}


void My_Matrix::print_matrix()
{
    for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->cols; j++)
            {
                std::cout << matr[i][j] << " ";
            }
            std::cout << std::endl;
        }
}

My_Matrix& My_Matrix::operator=(const My_Matrix& other)
{
    if (this == &other)
    {
        return *this;
    }
    if(rows != other.rows || cols != other.cols)
    {
        throw std::out_of_range("");
    }
    for (size_t i = 0; i < other.rows; ++i)
        {
            for(size_t j =0 ; j < other.cols; j++ )
            {
                matr[i][j] = other.matr[i][j];
            }
        }
    return *this;
}



My_Matrix& My_Matrix::operator +(const My_Matrix& other)
{
    if ((this->cols != other.getColumns()) || (this->rows != other.getRows()))
    {
        throw std::out_of_range("");
    }
    for(size_t i = 0; i < this->rows; i++)
    {
        for(size_t j = 0; j < this->cols;j++)
        {
            matr[i][j] = matr[i][j] + other.matr[i][j];
        }
    }
    return *this;

}
