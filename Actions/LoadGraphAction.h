#ifndef LOAD_GRAPH
#define LOAD_GRAPH

#include "Action.h"
#include <string>
#include <iostream>

class LoadGraphAction : public Action
{
private:
	std:: string fileName;
	GfxInfo tempGFX;
	Point tempPoint;
public:
	LoadGraphAction(ApplicationManager * pApp);

	void ReadActionParameters();
	void Execute();
};

#endif // !LOAD_GRAPH

