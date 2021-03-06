#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class CopyFigureAction :public Action
{
private:
	CFigure* SelectedFig; //Pointer to the selected figure
public:
	CopyFigureAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	~CopyFigureAction();
};

