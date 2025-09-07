#pragma once


class Cake {

	float _flourGrams;
	float _waterMl;
	float _sugarGrams;
	unsigned _currPiecesCount;
	unsigned _maxPiecesCount;

public:
	Cake();
	Cake(float flourGrams, float waterMl, float sugarGrams, unsigned currPiecesCount, unsigned maxPiecesCount);
	
	float getFlourGrams() const;
	float getWaterMl() const;
	float getSugarGrams() const;
	unsigned getCurrPiecesCount() const;
	unsigned getMaxPiecesCount() const;


	void setFlourGrams(float flourGrams);
	void setWaterMl(float waterMl);
	void setSugarGrams(float sugarGrams);
	void setCurrPiecesCount(unsigned currPiecesCount);
	void setMaxPiecesCount(unsigned maxPiecesCount);
	
	Cake& operator -=(int numberOfSlices);
	Cake& operator /=(int numberOfSlices);
	Cake& operator +=(int numberOfSlices);
};

Cake operator+(const Cake& lhs, int numOfPieces);
Cake operator-(const Cake& lhs, int numOfPieces);
Cake operator*(const Cake& lhs, int numOfPieces);
bool operator==(const Cake& lhs, const Cake& rhs);
bool operator!=(const Cake& lhs, const Cake& rhs);