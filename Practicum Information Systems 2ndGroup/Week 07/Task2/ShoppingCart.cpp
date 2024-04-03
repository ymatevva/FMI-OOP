#include<iostream>
#include"ShoppingCart.h"

#pragma warning (disable:4996)
void ShoppingCart::copyFrom(const ShoppingCart& other) {
	_products = new Product[other._capacity];
	for (size_t i = 0; i < other._productsCount; i++)
	{
		_products[i] = other._products[i];
	}
	_productsCount = other._productsCount;
	_capacity = other._capacity;
}
void ShoppingCart::free() {
	delete[] _products;
}

void ShoppingCart::resize(unsigned newCapacity) {

	Product* temp = new Product[newCapacity];
	for (size_t i = 0; i < _productsCount; i++)
	{
		temp[i] = _products[i];
	}

	delete[] _products;
	_products = temp;
	_capacity = newCapacity;
}

ShoppingCart::ShoppingCart(const Product* products, size_t productsCount) {
	if (!products) {
		return;
	}

	_products = new Product[productsCount];
	for (size_t i = 0; i < productsCount; i++)
	{
		addProduct(products[i]);
	}
	_productsCount = productsCount;
	_capacity = productsCount * 2;
}

int ShoppingCart::getIndexOfName(const char* name) const {
	if (!name)
		return -1;
	for (size_t i = 0; i < _productsCount; i++)
	{
		if (strcmp(name, _products[i].getName()) == 0)
			return i;
	}
	return -1;
}

void ShoppingCart::removeProduct(const Product& product) {
	
	int indexOfProduct = getIndexOfName(product.getName());
	if (indexOfProduct == -1)
		return;

	for (size_t i = indexOfProduct; i < _productsCount-1; i++)
	{
		_products[i] = _products[i + 1];
	}
	_productsCount--;
}

void ShoppingCart::addProduct(const Product& product) {
	if (_productsCount + 1 > _capacity)
		resize(_capacity * 2);

	_products[_productsCount++] = product;
}
unsigned ShoppingCart::getProductsCount() const{
	return _productsCount;
}

ShoppingCart::ShoppingCart(const ShoppingCart& other) {
	copyFrom(other);
}

ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
ShoppingCart::~ShoppingCart(){
	free(); 
}

float ShoppingCart::getTotalShoppingCartPrice() const {

	float totalSum = 0;
	for (size_t i = 0; i < _productsCount; i++)
	{
		totalSum += _products[i].getTotalPrice();
	}
	return totalSum;
}

void ShoppingCart::printShoppingCart() const {
	
	std::cout << "Shopping cart with " << _productsCount << " products. " << std::endl; 
	for (size_t i = 0; i < _productsCount; i++)
	{
		_products[i].printInfo();
	}
}



int main() {

	Product* products = new Product[3];
	products[0] = Product("CokeZero", 1.89, 5);
	products[1] = Product("Fanta", 1.78, 3);
	products[2] = Product("Megle", 1.50, 8);
	
	size_t numProducts = 3;

	ShoppingCart shoppingCart(products, numProducts);

	std::cout << "Initial shopping cart:\n";
	shoppingCart.printShoppingCart();
	std::cout << "Total price: " << shoppingCart.getTotalShoppingCartPrice() << std::endl;
	std::cout << "Number of products: " << shoppingCart.getProductsCount() << std::endl;

	
	Product newProduct("Sprite", 2.0, 4);
	shoppingCart.addProduct(newProduct);
	std::cout << "\nAfter adding a new product (Sprite):\n";
	shoppingCart.printShoppingCart();
	std::cout << "Total price: " << shoppingCart.getTotalShoppingCartPrice() << std::endl;
	std::cout << "Number of products: " << shoppingCart.getProductsCount() << std::endl;

	
	Product productToRemove("Fanta", 1.78, 3);
	shoppingCart.removeProduct(productToRemove);
	std::cout << "\nAfter removing product (Fanta):\n";
	shoppingCart.printShoppingCart();
	std::cout << "Total price: $" << shoppingCart.getTotalShoppingCartPrice() << std::endl;
	std::cout << "Number of products: " << shoppingCart.getProductsCount() << std::endl;

	delete[] products;
}