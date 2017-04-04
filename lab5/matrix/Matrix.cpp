//
// Created by matematyk60 on 04.04.17.
//

#include <iostream>
#include "Matrix.h"

std::vector<std::vector<std::complex<double>>> MakeCopy(std::vector<std::vector<std::complex<double>>> elements){
    return elements;
}



namespace algebra{
    Matrix::Matrix() {

    }

    Matrix::Matrix(int h, int w) {
        for(int i = 0 ; i < h ; i++){
            elements_.emplace_back(std::vector<std::complex<double>>());
            for(int j = 0 ; j < w ; j++){
                elements_[i].emplace_back(0 + 0*i);
            }
        }
    }

    Matrix::Matrix(const Matrix &matrice) {
        elements_ = MakeCopy(matrice.elements_);
    }

    Matrix::Matrix(const char *phrase) {

    }

    Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements) {
        elements_.clear();
        int i = 0;
        for(auto n : elements ){
            elements_.emplace_back(std::vector<std::complex<double>>());
            for(auto v : n){
                elements_[i].emplace_back(v);
            }
            i++;
        }
    }

    std::pair<size_t, size_t> Matrix::Size(void) const{
        if(elements_.size() == 0){
            return std::pair<size_t , size_t >{0,0};
        } else {
            return std::pair<size_t, size_t>{elements_.size(),elements_[0].size()};
        }
    }

    std::string Matrix::Print(void) const{
        if(this->Size().first == 0 || this->Size().second == 0){
            return "[]";
        }

        std::string answer = "";
        answer += '[';
        std::stringstream ss;
        for(auto n : elements_){
            for(auto v : n){
                answer += DoubleToString(v.real());
                answer += 'i';
                answer += DoubleToString(v.imag());
                answer += ", ";
            }
            answer.erase(answer.length()-2,2);
            answer += "; ";
        }
        answer.erase(answer.length()-2,2);
        answer += ']';

        return answer;
    }

    Matrix Matrix::Add(const Matrix &matrice) const{
        if(matrice.Size() != this->Size()){
            std::cout << "Cannot add matrices with different sizes" << std::endl;
        } else{
            Matrix answer{*this};
            for(int i = 0 ; i < matrice.Size().first ; i++){
                for(int j = 0 ; j < matrice.Size().second ; j++){
                    answer.elements_[i][j] += matrice.elements_[i][j];
                }
            }
            return answer;
        }
    }

    Matrix Matrix::Sub(const Matrix &matrice)const {
        if(matrice.Size() != this->Size()){
            std::cout << "Cannot subtract matrices with different sizes" << std::endl;
        } else{
            Matrix answer{*this};
            for(int i = 0 ; i < matrice.Size().first ; i++){
                for(int j = 0 ; j < matrice.Size().second ; j++){
                    answer.elements_[i][j] -= matrice.elements_[i][j];
                }
            }
            return answer;
        }
    }

    Matrix Matrix::Mul(const Matrix &matrice) const{
        if(this->Size().second != matrice.Size().first) {
            std::cout << "Wrong sizes for multiplication" << std::endl;
            Matrix answer{};
            return answer;

        } else {
            Matrix Answer{(int) this->Size().first, (int) matrice.Size().second};
            std::complex<double> tmp = 0 + 0i;

            for (int i = 0; i < Answer.Size().first; i++) {
                for (int j = 0; j < Answer.Size().second; j++) {
                    for (int k = 0; k < this->Size().second; k++) {
                        tmp += elements_[i][k] * matrice.elements_[k][j];
                    }
                    Answer.elements_[i][j] = tmp;
                    tmp = 0 + 0i;
                }
            }
            return Answer;
        }
    }


    Matrix Matrix::Div(const Matrix &matrice) const {
        return Matrix();
    }


    Matrix Matrix::Pow(int n)const {
        if(this->Size().first != this->Size().second){
            std::cout << "only square matrices can be powered" << std::endl;
            Matrix answer{};
            return answer;
        } else{
            if(n == 0){
                Matrix answer{(int)this->Size().second,(int)this->Size().second};
                for(int i = 0 ; i < this->Size().second ; i++){
                    answer.elements_[i][i] = 1. + 0.i;
                }
                return answer;
            } else{
                Matrix answer{*this};
                for(int i = 1 ; i < n ; i++){
                    answer = answer.Mul(*this);
                }
                return answer;
            }
        }
    }

    std::string DoubleToString(double number){
        std::string answer = "";
        std::stringstream ss;
        ss << number;
        ss >> answer;

        return answer;
    }
}