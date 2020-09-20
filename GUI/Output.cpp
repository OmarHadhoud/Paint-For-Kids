#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 47; // was 59 for 22 icons

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.CutFigureColor = GREY;		//This color is for cutted figures only --added
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


						//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];

	//The following icons are for shapes:
	MenuItemImages[ITM_SELECTFIG] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect2.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_Rhombus.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circle.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";


	//The following are for colors:

	MenuItemImages[ITM_CHANGE_FIG_COLOR] = "images\\MenuItems\\Menu_FigFillColor.jpg";
	MenuItemImages[ITM_CHANGE_DRW_COLOR] = "images\\MenuItems\\Menu_DrawColor.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\Menu_White.jpg";

	//The Following are for resize:

	MenuItemImages[ITM_DoubleSize] = "images\\MenuItems\\Menu_DoubleSize.jpg";
	MenuItemImages[ITM_QuadrupleSize] = "images\\MenuItems\\Menu_QuadrupleSize.jpg";
	MenuItemImages[ITM_HalfSize] = "images\\MenuItems\\Menu_HalfSize.jpg";
	MenuItemImages[ITM_QuarterSize] = "images\\MenuItems\\Menu_QuarterSize.jpg";

	//The following items are for various functions:
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_SWITCHTOPLAY] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_SAVE_GRAPH] = "images\\MenuItems\\Menu_SaveGraph.jpg";
	MenuItemImages[ITM_SAVE_BY_TYPE] = "images\\MenuItems\\Menu_SaveType.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	ClearToolBar();
	//Draw menu item one image at a time
	for (int i = 0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_FIGURE_TYPE] = "images\\MenuItems\\Figure_Type.jpeg";
	MenuItemImages[ITM_FIGURE_FILL_COLOUR] = "images\\MenuItems\\Figure_Fill_Colour.jpeg";
	MenuItemImages[ITM_SWITCH_TO_DRAW_MODE] = "images\\MenuItems\\Switch_To_Draw_Mode.jpeg";
	MenuItemImages[ITM_EXIT_P] = "images\\MenuItems\\Menu_Exit.jpg";

	ClearToolBar();
	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const //used to clear the old toolbar before drawing the new one
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::SetCrntDrawColor(color newDrawColor)
{
	UI.DrawColor = newDrawColor;
}

void Output::SetCrntFillColor(color newFillColor)
{
	UI.FillColor = newFillColor;
}
color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected, bool cutted) const
{
		color DrawingClr;
		if (cutted)
			DrawingClr = UI.CutFigureColor;
		else if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, 1);
		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			if (cutted)
			{
				pWind->SetBrush(UI.CutFigureColor);
			}
			else {
				pWind->SetBrush(RectGfxInfo.FillClr);
			}
		}
		else
			style = FRAME;


		pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawLine(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected, bool cutted) const
{
		color DrawingClr;
		if (cutted)
			DrawingClr = UI.CutFigureColor;
		else if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, 1);
		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			if (cutted)
			{
				pWind->SetBrush(UI.CutFigureColor);
			}
			else {
				pWind->SetBrush(RectGfxInfo.FillClr);
			}
		}
		else
			style = FRAME;


		pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected, bool cutted) const
{
		color DrawingClr;
		if (cutted)
			DrawingClr = UI.CutFigureColor;
		else if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, 1);
		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			if (cutted)
			{
				pWind->SetBrush(UI.CutFigureColor);
			}
			else {
				pWind->SetBrush(RectGfxInfo.FillClr);
			}
		}
		else
			style = FRAME;


		pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawRhom(Point P1, GfxInfo RectGfxInfo,int Size1,int Size2, bool selected, bool cutted) const
{
		color DrawingClr;
		if (cutted)
			DrawingClr = UI.CutFigureColor;
		else if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, 1);
		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			if (cutted)
			{
				pWind->SetBrush(UI.CutFigureColor);
			}
			else {
				pWind->SetBrush(RectGfxInfo.FillClr);
			}
		}
		else
			style = FRAME;

		int xS[4];
		int yS[4];
		xS[0] = P1.x - Size1, yS[0] = P1.y, xS[1] = P1.x, yS[1] = P1.y + Size2, xS[2] = P1.x +Size1, yS[2] = P1.y, xS[3] = P1.x, yS[3] = P1.y - Size2;
		pWind->DrawPolygon(xS, yS, 4, style);
}

void Output::DrawEllipse(Point P1, GfxInfo RectGfxInfo,int size, bool selected , bool cutted ) const
{
		color DrawingClr;
		if (cutted)
			DrawingClr = UI.CutFigureColor;
		else if (selected)
			DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, 1);
		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			if (cutted)
			{
				pWind->SetBrush(UI.CutFigureColor);
			}
			else {
				pWind->SetBrush(RectGfxInfo.FillClr);
			}
		}
		else
			style = FRAME;


		pWind->DrawCircle(P1.x, P1.y, size, style);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

