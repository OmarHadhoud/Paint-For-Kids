#ifndef CHANGEDRAWCOLOR_H
#define CHANGEDRAWCOLOR_H

#include "Action.h"
#include "../CMUgraphicsLib/colors.h"
#include "../Figures/CFigure.h"

class ChangeDrawColorAction : public Action
{
private:
	color NewDrawColor;
	CFigure* SelectedFig; 
public:
	ChangeDrawColorAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~ChangeDrawColorAction();


};

#endif // !CHANGEDRAWINGCOLOR_H

