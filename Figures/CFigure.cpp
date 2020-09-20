#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
	:TypeID(0)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Cutted = false;
	Hidden = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

void CFigure::SetCutted(bool c)
{
	Cutted = c;
}

bool CFigure::IsFilled() const
{
	return FigGfxInfo.isFilled;
}
bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::SetID(int id_)
{
	ID = id_;
}
int  CFigure::GetID() const {
	return ID;
}
void CFigure::HalfSize()
{}

void CFigure::QuadrupleSize()
{}

void CFigure::DoubleSize()
{}

void CFigure::QuarterSize()
{}

color CFigure::GetFillClr()	const
{
	return FigGfxInfo.FillClr;
}

color CFigure::GetDrawClr() const
{
	return FigGfxInfo.DrawClr;
}
void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

//Used in Pick and Hide
void CFigure::SetHidden(bool h)
{
	Hidden = h;
}
//Used in Updating Interface 
bool CFigure::IsHidden()	const
{
	return Hidden;
}

