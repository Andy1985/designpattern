#include "Factory.h"

#include <iostream>

ConcreateProduct::ConcreateProduct()
{
	std::cout << "construction of ConcreateProduct\n";
}

ConcreateProduct::~ConcreateProduct()
{
	std::cout << "destruction of ConcreateProduct\n";
}

void Creator::AnOperation()
{
	Product* p = FactoryMethod();
	std::cout << "an operation of product\n";
}

ConcreateCreator::ConcreateCreator()
{
	std::cout << "construction of ConcreateCreator\n";
}

ConcreateCreator::~ConcreateCreator()
{
	std::cout << "destruction of ConcreateCreator\n";
}

Product* ConcreateCreator::FactoryMethod()
{
	return new ConcreateProduct(); //wise poiter
}
