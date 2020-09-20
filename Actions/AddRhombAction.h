#ifndef ADD_RHOMB_ACTION_H
#define ADD_RHOMB_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddRhombAction: public Action
{
private:
	Point P; //Rhombus Center
	GfxInfo RectGfxInfo;
public:
	AddRhombAction(ApplicationManager *pApp);

	//Reads Rhombus parameters
	virtual void ReadActionParameters();
	
	//Add Rhombus to the ApplicationManager
	virtual void Execute() ;
	
	//Checks if the Rhombus can be drawn
	virtual bool CanDraw();
};

#endif