#include<fstream>
#include<exception>
#include<iomanip>
#include"ModifiableIntegerFunction.h"

void ModifiableIntegerFunction::copyFrom(const ModifiableIntegerFunction& other) {

	functionValues = new int16_t[FunctionConstants::TOTAL_VALUES];
	definedValues = new bool[FunctionConstants::TOTAL_VALUES];

	for (int value = FunctionConstants::MIN_VALUE; value <= FunctionConstants::MAX_VALUE; value++) {
		unsigned index = getIndex(value);
		functionValues[index] = other.functionValues[index];
		definedValues[index] = other.definedValues[index];
	}
}
void ModifiableIntegerFunction::free() {
	delete[] functionValues;
	delete[] definedValues;
}
unsigned ModifiableIntegerFunction::countExcludedPoints() const
{
	unsigned count = 0;
	for (size_t i = 0; i < FunctionConstants::TOTAL_VALUES; i++)
	{
		if (!definedValues[i]) {
			count++;
		}
	}
	return count;
}

ModifiableIntegerFunction::ModifiableIntegerFunction(int16_t(*f)(int16_t)) {

	if (!f) {
		throw std::invalid_argument("The function is invalid");
	}

	functionValues = new int16_t[FunctionConstants::TOTAL_VALUES];
	definedValues = new bool[FunctionConstants::TOTAL_VALUES];

	for (int value = FunctionConstants::MIN_VALUE; value <= FunctionConstants::MAX_VALUE; value++) {

		unsigned index = getIndex(value);
		functionValues[index] = f(value);
		definedValues[index] = true;
	}
}
ModifiableIntegerFunction::ModifiableIntegerFunction(const ModifiableIntegerFunction& other) {
	copyFrom(other);
}
ModifiableIntegerFunction& ModifiableIntegerFunction::operator=(const ModifiableIntegerFunction& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}
ModifiableIntegerFunction::~ModifiableIntegerFunction() {
	free();
}

bool ModifiableIntegerFunction::isPointDefined(int16_t input) const
{
	unsigned index = getIndex(input);
	if (index >= FunctionConstants::TOTAL_VALUES) {
		throw std::out_of_range("The index is out of range.");
	}

	return definedValues[index];
}
unsigned ModifiableIntegerFunction::getIndex(int16_t input) const {
	return input - FunctionConstants::MIN_VALUE;
}

int16_t ModifiableIntegerFunction::operator()(int16_t input) const {

	unsigned index = getIndex(input);
	if (!definedValues[index]) {
		throw std::exception("The function is not defined at this point.");
	}
	return functionValues[index];
}
void ModifiableIntegerFunction::removeValue(int16_t input) {

	unsigned index = getIndex(input);
	definedValues[index] = false;
}
void ModifiableIntegerFunction::includeValue(int16_t input) {

	unsigned index = getIndex(input);
	definedValues[index] = true;
}
void ModifiableIntegerFunction::setCustomValue(int16_t input, int16_t customOutput) {

	unsigned index = getIndex(input);
	functionValues[index] = customOutput;
}

bool ModifiableIntegerFunction::isInjection() const
{
	for (size_t i = 0; i < FunctionConstants::TOTAL_VALUES; i++)
	{
		for (size_t j = i + 1; j < FunctionConstants::TOTAL_VALUES; j++)
		{
			if (functionValues[i] == functionValues[j]) {
				return false;
			}
		}
	}
	return true;
}
bool ModifiableIntegerFunction::isSurjection() const
{
	for (size_t i = 0; i < FunctionConstants::TOTAL_VALUES; i++)
	{
		if (!definedValues[i]) {
			return false;
		}
	}
	return true;
}
bool ModifiableIntegerFunction::isBijection() const
{
	return isInjection() && isSurjection();
}

