#include "SetFactory.h"

static bool isValidOp(char ch) 
{
	return ch == '^' || ch == 'v' || ch == '!' || ch == 'x' || ch == '\\';
}

SetExpression* setFactory(StringView str)
{
	if (str.getLen() == 1) {
		return new Singleton(str[0]);
	}

	str = str.substr( 1, str.getLen() - 2);


	unsigned count = 0;
	for (size_t i = 0; i < str.getLen(); i++){
	
		if (str[i] == '('){ 
			count++; 
		}
		else if (str[i] == ')'){ 
			count--;
		}
		else if (count == 0 && isValidOp(str[i])) {
			switch (str[i]){
			case 'v': return new Union(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, str.getLen() - i - 1)));
			case '^': return new Intersection(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, str.getLen() - i - 1)));
			case '\\': return new Difference(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, str.getLen() - i - 1)));
			case 'x': return new XOR(setFactory(str.substr(0, i)), setFactory(str.substr(i + 1, str.getLen() - i - 1)));
			case '!': return new Addition(setFactory(str.substr(i + 1, str.getLen() - i - 1)));
			}
		}
	}
}
