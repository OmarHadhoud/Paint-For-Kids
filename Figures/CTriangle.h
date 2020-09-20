#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#define K 2/3 
#include "CFigure.h"
class CTriangle : public CFigure
{
private:
	const int TypeID;
	Point Point1;
	Point Point2;
	Point Point3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
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