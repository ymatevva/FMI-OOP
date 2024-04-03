#pragma once
#include"Movie.h"

constexpr int  DATE_LEN = 14;
constexpr int HALL_NAME_LEN = 19;

class Projection {
	char _date[DATE_LEN + 1];
	char _hallName[HALL_NAME_LEN + 1];
	Movie _movie;

public:

	Projection() = default;
	Projection(const char* date, const char* hallName,const Movie& movie);

	void setMovie(const Movie& movie);

	void setDate(const char* date);
	void setHallName(const char* hallName);
	void setMovie(Movie movie);

	const char* getDate() const;
	const char* getHallName() const;
	const Movie& getMovie() const;

};