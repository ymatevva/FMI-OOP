#include<iostream>
#include<fstream>
#include<iomanip>

constexpr int SECONDS_IN_HOUR = 3600;
constexpr int SECONDS_IN_MINUTE = 60;
constexpr int SECONDS_IN_DAY = 3600 * 24;

class Time {


private:

	unsigned secondsFromMidnight;

	bool isValidTime(unsigned lowerBound, unsigned upperBound, unsigned oldValue, unsigned newValue, unsigned multiplier) {

		if (newValue >= lowerBound && newValue <= upperBound) {

			(secondsFromMidnight -= (oldValue * multiplier)) += (newValue * multiplier);
			return true;
		}
		return false;
	}



public:

	Time() :secondsFromMidnight(0) {

	}

	Time(unsigned hours, unsigned minutes, unsigned seconds) {

		setHours(hours);
		setMinutes(minutes);
		setSeconds(seconds);
	}

	unsigned getHours()const {
		return secondsFromMidnight / SECONDS_IN_HOUR;
	}

	unsigned getMinutes()const {
		return (secondsFromMidnight / SECONDS_IN_MINUTE) % SECONDS_IN_MINUTE;
	}

	unsigned getSeconds()const {
		return secondsFromMidnight % 60;
	}

	bool setHours(unsigned hours) {
		return isValidTime(0, 23,getHours() ,hours,  SECONDS_IN_HOUR);
	}

	bool setMinutes(unsigned minutes) {
		return isValidTime(0, 59, getMinutes(),minutes , SECONDS_IN_MINUTE);
	}

	bool setSeconds(unsigned seconds) {
		return isValidTime(0, 59,  getSeconds(),seconds, 1);
	}

	void addOneSec() {
		++secondsFromMidnight %= SECONDS_IN_DAY;
	}

	void serialize(std::ostream& os) const
	{
		os << std::setw(2) << std::setfill('0') << getHours() << ":"
			<< std::setw(2) << std::setfill('0') << getMinutes() << ":"
			<< std::setw(2) << std::setfill('0') << getSeconds() << std::endl;

	}
};

int main() {


	Time t{ 11,38,33 };

	t.setMinutes(44);
	t.setSeconds(01);

	t.serialize(std::cout);
	t.addOneSec();
	t.serialize(std::cout);
	
	return 0;
}