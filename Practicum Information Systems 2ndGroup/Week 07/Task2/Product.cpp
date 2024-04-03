#include "Product.h"
#include<iostream>
#include<cstring>
#pragma warning (disable:4996)

void Product::copyFrom(const Product& other){
	_name = new char[strlen(other._name) + 1];
	strcpy(_name, other._name);
	_price = other._price;
	_quantity = other._quantity;
}

void Product::free(){
	delete[] _name;
}


Product::Product(const char* name, float price, unsigned quantity){
	setName(name);
	setPrice(price);
	setQuantity(quantity);
}

Product::Product(const Product& other){
	copyFrom(other);
}

Product& Product::operator=(const Product& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Product::~Product(){
	free();
}

void Product::setName(const char* name)
{
	if (!name || _name == name)
		return;
	delete[]_name;
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
}

void Product::setPrice(float price){
	if (price <= 0)
		return;
	_price = price;
}


void Product::setQuantity(unsigned quantity){
	_quantity = quantity;
}

const char* Product::getName() const{
	return _name;
}

float Product::getPrice() const{
	return _price;
}

unsigned Product::getQuantity() const{
	return _quantity;
}

void Product::printInfo() const
{
	std::cout << "Name: " << _name << " Price: " << _price << " Quantity: " << _quantity << std::endl;
}

float Product::getTotalPrice() const{
	return _price * _quantity;
}
