#include <iostream>
#include "Adapter.h"

void Adaptee::SpecialRequest()
{
	std::cout << "SpecialRequest of Adaptee\n";
}

Adapter::Adapter(Adaptee* pAdaptee) : m_pAdaptee(pAdaptee)
{
}

Adapter::~Adapter()
{
	delete m_pAdaptee;
	m_pAdaptee = NULL;
}

void Adapter::Request()
{
	std::cout << "Request of Adapter\n";
	m_pAdaptee->SpecialRequest();
}
