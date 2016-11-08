#include <stdlib.h>
#include "MapObserver.h"

Map m;
MapObserver obs;

///
/// This is the engine, loads the desired map and runs
///
int main()
{
	if (m.LoadMap("Map1.txt"))
		return 0;
	obs.SetMap(&m);
	obs.Display();
	m.Attach(&obs);
	string opc = "";
	do
	{
		cout << "Select an option:" << endl;
		cout << "  [1] Add item to a map cell" << endl;
		cout << "  [2] Remove item from a map cell" << endl;
		cout << "  [3] Show all items of a map cell" << endl;
		cout << "  [4] Exit" << endl;
		cout << "-->";
		cin >> opc;
		if (opc.compare("4") == 0)
			break;
		int row = -1, col = -1;
		do
		{
			cout << "Indicate the row number of the cell -->";
			cin >> row;
			cout << "Indicate the column number of the cell -->";
			cin >> col;
			if (!m.ValidPos(row - 1, col - 1))
			{
				cout << "Invalid position (" << row << "," << col << ")" << endl;
				cout << "Row should be between 1 and " << m.GetRows() << endl;
				cout << "Col should be between 1 and " << m.GetCols() << endl;
			}
			else
			{
				row--; col--; break;
			}
		} while (true);
		if (opc.compare("1") == 0)
		{
			do
			{
				cout << endl << "Select the item type to include into the cell " << row + 1 << "," << col + 1 << endl;
				cout << "  [1] Empty    (" << CHAR_EMPTY << ")" << endl;
				cout << "  [2] Player   (" << CHAR_PLAYER << ")" << endl;
				cout << "  [3] Enemy    (" << CHAR_ENEMY << ")" << endl;
				cout << "  [4] Wall     (" << CHAR_WALL << ")" << endl;
				cout << "  [5] Entrance (" << CHAR_ENTRY << ")" << endl;
				cout << "  [6] Exit     (" << CHAR_EXIT << ")" << endl;
				cout << "  [7] Chest    (" << CHAR_CHEST << ")" << endl;
				cout << "  [8] Armor    (" << CHAR_ARMOR << ")" << endl;
				cout << "  [9] Shield   (" << CHAR_SHIELD << ")" << endl;
				cout << " [10] Weapon   (" << CHAR_WEAPON << ")" << endl;
				cout << " [11] Boots    (" << CHAR_BOOTS << ")" << endl;
				cout << " [12] Ring     (" << CHAR_RING << ")" << endl;
				cout << " [13] Helmet   (" << CHAR_HELMET << ")" << endl;
				cout << " [14] Back to main menu" << endl;
				cout << "-->";
				cin >> opc;
				if (opc.compare("14") == 0)
					break;
				int value = -1;
				value = atoi(opc.c_str());
				if (value < 1 || value > 14)
				{
					cout << "Invalid opcion: " << opc << endl;
				}
				else if (value == 5)
				{
					if (m.SetEntrance(row, col) == false)
						cout << "Invalid entrance position. It already has a wall or an exit" << endl;
					break;

				}
				else if (value == 6)
				{
					if (m.SetExit(row, col) == false)
						cout << "Invalid exit position. It already has a wall or an entrance" << endl;
					break;
				}
				else
				{
					if (value == 1)
						m.StoreCell(row, col, CELL_EMPTY);
					else
						m.AddToCell(row, col, 1 << (value - 1));
					break;
				}
			} while (true);

		}
		if (opc.compare("2") == 0)
		{
			do
			{
				CELL_TYPE x = m.GetCell(row, col);
				cout << endl << "Select the item type to remove from the cell " << row + 1 << "," << col + 1 << endl;
				//cout << "  [1] Empty   (" << CHAR_EMPTY << ")" << endl;
				if (x & CELL_PLAYER)
					cout << "  [2] Player   (" << CHAR_PLAYER << ")" << endl;
				if (x & CELL_ENEMY)
					cout << "  [3] Enemy    (" << CHAR_ENEMY << ")" << endl;
				if (x & CELL_WALL)
					cout << "  [4] Wall     (" << CHAR_WALL << ")" << endl;
				if (x & CELL_ENTRY)
					cout << "  [5] Entrance (" << CHAR_ENTRY << ")" << endl;
				if (x & CELL_EXIT)
					cout << "  [6] Exit     (" << CHAR_EXIT << ")" << endl;
				if (x & CELL_CHEST)
					cout << "  [7] Chest    (" << CHAR_CHEST << ")" << endl;
				if (x & CELL_ARMOR)
					cout << "  [8] Armor    (" << CHAR_ARMOR << ")" << endl;
				if (x & CELL_SHIELD)
					cout << "  [9] Shield   (" << CHAR_SHIELD << ")" << endl;
				if (x & CELL_WEAPON)
					cout << " [10] Weapon   (" << CHAR_WEAPON << ")" << endl;
				if (x & CELL_BOOTS)
					cout << " [11] Boots    (" << CHAR_BOOTS << ")" << endl;
				if (x & CELL_RING)
					cout << " [12] Ring     (" << CHAR_RING << ")" << endl;
				else if (x & CELL_HELMET)
					cout << " [13] Helmet   (" << CHAR_HELMET << ")" << endl;
				cout << " [14] Back to main menu" << endl;
				cout << "-->";
				cin >> opc;
				if (opc.compare("14") == 0)
					break;
				int value = -1;
				value = atoi(opc.c_str());
				if (value < 2 || value > 14)
				{
					cout << "Invalid opcion: " << opc << endl;
				}
				else
				{
					m.RemoveToCell(row, col, 1 << (value - 1));
					break;
				}
			} while (true);
		}
		if (opc.compare("3") == 0)
		{
			CELL_TYPE x = m.GetCell(row, col);
			if (x == CELL_EMPTY)
				cout << "Cell is empty" << endl;
			else
			{
				cout << "Cell contains: ";
				if (x & CELL_PLAYER)
					cout << " Player";
				if (x & CELL_ENEMY)
					cout << " Enemy";
				if (x & CELL_WALL)
					cout << "Wall";
				if (x & CELL_ENTRY)
					cout << " Entry";
				if (x & CELL_EXIT)
					cout << " Exit";
				if (x & CELL_CHEST)
					cout << " Chest";
				if (x & CELL_ARMOR)
					cout << " Armor";
				if (x & CELL_SHIELD)
					cout << " Shield";
				if (x & CELL_WEAPON)
					cout << " Weapon";
				if (x & CELL_BOOTS)
					cout << " Boots";
				if (x & CELL_RING)
					cout << " Ring";
				if (x & CELL_HELMET)
					cout << " Helmet";
				cout << endl << endl;
			}
		}
	} while (true);
	return 0;
}

