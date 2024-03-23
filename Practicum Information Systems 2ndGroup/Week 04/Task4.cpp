#include<iostream>
#include<fstream>


#pragma warning(disable : 4996)

struct Customer {

	char* name = nullptr;
	long int ID = 0;
	unsigned age = 0;
};

struct Order {
	double price = 0;
	double DDS = 0;
	Customer customer{};
};

Order initOrder(double price, double DDS,  const char* name, long int ID, unsigned age) {

	Order order{};

	order.price = price;
	order.DDS = DDS;

	order.customer.name = new char[strlen(name) + 1];
	strcpy(order.customer.name, name);
	order.customer.ID = ID;
	order.customer.age= age;

	return order;
}

void readCustomer(std::ifstream& ifs, Customer& customer) {

	size_t nameLen = 0;
	ifs.read((char*)&nameLen, sizeof(nameLen));

	customer.name = new char[nameLen + 1];
	ifs.read((char*)customer.name, nameLen + 1);

	ifs.read((char*)&customer.ID, sizeof(customer.ID));
	ifs.read((char*)&customer.age, sizeof(customer.age));
}
void readOrderFromFile(std::ifstream& ifs, Order& order) {

	ifs.read(( char*)&order.price, sizeof(order.price));
	ifs.read(( char*)&order.DDS, sizeof(order.DDS));
	readCustomer(ifs, order.customer);
}
void readOrdersFromFile(std::ifstream& ifs, Order*& orders, size_t& sizeArr) {

	ifs.read(( char*)&sizeArr, sizeof(sizeArr));
	orders = new Order[sizeArr];
	ifs.read((char*)orders, sizeof(Order) * sizeArr);
}
void readFromFile(const char* fromFile, Order*& orders, size_t& sizeArr) {
	if (!fromFile)
		return;

	std::ifstream ifs(fromFile, std::ios::binary);
	if (!ifs.is_open())
		return;
	readOrdersFromFile(ifs, orders, sizeArr);
}

void writeCustomer(std::ofstream& ofs,const Customer& customer) {

	size_t nameLen = strlen(customer.name);
	ofs.write((const char*)&nameLen, sizeof(nameLen));

	ofs.write((const char*)customer.name, nameLen + 1);

	ofs.write((const char*)&customer.ID, sizeof(customer.ID));
	ofs.write((const char*)&customer.age, sizeof(customer.age));
}
void writeOrdersToFile(std::ofstream& ofs, const Order* orders, size_t sizeArr) {

	if (!orders)
		return;

	ofs.write((const char*)&sizeArr, sizeof(sizeArr));
	ofs.write((const char*)orders, sizeof(Order) * sizeArr);
}
void writeOrderToFile(std::ofstream& ofs, const Order& order) {

	ofs.write((const char*)&order.price, sizeof(order.price));
	ofs.write((const char*)&order.DDS, sizeof(order.DDS));
	writeCustomer(ofs, order.customer);
}
void writeToFile(const char* toFile,const Order* orders, size_t sizeArr) {
	if (!toFile)
		return;

	std::ofstream ofs(toFile, std::ios::binary);
	if (!ofs.is_open())
		return;
    writeOrdersToFile(ofs, orders, sizeArr);
}

void printCustomer(const Customer& customer) {

	std::cout << "Name: " << customer.name << " ID: " << customer.ID << " Age: " << customer.age << std::endl;
}
void printOrder(const Order& order) {

	std::cout << "Price: " << order.price << " DDS: " << order.DDS << " ";
	printCustomer(order.customer);
}
void printOrders(const Order* orders, size_t sizeArr) {

	for (size_t i = 0; i < sizeArr; i++){
		printOrder(orders[i]);
	}
}

void freeMemory(Order* orders, size_t size) {
	
	if (!orders)
		return;

	for (size_t i = 0; i < size; i++){
		delete[] orders[i].customer.name;
	}
	delete[] orders;
}

int main() {

	Order orders[2];
	orders[0] = initOrder(20.3, 0.1, "Yoana", 123445, 20);
	orders[1] = initOrder(80.9, 0.6, "Monika", 90098, 67);

	writeToFile("Orders.dat", orders, 2);

	size_t arrSize = 0;
	Order* ordersArr = nullptr;
	readFromFile("Orders.dat", ordersArr, arrSize);

	printOrders(ordersArr, arrSize);

	freeMemory(ordersArr, arrSize);
	return 0;
}