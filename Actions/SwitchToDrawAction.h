#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class SwitchToDrawAction:public Action
{
private:
	Output*pOut;

public:
	SwitchToDrawAction(ApplicationManager*);

	virtual void ReadActionParameters();

	virtual void Execute() ;


	~SwitchToDrawAction();
};

