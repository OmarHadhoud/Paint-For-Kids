#include"SaveByTypeAction.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CRhomb.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"
#include"Action.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


#include <fstream>
#include <iostream>
using namespace std;





SaveByType::SaveByType(ApplicationManager *pApp) :Action(pApp)
{

}



 string SaveByType::ConvertColor(color color_)
{
	if (color_ == BLACK)
		return "BLACK";

	if (color_ == BLUE)
		return "BLUE";

	if (color_ == WHITE)
		return "WHITE";

	if (color_ == GREEN)
		return "GREEN";

	if (color_ == RED)
		return "RED";
}


//changes String to color

 color SaveByType::ConvertStringToColor(string color_name)
{
	if (color_name == "BLACK")
		return BLACK;

	if (color_name == "WHITE")
		return WHITE;

	if (color_name == "GREEN")
		return GREEN;

	if (color_name == "BLUE")
		return BLUE;

	if (color_name == "RED")
		return RED;

}


void SaveByType::ReadActionParameters()
{
	//Creating pointers to input & output classes 
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	
	//getting type of figure
	pOut->PrintMessage("Please choose type to save by");
	Fig = pManager->GetUserAction();
	
	
	
	while (Fig != DRAW_RECT && Fig != DRAW_LINE && Fig != DRAW_RHOMBUS &&  Fig != DRAW_TRI &&  Fig != DRAW_ELLIPSE)
	{
		pOut->PrintMessage("Now choose a figure");
		Fig = pIn->GetUserAction();
	}
		

	switch (Fig)
	{
		case DRAW_LINE:
			FigType = line;
			break;

		case DRAW_RECT:
			FigType = rectangle;
			break;

		case DRAW_TRI:
			FigType = triangle;
			break;

		case DRAW_ELLIPSE:
			FigType = ellipse;
			break;

		case DRAW_RHOMBUS:
			FigType = rohmbus;
			break;
	}
		
	//getting name of file
	pOut->PrintMessage("Enter name of file to be saved");
	fileName = pIn->GetSrting(pOut) + ".txt";

	pOut->ClearStatusBar();


}


void SaveByType::Execute()
{
	//read parameters before executing
	ReadActionParameters();
	
	//creating and opening file
	ofstream outputfile;
	outputfile.open(fileName, ios::out);


	//writing general information
	outputfile << ConvertColor(pManager->GetOutput()->getCrntDrawColor()) << "		";		//draw colour
	outputfile << ConvertColor(pManager->GetOutput()->getCrntFillColor()) << "\n";			//fill colour

	

	//finding number of shapes

	int NumberOfFigures=0;		//not sure whether to make i a data member or not

	switch (FigType)
	{
	case line:
		for (int i = 0; i < pManager->GetFigCount(); i++)
		{
			CLine* PtrLine=dynamic_cast <CLine*> (pManager->GetFigureAtIndex(i));
			if (PtrLine != NULL)
			{
				NumberOfFigures++;
			}
				
		}
		break;
		
	case rectangle:
		for (int i = 0; i < pManager->GetFigCount(); i++)
		{
			CRectangle* PtrRectangle = dynamic_cast <CRectangle*> (pManager->GetFigureAtIndex(i));
			if (PtrRectangle != NULL)
			{
				NumberOfFigures++;
			}

		}
		break;
		
	case ellipse:
		for (int i = 0; i < pManager->GetFigCount(); i++)
		{
			CEllipse *PtrEllipse = dynamic_cast <CEllipse*> (pManager->GetFigureAtIndex(i));
			if (PtrEllipse != NULL)
			{
				NumberOfFigures++;
			}
		}
		break;

	case triangle:
		for (int i = 0; i < pManager->GetFigCount(); i++)
		{
			CTriangle * PtrTriangle = dynamic_cast <CTriangle*> (pManager->GetFigureAtIndex(i));
			if (PtrTriangle != NULL)
			{
				NumberOfFigures++;
			}
		}
		break;

	case rohmbus:
		for (int i = 0; i < pManager->GetFigCount(); i++)
		{
			CRhomb *PtrRohmbus = dynamic_cast <CRhomb*> (pManager->GetFigureAtIndex(i));
			if (PtrRohmbus != NULL)
			{
				NumberOfFigures++;
			}
		}
		break;

	}
	
	outputfile << NumberOfFigures;



	//Now Saving Each Shape
	if (NumberOfFigures > 0)		
	{

		switch (FigType)
		{
		case line:
			for (int i = 0; i < pManager->GetFigCount(); i++)
			{
				CLine* PtrLine = dynamic_cast <CLine*> (pManager->GetFigureAtIndex(i));
				if (PtrLine != NULL)
				{
					NumberOfFigures++;
				}

			}
			break;

		case rectangle:
			for (int i = 0; i < pManager->GetFigCount(); i++)
			{
				CRectangle* PtrRectangle = dynamic_cast <CRectangle*> (pManager->GetFigureAtIndex(i));
				if (PtrRectangle != NULL)
				{
					PtrRectangle->Save(outputfile);
				}

			}
			break;

		case ellipse:
			for (int i = 0; i < pManager->GetFigCount(); i++)
			{
				CEllipse *PtrEllipse = dynamic_cast <CEllipse*> (pManager->GetFigureAtIndex(i));
				if (PtrEllipse != NULL)
				{
					PtrEllipse->Save(outputfile);
				}
			}
			break;

		case triangle:
			for (int i = 0; i < pManager->GetFigCount(); i++)
			{
				CTriangle * PtrTriangle = dynamic_cast <CTriangle*> (pManager->GetFigureAtIndex(i));
				if (PtrTriangle != NULL)
				{
					PtrTriangle->Save(outputfile);
				}
			}
			break;

		case rohmbus:
			for (int i = 0; i < pManager->GetFigCount(); i++)
			{
				CRhomb *PtrRohmbus = dynamic_cast <CRhomb*> (pManager->GetFigureAtIndex(i));
				if (PtrRohmbus != NULL)
				{
					PtrRohmbus->Save(outputfile);
				}
			}
			break;

		}

	}
	
	//closing file 
	outputfile.close();
}