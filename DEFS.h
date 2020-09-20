#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.

#define RhombSize1 70 //The fixed rhombus size (half the first diagonal in x direction)
#define RhombSize2 120 //The fixed rhombus size (Half the second diagonal in  y direction)
#define EllipseSize 50 //The fixed ellipse size
#define PI 3.14159 //The PI.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,			//Draw Line
	DRAW_RECT,			//Draw Rectangle
	DRAW_TRI,			//Draw Triangle
	DRAW_RHOMBUS,		//Draw Rhombus
	DRAW_ELLIPSE,		//Draw Ellipse

	SELECT_FIG,			//Select figure
	CHNG_DRAW_CLR,		//Change the drawing color
	CHNG_FILL_CLR,		//Change the filling color

	SEL_BLUE,			//Change color to Blue
	SEL_RED,			//Change color to Red
	SEL_GREEN,			//Change color to Green
	SEL_BLACK,			//Change color to Black
	SEL_WHITE,			//Change color to White

	DOUBLESIZE,			//Change the Size of the Selected figure to double original size
	QUADRUPLESIZE,		//Change the size of the selected figure to fourtimes  original size
	HALFSIZE,			//Change the size of the selected fihure to half original size
	QUARTERSIZE,		//Change the size of the selected figure to quarter original size

	DEL,				//Delete a figure(s)
	COPY,				//Copy a figure
	CUT,				//Cut a figure
	PASTE,				//Paste the copied figure
	SAVE,				//Save the whole graph to a file
	SAVE_BY_TYPE,		//Save the all the figures that have a specific type
	LOAD,				//Load a graph from a file
	EXIT,				//Exit the application

	DRAWING_AREA,		//A click on the drawing area
	STATUS,				//A click on the status bar
	EMPTY,				//A click on empty place in the toolbar

	TO_DRAW,			//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode

	// play mode actions
	FIG_TYPE,			// SELECT FIGURES BY TYPE AS RECTANGLE,TRIANGLE
	FIG_FILL_COLOUR,	// SELECT FIGURES BY THE SPECIFIC COLOUR ASAS RED ,GREEN
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif