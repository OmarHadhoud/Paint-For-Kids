#ifndef PICKBYCOLOR_H
#define PICKBYCOLOR_H

#include "Action.h"
#include "../Figures/CFigure.h"
#include <vector>

class PickByColorAction : public Action
{
private:
	int CorrectCount;		//Count of Correct Selections
	int RealCorrectCount;	//number of valid answers
	int IncorrectCount;		//Count of Incorrect Selections

	int countFound;			//How Many of the randomly Generated Entity Exist

	int GeneratedColorNum;	//The Randomly Generated Color Number Inside The Following Enum 

	enum ColorType			//To be Used in the Random Generator 
	{
		COLOR_BLACK,
		COLOR_WHITE,
		COLOR_BLUE,
		COLOR_RED,
		COLOR_GREEN,
		COLOR_COUNT
	};

	color PickingColor;					//The Color To be Picked 
	
	CFigure * SelectedFigList[200];		//This Array Hides the Selected Figures

	int HiddenIndex;					

	CFigure * SelectedFig;				//Pointer to the selected figure

	bool oneFilled;						//Boolean to store if at least one figure is filled.

	vector<int> existingColors;			//Vector to store the existing colors.
public:
	PickByColorAction(ApplicationManager * pApp);

	void ReadActionParameters();

	void Execute();

	~PickByColorAction();
};
#endif // !PICKBYCOLOR_H



