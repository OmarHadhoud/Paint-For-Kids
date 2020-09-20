#ifndef SAVE_GRAPH_ACT
#define SAVE_GRAPH_ACT

#include "..\Actions\Action.h"
#include <string.h>
#include <iostream>

class SaveGraphAction :public Action
{

private:
	std:: string fileName;

public:
	SaveGraphAction(ApplicationManager *pApp);


	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif // !SAVE_GRAPH_ACT
