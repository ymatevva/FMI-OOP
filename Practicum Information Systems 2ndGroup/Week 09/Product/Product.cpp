#include "Product.h"
#include<cstring>
#include<exception>
#include<iostream>


#pragma warning(disable:4996)

unsigned Product::numDiffProducts = 0;
unsigned Product::numAllProducts = 0;


const char* Product::getName() const
{
	return name;
}
float Product::getPrice() const
{
	return price;
}
int Product::getGrams() const
{
	return grams;
}
int Product::getQuantity() const
{
	return quantity;
}
TypeProduct Product::getType() const
{
	return typeProd;
}

void Product::sellProduct(const Product& prod)
{
	if (quantity == prod.quantity)
	{
		numDiffProducts--;
	}
	numAllProducts -= quantity;
}

void Product::addProduct(const Product& prod)
{
	numDiffProducts	++;
	numAllProducts += prod.quantity;
}

void printProduct(const Product& prod)
{
	std::cout << "Name: " << prod.name << " " 
	<< "Grams: " << prod.grams << " " 
	<< "Quantity: " << prod.quantity << " " 
	<< "Price: " << prod.price << " "
	<< "Type: " << (int)prod.typeProd << std::endl;
}

void Product::setName(const char* name)
{
	if (!name || this->name == name) {
		throw std::invalid_argument("The name is invalid.");
	}

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Product::setGrams(int grams)
{
	if (grams < 0) {
		throw std::invalid_argument("The grams cannot be a negative number.");
	}
	this->grams = grams;
}

void Product::setQuantity(int quantity)
{
	if (quantity < 0) {
		throw std::invalid_argument("The quantitiy cannot be a negative number.");
	}
	numAllProducts += quantity - this->quantity;
	this->quantity = quantity;
}

void Product::setPrice(float price)
{
	if (price < 0) {
		throw std::invalid_argument("The price cannot be a negative number.");
	}
	this->price = price;
}

void Product::setType(TypeProduct typeProd){
	this->typeProd = typeProd;
}

void Product::copyFrom(const Product& other)
{
	name = other.name;

	grams = other.grams;

	quantity = other.quantity;

	price = other.price;

	typeProd = other.typeProd;
}

void Product::moveFrom(Product&& other)
{
	name = other.name;
	other.name = 0;

	grams = other.grams;
	other.grams = 0;

	quantity = other.quantity;
	other.quantity = 0;

	price = other.price;
	other.price = 0;

	typeProd = other.typeProd;
	other.typeProd = TypeProduct::Other;
}

void Product::free()
{
	delete[] name;
}

Product::Product() :name(nullptr), grams(0), quantity(0), price(0), typeProd(TypeProduct::Other){}

Product::Product(const char* name, double price, unsigned grams, unsigned quantity, TypeProduct typreProd)
{
	setName(name);
	setGrams(grams);
	setPrice(price);
	setQuantity(quantity);
	setType(typeProd);
}

Product::Product(const Product& other)
{
	copyFrom(other);
}

Product::Product(Product&& other) noexcept
{
	moveFrom(std::move(other));
}

Product& Product::operator=(const Product& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Product& Product::operator=(Product&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Product::~Product()
{
	free();
}
bool operator==(const Product& lhs, const Product& rhs) {
	return lhs.getGrams() == rhs.getGrams() &&
		lhs.getPrice() == rhs.getGrams() &&
		lhs.getName() == rhs.getName() &&
		lhs.getType() == rhs.getType();
 }/*
int main() {
	try {
		
		Product product1("Cake", 10.99, 500, 5, TypeProduct::Food);
		Product product2("Shirt", 19.99, 200, 10, TypeProduct::Other);

	
		std::cout << "Product name: " << product1.getName() << std::endl;
		std::cout << "Product price: " << product1.getPrice() << std::endl;
		std::cout << "Product grams: " << product1.getGrams() << std::endl;
		std::cout << "Product quantity: " << product1.getQuantity() << std::endl;
		std::cout << "Product type: " << (int)(product1.getType()) << std::endl;

		
		product1.setPrice(12.99);
		product1.setQuantity(7);
		product1.setType(TypeProduct::Food);

		std::cout << "Updated product price: " << product1.getPrice() << std::endl;
		std::cout << "Updated product quantity: " << product1.getQuantity() << std::endl;
		std::cout << "Updated product type: " << (int)(product1.getType()) << std::endl;

		product1.sellProduct(product1);
		product2.addProduct(product2);

		printProduct(product1);
		printProduct(product2);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}*/
