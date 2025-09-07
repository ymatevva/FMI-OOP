#include<iostream>


int** createMtx(unsigned rows, unsigned colls) {

	int** mtx = new int* [rows];

	for (size_t i = 0; i < rows; i++) {

		mtx[i] = new int[colls];
		for (size_t j = 0; j < colls; j++) {
			std::cin >> mtx[i][j];
		}
	}
	return mtx;
}


int** createEmptyMtx(unsigned rows, unsigned colls) {

	int** mtx = new int* [rows];

	for (size_t i = 0; i < rows; i++) {

		mtx[i] = new int[colls];
		for (size_t j = 0; j < colls; j++) {
			mtx[i][j] = 0;
		}
	}
	return mtx;
}

int** transposeMatrix(int** mtx, unsigned rows, unsigned colls) {

	if (!mtx)
		return 0;

	int** transposedMtx = createEmptyMtx(colls, rows);

	for (size_t i = 0; i < rows; i++) {

		for (size_t j = 0; j < colls; j++) {
			transposedMtx[j][i] = mtx[i][j];
		}
	}
	return transposedMtx;
}

void printMtx(int** mtx, unsigned rows, unsigned colls) {

	if (!mtx)
		return;

	for (size_t i = 0; i < rows; i++) {

		for (size_t j = 0; j < colls; j++) {
			std::cout << mtx[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void freeMtx(int** mtx, unsigned rows) {

	if (!mtx)
		return;

	for (size_t i = 0; i < rows; i++) {
		delete[] mtx[i];
	}

	delete[] mtx;
}


int main() {

	unsigned rows, colls;
	std::cin >> rows >> colls;

	int** mtx = createMtx(rows, colls);

	int** transposed = transposeMatrix(mtx, rows, colls);
	printMtx(transposed, colls, rows);

	freeMtx(transposed, colls);
	freeMtx(mtx, rows);
	return 0;
}