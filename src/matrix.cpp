#include "matrix.h"

#include <iomanip>
#include <iostream>

Matrix::Matrix()
    : n_rows(0), n_cols(0)
{
}

Matrix::Matrix(const Matrix &mat) : n_cols(mat.n_cols), n_rows(mat.n_rows), m_data(mat.m_data) {}

Matrix::Matrix(size_t n_rows, size_t n_cols) : n_cols(n_cols), n_rows(n_rows), m_data(n_cols * n_rows) {}
Matrix::Matrix(size_t n_rows, size_t n_cols, int initValue) : n_cols(n_cols), n_rows(n_rows), m_data(n_cols * n_rows, initValue) {}

void Matrix::print() const
{
    for (size_t r = 0; r < n_rows; r++)
    {
        for (size_t c = 0; c < n_cols; c++)
        {
            std::cout << (c > 0 ? " " : "") << std::setw(4);
            std::cout << at(r, c);
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::add(int val) const
{
    Matrix res(n_cols, n_rows);
    for (size_t i = 0; i < res.m_data.size(); i++)
    {
        res.m_data[i] = res.m_data[i] + val;
    }
    return res;
}

Matrix Matrix::multiply(int val) const
{
    Matrix res(n_cols, n_rows);
    for (size_t i = 0; i < res.m_data.size(); i++)
    {
        res.m_data[i] = res.m_data[i] * val;
    }
    return res;
}

Matrix Matrix::subtract(int val) const
{
    Matrix res(n_cols, n_rows);
    for (size_t i = 0; i < res.m_data.size(); i++)
    {
        res.m_data[i] = res.m_data[i] - val;
    }
    return res;
}

bool isSameDimensions(size_t left_rows_n, size_t right_rows_n, size_t left_cols_n, size_t right_cols_n)
{
    if (left_rows_n != right_rows_n || left_cols_n != right_cols_n)
        return false;
    return true;
};

Matrix Matrix::add(const Matrix &mat) const
{
    if (!isSameDimensions(n_rows, mat.n_rows, n_cols, mat.n_cols))
        return Matrix();
    else
    {
        Matrix res(n_cols, n_rows);
        for (size_t i = 0; i < res.m_data.size(); i++)
        {
            res.m_data[i] = m_data[i] + mat.m_data[i];
        }
        return res;
    };
}

Matrix &Matrix::operator=(const Matrix &mat)
{
    if (this != &mat)
    {
        n_rows = mat.n_rows;
        n_cols = mat.n_cols;
        m_data.assign(mat.m_data.begin(), mat.m_data.end());
    }
    return *this;
}