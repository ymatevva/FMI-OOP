#include "Shop.h"
#include<utility>
#include<cstring>
#include<iostream>

#pragma warning (disable:4996)
static bool compare(const Product& prod1, const Product& prod2)
{
	// Compare the names of the products
	return strcmp(prod1.getName(), prod2.getName()) == 0;
}

void Shop::free()
{
	delete[] shopName;
	for (size_t i = 0; i < capacity; i++)
	{
		delete[] products[i];
	}
	delete[] products;
}

void Shop::moveFrom(Shop&& other)
{
	products = other.products;
	other.products = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;

	shopName = other.shopName;
	other.shopName = nullptr;
}

void Shop::copyFrom(const Shop& other)
{
	shopName = new char[strlen(other.shopName) + 1];
	strcpy(shopName, other.shopName);

	size = other.size;
	capacity = other.capacity;

	products = new Product * [capacity];
	for (size_t i = 0; i < capacity; i++) {

		if (other.products[i] == nullptr) {
			products[i] = nullptr;
		}
		else
			products[i] = new Product(*other.products[i]);
	}

}

void Shop::resize(size_t newCap)
{
	capacity = newCap;

	Product** temp = new Product * [capacity] {nullptr};
	for (size_t i = 0; i < capacity; i++)
	{
		temp[i] = products[i];
	}

	delete[] products;
	products = temp;
}

Shop::Shop()
{
	shopName = nullptr;
	size = 0;
	capacity = 8;
	products = new Product * [capacity] {nullptr};
}

Shop::Shop(const char* shopName)
{
	this->shopName = new char[strlen(shopName) + 1];
	strcpy(this->shopName, shopName);

	size = 0;
	capacity = 8;
	products = new Product * [capacity] {nullptr};
}

Shop::Shop(const Shop& other)
{
	copyFrom(other);
}

Shop::Shop(Shop&& other) noexcept
{
	moveFrom(std::move(other));
}

Shop& Shop::operator=(const Shop& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Shop& Shop::operator=(Shop&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Shop::~Shop()
{
	free();
}

const char* Shop::getShopName() const
{
	return shopName;
}

unsigned Shop::getSize() const
{
	return size;
}

Product** Shop::getProductList() const
{
	return products;
}

void Shop::setShopName(const char* shopName)
{
	if (!shopName || this->shopName == shopName) {
		return;
	}

	delete[] this->shopName;
	this->shopName = new char[strlen(shopName) + 1];
	strcpy(this->shopName, shopName);
}

void Shop::sellProduct(Product& product)
{
	int indexToRemove = -1;

	for (int i = 0; i < this->capacity; ++i)
	{
		if (compare(*products[i], product))
		{
			indexToRemove = i;
			break;
		}
	}

	if (indexToRemove != -1)
	{
		if (product.getQuantity() == products[indexToRemove]->getQuantity())
		{
			Product::numDiffProducts--;
			delete products[indexToRemove];

			for (int i = indexToRemove; i < size - 1; ++i)
			{
				products[i] = products[i + 1];
			}

			--size;

			if (size < capacity / 4)
			{
				resize(capacity / 2);
			}
		}
		else
		{
			products[indexToRemove]->setQuantity(products[indexToRemove]->getQuantity() - product.getQuantity());
		}
	}
}

void Shop::addProducts(Product** productsToAdd)
{
	for (int i = 0; products[i] != nullptr; ++i)
	{
		Product* newProduct = products[i];
		bool found = false;
		for (int j = 0; j < size; ++j)
		{
			if (compare(*products[j], *newProduct))
			{
				products[j]->setQuantity(products[j]->getQuantity() + newProduct->getQuantity());
				Product::numAllProducts += newProduct->getQuantity();
				found = true;
				break;
			}
		}
		if (!found)
		{
			if (size >= capacity)
			{
				resize(capacity * 2);
			}

			this->products[size++] = newProduct;

			Product::numDiffProducts++;
			Product::numAllProducts += newProduct->getQuantity();
		}
	}
}



int main() {

	Product product1("Apple", 100, 10, 1.50,TypeProduct::Food);
	Product product2( "Water" , 500, 20, 0.0f, TypeProduct::Beverages);

	std::cout << "Product 1:" << std::endl;
	printProduct(product1);
	std::cout << std::endl;

	std::cout << "Product 2:" << std::endl;
	printProduct(product2);
	std::cout << std::endl;

	std::cout << "Different Products Count Initially: " << Product::numDiffProducts << std::endl;
	std::cout << "All Products Count Initially: " << Product::numAllProducts << std::endl;

	product1.addProduct(product1);
	product2.addProduct(product2);

	std::cout << "Different Products Count After Adding The Products: " << Product::numDiffProducts << std::endl;
	std::cout << "All Products Count After Adding The Products: " << Product::numAllProducts<< std::endl;

	product1.sellProduct(product1);
	product2.sellProduct(product2);

	std::cout << "Different Products Count After Deleting The Products: " << Product::numDiffProducts<< std::endl;
	std::cout << "All Products Count After Deleting The Products: " << Product::numAllProducts << std::endl;

	//task 2
	std::cout << "==========================================TASK 2<<==========================================" << std::endl;
	Shop shop("MyShop");

	Product* product3 = new Product("Apple",1.50 ,100, 10 , TypeProduct::Food);
	Product* product4 = new Product("Water", 0.5,500, 20, TypeProduct::Beverages);
	Product* product5 = new Product("Banana", 1.2,80, 15,  TypeProduct::Food);

	Product* productsToAdd[] = { product3, product4, product5, nullptr };

	shop.addProducts(productsToAdd);

	std::cout << "Shop Name: " << shop.getShopName() << std::endl;

	std::cout << "Products in the shop:" << std::endl;
	for (int i = 0; i < shop.getSize(); ++i) {
		std::cout << "Name: " << shop.getProductList()[i]->getName() << ", Count: " << shop.getProductList()[i]->getQuantity() << std::endl;
	}

	shop.sellProduct(*product3);
	Product* product6 = new Product("Banana", 80, 2, 1.2, TypeProduct:: Food);
	shop.sellProduct(*product6);


	std::cout << "\nProducts in the shop after removal:" << std::endl;
	for (int i = 0; i < shop.getSize(); ++i) {
		std::cout << "Name: " << shop.getProductList()[i]->getName() << ", Count: " << shop.getProductList()[i]->getQuantity() << std::endl;
	}
	return 0;
}

