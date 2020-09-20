#ifndef ADD_LINE_ACTION_H
#define ADD_LINE_ACTION_H

#include "Action.h"

//Add Line Action class
class AddLineAction : public Action
{
private:
	Point P1, P2; //Line starting and ending points
	GfxInfo RectGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);

	//Reads line parameters
	virtual void ReadActionParameters();

	//Add linee to the ApplicationManager
	virtual void Execute();

	//Checks if the Line can be drawn
	virtual bool CanDraw();
};

#endif