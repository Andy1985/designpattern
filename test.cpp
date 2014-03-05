#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "Observer.h"

int main(int argc,char* argv[])
{
	Observer* p1 = new ConcreateObserver();
	Observer* p2 = new ConcreateObserver();

	Subject* p = new ConcreateSubject();
	p->Attach(p1);
	p->Attach(p2);
	p->SetState(4);
	p->Notify();

	p->Detach(p1);
	p->SetState(10);
	p->Notify();

	delete p1;
	delete p;

	return 0;
}
