#include "CTriangle.h"
#include "../Actions/SaveByTypeAction.h"
#include <fstream>
#include <iostream>

CTriangle::CTriangle(Point P1, Point P2, Point P3,GfxInfo FigureGfxInfo) 
	:CFigure(FigureGfxInfo), TypeID(2)
{
	Point1 = P1;
	Point2 = P2;
	Point3 = P3;
}

int CTriangle::GetTypeID()	const
{
	return TypeID;
}
CFigure * CTriangle::GetCopyAtPoint(Point P) const {
	Point P2;
	Point P3;
	P2.x = P.x + (Point2.x - Point1.x);
	P2.y = P.y + (Point2.y - Point1.y);
	P3.x = P.x + (Point3.x - Point1.x);
	P3.y = P.y + (Point3.y - Point1.y);
	CTriangle *TRI = new CTriangle(P, P2, P3, FigGfxInfo);
	return TRI;
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a Triangle on the screen	
	pOut->DrawTri(Point1, Point2, Point3, FigGfxInfo, Selected, Cutted);
}

bool CTriangle::PointInside(int px, int py) const
{
	//Making Three vectors to the three vertices
	Point v1, v2, v3;
	v1.x = px - Point1.x;
	v1.y = py - Point1.y;
	v2.x = px - Point2.x;
	v2.y = py - Point2.y;
	v3.x = px - Point3.x;
	v3.y = py - Point3.y;
	double ang = 0;
	//Calculating angle between v1, v2 by dot product.
	ang += abs(acos((v1.x*v2.x + v1.y * v2.y) / (sqrt(pow(v1.x, 2) + pow(v1.y, 2)) * sqrt(pow(v2.x, 2) + pow(v2.y, 2)))));
	//Calculating angle between v1, v3.
	ang += abs(acos((v1.x*v3.x + v1.y * v3.y) / (sqrt(pow(v1.x, 2) + pow(v1.y, 2)) * sqrt(pow(v3.x, 2) + pow(v3.y, 2)))));
	//Calculating angle between v2, v3.
	ang += abs(acos((v3.x*v2.x + v3.y * v2.y) / (sqrt(pow(v3.x, 2) + pow(v3.y, 2)) * sqrt(pow(v2.x, 2) + pow(v2.y, 2)))));
	//If the angle is nearly 2PI, then point lies inside polygon.
	if (abs(ang - (2 * PI)) <= 0.1)
		return true;
	return false;
}

void CTriangle::HalfSize()
{
	Point CP;
	CP.x = abs(Point1.x + Point2.x) / 2;
	CP.y = abs(Point1.x + Point2.y) / 2;
	Point Centeroid;
	Centeroid.x = Point3.x + K * (CP.x - Point3.x);
	Centeroid.y = Point3.y + K * (CP.y - Point3.y);
	Point1.x = abs(Centeroid.x + Point1.x) / 2;
	Point1.y = abs(Centeroid.y + Point1.y) / 2;
	Point2.x = abs(Centeroid.x + Point2.x) / 2;
	Point2.y = abs(Centeroid.y + Point2.y) / 2;
	Point3.x = abs(Centeroid.x + Point3.x) / 2;
	Point3.y = abs(Centeroid.y + Point3.y) / 2;

}

void CTriangle::QuadrupleSize()
{
	Point CP;
	CP.x = abs(Point1.x + Point2.x) / 2;
	CP.y = abs(Point1.x + Point2.y) / 2;
	Point Centeroid;
	Centeroid.x = Point3.x + K * (CP.x - Point3.x);
	Centeroid.y = Point3.y + K * (CP.y - Point3.y);
	Point1.x = abs(Centeroid.x + Point1.x) * 4;
	Point1.y = abs(Centeroid.y + Point1.y) * 4;
	Point2.x = abs(Centeroid.x + Point2.x) * 4;
	Point2.y = abs(Centeroid.y + Point2.y) * 4;
	Point3.x = abs(Centeroid.x + Point3.x) * 4;
	Point3.y = abs(Centeroid.y + Point3.y) * 4;

}

void CTriangle::DoubleSize()
{
	Point CP;
	CP.x = abs(Point1.x + Point2.x) / 2;
	CP.y = abs(Point1.x + Point2.y) / 2;
	Point Centeroid;
	Centeroid.x = Point3.x + K * (CP.x - Point3.x);
	Centeroid.y = Point3.y + K * (CP.y - Point3.y);
	Point1.x = abs(Centeroid.x + Point1.x) * 2;
	Point1.y = abs(Centeroid.y + Point1.y) * 2;
	Point2.x = abs(Centeroid.x + Point2.x) * 2;
	Point2.y = abs(Centeroid.y + Point2.y) * 2;
	Point3.x = abs(Centeroid.x + Point3.x) * 2;
	Point3.y = abs(Centeroid.y + Point3.y) * 2;



}

void CTriangle::QuarterSize()
{
	Point CP;
	CP.x = abs(Point1.x + Point2.x) / 2;
	CP.y = abs(Point1.x + Point2.y) / 2;
	Point Centeroid;
	Centeroid.x = Point3.x + K * (CP.x - Point3.x);
	Centeroid.y = Point3.y + K * (CP.y - Point3.y);
	Point1.x = abs(Centeroid.x + Point1.x) / 4;
	Point1.y = abs(Centeroid.y + Point1.y) / 4;
	Point2.x = abs(Centeroid.x + Point2.x) / 4;
	Point2.y = abs(Centeroid.y + Point2.y) / 4;
	Point3.x = abs(Centeroid.x + Point3.x) / 4;
	Point3.y = abs(Centeroid.y + Point3.y) / 4;



}


void CTriangle::Save(ofstream &OutFile)
{
	//printing eneral information
	OutFile << "TRIANGLE	" << ID << "	" << Point1.x << "	" << Point1.y << "	" << Point2.x << "	" << Point2.y;
	OutFile << "	" << Point3.x << "	" << Point3.y;

	//saving colors
	OutFile << SaveByType::ConvertColor(FigGfxInfo.DrawClr);
	OutFile << "	";

	if (FigGfxInfo.isFilled)
		OutFile << SaveByType::ConvertColor(FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NO_FILL" << "\n";
}

void CTriangle::Load(ifstream &Infile)
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

	Infile >> x >> y;
	Point3.x = x;
	Point3.y = y;

	//readig colors
	string color_s;
	color Drwcolor;
	Infile >> color_s;
	Drwcolor = SaveByType::ConvertStringToColor(color_s);
	FigGfxInfo.DrawClr = Drwcolor;

	color Fillcolor;
	Infile >> color_s;
	if (color_s == "NO_FILL")
	{
		FigGfxInfo.isFilled = 0;
	}
	else
	{
		FigGfxInfo.isFilled = 1;
		Fillcolor = SaveByType::ConvertStringToColor(color_s);
		FigGfxInfo.FillClr = Fillcolor;
	}


}

void CTriangle::PrintInfo(Output* pOut) 	//print all figure info on the status bar
{
	string message = "Figure type : Triangle, Figure ID : " + to_string(ID) + " Point 1 : (" + to_string(Point1.x) + "," + to_string(Point1.y) + "), Point 2 : (" + to_string(Point2.x) + ", " + to_string(Point2.y) + "), Point 3 : (" + to_string(Point1.x) + "," + to_string(Point1.y)+ ")";
	pOut->PrintMessage(message);
}