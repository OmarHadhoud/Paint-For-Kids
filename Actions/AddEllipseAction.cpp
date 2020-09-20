#include "AddEllipseAction.h"

#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddEllipseAction::AddEllipseAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddEllipseAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse : Click at Center point");

	//Read center and store it in P
	pIn->GetPointClicked(P.x, P.y);



	RectGfxInfo.isFilled = pManager->GetIsFilled();	//default is not filled as it is line
									//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipseAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (CanDraw())
	{
		//Create an ellipse with the parameters read from the user
		CEllipse *ELL = new CEllipse(P, RectGfxInfo);

		//Add the ellipse to the list of figures
		pManager->AddFigure(ELL);
	}
	
}

bool AddEllipseAction::CanDraw() {	
	if (P.y > UI.ToolBarHeight + EllipseSize && P.y < (UI.height - UI.StatusBarHeight - EllipseSize))
	{
		return true;
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Error, Please stay in the drawing area.");
		return false;
	}
}
