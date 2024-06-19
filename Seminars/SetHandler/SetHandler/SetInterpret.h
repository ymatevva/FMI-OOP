#pragma once
#include<cassert>

class SetInterpret
{
protected:
	bool values[26] = {false};
public:
	
	bool getValue(char ch) const; 

	void setValue(char ch, bool value);
	
};

