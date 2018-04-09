//
// Created by hubert on 09.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string>
#include <vector>
#include <initializer_list>
#include <complex>

namespace algebra {

    class Matrix {

    private:
        size_t kolumny;
        size_t wiersze;
        std::vector<std::vector<std::complex<double>>> macierz;

    public:
        Matrix();
        Matrix(size_t, size_t);
        Matrix(std::string);
        Matrix(std::vector<std::vector<std::complex<double >>>);
        Matrix(std::initializer_list<std::vector<std::complex<double>>>);
        Matrix(const Matrix &);

        std::complex<double> Get(size_t , size_t ) const;
        std::pair<size_t,size_t> Size();

        Matrix Add(const Matrix) const;         // dodawanie
        Matrix Sub(const Matrix) const;         // odejmowanie
        Matrix Mul(const Matrix) const;         // mnożenie przez macierz
        Matrix Mul(const std::complex<double>) const; // mnożenie przez liczbę
        Matrix Div(const Matrix) const;         // dzielenie
        Matrix Pow(const int)const;            // potęgowanie

        std::complex<double> Determinant() const;     // wyznacznik
        Matrix Inverse() const;                       // odwacanie macierzy

        std::string Print() const;                    // wyswietlanie macierzy

        void my_method(int j, std::vector<std::vector<std::complex<double>>> &temp, Matrix &wynik) const;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
