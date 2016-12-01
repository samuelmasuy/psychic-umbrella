#include "MapEditor.h"
#include "MapBuilderB.h"

MapEditor::MapEditor()
{
	item = NULL;
}
///
/// The destructor
///
MapEditor::~MapEditor()
{

}

void MapEditor::Flush()
{

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

///
/// edit the current map 
///
void MapEditor::EditMap(Map *pMap, const string &filename)
{
	cout << "Current map is " << pMap->GetRows() << ", " << pMap->GetCols() << endl;
	do
	{
		pMap->Display();
		cout << "Select an option:" << endl;
		cout << "  [1] Modify a cell" << endl;
		cout << "  [2] Save map as " << filename << endl;
		cout << "  [3] Back to main menu" << endl;
		string opc;
		cin >> opc;
		Flush();
		if (opc.compare("3") == 0)
			///
			/// exit pressed!
			///
			break;
		else if (opc.compare("2") == 0)
			///
			/// save map pressed
			///
		{
			if (pMap->ValidateMap() == 0)
			{
				MapBuilderB mb(*pMap);

				if (mb.SaveLevel(filename.c_str()) == 0)
					cout << "File " << filename << " has been updated" << endl;
				else
					cout << "File " << filename << " cannot be updated. Check if the file is opened in a text editor, and it is not read-only." << endl;
			}
		}
		else if (opc.compare("1") == 0)
			///
			/// modify a cell
			///
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

					row--; col--; break;
				}
			} while (true);

			do
			{
				cout << endl << "Select the item type to put on the cell [" << row + 1 << "," << col + 1 << "]" << endl;
				cout << "  [1] Empty	(" << CHAR_EMPTY << ")" << endl;
				cout << "  [2] Player	(" << CHAR_PLAYER << ")" << endl;
				cout << "  [3] Elf   	(" << CHAR_ELF << ")" << endl;
				cout << "  [4] Goblin	(" << CHAR_GOBLIN << ")" << endl;
				cout << "  [5] Vine 	(" << CHAR_VINE << ")" << endl;
				cout << "  [6] Skeleton	(" << CHAR_SKELETON << ")" << endl;
				cout << "  [7] Medusa	(" << CHAR_MEDUSA << ")" << endl;
				cout << "  [8] Lizard	(" << CHAR_LIZARD << ")" << endl;
				cout << "  [9] Wall		(" << CHAR_WALL << ")" << endl;
				cout << "  [10] Entrance	(" << CHAR_ENTRY << ")" << endl;
				cout << "  [11] Exit		(" << CHAR_EXIT << ")" << endl;
				cout << "  [12] Chest	(" << CHAR_CHEST << ")" << endl;
				cout << "  [13] Friendly (" << CHAR_FRIENDLY << ")" << endl;
				cout << "  [14] Door  	(" << CHAR_DOOR << ")" << endl;
				cout << "  [0] Back to main menu" << endl;
				cout << "-->";
				cin >> opc;
				Flush();
				if (opc.compare("1") == 0)
				{

					pMap->setCell(row, col, CHAR_EMPTY);
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
					
					int i, j;
					pMap->GetExitPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the exit position" << endl;
						continue;
					}
					pMap->GetEntrancePos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the entrance position" << endl;
						continue;
					}
					pMap->GetPlayerPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the player position" << endl;
						continue;
					}
					pMap->setCell(row, col, CHAR_ELF);
				break;
				}
				else if (opc.compare("4") == 0)
				{
					int i, j;
					pMap->GetExitPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the exit position" << endl;
						continue;
					}
					pMap->GetEntrancePos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the entrance position" << endl;
						continue;
					}
					pMap->GetPlayerPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the player position" << endl;
						continue;
					}
					pMap->setCell(row, col, CHAR_GOBLIN);
					break;
				}
				else if (opc.compare("5") == 0)
				{
					int i, j;
					pMap->GetExitPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the exit position" << endl;
						continue;
					}
					pMap->GetEntrancePos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the entrance position" << endl;
						continue;
					}
					pMap->GetPlayerPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the player position" << endl;
						continue;
					}
					pMap->setCell(row, col, CHAR_VINE);
					break;
				}
				else if (opc.compare("6") == 0)
				{
					int i, j;
					pMap->GetExitPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the exit position" << endl;
						continue;
					}
					pMap->GetEntrancePos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the entrance position" << endl;
						continue;
					}
					pMap->GetPlayerPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the player position" << endl;
						continue;
					}
					pMap->setCell(row, col, CHAR_SKELETON);
					break;
				}
				else if (opc.compare("7") == 0)
				{
					int i, j;
					pMap->GetExitPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the exit position" << endl;
						continue;
					}
					pMap->GetEntrancePos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the entrance position" << endl;
						continue;
					}
					pMap->GetPlayerPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the player position" << endl;
						continue;
					}
					pMap->setCell(row, col, CHAR_MEDUSA);
					break;
				}
				else if (opc.compare("8") == 0)
				{
					int i, j;
					pMap->GetExitPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the exit position" << endl;
						continue;
					}
					pMap->GetEntrancePos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the entrance position" << endl;
						continue;
					}
					pMap->GetPlayerPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: an enemy cannot be located at the player position" << endl;
						continue;
					}
					pMap->setCell(row, col, CHAR_LIZARD);
					break;
				}
				else if (opc.compare("9") == 0)
				{
					int i, j;
					pMap->GetExitPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: a wall cannot be located at the exit position" << endl;
						continue;
					}
					pMap->GetEntrancePos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: a wall cannot be located at the entrance position" << endl;
						continue;
					}
					pMap->GetPlayerPos(i, j);
					if (i == row && j == col)
					{
						cout << "Invalid position: a wall cannot be located at the player position" << endl;
						continue;
					}
					pMap->setCell(row, col, CHAR_WALL);
					break;
				}
				else if (opc.compare("10") == 0)
				{
					if (pMap->SetEntrance(row, col))
						break;
					else
						cout << "Invalid position for entrance: This position contains a wall or exit" << endl;
				}
				else if (opc.compare("11") == 0)
				{
					if (pMap->SetExit(row, col))
						break;
					else
						cout << "Invalid position for exit: This position contains an entrance or wall" << endl;
				}
				else if (opc.compare("12") == 0)
				{
					string itemNumber;
					do
					{
						cout << "Which item do you want to create for the chest:" << endl;
						cout << " [1] helmet" << endl;
						cout << " [2] armor" << endl;
						cout << " [3] shield" << endl;
						cout << " [4] ring" << endl;
						cout << " [5] belt" << endl;
						cout << " [6] boots" << endl;
						cout << " [7] weapon" << endl;
						cout << " [8] back" << endl;

						cin >> itemNumber;
						Flush();
						if (itemNumber.compare("8") == 0)
							break;
						if (item)
						{
							delete item;
							item = NULL;
						}
						ItemBuilder *pBuilder = NULL;
						if (itemNumber.compare("1") == 0)	// helmet
							pBuilder = new HelmetBuilder;
						else if (itemNumber.compare("2") == 0)	// armor
							pBuilder = new ArmorBuilder;
						else if (itemNumber.compare("3") == 0)	// shield
							pBuilder = new ShieldBuilder;
						else if (itemNumber.compare("4") == 0)	// ring
							pBuilder = new RingBuilder;
						else if (itemNumber.compare("5") == 0)	// belt
							pBuilder = new BeltBuilder;
						else if (itemNumber.compare("6") == 0)	// boots
							pBuilder = new BootBuilder;
						else if (itemNumber.compare("7") == 0)	// weapon
							pBuilder = new WeaponBuilder;
						else
						{
							cout << "Invalid option " << itemNumber << endl;
							continue;	// to avoid execute the code below
						}
						pBuilder->createNewItem();
						item = pBuilder->getItem();
						break;
					} while (true);

					if (itemNumber.compare("8") != 0)	// we set the chest if a item was created
					{
						pMap->setCell(row, col, CHAR_CHEST);

					}

					break;
				}
				else if (opc.compare("13") == 0)
				{
					pMap->setCell(row, col, CHAR_FRIENDLY);
					break;
				}
				else if (opc.compare("14") == 0)
				{
					pMap->setCell(row, col, CHAR_DOOR);
					break;
				}
				else if (opc.compare("0") == 0)
					break;
				else
					cout << "Invalid option: " << opc << endl;
			} while (true);
		}


	} while (true);
}
