#include "MapEditor.h"

MapEditor::MapEditor()
{

}

// destructor
MapEditor::~MapEditor()
{

}

void MapEditor::Flush()
{
	//cin.ignore(INT_MAX);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


// edit the current map 
void MapEditor::EditMap(Map *pMap) 
{
	cout << "Current map is " << pMap->GetRows() << ", " << pMap->GetCols() << endl;
	do
	{
		pMap->Display();
		cout << "Select an option:" << endl;
		cout << "  [1] Modify a cell" << endl;
		cout << "  [2] Back to main menu" << endl;
		string opc;
		cin >> opc;
		Flush();
		if (opc.compare("2") == 0)	// exit pressed!
			break;
		else if (opc.compare("1") == 0)	// modify a cell
		{
			int row = -1, col = -1;
			do
			{
				cout << "Indicate the row number [1.." << pMap->GetRows() << "] of the cell -->";
				cin >> row;
				Flush();
				cout << "Indicate the column number [1.." << pMap->GetCols() << "] of the cell -->";
				cin >> col;
				Flush();
				if (!pMap->ValidPos(row - 1, col - 1))
				{
					cout << "Invalid position (" << row << "," << col << ")" << endl;
					cout << "Row should be between 1 and " << pMap->GetRows() << endl;
					cout << "Col should be between 1 and " << pMap->GetCols() << endl;
				}
				else
				{
					// go back to zero based indexes
					row--; col--; break;
				}
			} while (true);

			do
			{
				cout << endl << "Select the item type to put on the cell [" << row + 1 << "," << col + 1 << "]" << endl;
				cout << "  [1] Empty    (" << CHAR_EMPTY << ")" << endl;
				cout << "  [2] Player   (" << CHAR_PLAYER << ")" << endl;
				cout << "  [3] Enemy    (" << CHAR_ENEMY << ")" << endl;
				cout << "  [4] Wall     (" << CHAR_WALL << ")" << endl;
				cout << "  [5] Entrance (" << CHAR_ENTRY << ")" << endl;
				cout << "  [6] Exit     (" << CHAR_EXIT << ")" << endl;
				cout << "  [7] Chest    (" << CHAR_CHEST << ")" << endl;
				cout << "  [8] Back to main menu" << endl;
				cout << "-->";
				cin >> opc;
				Flush();
				if (opc.compare("1") == 0)
				{
					pMap->StoreCell(row, col, CHAR_EMPTY);
					break;
				}
				else if (opc.compare("2") == 0)
				{
					if (pMap->SetPlayerPos(row, col) == false)
						cout << "Invalid position for player: This position contains a wall" << endl;
					else
						break;
				}
				else if (opc.compare("3") == 0)
				{
					pMap->StoreCell(row, col, CHAR_ENEMY);
					break;
				}
				else if (opc.compare("4") == 0)
				{
					pMap->StoreCell(row, col, CHAR_WALL);
					break;
				}
				else if (opc.compare("5") == 0)
				{
					if (pMap->SetEntrance(row, col))
						break;
					else
						cout << "Invalid position for entrance: This position contains a wall or exit" << endl;
				}
				else if (opc.compare("6") == 0)
				{
					if (pMap->SetExit(row, col))
						break;
					else
						cout << "Invalid position for exit: This position contains an entrance or wall" << endl;
				}
				else if (opc.compare("7") == 0)
				{
					pMap->StoreCell(row, col, CHAR_CHEST);
					break;
				}
				else if (opc.compare("8") == 0)
					break;
				else
					cout << "Invalid opcion: " << opc << endl;
			} while (true);
		}


	} while (true);
}