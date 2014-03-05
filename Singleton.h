#ifndef SINGLETON_H
#define SINGLETON_H
class Singleton
{
	private:
		Singleton() { count = 0; }
	public:
		~Singleton() {}

	static Singleton* GetInstancePtr();
	static Singleton GetInstance();

	void Test();

	private:
		static Singleton* m_pStatic;
		int count;
};
#endif
