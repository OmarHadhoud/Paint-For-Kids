#ifndef SAVE__TYPE
#define SAVE__TYPE

#include "Action.h"

enum FigureType
{
	ellipse=1,line,rectangle,rohmbus,triangle,
};

class SaveByType : public Action
{
private:
	std::string fileName;
	enum FigureType FigType;
	ActionType Fig;

public:

	SaveByType(ApplicationManager *pApp);


	virtual void ReadActionParameters();
	virtual void Execute();
	//Global function that changes color to string
	static string ConvertColor(color color_);
	//changes String to color
	static color ConvertStringToColor(string color_name);

};
#endif // !SAVE__TYPE

