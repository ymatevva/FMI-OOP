#include<iostream>

constexpr int DESCRIPTION_SIZE = 32;

struct Product {

	char description[DESCRIPTION_SIZE];
	int partNum = 0;
	double cost = 0;
};

//a
void initProduct(Product& product) {

	std::cin.getline(product.description, DESCRIPTION_SIZE);
	std::cin >> product.partNum >> product.cost;
	std::cin.ignore();
}

//b
void printProduct(const Product& product) {

	std::cout << "Product description: " << product.description << "  Product number: " << product.partNum << " Price of product: " << product.cost << std::endl;
}

//c
void initProductsWithNeutral(Product* products, size_t size)
{
	if (!products)
		return;
	
	for (size_t i = 0; i < size; i++){
		products[i] = { 0, 0, 0 };
	}
}

//e
void initProductArr(Product* products, size_t numProducts) {
	
	if (!products)
		return;

	for (size_t i = 0; i < numProducts; i++){
		initProduct(products[i]);
	}
}

//f
void printProductArr(const Product* products, size_t numProducts) {
	
	if (!products)
		return;

	for (size_t i = 0; i < numProducts; i++){
		printProduct(products[i]);
	}
}
int main() {

	/**
	Product pr1;
	Product pr2;

	initProduct(pr1);
	initProduct(pr2);

	printProduct(pr1);
	printProduct(pr2);
	*/

	//c
	Product products[5];
	initProductArr(products, 5);
	printProductArr(products, 5);

	return 0;
}
