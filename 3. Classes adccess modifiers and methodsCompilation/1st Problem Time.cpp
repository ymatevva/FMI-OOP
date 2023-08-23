#include<iostream>
#include <cassert>
class Timestamp
{
private:

    const int SECONDS_IN_HOUR = 3600;
    const int SECONDS_IN_MINUTE = 60;
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;

    void prettyPrint(unsigned int timeToPrint) const
    {
        if (timeToPrint < 10)
        {
            std :: cout << "0";
        }
        std :: cout << timeToPrint;
    }

public:

    void setFromSeconds(const unsigned int seconds)
    {
        this -> hours = seconds / this -> SECONDS_IN_HOUR;
        int secondsLeft = seconds % this -> SECONDS_IN_HOUR;
        this -> minutes = secondsLeft / this -> SECONDS_IN_MINUTE;
        this -> seconds = secondsLeft % this -> SECONDS_IN_MINUTE;
    }

    void print() const
    {
        this -> prettyPrint(this -> hours);
        std::cout << ":";
        this -> prettyPrint(this -> minutes);
        std::cout << ":";
        this -> prettyPrint(this -> seconds);
        std::cout << '\n';
    }

    void add(const Timestamp &other)
    {
        unsigned int seconds_in_first = this -> toSeconds();
        unsigned int second_in_second = other.toSeconds();

        this->setFromSeconds(seconds_in_first + second_in_second);
    }

    unsigned int toSeconds() const
    {
        return this -> hours * this -> SECONDS_IN_HOUR + this -> minutes * this -> SECONDS_IN_MINUTE + this -> seconds;
    }
};

int main()
{

   Timestamp t1, t2;
   t1.setFromSeconds(420);
   t2.setFromSeconds(69);
   t1.print();
   t2.print();
   t1.add(t2);
   assert(t1.toSeconds() == 489);//if the result of the adding is not 489 the program will give a signal

    return 0;
}