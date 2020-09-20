#include "CRhomb.h"
#include "../ApplicationManager.h"
#include <fstream>
#include <iostream>
#include "../Actions/SaveByTypeAction.h"

CRhomb::CRhomb(Point P, GfxInfo FigureGfxInfo) 
	:CFigure(FigureGfxInfo), TypeID(3)
{
	RhombsSize1 = RhombSize1;
	RhombsSize2 = RhombSize2;
	Center = P;
}

CFigure * CRhomb::GetCopyAtPoint(Point P) const {
	CRhomb *RHMB = new CRhomb(P, FigGfxInfo);
	return RHMB;
}

int CRhomb::GetTypeID()	const
{
	return TypeID;
}

void CRhomb::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a Rhombus on the screen	
	pOut->DrawRhom(Center, FigGfxInfo, RhombsSize1, RhombsSize2, Selected, Cutted);
}

bool CRhomb::PointInside(int px, int py) const
{
	//Making four vectors to the four vertices
	Point v1, v2, v3, v4;
	v1.x = px - (Center.x - RhombsSize1);
	v1.y = py - Center.y;
	v2.x = px - (Center.x + RhombsSize1) ;
	v2.y = py - Center.y;
	v3.x = px - Center.x;
	v3.y = py - (Center.y + RhombsSize2);
	v4.x = px - Center.x;
	v4.y = py - (Center.y - RhombsSize2);
	double ang = 0;
	//Calculating angle between v1, v3 by dot product.
	ang += abs(acos((v1.x*v3.x + v1.y * v3.y) / (sqrt(pow(v1.x, 2) + pow(v1.y, 2)) * sqrt(pow(v3.x, 2) + pow(v3.y, 2)))));
	//Calculating angle between v2, v3.
	ang += abs(acos((v3.x*v2.x + v3.y * v2.y) / (sqrt(pow(v3.x, 2) + pow(v3.y, 2)) * sqrt(pow(v2.x, 2) + pow(v2.y, 2)))));
	//Calculating angle between v2, v4.
	ang += abs(acos((v4.x*v2.x + v4.y * v2.y) / (sqrt(pow(v4.x, 2) + pow(v4.y, 2)) * sqrt(pow(v2.x, 2) + pow(v2.y, 2)))));
	//Calculating angle between v1, v4.
	ang += abs(acos((v1.x*v4.x + v1.y * v4.y) / (sqrt(pow(v1.x, 2) + pow(v1.y, 2)) * sqrt(pow(v4.x, 2) + pow(v4.y, 2)))));
	//If the angle is nearly 2PI, then point lies inside polygon.
	if (abs(ang - (2 * PI)) <= 0.1)
		return true;
	return false;
}

void CRhomb::HalfSize()
{
	RhombsSize1 = RhombsSize1 / 2;
	RhombsSize2 = RhombsSize2 / 2;
}

void CRhomb::QuadrupleSize()
{
	RhombsSize1 = RhombsSize1 * 4;
	RhombsSize2 = RhombsSize2 * 4;
}

void CRhomb::DoubleSize()
{
	RhombsSize1 = RhombsSize1 * 2;
	RhombsSize2 = RhombsSize2 * 2;
}

void CRhomb::QuarterSize()
{
	RhombsSize1 = RhombsSize1 / 4;
	RhombsSize2 = RhombsSize2 / 4;
}


void CRhomb::Save(ofstream &OutFile)
{
	//saving General Info
	OutFile << "RHOMBUS	" << ID << "	" << Center.x << "	" << Center.y;

	//saving colors
	OutFile << SaveByType::ConvertColor(FigGfxInfo.DrawClr);
	OutFile << "	";

	if (FigGfxInfo.isFilled)
		OutFile << SaveByType::ConvertColor(FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NO_FILL" << "\n";
}

void CRhomb::Load(ifstream &Infile)
{
	//reading ID
	int id;
	Infile >> id;

	//reading points
	int x;
	int y;
	Infile >> x >> y;
	Center.x = x;
	Center.y = y;

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

void CRhomb::PrintInfo(Output* pOut) 	//print all figure info on the status bar
{
	string message = "Figure type : Rhombus, Figure ID : " + to_string(ID) + " ,Center : (" + to_string(Center.x) + ", " + to_string(Center.y) + ")";
	pOut->PrintMessage(message);
}