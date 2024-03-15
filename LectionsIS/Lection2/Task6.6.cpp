#include<iostream>
#include<fstream>

#pragma warning (disable: 4996)
namespace Constants {
	constexpr int PLANET_NAME = 20;
	constexpr long int LIGHT_SPEED = 299792;
}

//getFileSize
unsigned int getSymbolCount(std::ifstream& ifs, char ch) {

	unsigned count = 0;

	while (true) {

		char currCh = ifs.get();
		if (ifs.eof())
			break;

		if (currCh == ch)
			count++;
	}
	return count;
}

unsigned getLinesCount(std::ifstream& ifs){
	return getSymbolCount(ifs, '\n') + 1;
}

struct Planet {

	char name[Constants::PLANET_NAME];
	double distFromSun = 0;
	double diameter = 0;
	double mass = 0;
};


//writePlanetsToFile

void writePlanetToFile(std::ofstream& ofs, const Planet& planet) {

	ofs <<  planet.name << " " << planet.distFromSun <<" "<< planet.diameter << " "
		<< planet.mass << std::endl;
}

void writePlanetArrToFile(std::ofstream& ofs, const Planet* planets, size_t numPlanets) {

	if (!planets)
		return;

	//ofs << numPlanets << std::endl;
	for (size_t i = 0; i < numPlanets; i++){
		writePlanetToFile(ofs,planets[i]);
	}
}
void writetoFile(const char* toFile,const Planet* planets, size_t numPlanets) {

	if (!toFile || !planets)
		return;

	std::ofstream ofs(toFile);
	if (!ofs.is_open())
		return;

	writePlanetArrToFile(ofs, planets, numPlanets);
}

//readPlanetsFromFile
Planet readPlanetFromFile(std::ifstream& ifs) {

	Planet planet{};

	char nameBuff[Constants::PLANET_NAME];
	ifs >> nameBuff;
	strcpy( planet.name,nameBuff);

	ifs>>planet.distFromSun >> planet.diameter >> planet.mass;
	ifs.ignore();

	return planet;
}
Planet* readPlanetArrFromFile(const char* fromFile, size_t& size) {

	if (!fromFile)
		return nullptr;

	std::ifstream ifs(fromFile);
	if (!ifs.is_open())
		return nullptr;

	size = getLinesCount(ifs)-1;
	ifs.clear();
	ifs.seekg(0);

	Planet* planetsArr = new Planet[size];

	for (size_t i = 0; i < size; i++) {
		planetsArr[i] = readPlanetFromFile(ifs);
	}

	return planetsArr;
}


void printPlanet(const Planet& planet) {

	std::cout << "Name: " << planet.name
		<< " Distance from the Sun: " << planet.distFromSun
		<< " Diameter: " << planet.diameter
		<< " Mass: " << planet.mass << std::endl;
}

void printPlanetArr(const Planet* planets, size_t numPlanets) {
	for (size_t i = 0; i < numPlanets; i++) {
		printPlanet(planets[i]);
	}
}

int main() {

	Planet p1 = { "Moon",100,23,4.5 };
	Planet p2 = { "Mercury",90,6,8.9 };
	Planet p3 = { "Venus",95,15,10.8 };

	Planet planets[3] = { p1,p2,p2 };
	writetoFile("planets.txt", planets, 3);
	
	size_t size = 0;
	Planet* result = readPlanetArrFromFile("planets.txt", size);
	printPlanetArr(result, size);


	delete[] result;
	return 0;
}