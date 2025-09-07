#pragma once
#include "Engine.h"
#include"Wheel.h"

namespace Constants {
	constexpr int REG_NUM_SIZE= 8;
	constexpr int CAR_BRAND_LEN = 19;
	constexpr int CAR_MODEL_LEN = 19;
	constexpr int FUEL_SIZE = 3;
}

enum class Drivetrain {
	FrontWheel,
	BackWheel,
	FourXFour
};

class Car {

	char _carBrand[Constants::CAR_BRAND_LEN];
	char _carModel[Constants::CAR_MODEL_LEN];
	int _regNumber[Constants::REG_NUM_SIZE]{ 0 };
	float _fuelConsumption[Constants::FUEL_SIZE]{ 0 };
	Drivetrain _drivetrain;
	int _acceleration;
	int _topSpeed;
	int _handling;


    Engine _engine;
	Wheel* _wheel = nullptr;

	void copyFrom(const Car& other);

public:

	Car() = default;
	Car(const char* carBrand, const char* carModel, const int* regNumber, const float* fuelConsumption, Engine & engine, Wheel* wheel,Drivetrain drivetrain, int acceleration,int topSpeed,int handling);
	Car(const Car& other);
	Car& operator=(const Car& other);

	void setCarBrand(const char* carBrand);
	void setCarModel(const char* carBrand);
	void setRegNumber(const int* regNumber);
	void setFuelConsumption(const float* fuelCosumption);
	void setDrivetrain(Drivetrain drivetrain);
	void setAcceleration(int acceleration);
	void setTopSpeed(int topSpeed);
	void setHandling(int handling);

	const char* getCarBrand() const;
	const char* getCarModel() const;
	const int* getRegNumber() const;
	const float* getFuelConsumption() const;
	Drivetrain getDrivetrain() const;
	int getAcceleration() const;
	int getTopSpeed() const;
	int getHandling() const;

	const Engine& getEngine() const;//?
	void setEngine(const Engine& engine);//?

	const Wheel& getWheel() const;//?
	void setWheel(Wheel* wheel);//?

	bool isFuelEfficient(const Car& car) const;
	float fuelEfficiency(const Car& car) const;

    bool isMoreFuelEfficient(const Car& other)const;

	void print() const;
	
};