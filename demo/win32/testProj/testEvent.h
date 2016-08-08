#include <iostream>
#include "events\event.h"

class EvtA {

public:

	void func_A(AEvent* evt) {
		std::cout << "A::func_A" << std::endl;
	}


};

void testEvent() {
	EvtA* a = new EvtA;

	AEvent* evt = new AEvent("AA");
	EventDispatcher* ed = new EventDispatcher;
	ed->addEventListener("AA", [](AEvent*)->void {
		std::cout << "AA!!" << std::endl;
	});


	ed->addEventListener("AA", std::bind(&EvtA::func_A, a, std::placeholders::_1), a, 1);

	ed->dispatchEvent(evt);



	//std::cout << e.getType() << std::endl;



}