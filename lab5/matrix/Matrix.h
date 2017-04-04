//
// Created by janek on 03.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H


#include <cstddef>
#include <utility>
#include <string>
#include <array>
#include <complex>
#include <vector>

namespace algebra{
    class Matrix {
    public:
        Matrix();
        Matrix(int h, int w);
        Matrix(const Matrix &matrice);
        Matrix(std::string phrase);
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements);
        std::pair<size_t, size_t> Size(void) const;
        std::string Print(void) const;
        Matrix Add(const Matrix &matrice)const;
        Matrix Sub(const Matrix &matrice)const;
        Matrix Mul(const Matrix &matrice)const;
        Matrix Mul(std::complex<double> number)const;
        Matrix Div(const Matrix &matrice)const;
        Matrix Div(std::complex<double> number)const;
        Matrix Pow(int number)const;
    private:
        std::vector<std::vector<std::complex<double>>> elements_;
    };

    std::string DoubleToString(double number);
}


#endif //JIMP_EXERCISES_MATRIX_H