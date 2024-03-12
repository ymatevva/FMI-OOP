#include<iostream>
#include<fstream>

constexpr int NAME_SIZE = 64;

struct Person {
	char name[NAME_SIZE];
	bool gender;
	unsigned years = 0;
};


void readPerson(Person& person) {

	std::cin.ignore();
	std::cin.getline(person.name,NAME_SIZE);
	std::cin >> person.gender;
	std::cin >> person.years;

}

void personToFile(std::ofstream& ofs, const Person& person) {

	ofs << person.name << " ";
	ofs << person.gender << " ";
	ofs << person.years << " ";
}

void addToFile(const char* toFile, const Person* people,size_t numPeople) {

	if (!toFile)
		return;

	std::ofstream ofs(toFile);
	if (!ofs.is_open())
		return;

	for (size_t i = 0; i < numPeople; i++){
		
		personToFile(ofs, people[i]);
		if (numPeople >= i + 1)
			ofs << std ::endl;
	}

}
int main() {

	unsigned numPeople = 0;
	std::cin >> numPeople;

	Person* people = new Person[numPeople];

	for (size_t i = 0; i < numPeople; i++){
		readPerson(people[i]);
	}

	addToFile("Test.txt", people, numPeople);

	return 0;
}