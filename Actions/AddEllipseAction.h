#ifndef ADD_ELLIPSE_ACTION_H
#define ADD_ELLIPSE_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddEllipseAction: public Action
{
private:
	Point P; //Ellipse Center
	GfxInfo RectGfxInfo; 
public:
	AddEllipseAction(ApplicationManager *pApp);

	//Reads Ellipse parameters
	virtual void ReadActionParameters();
	
	//Adds Ellipse to the ApplicationManager
	virtual void Execute() ;
	
	//Checks if the Ellipse can be drawn
	virtual bool CanDraw();
};

#endif