#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <cmath>

//Base class for all figures
class CFigure
{
protected:
	const int TypeID;	//Each Type of Figure has a Number;
	int ID;				//Each figure has an ID
	bool Selected;		//true if the figure is selected.
	bool Cutted;		//true if the figure is cutted. -- added
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool Hidden;		//True if the User Selects a Figure Inside Pick And Hide
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);		//select/unselect the figure
	void SetCutted(bool c);			//cut/uncut the figure

	bool IsSelected()	const;		//check whether fig is selected
	bool IsFilled() const;			//check wheter fig is filled or not.
	void SetID(int id);				//Set the id of the figure
	int GetID()			const;		//Get the id of the figure
	virtual int GetTypeID()		const = 0;
	color GetFillClr()	const;		//Get the Color of the Figure
	color CFigure::GetDrawClr() const;
	
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual CFigure * GetCopyAtPoint(Point P) const = 0;

	//Resize functions:
	virtual void HalfSize();
	virtual void QuadrupleSize();
	virtual void DoubleSize();
	virtual void QuarterSize();

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	virtual bool PointInside(int px, int py) const = 0 ; //A function to check if the point clicked by the user lies on the figure or not.

	virtual void SetHidden(bool h);	//Setter for the IsHidden Datamember 
	virtual bool IsHidden()	const;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif