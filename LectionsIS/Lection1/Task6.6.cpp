#include<iostream>


namespace Constants {
	constexpr int PLANET_NAME = 20;
	constexpr long int LIGHT_SPEED = 299792;
}

struct Planet {

	char name[Constants::PLANET_NAME];
	double distFromSun = 0;
	double diameter = 0;
	double mass = 0;
};

//a
void initPlanet(Planet& planet) {

	std::cin.getline(planet.name,Constants::PLANET_NAME);
	std::cin >> planet.distFromSun >> planet.diameter >> planet.mass;
	std::cin.ignore();
}

//b
void printPlanet(const Planet& planet) {

	std::cout << "Name: " << planet.name 
		<< " Distance from the Sun: " << planet.distFromSun 
		<< " Diameter: " << planet.diameter 
		<< " Mass: " << planet.mass << std::endl;
}	

//c
unsigned int secToThePlanet(const Planet& planet) {

	return planet.distFromSun / Constants::LIGHT_SPEED;
}

//d
void initPlanetArr(Planet* planets, size_t numPlanets) {
	for (size_t i = 0; i < numPlanets; i++){
		initPlanet(planets[i]);
	}
}

//e
void printPlanetArr(const Planet* planets, size_t numPlanets) {
	for (size_t i = 0; i < numPlanets; i++) {
		printPlanet(planets[i]);
	}
}

//f
unsigned getIndexOfMaxDiameter(const Planet* planets, size_t numPlanets) {

	if (!planets)
		return 0;

	int maxDiam = INT_MIN;
	unsigned int maxDiamInd = 0;

	for (size_t i = 0; i < numPlanets; i++) {

		if (planets[i].diameter > maxDiam) {
			maxDiam = planets[i].diameter;
			maxDiamInd = i;
		}
	}
	return maxDiamInd;
}

void printPlanetWithMaxDiam(const Planet* planets, size_t numPlanets) {

	if (!planets)
		return;

	unsigned int indMaxDiam = getIndexOfMaxDiameter(planets, numPlanets);

	for (size_t i = 0; i < numPlanets; i++){
		if (i == indMaxDiam)
			printPlanet(planets[i]);
	}
}

int main() {

	Planet p1;
	Planet p2;
	Planet p3;

	Planet planets[3] = { p1,p2,p3 };
	initPlanetArr(planets, 3);

	printPlanetArr(planets, 3);
	printPlanetWithMaxDiam(planets, 3);

	return 0;
}