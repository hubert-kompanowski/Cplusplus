//
// Created by abrajner on 05.03.18.
//

#ifndef JIMP_EXERCISES_ARRAY2D_H
#define JIMP_EXERCISES_ARRAY2D_H

void UserInput(int n_rows, int n_columns);
int ** NewArray2D(int n_rows, int n_columns);
void DrawArray(int ** array, int n_rows, int n_columns);
void DeleteArray2D(int ** array, int n_rows, int n_columns);
void FillArray2D(int n_rows, int n_columns, int ** to_fill);


#endif //JIMP_EXERCISES_ARRAY2D_H