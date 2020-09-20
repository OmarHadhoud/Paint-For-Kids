#ifndef PICKBYTYPE_H
#define PICKBYTYPE_H

#include "Action.h" 
#include "../Figures/CFigure.h"
#include <vector>

class PickByTypeAction : public Action
{
private:
	int CorrectCount;		//Count of Correct Picks
	int RealCorrectCount;	//number of valid answers
	int IncorrectCount;		//Count of Incorrect Picks

	int GeneratedTypeNum;	//To Recieve the Generated Index Corresponding to the Figure Type Enum

	/*enum FigType
	{
		TYPE_RECT,
		TYPE_ELLIPSE,
		TYPE_LINE,
		TYPE_RHOMBUS,
		TYPE_TRIANGLE,

		TYPE_COUNT
	};
	*/

	CFigure * SelectedFiguresList[200];		//This Array Hides the Selected Figures

	int HiddenIndex;

	int PickingFigure;				        //Figure to be Picked According to its ID

	CFigure * SelectedFig;					//The Figure Selected by the User

	bool anyFigFound;						//Boolean to store if at least one figure is found.
	vector<int> existingFigures;			//Vector of existing figures.

public:
	PickByTypeAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~PickByTypeAction();


};


#endif // !PICKBYTYPE_H