# COMP345 - Project Make File
CC=g++

CFLAGS=-Wall

OUT=main
all:
	$(CC) $(CFLAGS) Campaign.cpp Character.cpp CharacterOBS.cpp Chest.cpp ChestBuilder.cpp ChestDirector.cpp Enhancement.cpp EnhancementBuilder.cpp EnhancementDirector.cpp Game.cpp GameBuilder.cpp Item.cpp ItemBuilder.cpp ItemContainer.cpp ItemDirector.cpp Map.cpp MapBuilder.cpp MapBuilderA.cpp MapBuilderB.cpp MapDirector.cpp MapEditor.cpp MapManager.cpp MapObserver.cpp Observer.cpp Subject.cpp main.cpp -o $(OUT)
clean:
	rm -rf *.o $(OUT)
doc:
	doxygen doc_generator
