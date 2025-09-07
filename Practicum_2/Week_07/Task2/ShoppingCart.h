#pragma once
#include"Product.h"

class ShoppingCart {

	Product* _products = nullptr;
	unsigned _productsCount = 0;
	unsigned _capacity = 1;


	void copyFrom(const ShoppingCart& other);
	void free();
	void resize(unsigned newCapacity);
	int getIndexOfName(const char* name) const;

public:

	ShoppingCart() = default;
	ShoppingCart(const Product* products, size_t productsCount);
	ShoppingCart(const ShoppingCart& other);
	ShoppingCart&operator=(const ShoppingCart& other);
	~ShoppingCart();

	unsigned getProductsCount() const;

	void addProduct(const Product& product);
	void removeProduct(const Product& product);

	float getTotalShoppingCartPrice() const;
	void printShoppingCart() const;
};