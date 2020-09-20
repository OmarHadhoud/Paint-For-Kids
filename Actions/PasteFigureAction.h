#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CEllipse.h"
#include "../Figures/CFigure.h"
#include "../Figures/CLine.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CRhomb.h"
#include "../Figures/CTriangle.h"

class PasteFigureAction : public Action
{
private:
	Point P;
	CFigure *Clipboard;
	bool Cut;
public:
	PasteFigureAction(ApplicationManager *pApp);

	//	void DrawSelectedFig(CFigure *);

	virtual void ReadActionParameters();
	virtual void Execute();

	~PasteFigureAction();
};