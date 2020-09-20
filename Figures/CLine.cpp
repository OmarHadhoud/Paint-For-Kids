#include "CLine.h"
#include "../Actions/SaveByTypeAction.h"
#include <fstream>

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) 
	:CFigure(FigureGfxInfo), TypeID(5)
{
	Point1 = P1;
	Point2 = P2;
}

int CLine::GetTypeID()	const
{
	return TypeID;
}
CFigure * CLine::GetCopyAtPoint(Point P) const {
	Point P2;
	P2.x = P.x + (Point2.x - Point1.x);
	P2.y = P.y + (Point2.y - Point1.y);
	CLine *L = new CLine(P, P2, FigGfxInfo);
	return L;
}
void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a linee on the screen	
	pOut->DrawLine(Point1, Point2, FigGfxInfo, Selected, Cutted);
}

bool CLine::PointInside(int px, int py) const
{
	//Making Two vectors to the starting and ending points
	Point v1, v2;
	v1.x = px - Point1.x;
	v1.y = py - Point1.y;
	v2.x = px - Point2.x;
	v2.y = py - Point2.y;
	double ang = 0;
	//Calculating angle between v1, v2 by dot product.
	ang += abs(acos((v1.x*v2.x + v1.y * v2.y) / (sqrt(pow(v1.x, 2) + pow(v1.y, 2)) * sqrt(pow(v2.x, 2) + pow(v2.y, 2)))));
	//If the angle is nearly PI, then point lies on line.
	if (abs(ang - (1 * PI)) <= 0.1)
		return true;
	return false;
}
Point CLine::GetUpper()const {
	if (Point1.y < Point2.y)
	{
		return Point1;
	}
	return Point2;
}
void CLine::HalfSize()
{
	Point1.x = (Point1.x + Point2.x) / 2;
	Point1.y = (Point1.y + Point2.y) / 2;
}

void CLine::QuadrupleSize()
{
	Point1.x = (Point1.x + Point2.x) * 4;
	Point1.y = (Point1.y + Point2.y) * 4;
}

void CLine::DoubleSize()
{
	Point1.x = (Point1.x + Point2.x) * 2;
	Point1.y = (Point1.y + Point2.y) * 2;
}

void CLine::QuarterSize()
{
	Point1.x = (Point1.x + Point2.x) / 4;
	Point1.y = (Point1.y + Point2.y) / 4;

}


void CLine::Save(ofstream &OutFile)
{
	//saving general Info
	OutFile << "LINE	" << ID << "	" << Point1.x << "	" << Point1.y << "	" << Point2.x << "	" << Point2.y;

	//saving color
	OutFile << SaveByType::ConvertColor(FigGfxInfo.DrawClr);
	OutFile << "\n";

}

void CLine::Load(ifstream &Infile)
{
	//reading ID
	int id;
	Infile >> id;

	//reading points
	int x;
	int y;
	Infile >> x >> y;
	Point1.x = x;
	Point1.y = y;

	Infile >> x >> y;
	Point2.x = x;
	Point2.y = y;

	//readig color
	string color_s;
	color Drwcolor;
	Infile >> color_s;
	Drwcolor = SaveByType::ConvertStringToColor(color_s);
	FigGfxInfo.DrawClr = Drwcolor;
	FigGfxInfo.isFilled = false;
}

void CLine::PrintInfo(Output* pOut) 	//print all figure info on the status bar
{
	string message = "Figure type : Line, Figure ID : " + to_string(ID) + " ,Starting point: " + to_string(Point1.x) + ", " + to_string(Point1.y) + ") ,Ending point: (" + to_string(Point2.x) + ", " + to_string(Point2.y) + ")";
	pOut->PrintMessage(message);
}