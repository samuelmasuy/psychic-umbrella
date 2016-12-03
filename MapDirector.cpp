#include "MapDirector.h"
///
/// default constructor
///
MapDirector::MapDirector() {
  m_pBuilder = NULL;
}
///
/// destructor
///
MapDirector::~MapDirector() {
}

void MapDirector::SetBuilder(MapBuilder *p) {
  m_pBuilder = p;
}

void MapDirector::GetMap(Map &m) {
  int a, b;
  if (!m_pBuilder) {
    cout << "Error in MapDirector::GetMap. Please, first set a builder!" << endl;
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

Map *MapDirector::GetMapPtr() {
	int a, b;
	if (!m_pBuilder) {
		cout << "Error in MapDirector::GetMap. Please, first set a builder!" << endl;
		return NULL;
	}
	Map *m = new Map();
	m_pBuilder->GetSize(a, b);
	m->SetMap(a, b, m_pBuilder->Get2DArray());

	m_pBuilder->GetEntrancePos(a, b);
	m->SetEntrance(a, b);

	m_pBuilder->GetExitPos(a, b);
	m->SetExit(a, b);

	m_pBuilder->GetPlayerPos(a, b);
	m->SetPlayerPos(a, b);

	return m;
}
