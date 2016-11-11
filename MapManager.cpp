///
/// This runs everything, it starts a fresh campaign, so to use it start
/// by creating a map, it automatically saves, then you click save campaign,
/// it saves the campaign, u can load it and display the maps in it,
/// and the actual map itself..
///
#include "MapManager.h"

void Flush()
{

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void NormalizeString(char *s)
{
	int len = strlen(s);
	while (len >= 0 && s[len] < 32)
	{
		s[len] = 0x00;
		len--;
	}
}

void GetSize(int &r, int &c)
{
	do
	{
		cout << "Indicate the number of rows   -->";
		cin >> r;
		Flush();
		cout << "Indicate the number of columns-->";
		cin >> c;
		Flush();
		if (r > 0 && c > 0)
			break;
	} while (true);
}

void manageMap()
{
	Campaign c;
	int currentLevel = -1;

	string opc = "";
	do
	{
		cout << "Select an option:" << endl;
		cout << "  [1] Create a new Campaign" << endl;
		cout << "  [2] Load Campaign" << endl;
		cout << "  [3] Save Campaign" << endl;
		cout << "  [4] Show information of current Campaign" << endl;
		cout << "  [5] Add a saved map into current Campaign" << endl;
		cout << "  [6] Delete a map from current Campaign" << endl;
		cout << "  [7] Edit a map" << endl;
		cout << "  [8] Duplicate a map" << endl;
		cout << "  [9] Build a new map" << endl;
		cout << " [10] Display a map from file" << endl;
		cout << " [11] Display all maps of the campaign" << endl;
		cout << " [12] Exit" << endl;
		cout << "-->";
		cin >> opc;
		Flush();
		if (opc.compare("12") == 0)	// exit pressed!
			break;
		else if (opc.compare("1") == 0)	// create an empty campaign
		{
			c.Clear();
			cout << "Campaign is now empty!" << endl;
		}
		else if (opc.compare("2") == 0)	// load campaign
		{
			char filename[240];
			do
			{
				cout << "Indicate the file name of the campaign to be loaded -->";
				cin.getline(filename, 240);
				NormalizeString(filename);
				if (c.Load(filename) == 0)
				{
					cout << "Campaign " << filename << " has been loaded" << endl;
					break;
				}
			} while (true);
		}
		else if (opc.compare("3") == 0)	// load campaign
		{
			char filename[240];
			do
			{
				cout << "Indicate the file name of the campaign to be saved -->";
				cin.getline(filename, 240);
				NormalizeString(filename);
				if (c.Save(filename) == 0)
				{
					cout << "Campaign has been saved into " << filename  << endl;
					break;
				}
			} while (true);
		}
		else if (opc.compare("4") == 0)	// show info
			c.Print();
		else if (opc.compare("5") == 0)	// add a saved map
		{
			string value;
			char filename[240];
			do
			{
				cout << "Indicate the level number --> ";
				cin >> value;
				Flush();
				int level = 0;
				if (sscanf_s(value.c_str(), "%d", &level) != 1 || level < 0)
				{
					cout << "Invalid level number: " << value << endl;
					continue;
				}
				cout << "Indicate level name --> ";
				cin.getline(filename,240);
				NormalizeString(filename);
				MapDirector d;

				// load map from file
				MapBuilderB mb;
				if (mb.LoadMap(filename, level))
					continue;

				// set this builder to director
				d.SetBuilder(&mb);
				Map m;

				// get the map from director
				d.GetMap(m);

				// store the map into campaign
				c.SetMap(level, m, filename);

				currentLevel = level;

				break;
			} while (true);

		}
		else if (opc.compare("6") == 0)	// delete a map from campaign
		{
			string value;
			if (c.Size() == 0)
			{
				cout << "There is nothing to delete. Campaign is empty now... press enter -->";
				cin >> value;
				Flush();
			}
			else
			{
				cout << "There are the set of Maps in the current Campaign" << endl;
				c.Print();
				do
				{
					cout << "Please, select a level number to delete -->";
					cin >> value;
					Flush();
					int level = -1;
					if (sscanf_s(value.c_str(), "%d", &level) != 1 || level < 0)
					{
						cout << "Invalid level number: " << value << endl;
						continue;
					}
					if (!c.ExistLevel(level))
					{
						cout << "Level " << level << " does not exit in campaign" << endl;
						continue;
					}
					c.DeleteMap(level);
					break;
				} while (true);

			}
		}
		else if (opc.compare("7") == 0)	// edit a map
		{
			string value;
			if (c.Size() == 0)
			{
				cout << "There is nothing to edit. Campaign is empty now... press enter -->";
				cin >> value;
				Flush();
			}
			else
			{
				cout << "These are the set of Maps in the current Campaign" << endl;
				c.Print();
				do
				{
					cout << "Please, select a level number to edit -->";
					cin >> value;
					Flush();
					int level = -1;
					if (sscanf_s(value.c_str(), "%d", &level) != 1 || level < 0)
					{
						cout << "Invalid level number: " << value << endl;
						continue;
					}
					if (!c.ExistLevel(level))
					{
						cout << "Level " << level << " does not exit in campaign" << endl;
						continue;
					}
					// edit using our map editor class
					MapEditor me;
					me.EditMap(c.GetMap(level), c.GetFileName(level)); 
					break;
				} while (true);

			}
		}
		else if (opc.compare("8") == 0)	// duplicate a map
		{

			string value;
			if (c.Size() == 0)
			{
				cout << "There is nothing to duplicate. Campaign is empty now... press enter -->";
				cin >> value;
				Flush();
			}
			else
			{
				cout << "These are the set of Maps in the current Campaign" << endl;
				c.Print();
				do
				{
					cout << "Please, select a level number to duplicate -->";
					cin >> value;
					Flush();
					int level = -1;
					if (sscanf_s(value.c_str(), "%d", &level) != 1 || level < 0)
					{
						cout << "Invalid level number: " << value << endl;
						continue;
					}
					if (!c.ExistLevel(level))
					{
						cout << "Level " << level << " does not exit in campaign" << endl;
						continue;
					}
					string newValue;
					do
					{
						cout << "Please, select the new level number for the map number " << level << " -->";
						cin >> newValue;
						Flush();
						int newLevel = -1;
						if (sscanf_s(newValue.c_str(), "%d", &newLevel) != 1 || newLevel < 0)
						{
							cout << "Invalid new level number: " << newValue << endl;
							continue;
						}
						c.SetMap(newLevel, *c.GetMap(level), c.GetFileName(level).c_str());
						break;
					} while (true);
					break;
				} while (true);
			}
		}
		else if (opc.compare("9") == 0)	// build a new map
		{
			string value;
			do
			{
				cout << "Please, select a level number to for the new map -->";
				cin >> value;
				Flush();
				int level = -1;
				if (sscanf_s(value.c_str(), "%d", &level) != 1 || level < 0)
				{
					cout << "Invalid level number: " << value << endl;
					continue;
				}
				if (c.ExistLevel(level))
				{
					cout << "Level " << level << "already exits in campaign" << endl;
					continue;
				}
				int i, j;

				GetSize(i, j);
				Map m;
				m.Create(i, j);

				// entrance
				int row = -1, col = -1;
				do
				{
					cout << "Indicate the row number [1.." << m.GetRows() << "] of the entrance position -->";
					cin >> row;
					Flush();
					cout << "Indicate the column number [1.." << m.GetCols() << "] of the entrance position -->";
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
						if (m.GetCell(row - 1, col - 1) == CHAR_WALL)
							m.setCell(row - 1, col - 1, CHAR_EMPTY);
						// go back to zero based indexes
						row--; col--; break;
					}
				} while (true);
				m.SetEntrance(row, col);

				// exit
				do
				{
					cout << "Indicate the row number [1.." << m.GetRows() << "] of the EXIT position -->";
					cin >> row;
					Flush();
					cout << "Indicate the column number [1.." << m.GetCols() << "] of the EXIT position -->";
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
						if (m.GetCell(row - 1, col - 1) == CHAR_WALL)
							m.setCell(row - 1, col - 1, CHAR_EMPTY);
						// go back to zero based indexes
						row--; col--; break;
					}
				} while (true);
				m.SetExit(row, col);

				// exit
				do
				{
					cout << "Indicate the row number [1.." << m.GetRows() << "] of the PLAYER position -->";
					cin >> row;
					Flush();
					cout << "Indicate the column number [1.." << m.GetCols() << "] of the PLAYER position -->";
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
						if (m.GetCell(row - 1, col - 1) == CHAR_WALL)
							m.setCell(row - 1, col - 1, CHAR_EMPTY);

						// go back to zero based indexes
						row--; col--; break;
					}
				} while (true);
				m.SetPlayerPos(row, col);

				// filename
				char filename[240];
				do
				{
					cout << "Indicate the file name of the map to be saved -->";
					cin.getline(filename, 240);
					NormalizeString(filename);
					MapBuilderB mb(m);
					if (mb.SaveLevel(filename) == 0)
						break;
				} while (true);

				c.SetMap(level, m, filename);
				break;
			} while (true);

		}
		else if (opc.compare("10") == 0)	// display a map
		{
			char filename[240];
			do
			{
				cout << "Indicate map name --> ";
				cin.getline(filename, 240);
				NormalizeString(filename);
				MapDirector d;

				// load map from file
				MapBuilderB mb;
				if (mb.LoadMap(filename, 1))
					continue;

				// set this builder to director
				d.SetBuilder(&mb);
				Map m;

				// get the map from director
				d.GetMap(m);

				m.Display();

				break;
			} while (true);
		}
		else if (opc.compare("11") == 0)	// print maps 
		{
			vector<int> levels;
			c.GetLevels(levels);

			for (int i=0; i<levels.size(); i++)
			{
				Map *m = c.GetMap(levels[i]);
				if (!m)
					continue;

				m->Display();
			} ;
		}
	} while (true);
  
}

