#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <list>

class Component
{
	public:
		Component() {}
		virtual ~Component() {}

	virtual void Operation() = 0;
	virtual void Add(Component* pChild);
	virtual void Remove(Component* pChild);
	virtual Component* GetChild(int nIndex);
};

class Leaf : public Component
{
	public:
		Leaf() {}
		virtual ~Leaf() {}

	virtual void Operation();
};

class Composite : public Component
{
	public:
		Composite() {}
		virtual ~Composite();

	virtual void Operation();
	virtual void Add(Component* pChild);
	virtual void Remove(Component* pChild);
	virtual Component* GetChild(int nIndex);

	private:
		std::list<Component*> m_ListOfComponent;
};
#endif
