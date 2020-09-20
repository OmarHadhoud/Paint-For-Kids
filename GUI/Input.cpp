#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				//selecting figures:
			case ITM_RECT:					return DRAW_RECT;		break;
			case ITM_TRIANGLE:				return DRAW_TRI;		break;
			case ITM_RHOMBUS:				return DRAW_RHOMBUS;	break;
			case ITM_CIRCLE:				return DRAW_ELLIPSE;	break;
			case ITM_LINE:					return DRAW_LINE;		break;

				//selecting colors:
			case ITM_SELECTFIG:				return SELECT_FIG;		break;
			case ITM_CHANGE_DRW_COLOR:		return CHNG_DRAW_CLR;	break;
			case ITM_CHANGE_FIG_COLOR:		return CHNG_FILL_CLR;	break;
			case ITM_BLUE:					return SEL_BLUE;		break;
			case ITM_RED:					return SEL_RED;			break;
			case ITM_BLACK:					return SEL_BLACK;		break;
			case ITM_GREEN:					return SEL_GREEN;		break;
			case ITM_WHITE:					return SEL_WHITE;		break;

				//Resize
			case ITM_HalfSize:				return HALFSIZE;		break;
			case ITM_DoubleSize:			return DOUBLESIZE; 		break;
			case ITM_QuadrupleSize:			return QUADRUPLESIZE;	break;
			case ITM_QuarterSize:			return QUARTERSIZE;		break;

				//functions:
			case ITM_COPY:					return COPY;			break;
			case ITM_CUT:					return CUT;				break;
			case ITM_PASTE:					return PASTE;			break;
			case ITM_DELETE:				return DEL;				break;
			case ITM_SAVE_BY_TYPE:			return SAVE_BY_TYPE;	break;
			case ITM_SAVE_GRAPH:			return SAVE;			break;
			case ITM_LOAD:					return LOAD;			break;
			case ITM_SWITCHTOPLAY:			return TO_PLAY;			break;

			case ITM_EXIT:					return EXIT;			break;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		//[1] If user clicks on the Toolbar
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				//selecting figures:
			case ITM_FIGURE_TYPE:					return FIG_TYPE;		break;
			case ITM_FIGURE_FILL_COLOUR:			return FIG_FILL_COLOUR;	break;
			case ITM_SWITCH_TO_DRAW_MODE:			return TO_DRAW;			break;

			case ITM_EXIT_P:						return EXIT;			break;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}

}
/////////////////////////////////

Input::~Input()
{
}
