#include "CRectangle.h"
#include <fstream>
#include "../Actions/SaveByTypeAction.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) 
	:CFigure(FigureGfxInfo), TypeID(1)
{
	Corner1 = P1;
	Corner2 = P2;
}

int CRectangle::GetTypeID()	const
{
	return TypeID;
}
CFigure * CRectangle::GetCopyAtPoint(Point P) const {
	Point P2;
	P2.x = P.x + (Corner2.x - Corner1.x);
	P2.y = P.y + (Corner2.y - Corner1.y);
	CRectangle *R = new CRectangle(P, P2, FigGfxInfo);
	return R;
}
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected, Cutted);
}

bool CRectangle::PointInside(int px, int py) const
{
	if ((px >= Corner1.x && px <= Corner2.x) || (px <= Corner1.x && px >= Corner2.x))
	{
		if ((py >= Corner1.y && py <= Corner2.y) || (py <= Corner1.y && py >= Corner2.y))
		{
			return true;
		}
	}
	return false;
}

void CRectangle::HalfSize()
{
	int pp = (Corner1.x + Corner2.x);
	Corner1.x = pp / 2;
	Corner1.y = (Corner1.y + Corner2.y) / 2;
}

void CRectangle::QuadrupleSize()
{
	Corner1.x = (Corner1.x + Corner2.x) * 4;
	Corner1.y = (Corner1.y + Corner2.y) * 4;
}

void CRectangle::DoubleSize()
{
	Corner1.x = (Corner1.x + Corner2.x) * 2;
	Corner1.y = (Corner1.y + Corner2.y) * 2;
}

void CRectangle::QuarterSize()
{
	Corner1.x = (Corner1.x + Corner2.x) / 4;
	Corner1.y = (Corner1.y + Corner2.y) / 4;
}


void CRectangle::Save(ofstream &OutFile)
{
	OutFile << "RECTANGLE	" << ID << "	" << Corner1.x << "	" << Corner1.y << "	" << Corner2.x << "	" << Corner2.y;


	OutFile << SaveByType::ConvertColor(FigGfxInfo.DrawClr);
	OutFile << "	";


	if (FigGfxInfo.isFilled)
		OutFile << SaveByType::ConvertColor(FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NO_FILL" << "\n";
}

void CRectangle::Load(ifstream &Infile)
{
	//reading ID
	int id;
	Infile >> id;

	//reading points
	int x;
	int y;
	Infile >> x >> y;
	Corner1.x = x;
	Corner1.y = y;

	Infile >> x >> y;
	Corner2.x = x;
	Corner2.y = y;

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

void CRectangle::PrintInfo(Output* pOut) 	//print all figure info on the status bar
{
	string message = "Figure type : Rectangle, Figure ID : " + to_string(ID) + " ,Length : " + to_string(abs(Corner1.x - Corner2.x)) + ", Width : " + to_string(abs(Corner1.x - Corner2.y)) + ", Center point : (" + to_string((Corner1.x + Corner2.x) / 2) + "," + to_string((Corner1.y+Corner2.y)/2) + ")";
	pOut->PrintMessage(message);
}