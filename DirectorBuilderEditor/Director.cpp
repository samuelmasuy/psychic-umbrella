#include "Director.h"

// default constructor
Director::Director()
{
	m_pBuilder = NULL;
}

// destructor
Director::~Director()
{
}

void Director::SetBuilder(MapBuilder *p)
{
	m_pBuilder = p;
}

void Director::GetMap(Map &m)
{
	int a, b;
	if (!m_pBuilder)
	{
		cout << "Error in Director::GetMap. Please, first set a builder!" << endl;
		return;
	}
	m_pBuilder->GetSize(a, b);
	m.SetMap(a, b, m_pBuilder->Get2DArray());

	m_pBuilder->GetEntrancePos(a, b);
	m.SetEntrance(a, b);

	m_pBuilder->GetExitPos(a, b);
	m.SetExit(a, b);

	m_pBuilder->GetPlayerPos(a, b);
	m.SetPlayerPos(a, b);

}
