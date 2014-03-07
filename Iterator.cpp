#include <iostream>
#include "Iterator.h"

ConcreateAggregate::ConcreateAggregate(int nSize) : m_nSize(nSize), m_pData(NULL)
{
	m_pData = new DATA[m_nSize];

	for (int i = 0; i < nSize; ++i)
	{
		m_pData[i] = i;
	}
}

ConcreateAggregate::~ConcreateAggregate()
{
	delete[] m_pData;
	m_pData = NULL;
}

Iterator* ConcreateAggregate::CreateIterator(Aggregate* pAggregate)
{
	return new ConcreateIterator(this);
}

int ConcreateAggregate::GetSize()
{
	return m_nSize;
}

DATA ConcreateAggregate::GetItem(int nIndex)
{
	if (nIndex < m_nSize)
	{
		return m_pData[nIndex];
	}
	else
	{
		return -1;
	}
}

ConcreateIterator::ConcreateIterator(Aggregate* pAggregate) 
	: m_pConcreateAggregate(pAggregate),m_nIndex(0)
{
}

void ConcreateIterator::First()
{
	m_nIndex = 0;
}

void ConcreateIterator::Next()
{
	if (m_nIndex < m_pConcreateAggregate->GetSize())
	{
		++m_nIndex;
	}
}

bool ConcreateIterator::IsDone()
{
	return m_nIndex == m_pConcreateAggregate->GetSize();
}

DATA ConcreateIterator::CurrentItem()
{
	return m_pConcreateAggregate->GetItem(m_nIndex);
}
