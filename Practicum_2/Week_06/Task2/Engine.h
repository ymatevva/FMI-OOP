#pragma once

constexpr int VIN_SIZE = 16;

class Engine {

	int _horsePower;
	int _displacement;
	char _VIN[VIN_SIZE + 1];

	void copyFrom(const Engine& other);
public:

	 Engine() = default;
	 Engine(int horsePower, int displacement, const char* VIN);
	 Engine(const Engine& other);
	// Engine& operator=(const Engine& other);

	 void setHorsePower(int horsePower);
	 void setDisplacement(int displacement);
	 void setVIN(const char* VIN);

	 int getHorsePower() const;
	 int getDisplacement() const;
	 const char* getVIN() const;



};