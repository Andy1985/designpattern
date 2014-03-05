#ifndef OBSERVER_H
#define OBSERVER_H

#include <list>

typedef int STATE;

class Observer;

class Subject
{
	public:
		Subject() : m_nSubjectState(-1) {}
		virtual ~Subject();

	void Notify();
	void Attach(Observer* pOberver);
	void Detach(Observer* pOberver);

	virtual void SetState(STATE nState);
	virtual STATE GetState();

	protected:
		STATE m_nSubjectState;
		std::list<Observer*> m_ListObserver;
};

class Observer
{
	public:
		Observer() : m_nObserverState(-1) {}
		virtual ~Observer() {}
	virtual void Update(Subject* pSubject) = 0;

	protected:
		STATE m_nObserverState;
};

class ConcreateSubject : public Subject
{
	public:
		ConcreateSubject() : Subject() {}
		virtual ~ConcreateSubject() {}

	virtual void SetState(STATE nState);
	virtual STATE GetState();
	void Update(Subject* pSubject);
};

class ConcreateObserver : public Observer
{
	public:
		ConcreateObserver() : Observer() {}
		virtual ~ConcreateObserver() {}

	virtual void Update(Subject* pSubject);
};
#endif
