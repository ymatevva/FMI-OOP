#include"Movie.h"
#include<iostream>

#pragma warning(disable:4996)
Movie::Movie(const char* title, const char* director, int movieLen) {
	setTitle(title);
	setDirector(director);
	setMovieLen(movieLen);
}

const char* Movie::getTitle() const {
	return _title;
}

const char* Movie::getDirector() const {
	return _director;
}

int Movie::getLength() const {
	return _movieLen;
}

void Movie::setTitle(const char* title) {
	if (!title || strlen(title) > TITLE_SIZE)
		return;
	strcpy(_title, title);
}

void Movie::setDirector(const char* director) {
	if (!director || strlen(director) > DIRECTOR_SIZE)
		return;
	strcpy(_director, director);
}

void Movie::setMovieLen(int movieLen) {
	if (movieLen < 0)
		return;
	_movieLen = movieLen;
}