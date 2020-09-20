#ifndef CHNGFILLCOLORACTION_H
#define	CHNGFILLCOLORACTION_H

#include "Action.h"
#include "../CMUgraphicsLib/colors.h"
#include "../Figures/CFigure.h"

class ChangeFillColorAction : public Action
{
private:
	color NewFillColor;
	CFigure* SelectedFig;
public:
	ChangeFillColorAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ChangeFillColorAction();
};
#endif // !CHNGFILLCOLORACTION_H


