#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class CutFigureAction :public Action
{
private:
	CFigure* SelectedFig; //Pointer to the selected figure
public:
	CutFigureAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();	//Reads parameters

	virtual void Execute(); 
	~CutFigureAction();
};

