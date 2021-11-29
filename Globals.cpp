//
// Created by Ladislav Davídek on 21.11.2021.
//


#include "Globals.h"

Item emptyItemG;

Location emptyLocationG;


Item* GlobalItems::emptyItem() {
	emptyItemG.modifyItem(&emptyItemG, 'e', false, false, "", "", 0, 0, 0);
	return &emptyItemG;
}

Location* GlobalLocations::emptyLocation() {
	emptyLocationG.name = "";
	emptyLocationG.description = "";
	return &emptyLocationG;
}
