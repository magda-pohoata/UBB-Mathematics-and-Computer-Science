#pragma once
#include "ArchitecturalStructure.h"

class Repository
{
public:
	void addRepo(ArchitecturalStructure* a);
	void deleteRepo(int id);

	ostream& display(ostream& os, bool (*filterFunction)(ArchitecturalStructure* a));
	
private:
	vector<ArchitecturalStructure*> m_repo;
};

