#include <iostream>
#include "Builder.h"

void ConcreateBuilder1::BuilderPartA()
{
	std::cout << "BuilderPartA by ConcreateBuilder1\n";
}

void ConcreateBuilder1::BuilderPartB()
{
	std::cout << "BuilderPartB by ConcreateBuilder1\n";
}

void ConcreateBuilder2::BuilderPartA()
{
	std::cout << "BuilderPartA by ConcreateBuilder2\n";
}

void ConcreateBuilder2::BuilderPartB()
{
	std::cout << "BuilderPartB by ConcreateBuilder2\n";
}

Director::Director(Builder* pBuilder) : m_pBuilder(pBuilder)
{
}

Director::~Director()
{
	delete m_pBuilder;
}

void Director::Construct()
{
	m_pBuilder->BuilderPartA();
	m_pBuilder->BuilderPartB();
}
