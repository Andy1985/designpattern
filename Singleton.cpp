#include <iostream>
#include "Singleton.h"

Singleton* Singleton::m_pStatic = NULL;

Singleton* Singleton::GetInstancePtr()
{
	if (NULL == m_pStatic)
	{
		m_pStatic = new Singleton();
	}

	return m_pStatic;
}

Singleton Singleton::GetInstance()
{
	return *GetInstancePtr();
}

void Singleton::Test()
{
	std::cout << "Test! " << count++ << std::endl;
}
