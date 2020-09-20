#include "AddRhombAction.h"

#include "..\Figures\CRhomb.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRhombAction::AddRhombAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddRhombAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at center point");

	//Read Center point and store it in P.
	pIn->GetPointClicked(P.x, P.y);


	RectGfxInfo.isFilled = pManager->GetIsFilled();	//default is not filled 
									//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhombAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	if (CanDraw()) {
		//Create a Rhombus with the parameters read from the user
		CRhomb *RHMB = new CRhomb(P, RectGfxInfo);

		//Add the Rhombus to the list of figures
		pManager->AddFigure(RHMB);
	}
}

bool AddRhombAction::CanDraw() {
	if (P.y > UI.ToolBarHeight + RhombSize2 && P.y < (UI.height - UI.StatusBarHeight - RhombSize2))
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