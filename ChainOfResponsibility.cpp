#include <iostream>
#include "ChainOfResponsibility.h"

Handler::Handler(Handler* pSuccessor) : m_pSuccessor(pSuccessor)
{
}

Handler::~Handler()
{
	delete m_pSuccessor;
	m_pSuccessor = NULL;
}

void ConcreateHandler1::HandleRequest()
{
	if (NULL != m_pSuccessor)
	{
		m_pSuccessor->HandleRequest();
	}
	else
	{
		std::cout << "HandleRequest by ConcreateHandler1\n";
	}
}

void ConcreateHandler2::HandleRequest()
{
	if (NULL != m_pSuccessor)
	{
		m_pSuccessor->HandleRequest();
	}
	else
	{
		std::cout << "HandleRequest by ConcreateHandler2\n";
	}
}
