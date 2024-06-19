#include"SetHandler.h"
#include<iostream>

int main() {

	SetHandler s("(((A^B)vC)vX)");

	SetInterpret el;
	el.setValue('A', true);
	el.setValue('B', false);
	el.setValue('C', false);

	std::cout << s.isElementIn(el);

	return 0;
}