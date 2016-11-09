#include "MapEditor.h"

/**
 * @brief Create a map manually from scratch
 * it should create the map and save it to a file.
 * the file should be name.map
 *
 * @param filename name of the new map
 */
MapEditor::MapEditor(string name) {
// TODO need modification
  int row = -1, col = -1;
  do {
    cout << "Please enter Row number [1.." << m.GetRows() << "] of the cell -->";
    cin >> row;
    Flush();
    cout << "Please enter Column number [1.." << m.GetCols() << "] of the cell -->";
    cin >> col;
    Flush();
    if (!m.ValidPos(row - 1, col - 1)) {
      cout << "Invalid position (" << row << "," << col << ")" << endl;
      cout << "Row should be between 1 and " << m.GetRows() << endl;
      cout << "Col should be between 1 and " << m.GetCols() << endl;
    } else {
      row--;
      col--;
      break;
    }
  } while (true);

  do {
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
    if (opc.compare("1") == 0) {
      m.StoreCell(row, col, CHAR_EMPTY);
      break;
    } else if (opc.compare("2") == 0) {
      if (m.SetPlayerPos(row, col) == false)
        cout << "Invalid position for player: This position contains a wall" << endl;
      else
        break;
    } else if (opc.compare("3") == 0) {
      m.StoreCell(row, col, CHAR_ENEMY);
      break;
    } else if (opc.compare("4") == 0) {
      m.StoreCell(row, col, CHAR_WALL);
      break;
    } else if (opc.compare("5") == 0) {
      if (m.SetEntrance(row, col))
        break;
      else
        cout << "Invalid position for entrance: This position contains a wall or exit" << endl;
    } else if (opc.compare("6") == 0) {
      if (m.SetExit(row, col))
        break;
      else
        cout << "Invalid position for exit: This position contains an entrance or wall" << endl;
    } else if (opc.compare("7") == 0) {
      m.StoreCell(row, col, CHAR_CHEST);
      break;
    } else if (opc.compare("8") == 0) {
      m.StoreCell(row, col, CHAR_ARMOR);
      break;
    } else if (opc.compare("9") == 0) {
      m.StoreCell(row, col, CHAR_SHIELD);
      break;
    } else if (opc.compare("10") == 0) {
      m.StoreCell(row, col, CHAR_WEAPON);
      break;
    } else if (opc.compare("11") == 0) {
      m.StoreCell(row, col, CHAR_BOOTS);
      break;
    } else if (opc.compare("12") == 0) {
      m.StoreCell(row, col, CHAR_RING);
      break;
    } else if (opc.compare("13") == 0) {
      m.StoreCell(row, col, CHAR_HELMET);
      break;
    } else if (opc.compare("14") == 0)
      break;
    else
      cout << "Invalid option: " << opc << endl;

  } while (true);
}
