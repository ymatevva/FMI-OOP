#pragma once
#include<iostream>

//Worked together with Aneliya Kandilarova SE 1th course 4th group and Monika Angelova SE 2nd course 4th group

namespace FunctionConstants {
	constexpr int TOTAL_VALUES = 65536;
	constexpr int MIN_VALUE = -32768;
	constexpr int MAX_VALUE = 32767;
}

namespace GraphicConstants {
	constexpr int  MAX_COORDINATE = 10;
	constexpr int  MIN_COORDINATE = -10;
	constexpr char POINT_MARK = '*';
	constexpr char EMPTY_CHAR = ' ';
	constexpr char ABCISSA_AXIS_CHAR = '|';
	constexpr char ORDINATE_AXIS_CHAR = '-';
}

class ModifiableIntegerFunction {

	int16_t* functionValues = nullptr;
	bool* definedValues = nullptr;
	// Dynamic allocation is used for the arrays to prevent stack overflow. 
	// Static allocation of large arrays directly in the objects exceeds the stack's capacity.

	void copyFrom(const ModifiableIntegerFunction& other);
	void free();
	unsigned countExcludedPoints() const;

public:
	ModifiableIntegerFunction() = default;
	ModifiableIntegerFunction(int16_t(*f)(int16_t));
	ModifiableIntegerFunction(const ModifiableIntegerFunction& other);
	ModifiableIntegerFunction& operator=(const ModifiableIntegerFunction& other);
	~ModifiableIntegerFunction();

	bool isPointDefined(int16_t input) const;
	unsigned getIndex(int16_t input) const;

	int16_t operator()(int16_t x) const;
	void removeValue(int16_t input);
	void includeValue(int16_t input);
	void setCustomValue(int16_t input, int16_t customOutput);

	bool isInjection() const;
	bool isSurjection() const;
	bool isBijection() const;

	ModifiableIntegerFunction& inverse();

	ModifiableIntegerFunction& operator+=(const ModifiableIntegerFunction& other);
	ModifiableIntegerFunction& operator-=(const ModifiableIntegerFunction& other);
	ModifiableIntegerFunction& operator^=(int k);

	void serialize(const char* filename) const;
	void deserialize(const char* filename);

	void drawFunction() const;

	friend bool  operator<(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
	friend bool  operator<=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
	friend bool  operator>(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
	friend bool  operator>=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
	friend bool  operator==(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
	friend bool  operator!=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
};

ModifiableIntegerFunction compose(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);

ModifiableIntegerFunction operator+(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
ModifiableIntegerFunction operator-(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);
ModifiableIntegerFunction operator^(const ModifiableIntegerFunction& func, int k);

bool areParallel(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs);