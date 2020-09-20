#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	const int TypeID;
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool PointInside(int px, int py) const;
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
	virtual int GetTypeID()	const;
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	virtual CFigure * GetCopyAtPoint(Point P) const;
	//Resize functions:
	virtual void HalfSize();
	virtual void QuadrupleSize();
	virtual void DoubleSize();
	virtual void QuarterSize();
};

#endif