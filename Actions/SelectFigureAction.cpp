#include "SelectFigureAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectFigureAction::SelectFigureAction(ApplicationManager * pApp):Action(pApp)
{}

void SelectFigureAction::ReadActionParameters()
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//pOut->PrintMessage("Select Figure: Click at figure");
	
	//Read point clicked and store it in P
	pIn->GetPointClicked(P.x, P.y);


	pOut->ClearStatusBar();

}

//Execute the action
void SelectFigureAction::Execute()
{
	ReadActionParameters();
	//Loop through the whole figure list and see if point lies inside the figure borders.
	CFigure *selected;
	selected = pManager->GetFigure(P.x, P.y);
	pManager->ChangeSelected(selected); //Calling function to change Application Manager selected file.
	if (selected != NULL)
	{
		selected->SetSelected(!selected->IsSelected());
	}
}
