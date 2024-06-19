#include "SetInterpret.h"

bool SetInterpret::getValue(char ch)const
{
	assert(ch >= 'A' && ch <= 'Z');
	return values[ch - 'A'];
}

void SetInterpret::setValue(char ch, bool value)
{
	assert(ch >= 'A' && ch <= 'Z');
	values[ch - 'A'] = value;
}