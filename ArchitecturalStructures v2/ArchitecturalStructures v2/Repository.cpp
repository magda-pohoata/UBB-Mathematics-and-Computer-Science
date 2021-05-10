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
		throw exception("Invalid ID");
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
	if (m_repo.size() == 0)
		throw exception("Nothing in repo");

	vector <ArchitecturalStructure*> Churches;
	vector <ArchitecturalStructure*> Castles;

	for (auto i = 0; i < m_repo.size(); i++)
	{
		if (m_repo[i]->getType()==1)
			Churches.push_back(m_repo[i]);
		else
			if (m_repo[i]->getType() == 2)
				Castles.push_back(m_repo[i]);
	}

	if (type == "1")
	{
		if (Churches.size() == 0)
			throw exception("There are no churches");
		cout << endl;
		for (auto i = 0; i < Churches.size(); i++)
			cout << *Churches[i] << endl;
		cout << endl;
	}
	else
	{
		if (Castles.size() == 0)
			throw exception("There are no castles");
		cout << endl;
		for (auto i = 0; i < Castles.size(); i++)
			cout << *Castles[i] << endl;
		cout << endl;
	}
}

void Repository::displayByYear(int year)   //display all arch str built after a specified year
{
	bool ok = false;
	for (auto i = 0; i < m_repo.size(); i++)
		if (m_repo[i]->getYear() >= year)
		{
			ok = true;
			cout << *m_repo[i] << endl;
		}
	if (ok == false)
		throw exception("There are no architectural structures to show");
}


Repository::~Repository()
{
	for (int i = 0; i < m_repo.size(); i++)
		delete m_repo[i];
}