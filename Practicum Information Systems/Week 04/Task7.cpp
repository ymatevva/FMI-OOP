#include<iostream>
#include<fstream>
//not fully completed task
enum class Toping {
	
	Undefined,
	Mustard,
	Ketchup,
	Mayonaise,
};


struct PizzaOrder {

	char pizzaName[30];
	Toping toping = Toping::Undefined;
	float price = 0;
};

struct OrderList {

	size_t numOrders = 0;
	PizzaOrder* pizzaOrders = nullptr;
};

size_t getFileSize(std::ifstream& ifs) {

	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);

	size_t size = ifs.tellg();
	ifs.seekg(currPos);
	ifs.clear();

	return size;
}

void writeOrders(std::ofstream& ofs, const OrderList& orderList) {
	ofs.write((const char*)orderList.pizzaOrders, sizeof(PizzaOrder) * orderList.numOrders);
}

void writeToFile(const char* toFile, const OrderList& orderList) {

	if (!toFile)
		return;

	std::ofstream ofs(toFile,std::ios::binary);
	if (!ofs.is_open())
		return;

	writeOrders(ofs, orderList);
}


void readOrders(std::ifstream& ifs, OrderList& orderList) {

	orderList.numOrders = getFileSize(ifs) / sizeof(PizzaOrder);
	orderList.pizzaOrders = new PizzaOrder[orderList.numOrders];
	ifs.read((char*)orderList.pizzaOrders, sizeof(PizzaOrder) * orderList.numOrders);
}

void readFile(const char* fromFile, OrderList& orderList) {
	if (!fromFile)
		return;

	std::ifstream ifs(fromFile,std::ios::binary);
	if (!ifs.is_open())
		return;

	readOrders(ifs, orderList);
}

void printToping(const Toping& toping) {

	switch (toping) {

	case Toping::Ketchup:
		std::cout << "Ketchup" << " "; break;

	case Toping::Mayonaise:
		std::cout << "Mayonaise" << " "; break;

	case Toping::Mustard:
		std::cout << "Mustard" << " "; break;

	case Toping::Undefined:
		std::cout << "Undefined" << " "; break;
	}
}
void printPizzaOrder(const PizzaOrder& pizzaOrder) {
	std::cout << pizzaOrder.pizzaName << " ";
	printToping(pizzaOrder.toping);
	std::cout << pizzaOrder.price <<std::endl;
}
void printOrderList(const OrderList& orderList) {
	for (size_t i = 0; i < orderList.numOrders; i++){
		printPizzaOrder(orderList.pizzaOrders[i]);
	}
}

int main() {

	/*
	PizzaOrder pizzaOrders[2] = {{"Margeritta", Toping::Mustard,12.5},{"QuattroFormaggi", Toping::Ketchup,9.7}};
	OrderList orderList = { 2,pizzaOrders };
	writeToFile("Orders.dat", orderList);
	*/
	OrderList orderList{};
	readFile("Orders.dat", orderList);
	
	printOrderList(orderList);

	delete[] orderList.pizzaOrders;
	return 0;
}