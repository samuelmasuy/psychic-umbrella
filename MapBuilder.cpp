#include "MapBuilder.h"

// default constructor
MapBuilder::MapBuilder()
{
	m_rows = m_cols = 0;
	m_scene = NULL;
	m_i0 = m_j0 = m_i1 = m_j1 = m_iPlayer = m_jPlayer = -1;
}

// destructor
MapBuilder::~MapBuilder()
{
}

// release memory of m_scene
void MapBuilder::FreeMem()
{
	if (m_rows>0 && m_scene)
	{
		for (int i = 0; i < m_rows; i++)
			delete[] m_scene[i];
		delete[] m_scene;
	}
	m_scene = NULL;
	m_rows = m_cols = 0;
}

// alloc memory for a 2D array
CELL_TYPE **MapBuilder::AllocMem(int rows, int cols)
{
	CELL_TYPE **aux;
	aux = new CELL_TYPE *[rows];
	for (int i = 0; i < rows; i++)
	{
		aux[i] = new CELL_TYPE[cols];
		memset(aux[i], 0, sizeof(CELL_TYPE)*cols);
	}
	return aux;
}
