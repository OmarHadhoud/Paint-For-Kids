#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddEllipseAction.h"
#include "Actions\AddRhombAction.h"
#include "Actions\SelectFigureAction.h"
#include "Actions\CopyFigureAction.h"
#include "Actions\CutFigureAction.h"
#include "Actions\DeleteFigureAction.h"
#include "Actions\SaveByTypeAction.h"
#include "Actions\SaveGraphAction.h"
#include "Actions\LoadGraphAction.h"
#include "Actions\ChangeDrawColorAction.h"
#include "Actions\ChangeFillColorAction.h"
#include "Actions\PickByColorAction.h"
#include "Actions\PickByTypeAction.h"
#include "Actions\PasteFigureAction.h"
#include "Actions\SwitchToPlayAction.h"
#include "Actions\SwitchToDrawAction.h"
#include <chrono>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	isFilled = false;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	

	//Making pointers point to NULL initially.
	SelectedFig = NULL;
	Clipboard = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriangleAction(this);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhombAction(this);
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);
			break;

		case SELECT_FIG:
			pAct = new SelectFigureAction(this);
			break;

		case CHNG_DRAW_CLR:
			pOut->PrintMessage("Please Select new Drawing Color");
			pAct = new ChangeDrawColorAction(this);
			break;

		case CHNG_FILL_CLR:
			pOut->PrintMessage("Please Select new Filling Color");
			pAct = new ChangeFillColorAction(this);
			break;

		case COPY:
			pAct = new CopyFigureAction(this);
			break;

		case PASTE:
			pAct = new PasteFigureAction(this);
			break;

		case CUT:
			pAct = new CutFigureAction(this);
			break;

		case DEL:
			pAct = new DeleteFigureAction(this);
			break;

		case SAVE:
			pAct = new SaveGraphAction(this);
			break;

		case SAVE_BY_TYPE:
			pAct = new SaveByType(this);
			break;

		case LOAD:
			pAct = new LoadGraphAction(this);
			break;


		case TO_PLAY:
			pAct = new SwitchToPlayAction(this);
			break;

		case HALFSIZE:
		{	
			if (!SelectedFig)	// not selected
			{
				pOut->PrintMessage("Error, Please select a figure first.");
			}
			else
			{
				SelectedFig->HalfSize();
			}
			break;
		}
		case QUADRUPLESIZE:
		{
			if (!SelectedFig)	// not selected
			{
				pOut->PrintMessage("Error, Please select a figure first.");
			}
			else
			{
				SelectedFig->QuadrupleSize();

			}
			break;
		}
		case DOUBLESIZE:
		{
			if (!SelectedFig)	// not selected
			{
				pOut->PrintMessage("Error, Please select a figure first.");
			}
			else
			{
				SelectedFig->DoubleSize();

			}
			break;
		}
		case QUARTERSIZE:
		{
			if (!SelectedFig)	// not selected
			{
				pOut->PrintMessage("Error, Please select a figure first.");
			}
			else
			{
				SelectedFig->QuarterSize();
			}
			
			break;
		}
		//Play mode 
		case TO_DRAW:
			pAct = new SwitchToDrawAction(this);
			break;

		case FIG_FILL_COLOUR:
			pOut->PrintMessage("Pick by Color Game.");
			_sleep(2000);
			pAct = new PickByColorAction(this);
			break;

		case FIG_TYPE:
			pOut->PrintMessage("Pick by Type Game.");
			_sleep(2000);
			pAct = new PickByTypeAction(this);
			break;

		case EXIT:
			pOut->PrintMessage("Exiting program...");
			_sleep(1000);
			//Clean up is already done in destructor of app manager.
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
	pFig->SetID(FigCount);
}

int ApplicationManager::GetFigCount()	const
{
	return FigCount;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	
	//Looping through the figures list
	for (int i = FigCount-1; i >= 0; i--)
	{
		if (FigList[i]->PointInside(x, y)) //If point lies on the figure, return pointer to the figure
		{
			return FigList[i];
		}
	}


	return NULL;
}


CFigure * ApplicationManager::GetFigureAtIndex(int i) const
{
	if (i <= FigCount)
		return FigList[i];

	return NULL;
}

 CFigure * ApplicationManager::GetSelected() const
{
	return SelectedFig;
}
 CFigure * ApplicationManager::GetClipboard() const
 {
	 return Clipboard;
 }
 bool ApplicationManager::GetIsFilled() const
 {
	 return isFilled;
 }

 void ApplicationManager::SetIsFilled(bool b)
 {
	 isFilled = b;
 }

//A function to change the Application manager selected figure.
void ApplicationManager::ChangeSelected(CFigure* newSelected)
{
	
		//If a selected figure exists, and the user isn't selecting the same figure selected.
		if(SelectedFig != NULL && SelectedFig != newSelected)
			SelectedFig->SetSelected(false);
		SelectedFig = newSelected;
		if (SelectedFig != NULL) //If user selected a figure, print its info.
			SelectedFig->PrintInfo(pOut);
}

void ApplicationManager::SaveAll(ofstream &outputfile)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(outputfile);
	}
}

//A function to change the Application manager selected figure.
void ApplicationManager::ChangeClipboard(CFigure* newClipboard , bool cut)
{
	if (Clipboard)					 // if there is a figure in the clipboard
		Clipboard->SetCutted(false); //sets the last clipboard figure's bool "isCutted" to false
	Clipboard = newClipboard;		 //stores a pointer to the selected figure in the clipboard	
	if (Clipboard)
		Clipboard->SetCutted(cut);	 //sets the figure's bool "isCutted" to "cut" value
	isCut = cut;					 //changes the bool representing the clipboard operation
}

bool ApplicationManager::GetIsCut()    const {
	return isCut;
}

//delete a figure from the list of figures
void ApplicationManager::DeleteFigure(CFigure* pFig) {
	int idx =pFig->GetID()-1;
	delete FigList[idx];
	for (int i = idx; i < FigCount-1; i++)
	{
		FigList[i] = FigList[i+1];
		FigList[i]->SetID(i+1);
	}
	FigCount--;
}


void ApplicationManager::DeleteAll()
{
	for (int i = 0; i < FigCount; i++)
	{
		DeleteFigure(FigList[i]);

	}

	FigCount = 0;

}

//Checks if the Generated figure inside pick and hide is logical or not
bool ApplicationManager::IsRandFigInList(int GeneratedFig)	const
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetTypeID() == GeneratedFig)
			return true;
	}
		return false;
}
//Returns Count of Figures of the Same Type as Generated in Pick by Type
int ApplicationManager::GetCountFoundFig(int GeneratedFig)	const
{
	int CountFound = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetTypeID() == GeneratedFig)
			CountFound++;
	}
	return CountFound;
}

bool ApplicationManager::IsAnyFigureFilled() const
{

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsFilled())
			return true;
	}
	return false;
}
//Checks if the generated color inside pick and hide is logical or not
bool ApplicationManager::IsRandColorInList(color GeneratedColor)	const
{
	
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetFillClr() == GeneratedColor && FigList[i]->IsFilled())
			return true;
	}
	return false;
}
//Returns Count of Figures Having Same Color as That Generated by Pick by Color
int ApplicationManager::GetCounfFoundColor(color GeneratedColor)			const
{
	int CountFound = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if ((FigList[i]->GetFillClr() == GeneratedColor && FigList[i]->GetTypeID() != 5) || (FigList[i]->GetDrawClr() == GeneratedColor && FigList[i]->GetID() == 5))
			CountFound++;
	}
	return CountFound;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if (!FigList[i]->IsHidden())
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }

//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }




////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
