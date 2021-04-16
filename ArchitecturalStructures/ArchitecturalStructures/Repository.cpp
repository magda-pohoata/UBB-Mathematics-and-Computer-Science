#include "Repository.h"

void Repository::addRepo(ArchitecturalStructure* a)
{
}

void Repository::deleteRepo(int id)
{
}

ostream& Repository::display(ostream& os, bool(*filterFunction)(ArchitecturalStructure* a))
{
	for (auto i = 0; i < m_repo.size(); i++)
	{
		if (filterFunction(m_repo[i]))
			os << *m_repo[i];
	}
	return os;

}
