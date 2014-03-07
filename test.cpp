#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "Visitor.h"

int main(int argc,char* argv[])
{
	Visitor* pVisitorA = new ConcreateVisitorA();
	Element* pElement = new ConcreateElementA();

	pElement->Accept(*pVisitorA);

	delete pElement;
	delete pVisitorA;

	return 0;
}
