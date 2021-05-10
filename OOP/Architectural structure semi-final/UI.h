#pragma once

#include "ArchitecturalStructure.h"
#include "Castle.h"
#include "Church.h"

#include "Controller.h"

#include <iostream>
#include <fstream>
using namespace std;

class UI
{
public:
	UI(Controller&);
	void addUI();
	void deleteUI();
	void displayAllUI();
	void displayByCountryUI();
	void displayByYearUI();
	void displayByTypeUI();
	void redoUI();
	void undoUI();
	void showUI();
	void initialize();
	
private:
	Controller m_controller;
};

