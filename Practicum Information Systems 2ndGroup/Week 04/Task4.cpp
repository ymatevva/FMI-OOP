#include<iostream>
#include<fstream>

struct Customer {

	char* name;
	char* ID;
    unsigned age;
};

struct Order {
	double price;
	double DDS;
	Customer customer;
};

void readCustomer(std::ifstream& ifs, Customer& customer) {

	size_t nameLen = 0;
	ifs.read((char*)&nameLen, sizeof(nameLen));

	customer.name = new char[nameLen + 1];
	ifs.read(customer.name, nameLen + 1);

	size_t IDLen = 0;
	ifs.read((char*)&IDLen, sizeof(IDLen));

	customer.ID = new char[IDLen + 1];
	ifs.read(customer.ID, IDLen);

	ifs.read((char*)&customer.age, sizeof(customer.age));
}

void readOrder(std::ifstream& ifs, Order& order) {
	ifs.read((char*)&order.price, sizeof(order.price));
	ifs.read((char*)&order.DDS, sizeof(order.DDS));
	readCustomer(ifs, order.customer);
}

void readOrdersFromFile(std::ifstream& ifs, Order*& orders, size_t& size) {

	ifs.read((char*)&size, sizeof(size));

	orders = new Order[size];
	for (size_t i = 0; i < size; i++){
		readOrder(ifs, orders[i]);
	}
}

void readFromFile(const char* fromFile, Order*& orders, size_t& size) {

	if (!fromFile)
		return;

	std::ifstream ifs(fromFile, std::ios::binary);
	if (!ifs.is_open())
		return;

	readOrdersFromFile(ifs, orders, size);
}

void writeCustomer(std::ofstream& ofs, const Customer& customer) {

	size_t nameSize = strlen(customer.name);
	size_t IDLen = strlen(customer.ID);

	ofs.write((const char*)&nameSize, sizeof(nameSize));
	ofs.write(customer.name, nameSize+1);

	ofs.write((const char*)&IDLen, sizeof(IDLen));
	ofs.write(customer.ID, IDLen + 1);

	ofs.write((const char*)&customer.age, sizeof(customer.age));
}

void writeOrder(std::ofstream& ofs, const Order& order) {

	ofs.write((const char*)&order.price, sizeof(order.price));
	ofs.write((const char*)&order.DDS, sizeof(order.DDS));
	writeCustomer(ofs, order.customer);
}

void writeOrdersToFile(std::ofstream& ofs, const Order* orders, size_t& size) {

	if (!orders)
		return;

	ofs.write((const char*)&size, sizeof(size));

	for (size_t i = 0; i < size; i++){
		writeOrder(ofs, orders[i]);
	}
}

void writeToFile(const char* toFile,const Order* orders, size_t size)
{
	if (!toFile || !orders)
		return;

	std::ofstream ofs(toFile, std::ios::binary);
	if (!ofs.is_open())
		return;

	writeOrdersToFile(ofs, orders, size);
}

void freeMemory(Order* orders, size_t size) {
	if (!orders)
		return;

	for (size_t i = 0; i < size; i++)
	{
		delete[] orders[i].customer.name;
		delete[] orders[i].customer.ID;
	}
	delete[] orders;
}
void printOrder(const Order& order)
{
	std::cout << "Price: " << order.price << std::endl << "DDS: " << order.DDS << std::endl;
	std::cout << "Name: " << order.customer.name << ", ID: " << order.customer.ID << ", Age: " << order.customer.age << std::endl;
}

int main() {

	Order firstOrd = { 15.7,0.7,{new char[6] {"Yoana"} ,new char[6] {"45678"},20} };
	Order order[] = { firstOrd };

	writeToFile("outputFile.dat", order, 1);

	return 0;
}