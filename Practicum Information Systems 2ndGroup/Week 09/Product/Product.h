#pragma once


enum class TypeProduct {
	Food,
	Beverages,
	Other
};


class Product {

	char* name;
	float price;
	int grams;
	int quantity;
	TypeProduct typeProd;


	void copyFrom(const Product& other);
	void moveFrom(Product&& other);
	void free();

public:

	static unsigned numDiffProducts;
	static unsigned numAllProducts;

	Product();
	Product(const char* name, double price, unsigned grams, unsigned quantity, TypeProduct typreProd);
	Product(const Product& other);
	Product(Product&& other)noexcept;
	Product& operator=(const Product& other);
	Product& operator=(Product&& other)noexcept;
	~Product();

	void setName(const char* name);
	void setGrams(int grams);
	void setQuantity(int quantity);
	void setPrice(float price);
	void setType(TypeProduct typeProd);

	const char* getName() const;
	float getPrice() const;
	int getGrams() const;
	int getQuantity() const;
	TypeProduct getType() const;

	void sellProduct(const Product& prod);
	 void addProduct(const Product& prod);
	friend void printProduct(const Product& prod);
	friend bool operator==(const Product& lhs, const Product& rhs);
};