ModifiableIntegerFunction& ModifiableIntegerFunction::inverse() {

	if (!this->isBijection()) {
		throw std::exception("The function is not a bijection.");
	}

	ModifiableIntegerFunction inverseFunc(*this);

	for (size_t index = 0; index < FunctionConstants::TOTAL_VALUES; index++) {

		int y = functionValues[index];

		inverseFunc.setCustomValue(y, index + FunctionConstants::MIN_VALUE);
	}

	*this = inverseFunc;
	return *this;
}

ModifiableIntegerFunction& ModifiableIntegerFunction::operator+=(const ModifiableIntegerFunction& other)
{
	for (int value = FunctionConstants::MIN_VALUE; value <= FunctionConstants::MAX_VALUE; value++) {

		unsigned index = getIndex(value);;

		if (other.definedValues[index] && definedValues[index]) {
			int16_t newValue = (*this)(value) + other(value);
			setCustomValue(value, newValue);
		}
		else {
			removeValue(value);
		}
	}
	return *this;
}
ModifiableIntegerFunction& ModifiableIntegerFunction::operator-=(const ModifiableIntegerFunction& other)
{
	for (int value = FunctionConstants::MIN_VALUE; value <= FunctionConstants::MAX_VALUE; value++) {

		unsigned index = getIndex(value);

		if (other.definedValues[index] && definedValues[index]) {
			int16_t newValue = (*this)(value) - other(value);
			setCustomValue(value, newValue);
		}
		else {
			removeValue(value);
		}
	}
	return *this;
}
ModifiableIntegerFunction& ModifiableIntegerFunction:: operator^=(int k) {
	if (k == -1) {
		return inverse();
	}
	if (k == 1) {
		return *this;
	}

	for (size_t index = 0; index < FunctionConstants::TOTAL_VALUES; index++) {

		if (definedValues[index])
		{
			int16_t currentValue = functionValues[index];

			for (size_t times = 1; times < k; times++) {
				currentValue = functionValues[currentValue - FunctionConstants::MIN_VALUE];
			}
			functionValues[index] = currentValue;
		}
	}
	return *this;
}

void ModifiableIntegerFunction::drawFunction() const
{
	for (int y = GraphicConstants::MAX_COORDINATE; y >= GraphicConstants::MIN_COORDINATE; y--)
	{
		for (int x = GraphicConstants::MIN_COORDINATE; x <= GraphicConstants::MAX_COORDINATE; x++)
		{
			char symbolToPrint = GraphicConstants::EMPTY_CHAR;
			int16_t result = (*this)((int16_t)(x));

			if (x == 0 && y == 0)
			{
				if (result == y) {
					symbolToPrint = GraphicConstants::POINT_MARK;
				}
				else {
					symbolToPrint = GraphicConstants::ORDINATE_AXIS_CHAR;
				}
			}

			else if (x == 0) {
				symbolToPrint = GraphicConstants::ABCISSA_AXIS_CHAR;
			}

			else if (y == 0) {
				symbolToPrint = GraphicConstants::ORDINATE_AXIS_CHAR;
			}

			if (result == y) {
				symbolToPrint = GraphicConstants::POINT_MARK;
			}

			std::cout << symbolToPrint;
		}
		std::cout << std::endl;
	}
}

bool operator<(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs)
{
	if (lhs.countExcludedPoints() != rhs.countExcludedPoints()) {
		return lhs.countExcludedPoints() > rhs.countExcludedPoints();
	}

	for (int value = FunctionConstants::MIN_VALUE; value <= FunctionConstants::MAX_VALUE; value++)
	{
		int16_t value1 = lhs.isPointDefined(value) ? lhs(value) : FunctionConstants::MIN_VALUE;
		int16_t value2 = rhs.isPointDefined(value) ? rhs(value) : FunctionConstants::MIN_VALUE;

		if (value1 >= value2) {
			return false;
		}
	}
	return true;
}
bool operator>(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs)
{
	return rhs < lhs;
}
bool operator<=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs)
{
	return !(rhs < lhs);
}
bool operator>=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs)
{
	return !(lhs < rhs);
}
bool operator==(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs)
{
	if (lhs.countExcludedPoints() != rhs.countExcludedPoints()) {
		return false;
	}

	for (int value = FunctionConstants::MIN_VALUE; value <= FunctionConstants::MAX_VALUE; value++){
		int16_t value1 = lhs.isPointDefined(value) ? lhs(value) : FunctionConstants::MIN_VALUE;
		int16_t value2 = rhs.isPointDefined(value) ? rhs(value) : FunctionConstants::MIN_VALUE;

		if (value1 != value2){
			return false;
		}
	}
	return true;
}
bool operator!=(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs)
{
	return !(lhs == rhs);
}

