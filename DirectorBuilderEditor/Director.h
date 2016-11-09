#pragma once

#include "MapBuilder.h"


class Director
{
public:
	///
	/// default constructor
	///
	Director();
	///
	/// destructor
	///
	virtual ~Director();
	///
	/// set builder to mapbuilder
	///
	void SetBuilder(MapBuilder *p);
	
	void GetMap(Map &m);

private:

	MapBuilder *m_pBuilder;
};

