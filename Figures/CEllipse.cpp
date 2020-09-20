#include "CEllipse.h"
#include "../ApplicationManager.h"
#include <fstream>
#include <iostream>
#include "../Actions/SaveByTypeAction.h"
CEllipse::CEllipse(Point P,GfxInfo FigureGfxInfo) 
	:CFigure(FigureGfxInfo), TypeID(4)
{
	 NewEllipseSize = EllipseSize;
	Center = P;
}

int CEllipse::GetTypeID()	const
{
	return TypeID;
}
CFigure * CEllipse::GetCopyAtPoint(Point P) const {
	CEllipse *ELL = new CEllipse(P, FigGfxInfo);
	return ELL;
}

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw an Ellipse on the screen	
	pOut->DrawEllipse(Center, FigGfxInfo,NewEllipseSize, Selected , Cutted);
}

bool CEllipse::PointInside(int px, int py) const
{
	int dis = pow((px - Center.x), 2) + pow((py - Center.y), 2);
	if (dis <= pow(NewEllipseSize, 2))
		return true;
	return false;
}

void CEllipse::HalfSize()
{
	NewEllipseSize = NewEllipseSize / 2;

}

void CEllipse::QuadrupleSize()
{
	NewEllipseSize = NewEllipseSize * 4;
}

void CEllipse::DoubleSize()
{
	NewEllipseSize = NewEllipseSize * 2;
}

void CEllipse::QuarterSize()
{
	NewEllipseSize = NewEllipseSize / 4;
}



void CEllipse::Save(ofstream &OutFile)
{
	//saving general info
	OutFile << "ELLIPSE	" << ID << "	" << Center.x << "	" << Center.y;

	//saving colors
	OutFile << SaveByType::ConvertColor(FigGfxInfo.DrawClr);
	OutFile << "	";

	if (FigGfxInfo.isFilled)
		OutFile << SaveByType::ConvertColor(FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NO_FILL" << "\n";
}

void CEllipse::Load(ifstream &Infile)
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

void CEllipse::PrintInfo(Output* pOut) 	//print all figure info on the status bar
{
	string message = "Figure type : Ellipse, Figure ID : " + to_string(ID) + " ,Center : (" + to_string(Center.x) + ", " + to_string(Center.y) + ")";
	pOut->PrintMessage(message);
}