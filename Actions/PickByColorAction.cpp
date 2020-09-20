#include "PickByColorAction.h"
#include "../ApplicationManager.h"
#include "../CMUgraphicsLib/colors.h"
#include "../Figures/CLine.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

#include <cstdlib>
#include <ctime>
#include <chrono>

#include <vector>


PickByColorAction::PickByColorAction(ApplicationManager * pApp)
	:Action(pApp)
{
	//Initializing Counters
	CorrectCount = 0;
	IncorrectCount = 0;
	HiddenIndex = 0;
	countFound = 0;
	oneFilled = true;
}

void PickByColorAction::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
	
	for (int i = 0; i < 5;i++)
	{
		switch (i)
		{
		case 0:
			PickingColor = BLACK;
			break;
		case 1:
			PickingColor = WHITE;
			break;
		case 2:
			PickingColor = BLUE;
			break;
		case 3:
			PickingColor = RED;
			break;
		case 4:
			PickingColor = GREEN;
			break;
		}
		if (pManager->IsRandColorInList(PickingColor))
			existingColors.push_back(i);
	}


	bool Check = existingColors.size()&& pManager->IsAnyFigureFilled();
	oneFilled = Check;

	while (Check)
	{

		srand(time(0));

		int GeneratedColorNumI = rand() % existingColors.size();

		GeneratedColorNum = existingColors[GeneratedColorNumI];
		switch (GeneratedColorNum)
		{
		case COLOR_BLACK:
			PickingColor = BLACK;
			break;

		case COLOR_WHITE:
			PickingColor = WHITE;
			break;

		case COLOR_BLUE:
			PickingColor = BLUE;
			break;

		case COLOR_RED:
			PickingColor = RED;
			break;

		case COLOR_GREEN:
			PickingColor = GREEN;
			break;
		}
		//Return if there is no figure filled
		/*if (IsAnyFigureFilled() == false)
		{
			oneFilled = false;
			return;
		}*/
		if (pManager->IsRandColorInList(PickingColor))
			Check = false;
	}
	RealCorrectCount = pManager->GetCounfFoundColor(PickingColor);
	switch (GeneratedColorNum)
	{
	case COLOR_BLACK:
		pOut->PrintMessage("Select Figures With the Color Black,  Double click to select");
		break;

	case COLOR_WHITE:
		pOut->PrintMessage("Select Figures With the Color White,  Double click to select");
		break;

	case COLOR_BLUE:
		pOut->PrintMessage("Select Figures With the Color Blue, Double click to select");
		break;

	case COLOR_RED:
		pOut->PrintMessage("Select Figures With the Color Red, Double click to select");
		break;

	case COLOR_GREEN:
		pOut->PrintMessage("Select Figures With the Color Green, Double click to select");
		break;
	}
	_sleep(1000);

}

void PickByColorAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	ReadActionParameters();

	if (oneFilled == false)
	{
		pOut->PrintMessage("No filled shape exist!");
		return;
	}

	while(CorrectCount < RealCorrectCount)
	{
		pOut->PrintMessage("Double Click to Select.");

		ActionType Click = pIn->GetUserAction();

		if (Click == TO_DRAW || Click == FIG_TYPE)
			break;

		pManager->ExecuteAction(SELECT_FIG);		//Prompts the User to Select a Figure

		SelectedFig = pManager->GetSelected();		//Gets a Pointer to the Selected Figure


		if (SelectedFig && SelectedFig->IsHidden() == false)
		{
			SelectedFigList[HiddenIndex] = SelectedFig;
			HiddenIndex++;

			SelectedFig->SetHidden(true);

			if (SelectedFig->GetFillClr() == PickingColor && SelectedFig->IsFilled())
			{
				pOut->PrintMessage("Correct Pick!");
				CorrectCount++;
				_sleep(500);
			}
			else
			{
				pOut->PrintMessage("Incorrect Pick!");
				IncorrectCount++;
				_sleep(500);
			}
			pManager->UpdateInterface();
		}
		else if (SelectedFig == NULL)
		{
			pOut->PrintMessage("You didn't select any figure!");
		}
		if (CorrectCount == pManager->GetCounfFoundColor(PickingColor))
			break;

	}
	string message = "Correct Picks : " + to_string(CorrectCount) + " Incorrect Picks : " + to_string(IncorrectCount);

	pOut->PrintMessage(message);
	_sleep(1500);
	for (int i = 0; i < HiddenIndex; i++)
	{
		SelectedFigList[i]->SetHidden(false);
		SelectedFigList[i]->SetSelected(false);
	}
	pManager->UpdateInterface();
}

PickByColorAction::~PickByColorAction()
{
	for (int i = 0; i < HiddenIndex; i++)
	{
		delete SelectedFigList[i];
	}
}