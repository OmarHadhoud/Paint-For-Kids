#include "AddLineAction.h"

#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first point");

	//Read 1st point and store it in P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second point");

	//Read 2nd point and store it in P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = false;	//default is not filled as it is line
									//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddLineAction::Execute()
{	
	//This action needs to read some parameters first
	ReadActionParameters();
	if (CanDraw()) {
		//Create a line with the parameters read from the user
		CLine *L = new CLine(P1, P2, RectGfxInfo);

		//Add the line to the list of figures
		pManager->AddFigure(L);
	}
	
}

bool AddLineAction::CanDraw() {
	if (P1.y > UI.ToolBarHeight && P2.y > UI.ToolBarHeight &&P1.y < (UI.height - UI.StatusBarHeight) && P2.y < (UI.height - UI.StatusBarHeight)) // is inside drawing area ?
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
