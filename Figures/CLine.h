#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	const int TypeID;
	Point Point1;
	Point Point2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool PointInside(int px, int py) const;
	virtual void PrintInfo(Output* pOut) ;	//print all figure info on the status bar
	virtual int GetTypeID()	const;
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	Point GetUpper()const; // not used added by f
	virtual CFigure * GetCopyAtPoint(Point P) const;
	//Resize functions:
	virtual void HalfSize();
	virtual void QuadrupleSize();
	virtual void DoubleSize();
	virtual void QuarterSize();
};

#endif