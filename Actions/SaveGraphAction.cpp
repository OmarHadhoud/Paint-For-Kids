#include "SaveGraphAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"
#include"..\Actions\SaveByTypeAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <fstream>
#include <iostream>
using namespace std;

SaveGraphAction:: SaveGraphAction(ApplicationManager *pApp) : Action(pApp)
{

}




//gets name of file  to be saved from user 
//gets type of figure to be saved 
void SaveGraphAction::ReadActionParameters()
{
	//Creating pointers to input & output classes 
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//getting name of file
	pOut->PrintMessage("Enter name of file to be saved");
	fileName = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();

}

//saves graph
//overwrites file if it has the same name as a previously created one

void SaveGraphAction::Execute()
{
	//read parameters before executing
	ReadActionParameters();

	//creating and opening file
	ofstream outputfile;
	outputfile.open(fileName, ios::out);


	//writing general information
	outputfile << SaveByType::ConvertColor(pManager->GetOutput()->getCrntDrawColor()) << "		";		//draw colour
	outputfile << SaveByType::ConvertColor( pManager->GetOutput()->getCrntFillColor()) << "\n";			//fill colour

	outputfile << pManager->GetFigCount();	//count of figures

	//calling save function of each shape
	
		pManager->SaveAll(outputfile);
	

	//closing file 
	outputfile.close();

}
