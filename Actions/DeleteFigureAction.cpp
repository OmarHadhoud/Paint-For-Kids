#include "DeleteFigureAction.h"
#include "..\ApplicationManager.h"
#include "Action.h"


DeleteFigureAction::DeleteFigureAction(ApplicationManager *pApp):Action(pApp)
{

}

void DeleteFigureAction::ReadActionParameters() {
	SelectedFig = pManager->GetSelected(); // gets a pointer to the selected figure

	if (!SelectedFig)	// not selected
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Error, Please select a figure first.");
	}
}

void DeleteFigureAction::Execute() {
	ReadActionParameters();
	if (SelectedFig)	// is selected
	{
		pManager->DeleteFigure(SelectedFig);
	}
}

DeleteFigureAction::~DeleteFigureAction()
{
}
