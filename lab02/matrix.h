
#ifndef MATRIX_H
#define MATRIX_H


#define N 5


float getMin(const float[][N]);//Минимум матрицы
float getMax(const float[][N]);//Максимум матрицы
float getMinMax(const float[][N], const bool);

float getMinTriangleUpper(const float[][N]);//Минимум верхнетреугольной части
float getMaxTriangleUpper(const float[][N]);//Максимум верхнетреугольной части
float getMinTriangleLower(const float[][N]);//Минимум нижнетреугольной части
float getMaxTriangleLower(const float[][N]);//Максимум нижнетреугольной части
float getMinMaxTriangle(const float[][N], const bool, const bool);

float getMinDiagonalPrimary(const float[][N]);//Минимум главной диагонали
float getMaxDiagonalPrimary(const float[][N]);//Максимум главной диагонали
float getMinDiagonalSecondary(const float[][N]);//Минимум второстепенной диагонали
float getMaxDiagonalSecondary(const float[][N]);//Максимум второстепенной диагонали
float getMinMaxDiagonal(const float[][N], const bool, const bool);

float getAverage(const float[][N]);//Среднеарифметическое значение элементов матрицы

float getAverageTriangleUpper(const float[][N]);//Среднеарифметическое значение элементов верхнетреугольной части
float getAverageTriangleLower(const float[][N]);//Среднеарифметическое значение элементов нижнетреугольной части
float getAverageTriangle(const float[][N], const bool);

void calcSumRows(const float[][N], float*);//Сумма строк
void calcSumColumns(const float[][N], float*);//Сумма столбцов
void calcSumRowsColumns(const float[][N], float*, const bool);

void calcMinRows(const float[][N], float*);//Минимальные значения строк
void calcMinColumns(const float[][N], float*);//Минимальные значения столбцов
void calcMaxRows(const float[][N], float*);//Максимальные значения строк
void calcMaxColumns(const float[][N], float*);//Максимальные значения столбцов
void calcMinMaxRowsColumns(const float[][N], float*, const bool, const bool);

void calcAverageRows(const float[][N], float*);//Средние арифметические строк
void calcAverageColumns(const float[][N], float*);//Средние арифметические столбцов
void calcAverageRowsColumns(const float[][N], float*, const bool);

float getSumTriangleUpper(const float[][N]);//Сумма верхнетреугольной части
float getSumTriangleLower(const float[][N]);//Сумма нижнетреугольной части
float getSumTriangle(const float[][N], const bool);

float getClosestToAverage(const float[][N]);//Элемент, ближайший к среднеарифметическому

void printArray(const float*);


#endif
