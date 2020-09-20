#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window * pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearToolBar() const; // clears the tool bar (before switching modes)
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

								// -- Figures Drawing functions
								//void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle

	void DrawLine(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false, bool cutted =false) const; //Draw a line
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false, bool cutted = false) const;  //Draw a rectangle
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected = false, bool cutted = false) const; //Draw a triangle
	void DrawRhom(Point P1, GfxInfo RectGfxInfo, int Size1, int Size2, bool selected = false, bool cutted = false) const;  //Draw a rhombus
	void DrawEllipse(Point P1, GfxInfo RectGfxInfo,int size, bool selected = false, bool cutted = false) const; //Draw an ellipse

																				  ///Make similar functions for drawing all other figure types. (done)

	void PrintMessage(string msg) const;		//Print a message on Status bar
	void SetCrntDrawColor(color newDrawColor);	//Set current drawing color
	void SetCrntFillColor(color newFillColor);	//Set current filling color
	color getCrntDrawColor() const;				//get current drwawing color
	color getCrntFillColor() const;				//get current filling color
	int getCrntPenWidth() const;				//get current pen width


	~Output();
};

#endif