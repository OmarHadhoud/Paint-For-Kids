#include "ChangeDrawColorAction.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"


ChangeDrawColorAction::ChangeDrawColorAction(ApplicationManager * pApp)
	:Action(pApp)
{
}

void ChangeDrawColorAction::ReadActionParameters()
{
	SelectedFig = pManager->GetSelected();		//Pointer to the Selected Figure 

	//Makes Sure a Figure is Selected 
	while (!SelectedFig)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Error, Please select a figure first.");
	}

	Input* pIn = pManager->GetInput();

	ActionType SelColor = pIn->GetUserAction();		//The User Selects a Color

	switch (SelColor)
	{
	case SEL_BLUE:
		NewDrawColor = BLUE;
		break;

	case SEL_BLACK:
		NewDrawColor = BLACK;
		break;

	case SEL_GREEN:
		NewDrawColor = GREEN;
		break;

	case SEL_RED:
		NewDrawColor = RED;
		break;

	case SEL_WHITE:
		NewDrawColor = WHITE;
		break;
	}
}

void ChangeDrawColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->GetSelected() == NULL) //Making sure user selected a figure
	{
		pOut->PrintMessage("Error! Please select a figure first.");
		return;
	}
	ReadActionParameters();


	pOut->SetCrntDrawColor(NewDrawColor);	//Sets the Drawing Color by the Selected Color

	SelectedFig->ChngDrawClr(NewDrawColor);	//Changes the Drawing Color of the Selected Figure as well
	
	pOut->PrintMessage("Changed draw color."); //Printing message to the user that draw color changed.

	pManager->ChangeSelected(NULL); //stop selecting the figure.

}

ChangeDrawColorAction::~ChangeDrawColorAction()
{
}
