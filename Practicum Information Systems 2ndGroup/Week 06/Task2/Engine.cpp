#include<iostream>
#include"Engine.h"

#pragma warning(disable:4996)
void Engine::copyFrom(const Engine& other) {
	setHorsePower(other._horsePower);
	setDisplacement(other._displacement);
	setVIN(other._VIN);
}

Engine::Engine( int horsePower, int displacement, const char* VIN ) {
	setHorsePower(horsePower);
	setDisplacement(displacement);
	setVIN(VIN);
}

Engine::Engine(const Engine& other) {
	copyFrom(other);
}

/* we do not write this func bc we can not put the same engine in two cars
Engine& Engine::operator=(const Engine& other) {
	if (this != &other) {
		copyFrom(other);
	}
	return *this;
}
*/
void Engine::setHorsePower(int horsePower) {
	if (horsePower < 0)
		return;
	_horsePower = horsePower;
}

void Engine::setDisplacement(int displacement) {
	if (displacement < 0)
		return;
	_displacement = displacement;
}

void Engine::setVIN(const char* VIN) {
	if (!VIN || strlen(VIN) != VIN_SIZE)
		return;
	strcpy(_VIN, VIN);
}

const char* Engine::getVIN() const {
	return _VIN;
}

int Engine::getDisplacement()const {
	return  _displacement;
}

int Engine::getHorsePower() const {
	
	return _displacement;
}
