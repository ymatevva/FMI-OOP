#pragma once


class Product {

	char* _name = nullptr;
	float _price = 0;
	unsigned _quantity = 0;

	void copyFrom(const Product& other);
	void free();
public:

	Product() = default;
	Product(const char* name, float price, unsigned quantity);
	Product(const Product& other);
	Product&operator=(const Product& other);
	~Product();


	void setName(const char* name);
	void setPrice(float price);
	void setQuantity(unsigned quantity);

	const char* getName() const;
	float getPrice() const;
	unsigned getQuantity() const;

	void printInfo() const;
	float getTotalPrice() const;
};