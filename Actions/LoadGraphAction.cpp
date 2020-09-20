#include "LoadGraphAction.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CRhomb.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"
#include"..\Actions\SaveByTypeAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;


LoadGraphAction::LoadGraphAction(ApplicationManager * pApp) : Action(pApp)
{
	
}

void LoadGraphAction::ReadActionParameters()
{
	//Creating pointers to input & output classes 
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//getting name of loaded file
	pOut->PrintMessage("Enter name of file to be loaded");
	fileName = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
}


void LoadGraphAction::Execute()
{
	//read parameters before executing
	ReadActionParameters();


	ifstream inputfile(fileName);

	if (inputfile.is_open())
	{
		//Deleting and reseting current FigList
		pManager->DeleteAll();
		pManager->GetOutput()->ClearDrawArea();	//clears drawing area before loading graph


		//setting draw color
		string Clr;
		inputfile >> Clr;
		pManager->GetOutput()->SetCrntDrawColor(SaveByType::ConvertStringToColor(Clr));

		//setting fill color
		inputfile >> Clr;
		pManager->GetOutput()->SetCrntFillColor(SaveByType::ConvertStringToColor(Clr));

	
		//getting number of figures
		int NumberOfFigures;
		inputfile >> NumberOfFigures;
		
		//loading figures 
		for (int i = 0; i < NumberOfFigures; i++)
		{
			CFigure* currentFig;

			string figType;
			inputfile >> figType;

			//checking type of each figure
			if (figType == "ELLIPSE")
			{
				currentFig = new CEllipse(tempPoint, tempGFX);
				currentFig->Load(inputfile);
				pManager->AddFigure(currentFig);
			}

			if (figType == "LINE")
			{
				currentFig = new CLine(tempPoint, tempPoint, tempGFX);
				currentFig->Load(inputfile);
				pManager->AddFigure(currentFig);
			}

			if (figType == "RECTANGLE")
			{
				currentFig = new CRectangle(tempPoint,tempPoint, tempGFX);
				currentFig->Load(inputfile);
				pManager->AddFigure(currentFig);
			}

			if (figType == "RHOMBUS")
			{
				currentFig = new CRhomb(tempPoint, tempGFX);
				currentFig->Load(inputfile);
				pManager->AddFigure(currentFig);
			}

			if (figType == "TRIANGLE")
			{
				currentFig = new CTriangle(tempPoint, tempPoint, tempPoint, tempGFX);
				currentFig->Load(inputfile);
				pManager->AddFigure(currentFig);
			}
							
		}

		inputfile.close();
		
	}

	else
		pManager->GetOutput()->PrintMessage("The file you entered does not exist");
}
