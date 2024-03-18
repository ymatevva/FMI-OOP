#include<iostream>
#include<fstream>
#pragma warning( disable : 4996)

enum class Size {
	Undefined,
	Small,
	Medium,
	Large
};

enum class Toping {
	Undefined,
	TomatoSauce,
	Pesto,
	Cheese
};

struct Pizza {

	char* name;
	Size size;
	Toping toping;
	bool isSpicy;

	/*Pizza(){
		name = nullptr;
		size = Size::Undefined;
		toping = Toping::Undefined;
		isSpicy = true;
	}*/
};

struct PizzaOrder {

	char* customerName;
	int quantity;
	float price;
	Pizza pizza;

	/*PizzaOrder() {
		customerName = nullptr;
		quantity = 0;
		price = 0;
	}*/
};


void writePizza(std::ofstream& ofs, const Pizza& pizza) {

	int nameLen = strlen(pizza.name);
	ofs.write((const char*)&nameLen, sizeof(nameLen));
	ofs.write(pizza.name, nameLen + 1);

	ofs.write((const char*)&pizza.size, sizeof(pizza.size));
	ofs.write((const char*)&pizza.toping, sizeof(pizza.toping));
	ofs.write((const char*)&pizza.isSpicy, sizeof(pizza.isSpicy));
}

void writePizzaOrder(std::ofstream& ofs, const PizzaOrder& pizzaOrder) {

	int nameLen = strlen(pizzaOrder.customerName);
	ofs.write((const char*)&nameLen, sizeof(nameLen));
	ofs.write(pizzaOrder.customerName, nameLen + 1);

	ofs.write((const char*)&pizzaOrder.quantity, sizeof(pizzaOrder.quantity));
	ofs.write((const char*)&pizzaOrder.price, sizeof(pizzaOrder.price));

	writePizza(ofs, pizzaOrder.pizza);
}

void writePizzaOrdersToFile(std::ofstream& ofs, const PizzaOrder* pizzaOrders, size_t numOrders) {

	if (!pizzaOrders)
		return;

	ofs.write((const char*)&numOrders, sizeof(numOrders));
	for (size_t i = 0; i < numOrders; i++) {
		writePizzaOrder(ofs, pizzaOrders[i]);
	}

}
void writeToFile(const char* toFile, const PizzaOrder* pizzaOrders, size_t numOrders) {
	if (!toFile)
		return;
	std::ofstream ofs(toFile, std::ios::binary);
	if (!ofs.is_open())
		return;
	writePizzaOrdersToFile(ofs, pizzaOrders, numOrders);
}


void readPizza(std::ifstream& ifs, Pizza& pizza) {

	int nameLen = 0;
	ifs.read((char*)&nameLen, sizeof(nameLen));
	pizza.name = new char[nameLen + 1];
	ifs.read(pizza.name, nameLen + 1);
	ifs.read((char*)&pizza.size, sizeof(pizza.size));
	ifs.read((char*)&pizza.toping, sizeof(pizza.toping));
	ifs.read((char*)&pizza.isSpicy, sizeof(pizza.isSpicy));
}

void readPizzaOrder(std::ifstream& ifs, PizzaOrder& pizzaOrder) {
	int nameLen = 0;
	ifs.read((char*)&nameLen, sizeof(nameLen));
	pizzaOrder.customerName = new char[nameLen + 1];
	ifs.read(pizzaOrder.customerName, nameLen + 1);

	ifs.read((char*)&pizzaOrder.quantity, sizeof(pizzaOrder.quantity));
	ifs.read((char*)&pizzaOrder.price, sizeof(pizzaOrder.price));

	readPizza(ifs, pizzaOrder.pizza);

}
void readPizzaOrdersFromFile(std::ifstream& ifs, PizzaOrder*& pizzaOrders, size_t& sizeArr) {

	ifs.read((char*)&sizeArr, sizeof(sizeArr));

	pizzaOrders = new PizzaOrder[sizeArr];
	for (size_t i = 0; i < sizeArr; i++) {
		readPizzaOrder(ifs, pizzaOrders[i]);
	}
}
void readFile(const char* fromFile, PizzaOrder*& pizzaOrders, size_t& sizeArr) {

	if (!fromFile)
		return;

	std::ifstream ifs(fromFile,std::ios::binary);
	if (!ifs.is_open())
		return;

	readPizzaOrdersFromFile(ifs, pizzaOrders, sizeArr);
}


void printPizza(const Pizza& pizza) {
	std::cout << pizza.name << " " << pizza.isSpicy << std::endl;
}
void printPizzaOrder(const PizzaOrder& pizzaOrder) {

	std::cout << pizzaOrder.customerName << " " << pizzaOrder.quantity << " " << pizzaOrder.price << " ";
	printPizza(pizzaOrder.pizza);
}
void printPizzaOrders(const PizzaOrder* pizzaOrders, size_t sizeArr) {

	if (!pizzaOrders)
		return;

	for (size_t i = 0; i < sizeArr; i++)
	{
		printPizzaOrder(pizzaOrders[i]);
	}
}
int main() {

	/*
	PizzaOrder pizzaOrders[2] = { {new char[6] {"Yoana"}, 10,12,{new char[11] {"Margherita"},Size::Large,Toping::Cheese,true}},
								{new char[7] {"Teodor"}, 7,13,{new char[20] {"Quatro Formaggi"},Size::Small,Toping::Pesto,false}} };

	writeToFile("PizzaOrders.dat", pizzaOrders, 2);

	*/
	PizzaOrder* res = nullptr;
	size_t sizeArr = 0;

	readFile("PizzaOrders.dat", res, sizeArr);
	printPizzaOrders(res, sizeArr);
	for (size_t i = 0; i < sizeArr; ++i) {
		delete[] res[i].customerName;
		delete[] res[i].pizza.name;
	}
	delete[] res;

	
	return 0;
}