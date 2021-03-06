#include "pch.h"
#include <iostream>
#include "Comp.h"
#include "Comp.hpp"
int Comp<double>::count = 0;

Comp<double> Fun1(Comp<double> c1, Comp<double> c2)
{
	std::cout << "Fun1" << std::endl;
	Comp<double> c3 = c1 + c2;
	return c3;
}

Comp<double> Fun2(Comp<double> &c1, Comp<double> &c2)
{
	Comp<double> c3 = c1 + c2;
	return c3;
}

Comp<double> Fun3(Comp<double> *c1, Comp<double> *c2)
{
	Comp<double> c3 = *c1 + *c2;
	return c3;
}

int main()
{
	Comp<double> c1(5, -2), c2(1, 6), c3;
	c2 = Fun1(c1, c2);
	std::cout << "c1=" << c1 << std::endl;
	std::cout << "enter c3: " << std::endl;
	std::cin >> c3;
	std::cout << "c3=" << c3 << std::endl;
	return 0;
}
