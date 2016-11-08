#include "MapObserver.h"


///
/// Default constructor
///
MapObserver::MapObserver()
{
	m_pMap = NULL;
}

///
/// Constructor with a map
///
MapObserver::MapObserver(Map *m)
{
	m_pMap = m;
}

///
/// Destructor
///
MapObserver::~MapObserver()
{

}


///
///Here we can set the map to be observed
///
void MapObserver::SetMap(Map *m)
{
	m_pMap = m;
}


///
///Here we update everytime something happens
///
void MapObserver::Update()
{
	Display();
}

///
///Here we can set the map to be observed
///
void MapObserver::Display()
{
	cout << endl;
	for (int r = 0; r < m_pMap->GetRows(); r++)
	{
		for (int c = 0; c < m_pMap->GetCols(); c++)
		{
			CELL_TYPE x = m_pMap->GetCell(r, c);
			char y = CHAR_EMPTY;
			///
			/// Here we show the map items in this sequence 
			///
			if (x & CELL_PLAYER)
				y = CHAR_PLAYER;
			else if (x & CELL_ENEMY)
				y = CHAR_ENEMY;
			else if (x & CELL_WALL)
				y = CHAR_WALL;
			else if (x & CELL_ENTRY)
				y = CHAR_ENTRY;
			else if (x & CELL_EXIT)
				y = CHAR_EXIT;
			else if (x & CELL_CHEST)
				y = CHAR_CHEST;
			else if (x & CELL_ARMOR)
				y = CHAR_ARMOR;
			else if (x & CELL_SHIELD)
				y = CHAR_SHIELD;
			else if (x & CELL_WEAPON)
				y = CHAR_WEAPON;
			else if (x & CELL_BOOTS)
				y = CHAR_BOOTS;
			else if (x & CELL_RING)
				y = CHAR_RING;
			else if (x & CELL_HELMET)
				y = CHAR_HELMET;
			cout << y;
		}
		cout << endl;
	}
}