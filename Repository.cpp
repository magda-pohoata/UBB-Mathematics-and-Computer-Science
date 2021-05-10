#include "Repository.h"
#include <algorithm>
#include <functional>

using namespace std;

void Repository::addRepo(ArchitecturalStructure* a)
{
	m_repo.push_back(a);
}

int Repository::getPosition(int id)             //get the position of the element with the id chosen by the user
{
	for (int i = 0; i < m_repo.size(); i++)
	{
		if (m_repo[i]->getId() == id)
			return i;
	}
	return -1;
}

ArchitecturalStructure* Repository::getElementAt(int pos)       //gets the object from the position pos
{
	return m_repo[pos];
}

int Repository::size()
{
	return m_repo.size();
}

ArchitecturalStructure* Repository::deleteRepo(int id)
{
	ArchitecturalStructure* a = nullptr;
	auto index = find_if(m_repo.begin(), m_repo.end(), [id](ArchitecturalStructure* a)->bool {
		return a->getId() == id;
		});
	if (index != m_repo.end())
	{
		a = *index;
		m_repo.erase(index);
	}
	else
	{
		throw exception();
	}
	return a;
}


ostream& Repository::display(ostream& os, bool(*filterFunction)(ArchitecturalStructure* a))
{
	if (m_repo.size() == 0)
		throw exception("Nothing in repo");

	for (auto i = 0; i < m_repo.size(); i++)
	{
		if (filterFunction(m_repo[i]))
			os << m_repo[i]->getId() << " - " << *m_repo[i] << endl;
	}
	return os;

}

void Repository::displayByType(string type)
{
	vector <ArchitecturalStructure*> Churches;
	vector <ArchitecturalStructure*> Castles;

	for (auto i = 0; i < m_repo.size(); i++)
	{
		if (dynamic_cast<Church*>(m_repo[i]))
			Churches.push_back(m_repo[i]);
		
		if (dynamic_cast<Castle*>(m_repo[i]))
			Castles.push_back(m_repo[i]);
	}

	if (type == "1")
	{
		for (auto i = 0; i < Castles.size(); i++)
			Castles[i]->display(cout);
	}
	else
	{
		for (auto i = 0; i < Churches.size(); i++)
			Churches[i]->display(cout);
	}
}


Repository::~Repository()
{
	for (int i = 0; i <= m_repo.size(); i++)
		delete m_repo[i];
}