#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
public:
    Matrix();
    Matrix(const Matrix &mat);
    Matrix(size_t num_rows, size_t num_cols);
    Matrix(size_t num_rows, size_t num_cols, int initValue);

    inline size_t getRows() const { return n_rows; }
    inline size_t getCols() const { return n_cols; }
    inline const int &at(size_t row, size_t col) const { return m_data[row * n_cols + col]; };
    inline int &at(size_t row, size_t col) { return m_data[row * n_cols + col]; };
    std::vector<int> getData() const { return m_data; }
    Matrix add(int val) const;
    Matrix multiply(int val) const;
    Matrix subtract(int val) const;
    Matrix add(const Matrix &mat) const;
    Matrix multiply(const Matrix &mat) const;
    Matrix subtract(const Matrix &mat) const;
    Matrix &operator=(const Matrix &mat);

    void print() const;

private:
    size_t n_cols;
    size_t n_rows;
    std::vector<int> m_data;
};

#endif