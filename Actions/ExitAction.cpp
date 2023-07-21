#include "ExitAction.h"
#include "../ApplicationManager.h"

ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{
	exitaction = false;
}

void ExitAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Exit Action, Press Any Key + Enter");

	string response = pIn->GetSrting(pOut);
		exitaction = true;Sleep(800);
	

	pOut->ClearStatusBar();
}


void ExitAction::Execute()
{
	ReadActionParameters();

	if (exitaction)
	{
		Output* pOut = pManager->GetOutput();
		pOut->ClearDrawArea();
		pManager->deleteAllFigures();
		CFigure::ResetCounter();
		pManager->DeleteActionList();
		//TODO
		// Delete All Recordings & reset all variables
		pManager->setneedtodraw();

	}
}


ExitAction::~ExitAction()
{};
