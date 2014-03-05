#include <iostream>
#include "Command.h"

void Receiver::Action()
{
	std::cout << "Receiver Action\n";
}

Invoker::Invoker(Command* pCommand) : m_pCommand(pCommand)
{
}

Invoker::~Invoker()
{
	delete m_pCommand;
	m_pCommand = NULL;
}

void Invoker::Invoke()
{
	if (NULL != m_pCommand)
	{
		m_pCommand->Execute();
	}
}

ConcreateCommand::ConcreateCommand(Receiver* pReceiver) : m_Receiver(pReceiver)
{
}

ConcreateCommand::~ConcreateCommand()
{
	delete m_Receiver;
	m_Receiver = NULL;
}

void ConcreateCommand::Execute()
{
	if (NULL != m_Receiver)
	{
		m_Receiver->Action();
	}

	std::cout << "Execute by ConcreateCommand\n";
}
