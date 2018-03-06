//
// Created by abrajner on 05.03.18.
//

#include "Array2D.h"

int main(){
    int n_rows = 0, n_columns = 0;

    UserInput(n_rows, n_columns);
    int ** array = Array2D(n_rows, n_columns);
    DrawArray(array, n_rows, n_columns);
    DeleteArray2D(array, n_rows, n_columns);

    return 0;
}