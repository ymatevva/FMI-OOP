#pragma once
#include "PartialFunctionFromFile.h"


class UserInterface
{
	PartialFunctionFromFile partialFunctionFromFile;
	int a = 0;
	int b = 0;

public:
	UserInterface();
	void interval()const;
	void generatingAllElements()const;
};