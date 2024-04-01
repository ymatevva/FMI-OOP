#include<iostream>
#include"Car.h"

#pragma warning(disable:4996)
using namespace Constants;

void Car::copyFrom(const Car& other) {
	setCarBrand(other._carBrand);
	setCarModel(other._carModel);
	setRegNumber(other._regNumber);
	setFuelConsumption(other._fuelConsumption);
	setEngine(other._engine);
	setWheel(other._wheel);
	setDrivetrain(other._drivetrain);
	setAcceleration(other._acceleration);
	setTopSpeed(other._topSpeed);
	setHandling(other._handling);
}


Car::Car(const char* carBrand, const char* carModel, const int* regNumber, const float* fuelConsumption,  Engine& engine, Wheel* wheel, Drivetrain drivetrain, int acceleration, int topSpeed, int handling) {
	setCarBrand(carBrand);
	setCarModel(carModel);
	setRegNumber(regNumber);
	setFuelConsumption(fuelConsumption);
	setEngine(engine);
	setWheel(wheel);
	setDrivetrain(drivetrain);
	setAcceleration(acceleration);
	setTopSpeed(topSpeed);
	setHandling(handling);
}

Car::Car(const Car& other) {
	copyFrom(other);
}

Car& Car::operator=(const Car& other) {
	if (this != &other) {
		copyFrom(other);
	}
	return *this;
}

const char* Car::getCarBrand() const{
	return _carBrand;
}

const char* Car::getCarModel() const {
	return _carModel;
}

const int* Car::getRegNumber() const {
	return _regNumber;
}

const float* Car::getFuelConsumption() const {
	return _fuelConsumption;
}


void Car::setCarBrand(const char* carBrand) {
	if (!carBrand || strlen(carBrand) > CAR_BRAND_LEN)
		strcpy(_carBrand, "unknown");
	else
		strcpy(_carBrand, carBrand);
}


void Car::setCarModel(const char* carModel) {
	if (!carModel || strlen(carModel) > CAR_MODEL_LEN)
		strcpy(_carModel, "unknown");
	else
		strcpy(_carModel, carModel);
}

void Car::setRegNumber(const int* regNumber) {
	if (!regNumber)
		return;
	for (size_t i = 0; i < REG_NUM_SIZE; i++){
		_regNumber[i] = regNumber[i];
	}
}
void Car::setFuelConsumption(const float* fuelConsumption) {
	if (!fuelConsumption || (fuelConsumption[0] < 0 || fuelConsumption[1] <0 || fuelConsumption[2] < 0))
		return;

	for (size_t i = 0; i < 3; i++){
		_fuelConsumption[i] = fuelConsumption[i];
	}
}

bool Car::isFuelEfficient(const Car& car) const {

	float avgFuelConsumption = (_fuelConsumption[0] + _fuelConsumption[1] + _fuelConsumption[2])/3;
	return avgFuelConsumption <= 6 ;
}

float Car::fuelEfficiency(const Car& other) const {
	if (!isFuelEfficient(other))
		return -1;

	float avgFuelConsumption = (other._fuelConsumption[0] + other._fuelConsumption[1] + other._fuelConsumption[2]) / 3;
	return avgFuelConsumption;
}


bool Car:: isMoreFuelEfficient(const Car& other) const {
	return abs(fuelEfficiency(*this) - fuelEfficiency(other)) <= 0.0001;
}



void Car::setEngine(const Engine& engine){
	_engine = engine;
}

void Car::setWheel(Wheel* wheel){
	_wheel = wheel;
}

const Engine& Car::getEngine() const{
	return _engine;
}

const Wheel& Car::getWheel() const{
	if (!_wheel){
		return {};
	}
	return *_wheel;
}



Drivetrain Car::getDrivetrain() const
{
	return _drivetrain;
}

void Car::setDrivetrain(Drivetrain drivetrain)
{
	_drivetrain = drivetrain;
}

int Car::getAcceleration() const
{
	return _acceleration;
}

void Car::setAcceleration(int acceleration){
	if (acceleration < 0 || acceleration > 100){
		return;
	}
	_acceleration = acceleration;
}

int Car::getTopSpeed() const
{
	return _topSpeed;
}

void Car::setTopSpeed(int topSpeed){
	if (topSpeed < 0 || topSpeed > 100){
		return;
	}
	_topSpeed = topSpeed;
}

int Car::getHandling() const{
	return _handling;
}

void Car::setHandling(int handling){
	if (handling < 0 || handling > 100){
		return;
	}
	_handling = handling;
}

void Car::print() const
{
	std::cout << _carBrand << "  " << _carModel << " ";
	std::cout<< _regNumber[0] << _regNumber[1] << _regNumber[2] << " " << _fuelConsumption[0] << _fuelConsumption[1] << _fuelConsumption[2] << " " << (int)_drivetrain << " " << _acceleration << " " << _topSpeed << " " << _handling;
}
int main() {

	Engine engine(4, 2000, "V4");
	// Create a Wheel object
	Wheel wheel(18, Material::Aluminium);
	int regNumber[3] = { 1, 2, 3 };//not 8 symbols like in the pdf
	float fuelConsumption[3] = { 8.5, 7.8, 9.2 };
	
	Car car1("Toyota", "Camry", regNumber, fuelConsumption, engine, &wheel, Drivetrain::FrontWheel, 80, 180, 70);

	std::cout << "Car Brand: " << car1.getCarBrand() << std::endl;
	std::cout << "Car Model: " << car1.getCarModel() << std::endl;
	const int* regNumber1 = car1.getRegNumber();
	std::cout << "Registration Number: " << regNumber[0] << regNumber[1] << regNumber[2] << std::endl;
	const float* fuelConsumption1 = car1.getFuelConsumption();
	std::cout << "Fuel Consumption (City, Highway, Combined): " << fuelConsumption[0] << ", " << fuelConsumption[1] << ", " << fuelConsumption[2] << std::endl;
	std::cout << "Drivetrain: " << static_cast<int>(car1.getDrivetrain()) << std::endl;//do not have print func for Drivetrain
	std::cout << "Acceleration: " << car1.getAcceleration() << std::endl;
	std::cout << "Top Speed: " << car1.getTopSpeed() << std::endl;
	std::cout << "Handling: " << car1.getHandling() << std::endl;

	
	if (car1.isFuelEfficient(car1))
		std::cout << "Car is fuel efficient." << std::endl;
	else
		std::cout << "Car is not fuel efficient." << std::endl;

	
	car1.print();

	return 0;
} 

