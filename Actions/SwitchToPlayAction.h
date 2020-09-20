#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class SwitchToPlayAction :public Action
{
private:
	Output*pOut;

public:
	SwitchToPlayAction(ApplicationManager*);

	virtual void ReadActionParameters();

	virtual void Execute();

	~SwitchToPlayAction();
};

