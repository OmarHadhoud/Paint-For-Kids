#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	int NewEllipseSize;
	const int TypeID;
	Point Center;
public:
	CEllipse(Point,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool PointInside(int px, int py) const;
	virtual void PrintInfo(Output* pOut) ;	//print all figure info on the status bar
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