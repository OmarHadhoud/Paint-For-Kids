#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H

#include "Action.h"

//Add Triangle Action class
class AddTriangleAction : public Action
{
private:
	Point P1, P2, P3; //The three points of the triangle
	GfxInfo RectGfxInfo;
public:
	AddTriangleAction(ApplicationManager *pApp);

	//Reads Triangle parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();

	//Checks if the triangle can be drawn
	virtual bool CanDraw();
};

#endif