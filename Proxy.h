#ifndef PROXY_H
#define PROXY_H

class Subject
{
	public:
		Subject() {}
		virtual ~Subject() {}

	virtual void Request() = 0;
};

class RealSubject : public Subject
{
	public:
		RealSubject();
		virtual ~RealSubject() {}
	
	virtual void Request();
};

class Proxy : public Subject
{
	public:
		Proxy();
		virtual ~Proxy();

		virtual void Request();
	private:
		RealSubject* m_pRealSubject;
};
#endif
