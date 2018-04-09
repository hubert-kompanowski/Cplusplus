//
// Created by hubert on 09.04.18.
//

#include "Matrix.h"
#include <memory>
#include <iostream>

using namespace algebra;

Matrix::Matrix(size_t kol, size_t wier) {
    for(int i=0; i<wier; i++) {
        for(int j=0; j<kol; j++) {
            macierz.push_back({0,0});
        }
    }
    kolumny = kol;
    wiersze = wier;
}

Matrix::Matrix(std::vector<std::vector<std::complex<double>>> lista) {
    macierz = lista;
    wiersze = lista.size();
    kolumny = lista[0].size();
}

Matrix::Matrix() {
    kolumny = wiersze = 0;
}

Matrix::Matrix(const Matrix &other) {
    macierz = other.macierz;
    kolumny = other.kolumny;
    wiersze = other.wiersze;
}

Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> lista) {
    for(std::vector<std::complex<double>> v : lista){
        std::vector<std::complex<double>> temp;
        for(int b = 0; b< v.size();b++) {
            temp.push_back(v[b]);
        }
        kolumny = temp.size();
        macierz.push_back(temp);
    }
    wiersze = macierz.size();
}

std::complex<double> get_complex(std::string numer) {
    std::string cz_rzeczywista;
    std::string cz_urojona;
    bool flaga = true;
    for(char v: numer) {
        if(flaga) {
            if(v == 'i')
                flaga = false;
            else
                cz_rzeczywista += v;
        }
        else
            cz_urojona += v;
    }

    std::complex<double> wynik;
    if(flaga) {
        if(cz_rzeczywista != "")
            wynik = {stod(cz_rzeczywista), 0};
        else
            wynik = {0, 0};
    }
    else {
        wynik = {stod(cz_rzeczywista), stod(cz_urojona)};
    }
    return wynik;
}

Matrix::Matrix(std::string matrix) {
    std::string numer;
    std::vector<std::complex<double>> wiersz;

    for(char v : matrix) {
        if(v == '[')
            continue;

        if(v == ' ') {
            if(numer == "")
                continue;
            wiersz.push_back(get_complex(numer));
            numer.clear();
        }

        if(v == ';' || v == ']') {
            if(numer != "")
                wiersz.push_back(get_complex(numer));
            numer.clear();
            kolumny = wiersz.size();
            macierz.push_back(wiersz);
            wiersz.clear();
        }
        else
            numer+= v;
    }
    wiersze = macierz.size();
}

std::complex<double> Matrix::Get(size_t kol, size_t wier) const {
    return macierz[wier][kol];
}

std::pair<size_t,size_t> Matrix::Size() {
    return {kolumny,wiersze};
}

Matrix Matrix::Add(const Matrix other) const {
    if(wiersze != other.wiersze || kolumny != other.kolumny) {
        exit(2);
    }
    std::vector<std::vector<std::complex<double>>> wynik;
    std::vector<std::complex<double>> wiersz;
    for(int i=0; i < wiersze; i++) {
        wiersz.clear();
        for(int j=0; j < kolumny; j++) {
            wiersz.push_back(Get(j,i) + other.Get(j,i));
        }
        wynik.push_back(wiersz);
    }
    return Matrix(wynik);
}

Matrix Matrix::Sub(const Matrix other) const {
    if(wiersze != other.wiersze  || kolumny != other.kolumny)  {
        exit(2);
    }
    std::vector<std::vector<std::complex<double>>> wynik;
    std::vector<std::complex<double>> wiersz;
    for(int i=0; i < wiersze; i++) {
        wiersz.clear();
        for(int j=0; j < kolumny; j++) {
            wiersz.push_back(this->Get(j,i) - other.Get(j,i));
        }
        wynik.push_back(wiersz);
    }
    return Matrix(wynik);
}

Matrix Matrix::Mul(const Matrix other) const {
    if(kolumny != other.wiersze) {
        return Matrix();
    }
    std::vector<std::vector<std::complex<double>>> wynik;
    std::vector<std::complex<double>> wiersz;
    std::complex<double> temp;
    for(int i=0; i < wiersze; i++) {
        wiersz.clear();
        for(int j=0; j < other.kolumny; j++) {
            temp = {0,0};
            for(int k=0; k < kolumny; k++) {
                temp += (macierz[i][k] * other.macierz[k][j]);
            }
            wiersz.push_back(temp);
        }
        wynik.push_back(wiersz);
    }
    return Matrix(wynik);
}

