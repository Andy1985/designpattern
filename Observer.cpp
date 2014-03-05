#include <iostream>
#include <algorithm>
#include "Observer.h"

void Subject::Attach(Observer* pObserver)
{
	std::cout << "Attach an Observer\n";
	m_ListObserver.push_back(pObserver);
}

void Subject::Detach(Observer* pOberver)
{
	std::list<Observer*>::iterator iter;
	iter = std::find(m_ListObserver.begin(),m_ListObserver.end(),pOberver);
	
	if (m_ListObserver.end() != iter)
	{
		m_ListObserver.erase(iter);
	}

	std::cout << "Detach an Observer\n";
}

void Subject::Notify()
{
	std::cout << "Notify Observer's State\n";

	std::list<Observer*>::iterator iter1,iter2;
	
	for (iter1 = m_ListObserver.begin(),iter2 = m_ListObserver.end();
		iter1 != iter2; ++iter1)
	{
		(*iter1)->Update(this);
	}
}

void Subject::SetState(STATE nState)
{
	std::cout << "SetState By Subject\n";
	m_nSubjectState = nState;
}

STATE Subject::GetState()
{
	std::cout << "GetState By Subject\n";
	return m_nSubjectState;
}

Subject::~Subject()
{
	std::list<Observer*>::iterator iter1,iter2,temp;
	for (iter1 = m_ListObserver.begin(),iter2 = m_ListObserver.end();
		iter1 != iter2;)
	{
		temp = iter1;
		++iter1;
		delete(*temp);
	}

	m_ListObserver.clear();
}

void ConcreateSubject::SetState(STATE nState)
{
	std::cout << "SetState By ConcreateSubject\n";
	m_nSubjectState = nState;
}

STATE ConcreateSubject::GetState()
{
	std::cout << "GetState By ConcreateSubject\n";
	return m_nSubjectState;
}

void ConcreateObserver::Update(Subject* pSubject)
{
	if (NULL == pSubject)
	{
		return;
	}

	m_nObserverState = pSubject->GetState();
	
	std::cout << "The ObserverState is " << m_nObserverState << std::endl;
}

