#ifndef DECORATOR_H
#define DECORATOR_H
class Component
{
	public:
		Component() {}
		virtual ~Component() {}
	virtual void Operation() = 0;
};

class Decorator : public Component
{
	public:
		Decorator(Component* pComponent) : m_pComponent(pComponent) {}
		virtual ~Decorator();

	protected:
		Component* m_pComponent;
};

class ConcreateComponent : public Component
{
	public:
		ConcreateComponent() {}
		virtual ~ConcreateComponent() {}
		
		virtual void Operation();
};

class ConcreateDecorator : public Decorator
{
	public:
		ConcreateDecorator(Component* pComponent) : Decorator(pComponent) {}
		virtual ~ConcreateDecorator() {}

	virtual void Operation();

	private:
		void AddedBehavior();
};
#endif
