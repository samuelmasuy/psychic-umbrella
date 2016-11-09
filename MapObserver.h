#include "MapBuilder.h"
///
/// Here is our Observer class in which the map maintains a list of dependents and notifies them automatically of any state changes, usually by calling a method.
///
class MapObserver
{
	///
	/// Here we are creating a pointer to the object to be observed which is the map.
	///
	Map *m_pMap;
public:
	///
	/// Here is our default constructor
	///
	MapObserver();
	///
	/// Creating a Constructor with a map
	///
	MapObserver(Map *m);
	///
	/// Creating the Destructor
	///
	~MapObserver();
	///
	/// Here we set the current object to be observed which is again the map
	///
	void SetMap(Map *m);
	///
	/// Here we are displaying the observed object
	///
	void Display();
	///
	/// Here we get an update everytime that something changes
	///
	virtual void Update();
};

