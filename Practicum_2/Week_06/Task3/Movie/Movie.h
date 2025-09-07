#pragma once

constexpr int TITLE_SIZE = 29;
constexpr int DIRECTOR_SIZE = 29;

class Movie {
	char _title[TITLE_SIZE + 1];
	char _director[DIRECTOR_SIZE + 1];
	int _movieLen;

public:

	Movie() = default;
	Movie(const char* title, const char* director, int movieLen);
	const char* getTitle() const;
	void setTitle(const char* title);
	const char* getDirector() const;
	void setDirector(const char* director);
	int getLength() const;
	void setMovieLen(int length);
};