#pragma once
#include "ArchitecturalStructure.h"
#include "Church.h"
#include "Castle.h"
#include <fstream>
#include <iostream>

using namespace std;


class Repository
{
public:
	void addRepo(ArchitecturalStructure* a);
	int getPosition(int);
	ArchitecturalStructure* getElementAt(int);
	int size();
	ArchitecturalStructure* deleteRepo(int id);
    ~Repository();

	ostream& display(ostream& os, bool(*filterFunction)(ArchitecturalStructure* a));
	void displayByType(string);


	void loadFromCSV(const string& csvFilepath)
	{

		ifstream f;
		f.open(csvFilepath);


		if (!f.is_open())     //if the file can't be opened(doesn't exist) then it creates it
		{
			ofstream g;
			g.open(csvFilepath);
			//f.open(csvFilepath);
		}
		else
		{
			
			while (!f.eof())       //reads the data from the CSV file and keeps it in the repo
			{
				ArchitecturalStructure* arch = new ArchitecturalStructure;
				f >> *arch;
				m_repo.push_back(arch);
			}
		}

		f.close();
	}
	
	void writeToCSV(string csvFilepath)
	{

		ofstream g;
		g.open(csvFilepath);

		if (m_repo.size() > 0)
		{
			g << *m_repo[0];
			for (int i = 1; i < m_repo.size(); i++)       //overwrites the CSV file with the current repository data
			{
				g << endl << *m_repo[i];
			}
		}

		g.close();

	}

private:
	vector<ArchitecturalStructure*> m_repo;
};

