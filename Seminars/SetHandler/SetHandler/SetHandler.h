#pragma once
#include"SetFactory.h"

class SetHandler
{
	SetExpression* expr;

	void copyFrom(const SetHandler& other);
	void moveFrom(SetHandler&& other);
	void free();
public:
	SetHandler(const char* str);
	SetHandler(const SetHandler& other);
	SetHandler(SetHandler&& other)noexcept;
	SetHandler& operator=(const SetHandler& other);
	SetHandler& operator=(SetHandler&& other)noexcept;
	~SetHandler();

	bool isElementIn(const SetInterpret& inter) const;
};

