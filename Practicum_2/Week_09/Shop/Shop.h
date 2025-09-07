#pragma once
#include"Product.h"

class Shop {

	Product** products;
	char* shopName;
	size_t size;
	size_t capacity;

	void free();
	void moveFrom(Shop&& other);
	void copyFrom(const Shop& other);
	void resize(size_t newCap);

public:
	Shop();
	Shop( const char* shopName);
	Shop(const Shop& other);
	Shop(Shop&& other) noexcept;
	Shop& operator=(const Shop& other);
	Shop& operator=(Shop&& other)noexcept;
	~Shop();

	const char* getShopName() const;
	unsigned getSize() const;
	Product** getProductList() const;

	void setShopName(const char* shopName);

	void sellProduct(Product& product);
	void addProducts(Product** productsToAdd);
};