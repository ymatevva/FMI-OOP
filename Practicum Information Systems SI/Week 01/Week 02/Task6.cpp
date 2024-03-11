#include<iostream>
#include<fstream>

namespace Constants {
	
	constexpr int CITY_NAME_SIZE = 64;
	constexpr int DISTRICT_SIZE = 20;
}

struct City {

	char cityName[Constants :: CITY_NAME_SIZE];
	unsigned int population = 0;
};

struct District {
	
	size_t citiesNum = 0;
	City cities[Constants :: DISTRICT_SIZE];
};

void readCity(std :: ifstream& ifs, City& city) {

	ifs.getline(city.cityName,Constants :: CITY_NAME_SIZE);
	ifs >> city.population;
	ifs.ignore();
}

void readDistrict(std :: ifstream & ifs, District& district) {

	int ind = 0;
	while (!ifs.eof()){
		readCity(ifs, district.cities[ind++]);
	}
	district.citiesNum = ind;
	
}

void readDistrictFromFile(const char* fileName, District& district) {

	if (!fileName)
		return;

	std::ifstream ifs(fileName);
	if (!ifs.is_open())
		return;

	readDistrict(ifs, district);
}



void printCity(std::ofstream& ofs, const City& city) {
	ofs << city.cityName << std::endl;
	ofs << city.population << std::endl;
}

void printDistrict(std::ofstream& ofs, const District& district) {

	for (size_t i = 0; i < district.citiesNum; i++) {
		
		printCity(ofs, district.cities[i]);

		if (i < district.citiesNum - 1)
			ofs << std :: endl;
	}
}

void printDistrictIntoFile(const char* fileName, const District& district) {

	if (!fileName)
		return;

	std::ofstream ofs(fileName);
	if (!ofs.is_open())
		return;

	printDistrict(ofs, district);

}

void sortTowns(District& district) {

	for (size_t i = 0; i < district.citiesNum - 1; i++) {

		int minElInd = i;
		for (size_t j = i + 1; j < district.citiesNum; j++) {

			if (district.cities[i].population > district.cities[j].population)
				minElInd = j;
		}

		if (minElInd != i) {
			std::swap(district.cities[i], district.cities[minElInd]);
		}
	}
}
int main() {

	District district{};
	readDistrictFromFile("Input.txt",district);
	sortTowns(district);
	printDistrictIntoFile("Output.txt",district);

	return 0;
}