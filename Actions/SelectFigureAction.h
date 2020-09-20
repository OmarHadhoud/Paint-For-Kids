#ifndef SELECT_FIGURE_ACTION_H
#define SELECT_FIGURE_ACTION_H

#include "Action.h"

//Add select figure Action class
class SelectFigureAction: public Action
{
private:
	Point P; //Point clicked
public:
	SelectFigureAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute();
	
};

#endif