#include<iostream>
#include<fstream>
#include<cstring>

constexpr int NAME_SIZE = 64;

enum typeOfTire {
	Soft,
	Medium,
	Hard,
	Intern,
	Wet,
	Unknown
};

typeOfTire readTire(const char* type){

	if (strcmp(type, "soft") == 0)
		return typeOfTire::Soft;
	else if (strcmp(type, "medium") == 0)
		return typeOfTire::Medium;
	else if (strcmp(type, "hard") == 0)
		return typeOfTire::Hard;
	else if (strcmp(type, "intern") == 0)
		return typeOfTire::Intern;
	else if (strcmp(type, "wet") == 0)
		return typeOfTire::Wet;
	else
		return typeOfTire::Unknown;

}
struct Bolide {
    
	bool isBroken;
	char name[NAME_SIZE];
	int year;
	typeOfTire type;
	int maxLap;
	double coef;
};

unsigned setMaxLap(const typeOfTire& type) {
	
	if (type == typeOfTire::Soft)
		return 45;
	else if (type == typeOfTire::Medium)
		return 50;
	else if (type == typeOfTire::Hard)
		return 60;
	else if (type == typeOfTire::Intern)
		return 40;
	else if (type == typeOfTire::Wet)
		return 35;
	else
		return 0;

}

double maxNumLaps(const Bolide& bol) {
	return bol.maxLap * bol.coef;
}


Bolide readBolide() {

	Bolide bol;

	std::cin >> bol.isBroken;
	std::cin.getline(bol.name, NAME_SIZE);
	std::cin >> bol.year;

	char tyre[16];
	std::cin >> tyre;
	bol.type = readTire(tyre);

	bol.maxLap = setMaxLap(bol.type);
	std::cin >> bol.coef;

	return bol;
}


void printBolide(const Bolide& bol) {

	std::cout << bol.name << std::endl;
	std::cout << bol.year << std::endl;
	std::cout << bol.type << std::endl;
	std::cout <<  bol.coef << std::endl;
	std::cout << bol.isBroken << std::endl;
	std::cout << bol.maxLap << std::endl;
}


void sortBolides(const Bolide* bolArr, size_t N) {


	for (size_t i = 0; i < N-1; i++)
	{
		int minElInd = i;
		for (size_t j = i + 1; j < N; j++) {
			if (bolArr[j].year < bolArr[minElInd].year)
				minElInd = j;
		}
		if (i != minElInd)
			std::swap(bolArr[minElInd], bolArr[i]);
	}
}
int main()
{
	unsigned N;
	std::cin >> N;

	Bolide* bolArr = new Bolide[N];

	for (size_t i = 0; i < N; i++){
		bolArr[i] = readBolide();
	}

	sortBolides(bolArr, N);

	for (size_t i = 0; i < N; i++)	{
		printBolide(bolArr[i]);
	}
}