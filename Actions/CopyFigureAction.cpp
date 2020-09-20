#include "CopyFigureAction.h"

#include "..\ApplicationManager.h"
#include "Action.h"

CopyFigureAction::CopyFigureAction(ApplicationManager * pApp) :Action(pApp)
{}

void CopyFigureAction::ReadActionParameters()
{
	SelectedFig = pManager->GetSelected(); // gets a pointer to the selected figure
	
	if (!SelectedFig)	// not selected
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Error, Please select a figure first.");
	}
}

void CopyFigureAction::Execute()
{
	ReadActionParameters();
	if (SelectedFig)	// is selected
	{
		pManager->ChangeClipboard(SelectedFig, false);  // Changes the value of the clipboard to the new figure and cut bool to false
	}

}
CopyFigureAction::~CopyFigureAction()
{
}
