#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class DeleteFigureAction :
	public Action
{
private:
	CFigure* SelectedFig; //Pointer to the selected figure
public:
	DeleteFigureAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	~DeleteFigureAction();
};

