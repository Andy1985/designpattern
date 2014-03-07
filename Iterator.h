#ifndef ITERATOR_H
#define ITERATOR_H

typedef int DATA;

class Iterator;

class Aggregate
{
	public:
		virtual ~Aggregate() {}
		virtual Iterator* CreateIterator(Aggregate* pAggregate) = 0;
		virtual int GetSize() = 0;
		virtual DATA GetItem(int nIndex) = 0;
};

class Iterator
{
	public:
		virtual ~Iterator() {}
		
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual DATA CurrentItem() = 0;
};

class ConcreateAggregate : public Aggregate
{
	public:
		ConcreateAggregate(int nSize);
		virtual ~ConcreateAggregate();

		virtual Iterator* CreateIterator(Aggregate* pAggregate);
		virtual int GetSize();
		virtual DATA GetItem(int nIndex);
	private:
		int m_nSize;
		DATA* m_pData;
};

class ConcreateIterator : public Iterator
{
	public:
		ConcreateIterator(Aggregate* pAggregate);
		virtual ~ConcreateIterator() {}

	virtual void First();
	virtual void Next();
	virtual bool IsDone();
	virtual DATA CurrentItem();

	private:
		Aggregate* m_pConcreateAggregate;
		int m_nIndex;
};
#endif
