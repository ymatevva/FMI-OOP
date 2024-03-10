#include<iostream>
#include<fstream>

struct Pair {

	unsigned int a;
	unsigned int b;
};

struct Relation {

	size_t count = 0;
	Pair pairs[25];
};

void readRelation(std::ifstream& ifs, Relation& relation) {

	while (!ifs.eof()) {
		ifs >> relation.pairs[relation.count].a >> relation.pairs[relation.count].b;
		relation.count++;
	}
}

void readFile(const char* fileName, Relation& relation) {
	
	if (!fileName)
		return;

	std::ifstream ifs(fileName);
	if (!ifs.is_open())
		return;

	readRelation(ifs, relation);

}

void addPair(const Pair& pair, Relation& relation) {
	
	if (relation.count + 1 > 25)
		std::cout << "Not enough space." << std::endl;

	relation.pairs[relation.count++] = pair;
}


void saveRelationToFile(const char* fileName,const Relation& relation) {
	
	if (!fileName)
		return;

	std::ofstream outputFile(fileName);

	if (!outputFile.is_open())
		return;

	for (size_t i = 0; i < relation.count; i++){
		outputFile << relation.pairs[i].a << " " << relation.pairs[i].b ;
		if (relation.count > i + 1)
			outputFile << std::endl;
	}

}


int main() {


	Relation relation = { 3, {{1,2},{3,4},{5,6}} };
	saveRelationToFile("Test.txt", relation);
	return 0;
}