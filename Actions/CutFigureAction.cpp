#include "CutFigureAction.h"

#include "..\ApplicationManager.h"
#include "Action.h"


CutFigureAction::CutFigureAction(ApplicationManager * pApp) :Action(pApp)
{}

void CutFigureAction::ReadActionParameters()
{
	SelectedFig = pManager->GetSelected();	//gets a pointer to the selected figure

	if (!SelectedFig)	// is selected
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Error, Please select a figure first.");
	}
}

void CutFigureAction::Execute()
{
	ReadActionParameters();
	if (SelectedFig)	// is selected
	{
		pManager->ChangeClipboard(SelectedFig,true);  // Changes the value of the clipboard to the new figure and cut bool to true
	}

}


CutFigureAction::~CutFigureAction()
{
}
