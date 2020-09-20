#include "PickByTypeAction.h"
#include "../ApplicationManager.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CEllipse.h"
#include "../Figures/CLine.h"
#include "../Figures/CRhomb.h"
#include "../Figures/CTriangle.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

#include <cstdlib>
#include <ctime>
#include <chrono>

#include <vector>



PickByTypeAction::PickByTypeAction(ApplicationManager * pApp)
	:Action(pApp)
{
	//Initializing Counters
	CorrectCount = 0;
	IncorrectCount = 0;
	HiddenIndex = 0;
	anyFigFound = true;
}

void PickByTypeAction::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();

	for (int i = 1; i <= 5;i++)
	{
		switch (i)
		{
		case 1:
			PickingFigure = i;
			break;
		case 2:
			PickingFigure = i;
			break;
		case 3:
			PickingFigure = i;
			break;
		case 4:
			PickingFigure = i;
			break;
		case 5:
			PickingFigure = i;
			break;
		}
		if (pManager->IsRandFigInList(PickingFigure))
			existingFigures.push_back(i);
	}

	bool Check = existingFigures.size();//Checking at least one shape exists
	anyFigFound = Check;
	while (Check)
	{
		
	

		srand(time(0));

		GeneratedTypeNum = 1 + (rand() % existingFigures.size());
		

		switch (GeneratedTypeNum)
		{
		case 1:
			PickingFigure = 1;
			break;

		case 2:
			PickingFigure = 2;
			break;

		case 3:
			PickingFigure = 3;
			break;

		case 4:
			PickingFigure = 4;
			break;

		case 5:
			PickingFigure = 5;
			break;
		}

		if (pManager->IsRandFigInList(PickingFigure))
			Check = false;
	}

	
	RealCorrectCount = pManager->GetCountFoundFig(GeneratedTypeNum);
	switch (GeneratedTypeNum)
	{
	case 1:
		pOut->PrintMessage("Select all Rectangles, Double click to select");
		break;
	case 5:
		pOut->PrintMessage("Select all Lines, Double click to select");
		break;
	case 4:
		pOut->PrintMessage("Select all Ellipses,  Double click to select");
		break;
	case 2:
		pOut->PrintMessage("Select all Triangles,  Double click to select");
		break;
	case 3:
		pOut->PrintMessage("Select all Rhombus,  Double click to select");
		break;
	}
	_sleep(1000);
}

void PickByTypeAction::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	
	//Checking if no figure exists.
	if (anyFigFound == false)
	{
		pOut->PrintMessage("No shape exist!");
		return;
	}


	while(CorrectCount < RealCorrectCount)
	{

		ActionType Click = pIn->GetUserAction();

		if (Click == TO_DRAW || Click == FIG_TYPE)
			break;

		pManager->ExecuteAction(SELECT_FIG);

		SelectedFig = pManager->GetSelected();		//Gets a Pointer to the Selected Figure

		if (SelectedFig && SelectedFig->IsHidden() == false)
		{
			SelectedFiguresList[HiddenIndex] = SelectedFig;
			HiddenIndex++;

			SelectedFig->SetHidden(true);

			if (SelectedFig->GetTypeID() == PickingFigure)
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
		if (CorrectCount == pManager->GetCountFoundFig(PickingFigure))
			break;
	}
	string message = "Correct Selections : " + to_string(CorrectCount) + " Incorrect Selections : " + to_string(IncorrectCount);

	pOut->PrintMessage(message);
	_sleep(1500);
	for (int i = 0; i < HiddenIndex; i++)
	{
		SelectedFiguresList[i]->SetHidden(false);
		SelectedFiguresList[i]->SetSelected(false);
	}
	pManager->UpdateInterface();
}

PickByTypeAction::~PickByTypeAction()
{
	for (int i = 0; i < HiddenIndex; i++)
	{
		delete SelectedFiguresList[i];
	}
}
