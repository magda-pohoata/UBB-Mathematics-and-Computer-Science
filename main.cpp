#include <iostream>
#include "Controller.h"
#include "Repository.h"
#include "UI.h"

using namespace std;

int main()
{
	
	Repository repo;
	Controller controller{ repo };
	UI ui{ controller };


	ui.initialize();
	return 0;
}
