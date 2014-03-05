#include <iostream>
#include "TemplateMethod.h"

void AbstractClass::TemplateMethod()
{
	PrimitiveOperation1();
	PrimitiveOperation2();
}

void ConcreateClass::PrimitiveOperation1()
{
	std::cout << "PrimitiveOperation1 by ConcreateClass\n";
}

void ConcreateClass::PrimitiveOperation2()
{
	std::cout << "PrimitiveOperation2 by ConcreateClass\n";
}
