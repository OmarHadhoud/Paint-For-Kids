#include "SwitchToPlayAction.h"



SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp ):Action(pApp)
{
	pOut = pManager->GetOutput();
}

void SwitchToPlayAction::ReadActionParameters()
{}

void SwitchToPlayAction::Execute()
{
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
}

SwitchToPlayAction::~SwitchToPlayAction()
{
}
