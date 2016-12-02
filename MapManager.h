#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Map.h"
#include "MapBuilderA.h"
#include "MapBuilderB.h"
#include "MapEditor.h"
#include "MapDirector.h"
#include "Campaign.h"

using namespace std;

void NormalizeString(char *s);
void GetSize(int &r, int &c);
void manageMap();
