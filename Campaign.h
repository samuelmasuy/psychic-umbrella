#pragma once

#include "Map.h"
#include <map>

///
/// Here we have a class that gathers numerous maps
///
class Campaign
{
public:
	///
	/// default constructor
	///
	Campaign();
	///
	/// destructor
	///
	~Campaign();
	///
	/// save the campaigns into a text file, with the name of the leves
	///
	int Save(const char *filename);
	///
	/// load a campaign
	///
	int Load(const char *filename);
	///
	/// Setting map
	///
	void SetMap(int levelNumber, const Map &x, const char *filename);

	Map * GetMap(int levelNumber);

	string GetFileName(int levelNumber);
	///
	/// Deleting a map
	///
	void DeleteMap(int levelNumber);
	///
	/// Clear a campaign
	///
	void Clear();
	///
	/// Print a campaign
	///
	void Print();
	///
	/// Returns number of maps
	///
	int Size();
	///
	/// Return true if the level exists in the campaign
	///
	bool ExistLevel(int level);
	///
	/// Get the levels
	///
	void GetLevels(vector<int> &levels);
private:
	///
	/// mapping a level number to Map, and filename
	///
	map <int, Map> m_maps;
	map <int, string> m_fileNames;

	void NormalizeString(char *s);
};

