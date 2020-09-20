#include "SwitchToDrawAction.h"



SwitchToDrawAction::SwitchToDrawAction(ApplicationManager* pAct):Action(pAct)
{
	pOut = pManager->GetOutput();
}

void SwitchToDrawAction::ReadActionParameters()
{}

void SwitchToDrawAction::Execute()
{
	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
}

SwitchToDrawAction::~SwitchToDrawAction()
{
}
