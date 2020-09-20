#include "PasteFigureAction.h"



PasteFigureAction::PasteFigureAction(ApplicationManager *pApp) :Action(pApp)
{}

void PasteFigureAction::ReadActionParameters()
{
	Clipboard = pManager->GetClipboard(); // gets a pointer to the selected figure
	Output *pOut = pManager->GetOutput();

	if (!Clipboard) // not selected
	{
		pOut->PrintMessage("Error, Please copy/cut a figure first.");
	}
	else {
		Input* pIn = pManager->GetInput();

		pOut->PrintMessage("Click at paste point");

		//Read center and store it in P
		pIn->GetPointClicked(P.x, P.y);
	}
	Cut = pManager->GetIsCut();
}



void PasteFigureAction::Execute()
{
	ReadActionParameters();

	Output *pOut = pManager->GetOutput();
	if (Clipboard)
	{
		CFigure* Newfig = Clipboard->GetCopyAtPoint(P);
		pManager->AddFigure(Newfig);
		if (Cut)
		{
			pManager->DeleteFigure(Clipboard);
			pManager->ChangeClipboard(NULL, false);
		}
	}
}



PasteFigureAction::~PasteFigureAction()
{}
