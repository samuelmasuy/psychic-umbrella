#pragma once
#include "Map.h"
#include "Observer.h"
#include "Subject.h"
#include "Logger.h"

/**
* @brief Observer pattern for map
*/
class MapOBS : public Observer {
public:
	/**
	* @brief constructor
	*/
	MapOBS();
	/**
	* @brief Constructor taking a character.
	*
	* @param theCharacter
	*/
	MapOBS(Map* theMap);
	/**
	* @brief Destructor
	*/
	virtual ~MapOBS();
	/**
	* @brief Print the character info.
	*/
	void printMapInfo();
	/**
	* @brief Call when the character is updated.
	*/
	void update();

private:
	Map* theMap;
};

