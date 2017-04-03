//
// Created by janek on 03.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <complex>

namespace algebra{
    class Matrix{
    public:
        //domyślny konstruktor
        Matrix();
        //konstruktory parametryczne
        Matrix(int siz);
        Matrix(const char*);

        //Rule of five://
        //1. konstruktor kopiujący
        Matrix(const Matrix &other_matrix);
        //2. konstruktor przenoszący
        Matrix(Matrix &&xxx)=delete;
        //3. operator przypisania kopiujący
        Matrix &operator=(const Matrix &xxx)=delete;
        //4. operator przypisania przenoszący
        Matrix &operator=(Matrix &&xxx)=delete;
        //5. Destruktor
        ~Matrix()=delete;

        void BuildMatrix();
        void print();
        Matrix add(const Matrix &other_matrix) const;
        Matrix sub(const Matrix &other_matrix) const;
        Matrix mul(const Matrix &other_matrix) const;
        Matrix div(const Matrix &other_matrix) const;
        Matrix pow(const int po) const;
    private:
        std::complex<double> matrix_;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
