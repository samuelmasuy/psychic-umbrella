# Psychic Umbrella

*COMP345: Advanced program design with C++*

## Authors

Cristian Ardelean 27498691
Nadia Sheikh 25644151
Ahamd Baiazid 27393016
Samuel Masuy 26590624

## Usage

**WARNING** Please make sure to have all the text file in this directory, at the
reach of the program. So that they can be used to interact with the map.

### How to Create a Campaign
(ALL MAPS AND CAMPAIGNS HAVE TO BE IN THE PROJECT DIRECTORY)

1. The campaign menu starts with a fresh empty campaign, so in order to create one, you simply build Maps of different levels(Option number 9) and save them or load a map into the campaign(Option number 5). After you are done saving the maps, choose the option to Save the campaign, make sure to always save with .txt at the end as an extension. Once the campaign is saved it stores your collection of newly created maps in order from the lowest level to the highest.
2. If you want to edit a map you created in a campaign, or an already existing map in a loaded campaign, simply choose the Edit a map option(Option 7), and modify the cells as you please. This will only work if the map you want to load is in your campaign. Choose save and it will save the map you edited to the campaign, choose Exit to main menu, and it will leave without saving any of the changes you made from the last time you saved.
3. Build a Map, you can always build a map, in order for a map to be valid it has to have an Entry, an Exit, and a Player. The program will prompt you where to add these automatically, that way we always ensure an entry, exit and a player on the map. 
4. You can display or load a map/levels by inputing its name from the Display all levels or Display a map options.
5. Once you are done and exit the campaign editor (Option 12) and its time to play, you can attempt to load ErrorMap1.ext, ErrorMa21.ext, ErrorMap3.ext to show all the invalid map types, this is our verification process. We will not be able to load a map without an entrance, exit or player.

## Design

* We extensively used the builder pattern for each part of this project.
* The Game is separted into two part, first of all there is the Map Manager,
  where you can edit maps, create them, create campaign, and save them. The
  second part is the game itself, where the user can move its character along
  the map, open chests, and reach the final destination.

### Map Design

The player usually starts at the entry of the map `E`, the goal is to reach the
exit denoted by `O`.

	Empty   ' '
	Player  'P'
	Enemy   'E'
	Wall    '*'
	Entry   'I'
	Exit    'O'
	Chest   'c'


