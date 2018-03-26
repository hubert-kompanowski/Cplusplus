//
// Created by abrajner on 05.03.18.
//

#include <iostream>
#include <string>
#include "Array2D.h"


void UserInput(int n_rows, int n_columns){
    std::cout << "podaj liczbę kolumn ";
    std::cin >> n_columns;
    std::cout << std::endl << "Podaj liczbe wierszy ";
    std::cin >> n_rows;
    std::cout << std::endl;
}

void DeleteArray2D(int ** array, int n_rows, int n_columns){
    for(int i = 0; i < n_rows; i++){
        delete [] array[i];
    }

    delete [] array;

    array = nullptr;
}

void FillArray2D(int n_rows, int n_columns, int ** to_fill){
    int counter = 1;
    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_columns; j++){
            to_fill[i][j] = counter;
            counter++;
        }
    }
}

int ** NewArray2D(int n_rows, int n_columns){

    if(n_rows <= 0 || n_columns <= 0) {
        return nullptr;
    }

    int ** array = new int *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        array[i] = new int[n_columns];
    }

    FillArray2D(n_rows, n_columns, array);
    return array;
}

void DrawArray(int ** array, int n_rows, int n_columns){
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_columns; j++) {
                std::cout.width(5);
                std::cout << array[i][j];
            }
            std::cout << std::endl;
        }
}


int ** Array2D(int n_rows, int n_columns){

    if(n_rows <= 0 || n_columns <= 0) {
        return nullptr;
    }

    int ** array = new int *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        array[i] = new int[n_columns];
    }

    FillArray2D(n_rows, n_columns, array);
    return array;
}


