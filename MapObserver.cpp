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
///Here we can set the Display to be observed
///
void MapObserver::Display()
{
	cout << endl;

	int i0, j0, i1, j1, ip, jp;
	m_pMap->GetPlayerPos(ip, jp);
	m_pMap->GetEntrancePos(i0, j0);
	m_pMap->GetExitPos(i1, j1);

	for (int r = 0; r < m_pMap->GetRows(); r++)
	{
		for (int c = 0; c < m_pMap->GetCols(); c++)
		{
			if (r == ip && c == jp)
				cout << CHAR_PLAYER;
			else if (r == i0 && c == j0)
				cout << CHAR_ENTRY;
			else if (r == i1 && c == j1)
				cout << CHAR_EXIT;
			else
				cout << m_pMap->GetCell(r, c);
		}
		cout << endl;
	}
	cout << endl;
}