#include "Campaign.h"
#include "MapBuilderA.h"
#include "MapDirector.h"
#include <stdio.h>
#include <stdlib.h>

Campaign::Campaign()
{

}
///
///This is the destructor
///
Campaign::~Campaign()
{

}
///
/// save the campaigns into a text file, with the name of the levels
///
int Campaign::Save(const char *filename)
{
	FILE *f = NULL;
	fopen_s(&f, filename, "wt");
	if (f == NULL)
	{
		cout << "Error loading campaign " << filename << endl;
		return 1;
	}
	for (map<int,string>::iterator i = m_fileNames.begin(); i!=m_fileNames.end(); i++)
	{
		///
		/// level number plus Map filename
		///
		fprintf(f, "%d\n%s\n", i->first, i->second.c_str());
	}
	fclose(f);
	return 0;
}
///
/// Loads a Campaign
///
int Campaign::Load(const char *filename)
{
	Clear();
	FILE *f = NULL;
	fopen_s(&f, filename, "rt");
	if (f == NULL)
	{
		cout << "Error loading campaign " << filename << endl;
		return 1;
	}
	///
	/// Here is the level number plus Map filename
	///
	char number [240];
	char mapName[240] = "";
	do
	{
		if (fgets(number, 240, f) && fgets(mapName, 240, f))
		{
			NormalizeString(number);
			NormalizeString(mapName);
			MapBuilderA m;
			int ret = m.LoadMap(mapName);
			int index = atoi(number);
			if (ret == 0)
			{
				MapBuilderA b;
				if (b.LoadMap(mapName) != 0)
				{
					cout << "Error loading " << mapName << " from campaign " << filename << endl;
				}
				else
				{
					MapDirector d;
					d.SetBuilder(&b);
					Map aux;
					m_maps[index] = aux;
					///
					/// set to get the map and filename
					///
					d.GetMap(m_maps[index]);
					m_fileNames[index] = string(mapName);
				}
			}
			else
			{
				cout << "Error loading " << mapName << " from campaign " << filename << endl;
			}
		}
		else
			break;
	} while (true);
	fclose(f);
	return 0;
}
///
/// Here the map is set with a level number and name
///
void Campaign::SetMap(int levelNumber, const Map &x, const char *filename)
{
	m_maps[levelNumber] = x;
	m_fileNames[levelNumber] = string(filename);
}
///
/// Get Map
///.
Map * Campaign::GetMap(int levelNumber)
{
	return &m_maps[levelNumber];
}
///
/// Clear Campaign
///
void Campaign::Clear()
{
	m_maps.clear();
	m_fileNames.clear();
}

///
/// Deletes Map
///
void Campaign::DeleteMap(int levelNumber)
{
	m_maps.erase(levelNumber);
	m_fileNames.erase(levelNumber);
}
///
/// Need to normalize string
///
void Campaign::NormalizeString(char *s)
{
	int len = strlen(s);
	while (len >= 0 && s[len] < 32)
	{
		s[len] = 0x00;
		len--;
	}
}

void Campaign::Print()
{
	
	for (map<int, string>::iterator i = m_fileNames.begin(); i != m_fileNames.end(); i++)
		cout << "Level " << i->first << " Map name " << i->second << endl;
	cout << endl;
}

int Campaign::Size()
{
	return m_fileNames.size();
}

bool Campaign::ExistLevel(int level)
{
	return m_fileNames.find(level) != m_fileNames.end();
}

string Campaign::GetFileName(int levelNumber)
{
	return m_fileNames[levelNumber];
}

void Campaign::GetLevels(vector<int> &levels)
{
	levels.clear();
	for (map<int, Map>::iterator i = m_maps.begin(); i != m_maps.end(); i++)
	{
		levels.push_back(i->first);
	}
}

