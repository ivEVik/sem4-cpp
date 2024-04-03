#include <functional>
#include <limits>
#include <iostream>
#include <iomanip>
#include <conio.h>

#include "matrix.h"


int main()
{
	float matrix[N][N];
	
	for(size_t y = 0; y < N; ++y)
		for(size_t x = 0; x < N; ++x)
			matrix[x][y] = rand() / 10.;
	
	for(size_t y = 0; y < N; ++y)
	{
		for(size_t x = 0; x < N; ++x)
			std::cout << std::setw(8) << std::setprecision(5) << matrix[x][y];
		std::cout << std::endl;
	}
	
	std::cout << "\nmin\t\t= " << getMin(matrix);
	std::cout << "\nmax\t\t= " << getMax(matrix);
	
	std::cout << "\n\nupper triangle min\t= " << getMinTriangleUpper(matrix);
	std::cout << "\nupper triangle max\t= " << getMaxTriangleUpper(matrix);
	std::cout << "\nlower triangle min\t= " << getMinTriangleLower(matrix);
	std::cout << "\nlower triangle max\t= " << getMaxTriangleLower(matrix);
	
	std::cout << "\n\nprimary diagonal min\t= " << getMinDiagonalPrimary(matrix);
	std::cout << "\nprimary diagonal max\t= " << getMaxDiagonalPrimary(matrix);
	std::cout << "\nsecondary diagonal min\t= " << getMinDiagonalSecondary(matrix);
	std::cout << "\nsecondary diagonal max\t= " << getMaxDiagonalSecondary(matrix);
	
	std::cout << "\n\nmatrix average\t\t= " << getAverage(matrix);
	std::cout << "\nclosest to average\t= " << getClosestToAverage(matrix);
	
	std::cout << "\n\nupper triangle average\t= " << getAverageTriangleUpper(matrix);
	std::cout << "\nlower triangle average\t= " << getAverageTriangleLower(matrix);
	
	float* array = new float[N];
	calcSumRows(matrix, array);
	std::cout << "\n\nrow sums\t\t= ";
	printArray(array);
	
	calcSumColumns(matrix, array);
	std::cout << "\ncolumn sums\t\t= ";
	printArray(array);
	
	calcAverageRows(matrix, array);
	std::cout << "\n\nrow averages\t\t= ";
	printArray(array);
	
	calcAverageColumns(matrix, array);
	std::cout << "\ncolumn averages\t\t= ";
	printArray(array);
	
	std::cout << "\n\nupper triangle sum\t= " << getSumTriangleUpper(matrix);
	std::cout << "\nlower triangle sum\t= " << getSumTriangleLower(matrix);
	
	delete[] array;
	std::cout << std::endl;
	_getch();
}


float getMin(const float matrix[][N]) { return getMinMax(matrix, false); }
float getMax(const float matrix[][N]) { return getMinMax(matrix, true); }

float getMinMax(const float matrix[][N], const bool max)
{
	std::function<float(float, float)> filter = max
		? [](float a, float b) -> float { return a > b ? a : b; }
		: [](float a, float b) -> float { return a < b ? a : b; };
	float result = matrix[0][0];
	
	for(size_t y = 0; y < N; ++y)
		for(size_t x = 0; x < N; ++x)
			result = filter(result, matrix[x][y]);
	
	return result;
}

float getMinTriangleUpper(const float matrix[][N]) { return getMinMaxTriangle(matrix, false, true); }
float getMaxTriangleUpper(const float matrix[][N]) { return getMinMaxTriangle(matrix, true, true); }
float getMinTriangleLower(const float matrix[][N]) { return getMinMaxTriangle(matrix, false, false); }
float getMaxTriangleLower(const float matrix[][N]) { return getMinMaxTriangle(matrix, true, false); }

float getMinMaxTriangle(const float matrix[][N], const bool max, const bool upper)
{
	std::function<float(float, float)> filter = max
		? [](float a, float b) -> float { return a > b ? a : b; }
		: [](float a, float b) -> float { return a < b ? a : b; };
	float result = matrix[0][0];
	
	for(size_t y = 0; y < N; ++y)
		for(size_t x = upper ? y : 0; x < (upper ? N : y + 1); ++x)
			result = filter(result, matrix[x][y]);
	
	return result;
}

float getMinDiagonalPrimary(const float matrix[][N]) { return getMinMaxDiagonal(matrix, false, true); }
float getMaxDiagonalPrimary(const float matrix[][N]) { return getMinMaxDiagonal(matrix, true, true); }
float getMinDiagonalSecondary(const float matrix[][N]) { return getMinMaxDiagonal(matrix, false, false); }
float getMaxDiagonalSecondary(const float matrix[][N]) { return getMinMaxDiagonal(matrix, true, false); }

