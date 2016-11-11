//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/// Our Game & Design Info: This is our MapEditor class///
/// where we can edit the maps we would like to use in ///
/// our campaigns, we also validate them.              ///
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/// LIBRARIES USED:                                    ///
/// iosteam: This is used for our basic input/output   ///
/// services for our project such as cin and cout.     ///                
///fstream: This is another input/output stream used   ///
/// for parameters such as char_type                   ///
///	vector: This is used for the arrays and all its///
/// related member functions such as size, max, empty. ///
/// stdlib: This is used for memory management.        ///
/// string: Used for string types                      ///
///                                                    ///
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////


#pragma once

#include "Map.h"
#include "MapBuilderB.h"

class MapEditor
{
public:
	///
	/// default constructor
	///
	MapEditor();
	///
	/// destructor
	///
	~MapEditor();
	///
	/// edit the current map 
	///
	void EditMap(Map *pMap, const string &filename);

private:
	///
	/// flush the keyboard buffer
	///
	void Flush();

};
