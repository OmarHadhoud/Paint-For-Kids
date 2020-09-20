#include "AddTriangleAction.h"

#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first point");

	//Read 1st point and store it in P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second point");

	//Read 2nd point and store it in P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Traingle: Click at thrid point");
	
	//Read 3rd point and store it in P3
	pIn->GetPointClicked(P3.x, P3.y);

	RectGfxInfo.isFilled = pManager->GetIsFilled();	//default is not filled
									//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriangleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (CanDraw()) {
		//Create a triangle with the parameters read from the user
		CTriangle *TRI = new CTriangle(P1, P2, P3, RectGfxInfo);

		//Add the triangle to the list of figures
		pManager->AddFigure(TRI);
	}
}

bool AddTriangleAction::CanDraw() {
	if (P1.y > UI.ToolBarHeight && P2.y > UI.ToolBarHeight && P3.y > UI.ToolBarHeight && P1.y < (UI.height - UI.StatusBarHeight) && P2.y < (UI.height - UI.StatusBarHeight) && P3.y < (UI.height - UI.StatusBarHeight))
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