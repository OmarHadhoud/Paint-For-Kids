#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };			//Max no of figures

private:
	int FigCount;		                //Actual number of figures
	CFigure* FigList[MaxFigCount+1];	//List of all figures (Array of pointers)

	CFigure* SelectedFig;				//Pointer to the selected figure
	CFigure* Clipboard;					//Pointer to the copied/cut figure
	bool isCut;							//true if the file in the clipboard should be cut
	bool isFilled;						//If the shape should be filled or not.

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ;			//Creates an action and executes it
	void SaveAll(ofstream &outputfile);								//Calls save function for all figures.

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);								//Adds a new figure to the FigList
	int GetFigCount()						const;				//Returns Count of Figures in List
	bool GetIsCut()    const;									//returns true if last operation was cut

	bool GetIsFilled()						const;				//Return true if should be filled.
	CFigure *GetFigure(int x, int y)		const;				//Search for a figure given a point inside the figure
	CFigure *GetFigureAtIndex(int i) const;						//returns figure in Fig list
	CFigure *GetClipboard()					const;				//returns the clipboard	
	CFigure *GetSelected()					const;				//returns the selected figure
	void ChangeSelected(CFigure* NewSelected);					//Change the pointer to the selected figure
	void ChangeClipboard(CFigure* NewClipboard , bool cut);		//Change the pointer to the selected figure
	void SetIsFilled(bool b);									//Change the fill status for next figures.
	void DeleteFigure(CFigure* pFig);
	void DeleteAll();	
	int GetCountFoundFig(int GeneratedFig)			const;
	int GetCounfFoundColor(color GeneratedColor)	const;
	bool IsAnyFigureFilled() const;								//True if at least one shape is filled.
	bool IsRandFigInList(int)						const;		//True if the Randomly Generated Figure Exists in the List
	bool IsRandColorInList(color GeneratedColor)	const;		//True if the Randomly Generated Color Exists in the List
	// -- Interface Management Functions
	Input *GetInput()		const;				//Return pointer to the input
	Output *GetOutput()		const;				//Return pointer to the output
	void UpdateInterface()	const;				//Redraws all the drawing window	
	//Other functions
	
};

#endif