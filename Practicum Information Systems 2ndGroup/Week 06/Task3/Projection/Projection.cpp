#include<iostream>
#include"Projection.h"
#pragma warning(disable:4996)

Projection::Projection(const char* date, const char* hallName,const Movie& movie) : _movie(movie){
	setDate(date);
	setHallName(hallName);
}

void Projection::setMovie(const Movie& movie){
	_movie = movie;
}

void Projection::setDate(const char* date) {
	if (!date || strlen(date) != 14)
		return;
	strcpy(_date, date);
}

void Projection::setHallName(const char* hallName) {
	if (!hallName || strlen(hallName) > HALL_NAME_LEN)
		return;
	strcpy(_hallName, hallName);
}

const char* Projection::getDate() const{
	return _date;
}

const char* Projection::getHallName() const{
	return _hallName;
}

const Movie& Projection::getMovie() const{
	return _movie;
}