Matrix Matrix::Mul(const std::complex<double> numer) const {
    std::vector<std::vector<std::complex<double>>> wynik;
    std::vector<std::complex<double>> wiersz;
    for(int i=0; i < wiersze; i++) {
        wiersz.clear();
        for(int j=0; j < kolumny; j++) {
            wiersz.push_back(numer * Get(j,i));
        }
        wynik.push_back(wiersz);
    }
    return Matrix(wynik);
}

Matrix Matrix::Pow(const int numer)const {
    Matrix wynik (*this);
    for(int i=0; i < numer-1; i++) {
        wynik = wynik.Mul(*this);
    }
    if(numer != 0){
        return wynik;
    }
    std::vector<std::vector<std::complex<double >>> temp;
    std::vector<std::complex<double>> wiersz;
    for(int i=0; i < wiersze; i++) {
        wiersz.clear();
        for(int j=0; j < kolumny; j++) {
            if(i == j) {
                wiersz.push_back({1,0});
            }
            else {
                wiersz.push_back({0,0});
            }
        }
        temp.push_back(wiersz);
    }
    return Matrix(temp);
}

std::string Matrix::Print() const {
    std::string wynik = "[";
    for(int i=0; i < wiersze; i++) {
        if(i != 0)
            wynik += "; ";
        for(int j=0; j < kolumny; j++) {
            if(j != 0)
                wynik += ", ";

            std::ostringstream stream1;
            stream1 << macierz[i][j].real();
            wynik += stream1.str();

            std::ostringstream stream2;
            stream2 << macierz[i][j].imag();
            wynik = wynik + "i" + stream2.str();
        }
    }
    wynik += "]";
    return wynik;
}

std::complex<double> Matrix::Determinant() const {
    if(kolumny != wiersze) {
        return {0, 0};
    }
    std::vector<std::vector<std::complex<double>>> temp = macierz;
    std::complex<double> scalar;
    for(int i=0; i < wiersze; i++) {
        for(int j=i+1; j < kolumny; j++) {
            if(temp[i][i] == std::complex<double>({0,0})) {
                for(int k=0; k < kolumny; k++) {
                    temp[j-1][k] += temp[j][k];
                }
            }
            scalar = temp[j][i]/temp[i][i];
            for(int l=0; l < kolumny; l++) {
                temp[j][l] -= scalar * temp[i][l];
            }
        }
    }
    std::complex<double> result = {1,0};
    for(int m=0; m < wiersze; m++) {
        result *= temp[m][m];
    }
    return result;
}

Matrix Matrix::Inverse()const {
    if(Determinant() == std::complex<double> ({0,0})) {
        return Matrix();
    }

    std::vector<std::vector<std::complex<double>>> temp = macierz;
    std::complex<double> wartosc;
    Matrix wynik(kolumny,wiersze);
    for(int i=0; i < wiersze; i++) {
        wynik.macierz[i][i] = {1,0};
    }
    for(int i=0; i < wiersze; i++) {
        my_method(i, temp, wynik);
    }
    for(int i=kolumny-1; i >= 0; i--) {
        my_method(i, temp, wynik);
    }
    for(int i=0; i < wiersze; i++) {
        wartosc = temp[i][i];
        for(int j=0; j < kolumny; j++) {
            wynik.macierz[i][j] = wynik.macierz[i][j]/wartosc;
        }
    }
    return wynik;
}

void Matrix::my_method(int j, std::vector<std::vector<std::complex<double>>> &temp, Matrix &wynik) const {
    std::complex<double> wartosc;
    for(int k=j+1; k < kolumny; k++) {
            if(temp[j][j]== std::complex<double>({0, 0})) {
                for(int l=0; l < kolumny; l++) {
                    temp[k-1][l] += temp[k][l];
                }
            }
            wartosc = temp[k][j] / temp[j][j];
            for(int m=0; m < kolumny; m++) {
                temp[k][m] -= wartosc * temp[j][m];
                wynik.macierz[k][m] -= wartosc * wynik.macierz[j][m];
            }
        }
}

Matrix Matrix::Div(const Matrix other) const {
    if(other.Determinant() == std::complex<double> ({0,0})) {
        return Matrix();
    }
    return Mul(other.Inverse());
}