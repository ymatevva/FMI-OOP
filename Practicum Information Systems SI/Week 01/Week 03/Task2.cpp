#include<iostream>
#include<fstream>

namespace Constants {

	constexpr int PRODUCT_NAME = 101;
	constexpr int PRODUCT_SUPPLIER = 101;
	constexpr int PRODUCTS_NUM = 100;
	constexpr int CATEGORY_SIZE = 20;
	constexpr int COMMAND_SIZE = 10;
}

enum class Category {
	Undefined,
	Electronics,
	Clothing,
	Books,
	Food,
	Beauty
};

struct Product {

	char productName[Constants::PRODUCT_NAME];
	char productSupplier[Constants::PRODUCT_SUPPLIER];
	Category category;
	int quantity = 0;
	double price = 0;
};

struct Warehouse {

	size_t numProducts = 0;
	Product* products = nullptr;;
};

unsigned getFileSize(std::ifstream& ifs)
{
	int currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);

	unsigned size = ifs.tellg();
	ifs.seekg(currPos);
	ifs.clear();

	return size;
}

//loading products from binary
void readWarehouseFromFile(std::ifstream& ifs, Warehouse& warehouse) {

	warehouse.numProducts = getFileSize(ifs) / sizeof(Product);
	warehouse.products = new Product[warehouse.numProducts];
	ifs.read((char*)warehouse.products, warehouse.numProducts* sizeof(Product));
}

void readFromFile(const char* fromFile,Warehouse& warehouse) {

	if (!fromFile)
		return;

	std::ifstream ifs(fromFile, std::ios::binary);
	if (!ifs.is_open())
		return;

	readWarehouseFromFile(ifs, warehouse);
}

// input from console
Category readCategory() {
	
	char category[Constants::CATEGORY_SIZE];
	std::cin.getline(category, Constants::CATEGORY_SIZE);

	if (strcmp(category, "Beauty") == 0)
		return Category::Beauty;

	else if (strcmp(category, "Books") == 0)
		return Category::Books;

	else if (strcmp(category, "Electronics") == 0)
		return Category::Electronics;

	else if (strcmp(category, "Clothing") == 0)
		return Category::Clothing;

	else if (strcmp(category, "Food") == 0)
		return Category::Food;

	else
		return Category::Undefined;
}

void readProductFromConsole(Product& product){

	std::cin.getline(product.productName, Constants::PRODUCT_NAME);
	std::cin.getline(product.productSupplier, Constants::PRODUCT_SUPPLIER);
	product.category = readCategory();
	std::cin >> product.quantity >> product.price;
}

void readWarehouseFromConsole(Warehouse& warehouse) {

	std::cin >> warehouse.numProducts;
	std::cin.ignore();
	for (size_t i = 0; i < warehouse.numProducts; i++){
		readProductFromConsole(warehouse.products[i]);
	}
}

// warehouse to file

void writeWarehouse(std::ofstream& ofs, const Warehouse& warehouse) {

	ofs.write((const char*)warehouse.products, sizeof(Product)*warehouse.numProducts);
	
}

void writeToFile(const char* toFile, const Warehouse& warehouse) {
	
	if (!toFile)
		return;

	std::ofstream ofs(toFile, std::ios::binary);
	if (!ofs.is_open())
		return;

	writeWarehouse(ofs, warehouse);
}

// print warehouse
void printCategory(const Category& category) {

	switch (category)
	{
	  case Category::Beauty:
		std::cout << "Beauty" << " "; break;

	  case Category::Books:
		std::cout << "Books" << std::endl; break;

	  case Category::Electronics:
		  std::cout << "Electronics" << std::endl; break;

	  case Category::Food:
		  std::cout << "Food" << std::endl; break;

	  case Category::Clothing:
		  std::cout << "Clothing" << std::endl; break;

	  case Category::Undefined:
		  std::cout << "Undefined" << std::endl; break;
	}
}
void printProduct(const Product& product) {

	std::cout << product.productName << " " << product.productSupplier << " " << product.price << " " << product.quantity << " ";
	printCategory(product.category);
}
void printWarehouse(const Warehouse& warehouse) {

	for (size_t i = 0; i < warehouse.numProducts; i++){
		printProduct(warehouse.products[i]);
		std::cout << std::endl;
	}
}

//print product by given name
void printExactProduct(const Warehouse& warehouse,const char* nameProduct) {

	for (size_t i = 0; i < warehouse.numProducts; i++) {
		
		if(strcmp(nameProduct,warehouse.products[i].productName) == 0)
		printProduct(warehouse.products[i]);
	}
	std::cout << "The product is missing" << std::endl;
}

void changeQuantity( Product& product, int newQuantity) {
	product.quantity = newQuantity;
}

//write in file only products from given category
void writeProductsFromCat(std::ofstream& ofs,const Warehouse& warehouse, Category category) {
	
	for (size_t i = 0; i < warehouse.numProducts; i++) {
		if (warehouse.products[i].category == category)
			ofs.write((const char*)&warehouse.products[i], sizeof(warehouse.products[i]));
	}
}

void writeProductsFromCategory(const char* toFile,const Warehouse& warehouse,  Category category) {

	if (!toFile)
		return;

	std::ofstream ofs(toFile,std::ios::binary);
	if (!ofs.is_open())
		return;

	writeProductsFromCat(ofs, warehouse, category);
}

int main() {

	
	Product p1 = { "NYX Lip gloss", "Notino",Category::Beauty,20,5.6 };
	Product p2 = { "Death on the Nile", "Ciela",Category::Books,13, 7.8};

	Product products[2] = { p1,p2 };
	//Warehouse warehouse{ 2,products};

	//writeToFile("ProductsToFile.dat",warehouse);
	//printWarehouse(warehouse);
	
	
	
	Warehouse warehouse{};
	readFromFile("ProductsToFile.dat", warehouse);
	printWarehouse(warehouse);
	
	
	writeProductsFromCategory("Products.dat", warehouse, Category::Books);

	delete[] warehouse.products;
	return 0;
}