void ModifiableIntegerFunction::serialize(const char* toFile) const {

	if (!toFile) {
		throw std::invalid_argument("Invalid filename");
	}

	std::ofstream ofs(toFile, std::ios::binary);

	if (!ofs.is_open()) {
		throw std::runtime_error("Cannot open file for writing.");
	}

	ofs.write((const char*)functionValues, FunctionConstants::TOTAL_VALUES * sizeof(int16_t));
	ofs.write((const char*)definedValues, FunctionConstants::TOTAL_VALUES * sizeof(bool));

	ofs.close();
}
void ModifiableIntegerFunction::deserialize(const char* fromFile) {

	if (!fromFile) {
		throw std::invalid_argument("Invalid filename");
	}

	std::ifstream ifs(fromFile, std::ios::binary);

	if (!ifs.is_open()) {
		throw std::runtime_error("Cannot open file for reading.");
	}

	delete[] functionValues;
	delete[] definedValues;

	functionValues = new int16_t[FunctionConstants::TOTAL_VALUES];
	definedValues = new bool[FunctionConstants::TOTAL_VALUES];

	ifs.read((char*)functionValues, FunctionConstants::TOTAL_VALUES * sizeof(int16_t));
	ifs.read((char*)definedValues, FunctionConstants::TOTAL_VALUES * sizeof(bool));

	ifs.close();
}

ModifiableIntegerFunction compose(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs) {

	ModifiableIntegerFunction composition(rhs);

	for (int value = FunctionConstants::MIN_VALUE; value <= FunctionConstants::MAX_VALUE; value++) {

		if (lhs.isPointDefined(value) && rhs.isPointDefined(lhs(value)))
		{
			int16_t result = lhs(composition(value));
			composition.setCustomValue(value, result);
		}
		else {
			composition.removeValue(value);
		}
	}
	return composition;
}

ModifiableIntegerFunction operator+(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs)
{
	ModifiableIntegerFunction result(lhs);
	result += rhs;
	return result;
}
ModifiableIntegerFunction operator-(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs)
{
	ModifiableIntegerFunction result(lhs);
	result -= rhs;
	return result;
}
ModifiableIntegerFunction operator^(const ModifiableIntegerFunction& func, int k)
{
	ModifiableIntegerFunction result(func);
	result ^= k;
	return result;
}

bool areParallel(const ModifiableIntegerFunction& lhs, const ModifiableIntegerFunction& rhs)
{
	bool isDiffCalculated = false;
	int initialDiff = 0;

	for (int value = FunctionConstants::MIN_VALUE; value <= FunctionConstants::MAX_VALUE; value++)
	{

		if (!lhs.isPointDefined(value) || !rhs.isPointDefined(value))
		{
			if ((!lhs.isPointDefined(value) && rhs.isPointDefined(value))|| (lhs.isPointDefined(value) && !rhs.isPointDefined(value)))
			{
				return false;
			}
			continue;
		}

		int currDiff = std::abs((lhs(value)) - (rhs(value)));

		if (!isDiffCalculated)
		{
			initialDiff = currDiff;
			isDiffCalculated = true;
		}

		else if (currDiff != initialDiff)
		{
			return false;
		}
	}
	return true;
}

int main() {

}