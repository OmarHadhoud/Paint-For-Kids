#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)  DONE
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here'   

	//The following items are for shapes:
	ITM_SELECTFIG,		//Select Figure
	ITM_RECT,			//Recangle item 
	ITM_TRIANGLE,		//Triangle item 
	ITM_RHOMBUS,		//Rhombus item 
	ITM_CIRCLE,			//Circle item
	ITM_LINE,			//Line item


	//The following items are for colors:
	ITM_CHANGE_FIG_COLOR,//changes color of selected figure
	ITM_CHANGE_DRW_COLOR,//changes the border color
	ITM_BLUE,			//Blue color item
	ITM_RED,			//Red color item
	ITM_GREEN,			//Green color item
	ITM_BLACK,			//Black color item
	ITM_WHITE,			//White color item

	//The following items are for resize:
	ITM_DoubleSize,
	ITM_QuadrupleSize,
	ITM_HalfSize,
	ITM_QuarterSize,

	//The following items are for various functions:
	ITM_COPY,			//copies selected figure
	ITM_CUT,			//cuts selected figure
	ITM_PASTE,			//pastes selected figure
	ITM_DELETE,			//deletes selected figure

	ITM_SWITCHTOPLAY,	//Switch To Play Mode icon
	ITM_LOAD,			//Load Existing figure
	ITM_SAVE_GRAPH,		//Saves all figures icon
	ITM_SAVE_BY_TYPE,	//Saves all figures of selected figure type icon
	ITM_EXIT,			//exits icon



	DRAW_ITM_COUNT		//no. of menu items 

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_FIGURE_TYPE,			// SELECT FIGURES BY TYPE AS RECTANGLE,TRIANGLE
	ITM_FIGURE_FILL_COLOUR,		// SELECT FIGURES BY THE SPECIFIC COLOUR AS RED ,GREEN
	ITM_SWITCH_TO_DRAW_MODE,	// SWITCH TO DRAW MODE
	ITM_EXIT_P,					// EXIT

	PLAY_ITM_COUNT				//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height;	    //Window width and height
	int wx, wy;			//Window starting coordinates
	int StatusBarHeight;	//Status Bar Height
	int ToolBarHeight;		//Tool Bar Height (distance from top of window to bottom line of toolbar)
	int MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color CutFigureColor;	//Cutting color ---added
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

}UI;	//create a global object UI

#endif