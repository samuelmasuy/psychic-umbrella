#include <stdlib.h>
#include <stdio.h>
#include "MapObserver.h"
///
///
/// To create a map, enter the number of rows and columns you want, it will only save if you include an entrance, exit, and player
///
///To load a map that is already in the directory just write its name including the .txt extension
///
/// If you want to draw a map in a .txt file and then load it, ensure that this sequence is at the top of the page, (Total number of rows) (Total number of columns) (Row of Entry) (Column of Entry) (Row of Exit) (Column of Exit) (Row of Player) (Column of Player) this sets the number of rows and random entrance, exit, and player so its valid
///																											Example:20 20 1 1 9 8 8 8 
///
///
///If you want to replace a cell make sure it is empty first, for example if you want to replace a wall with an item, then replace the wall with an empty cell first, then add the item
///
///Save with .txt extension 
///
///
///
Map m;
MapObserver obs;

void Flush()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool GetSize(int &r, int &c)
{
	cout << "How many rows would you like the Map to be   -->";
	cin >> r;
	Flush();
	cout << "How many columns would you like the Map to be-->";
	cin >> c;
	Flush();
	return  (r > 0 && c > 0);
}

int main()
{
	obs.SetMap(&m);
	m.Attach(&obs);

	string opc = "";
	do
	{
		cout << "Select an option:" << endl;
		cout << "  [1] Build your own Custom Map" << endl;
		cout << "  [2] To load an existing .txt Map (please use the file extension .txt)" << endl;
		cout << "  [3] Save your Map (please save using .txt extension)" << endl;
		cout << "  [4] Change a Cell (please ensure the cell you are trying to change is empty first)" << endl;
		cout << "  [5] Exit" << endl;
		cout << "-->";
		cin >> opc;
		Flush();
		if (opc.compare("5") == 0)	
			break;
		else if (opc.compare("1") == 0)	// Here we create an empty Map with just walls in the exterior 
		{
			int rows, cols;
			while (GetSize(rows, cols) == false)
			{
				cout << "Can only accept Positive Numbers" << endl;
			}
			m.Create(rows, cols);
		}
		else if (opc.compare("2") == 0)	// Here we can load a map
		{
			while (true)
			{
				cout << "Please enter the filename with the .txt extension -->";
				char filename[240];
				cin.getline(filename, 240);
				int len = strlen(filename);
				while (len >= 0)
				{
					if (filename[len] < 32)	
						filename[len] = 0x00;
					else
						break;
					len--;
				}
				if (m.LoadMap(filename) == 0)
					break;
			}
		}
		else if (opc.compare("3") == 0)	// save a map into a file
		{
			if (m.ValidateMap() == 0)
			{
				while (true)
				{
					cout << "Introduce the filename to save -->";
					char filename[240];
					cin.getline(filename, 240);
					//Flush();
					int len = strlen(filename);
					while (len >= 0)
					{
						if (filename[len] < 32)	// a special char
							filename[len] = 0x00;
						else
							break;
						len--;
					}
					if (m.SaveMap(filename) == 0)	// success
						break;
				}
			}
		}
		else if (opc.compare("4") == 0)	// modify a cell
		{
			int row = -1, col = -1;
			do
			{
				cout << "Please enter Row number [1.." << m.GetRows() << "] of the cell -->";
				cin >> row;
				Flush();
				cout << "Please enter Column number [1.." << m.GetCols() << "] of the cell -->";
				cin >> col;
				Flush();
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

			do
			{
				cout << endl << "Select the item type to insert into the cell [" << row + 1 << "," << col + 1 << "]" << endl;
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
				Flush();
				if (opc.compare("1") == 0)
				{
					m.StoreCell(row, col, CHAR_EMPTY);
					break;
				}
				else if (opc.compare("2") == 0)
				{
					if (m.SetPlayerPos(row, col) == false)
						cout << "Invalid position for player: This position contains a wall" << endl;
					else
						break;
				}
				else if (opc.compare("3") == 0)
				{
					m.StoreCell(row, col, CHAR_ENEMY);
					break;
				}
				else if (opc.compare("4") == 0)
				{
					m.StoreCell(row, col, CHAR_WALL);
					break;
				}
				else if (opc.compare("5") == 0)
				{
					if (m.SetEntrance(row, col))
						break;
					else
						cout << "Invalid position for entrance: This position contains a wall or exit" << endl;
				}
				else if (opc.compare("6") == 0)
				{
					if (m.SetExit(row, col))
						break;
					else
						cout << "Invalid position for exit: This position contains an entrance or wall" << endl;
				}
				else if (opc.compare("7") == 0)
				{
					m.StoreCell(row, col, CHAR_CHEST);
					break;
				}
				else if (opc.compare("8") == 0)
				{
					m.StoreCell(row, col, CHAR_ARMOR);
					break;
				}
				else if (opc.compare("9") == 0)
				{
					m.StoreCell(row, col, CHAR_SHIELD);
					break;
				}
				else if (opc.compare("10") == 0)
				{
					m.StoreCell(row, col, CHAR_WEAPON);
					break;
				}
				else if (opc.compare("11") == 0)
				{
					m.StoreCell(row, col, CHAR_BOOTS);
					break;
				}
				else if (opc.compare("12") == 0)
				{
					m.StoreCell(row, col, CHAR_RING);
					break;
				}
				else if (opc.compare("13") == 0)
				{
					m.StoreCell(row, col, CHAR_HELMET);
					break;
				}
				else if (opc.compare("14") == 0)
					break;
				else
					cout << "Invalid option: " << opc << endl;

			} while (true);
		}
	} while (true);
	return 0;
}

