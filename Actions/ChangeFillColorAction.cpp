#include "ChangeFillColorAction.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

ChangeFillColorAction::ChangeFillColorAction(ApplicationManager * pApp):Action(pApp)
{
}

void ChangeFillColorAction::ReadActionParameters()
{
	SelectedFig = pManager->GetSelected();		//Pointer to The Selected Figure

	//Makes Sure a Figure is Selected 
	while (!SelectedFig)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Error, Please select a figure first.");
	}

	Input* pIn = pManager->GetInput();
	ActionType SelColor = pIn->GetUserAction();	//Gets the selected color by the user

	switch (SelColor)
	{
	case SEL_BLUE:
		NewFillColor = BLUE;
		break;

	case SEL_BLACK:
		NewFillColor = BLACK;
		break;

	case SEL_GREEN:
		NewFillColor = GREEN;
		break;

	case SEL_RED:
		NewFillColor = RED;
		break;

	case SEL_WHITE:
		NewFillColor = WHITE;
		break;
	}
}

void ChangeFillColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->GetSelected() == NULL) //Making sure user selected a figure
	{
		pOut->PrintMessage("Error! Please select a figure first.");
		return;
	}

	//Making sure the selected figure isn't a line as can't change line fill color.
	if (pManager->GetSelected()->GetTypeID() == 5)
	{
		pOut->PrintMessage("There is no fill color to change in line!");
		pManager->ChangeSelected(NULL); //stop selecting the figure.
		return;
	}
	ReadActionParameters();

	pOut->SetCrntFillColor(NewFillColor);	//Sets the Fill Color With the Selected Color by User 
	pManager->SetIsFilled(true);			//Sets the fill status for the figures that will be drawn.
	SelectedFig->ChngFillClr(NewFillColor);	//Changes the Fill Color of the Selected Figure as well

	pOut->PrintMessage("Changed fill color."); //Printing message to the user that fill color changed.

	pManager->ChangeSelected(NULL); //stop selecting the figure.

}

ChangeFillColorAction::~ChangeFillColorAction()
{

}