float getMinMaxDiagonal(const float matrix[][N], const bool max, const bool primary)
{
	std::function<float(float, float)> filter = max
		? [](float a, float b) -> float { return a > b ? a : b; }
		: [](float a, float b) -> float { return a < b ? a : b; };
	std::function<bool(int)> yCompare = primary
		? [](int y) -> bool { return y < N; }
		: [](int y) -> bool { return y >= 0; };
	float result = primary ? matrix[0][0] : matrix[0][N - 1];
	
	for(int y = primary ? 0 : N - 1; yCompare(y); y += primary ? 1 : -1)
		result = primary ? filter(result, matrix[y][y]) : filter(result, matrix[N - y - 1][y]);
	
	return result;
}

float getAverage(const float matrix[][N])
{
	float result = 0;
	
	for(size_t y = 0; y < N; ++y)
		for(size_t x = 0; x < N; ++x)
			result += matrix[x][y];
	
	result /= N * N;
	
	return result;
}

float getAverageTriangleUpper(const float matrix[][N]) { return getAverageTriangle(matrix, true); }
float getAverageTriangleLower(const float matrix[][N]) { return getAverageTriangle(matrix, false); }

float getAverageTriangle(const float matrix[][N], const bool upper)
{
	float result = 0;
	int count = 0;
	
	for(size_t y = 0; y < N; ++y)
		for(size_t x = upper ? y : 0; x < (upper ? N : y + 1); ++x)
		{
			result += matrix[x][y];
			++count;
		}
	
	result /= count;
	
	return result;
}

void calcSumRows(const float matrix[][N], float* result) { calcSumRowsColumns(matrix, result, true); }
void calcSumColumns(const float matrix[][N], float* result) { calcSumRowsColumns(matrix, result, false); }

void calcSumRowsColumns(const float matrix[][N], float* result, const bool rows)
{
	delete[] result;
	result = new float[N]();
	
	for(size_t y = 0; y < N; ++y)
		for(size_t x = 0; x < N; ++x)
			result[rows ? y : x] += matrix[x][y];
}

void calcMinRows(const float matrix[][N], float* result) { calcMinMaxRowsColumns(matrix, result, false, true); }
void calcMinColumns(const float matrix[][N], float* result) { calcMinMaxRowsColumns(matrix, result, false, false); }
void calcMaxRows(const float matrix[][N], float* result) { calcMinMaxRowsColumns(matrix, result, true, true); }
void calcMaxColumns(const float matrix[][N], float* result) { calcMinMaxRowsColumns(matrix, result, true, false); }

void calcMinMaxRowsColumns(const float matrix[][N], float* result, const bool max, const bool rows)
{
	delete[] result;
	result = new float[N]();
	
	std::function<float(float, float)> filter = max
		? [](float a, float b) -> float { return a > b ? a : b; }
		: [](float a, float b) -> float { return a < b ? a : b; };
	
	for(size_t y = 0; y < N; ++y)
		for(size_t x = 0; x < N; ++x)
			result[rows ? y : x] = filter(result[rows ? y : x], matrix[x][y]);
}

void calcAverageRows(const float matrix[][N], float* result) { calcAverageRowsColumns(matrix, result, true); }
void calcAverageColumns(const float matrix[][N], float* result) { calcAverageRowsColumns(matrix, result, false); }

void calcAverageRowsColumns(const float matrix[][N], float* result, const bool rows)
{
	delete[] result;
	result = new float[N]();
	
	calcSumRowsColumns(matrix, result, rows);
	
	for(size_t t = 0; t < N; ++t)
		result[t] /= N;
}

float getSumTriangleUpper(const float matrix[][N]) { return getSumTriangle(matrix, true); }
float getSumTriangleLower(const float matrix[][N]) { return getSumTriangle(matrix, false); }
float getSumTriangle(const float matrix[][N], const bool upper)
{
	float result = 0;
	
	for(size_t y = 0; y < N; ++y)
		for(size_t x = upper ? y : 0; x < (upper ? N : y + 1); ++x)
			result += matrix[x][y];
	
	return result;
}

float getClosestToAverage(const float matrix[][N])
{
	const float average = getAverage(matrix);
	float difference = std::numeric_limits<float>::max();
	float result = matrix[0][0];
	
	for(size_t y = 0; y < N; ++y)
		for(size_t x = 0; x < N; ++x)
			if(abs(matrix[x][y] - average) < difference)
			{
				result = matrix[x][y];
				difference = abs(result - average);
			}
	
	return result;
}


void printArray(const float* array)
{
	std::cout << "{ ";
	for(size_t t = 0; t < N; ++t)
		std::cout << array[t] << ' ';
	std::cout << '}';
}
