#include<iostream>
#include<fstream>

constexpr int NAME_SIZE = 64;

struct Person {
	char name[NAME_SIZE];
	bool gender;
	unsigned years = 0;
};


void readPersonFromFile(std::ifstream& ifs, Person& person) {

	ifs >> person.name;
	ifs >> person.gender;
	ifs >> person.years;

}

void readPeople(std::ifstream& ifs, Person* people) {
	int index = 0;
	while (!ifs.eof()) {
		readPersonFromFile(ifs, people[index++]);
	}
}


void readPeopleFromFile(const char* fromFile, Person* people) {

	if (!fromFile)
		return;

	std::ifstream ifs(fromFile);
	if (!ifs.is_open())
		return;

	readPeople(ifs, people);
}


void personToFile(std::ofstream& ofs, const Person& person) {

	ofs << person.name << " ";
	ofs << person.gender << " ";
	ofs << person.years;
}

void peopleToFile(std::ofstream& ofs, const Person* people, size_t personSize) {

	for (size_t i = 0; i < personSize; i++) {
		personToFile(ofs, people[i]);
		if (i < personSize - 1)
			ofs << std::endl;
	}
}

void addToFile(const char* toFile, const Person* people, size_t numPeople) {

	if (!toFile)
		return;

	std::ofstream ofs(toFile);
	if (!ofs.is_open())
		return;

	peopleToFile(ofs, people, numPeople);
}

unsigned int countSymbols(std::ifstream& ifs, char ch) {

	unsigned int count = 0;
	while (!ifs.eof()) {

		char currCh = ifs.get();
		if (currCh == ch)
			count++;
	}
	return count;
}

unsigned int countNewLines(const char* fileName) {

	if (!fileName)
		return 0;

	std::ifstream ifs(fileName);
	return countSymbols(ifs, '\n') + 1;
}

int main() {

	size_t numPeople = countNewLines("people.txt");
	Person* people = new Person[numPeople];

	readPeopleFromFile("people.txt", people);
	addToFile("outputPeople.txt", people, numPeople);

	return 0;
}