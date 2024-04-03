#include "Festival.h"

Festival::Festival(const char* festivalName):numProjections(0){
	setFestivalName(festivalName);
}

void Festival::setFestivalName(const char* festivalName){
	if (!festivalName || strlen(festivalName) > FEST_NAME)
		return;

	strcpy(this->festivalName, festivalName);
}


void Festival::addProjection(const Projection& projection){
	if (numProjections < MAX_PROJECTIONS){
		projections[numProjections++] = projection;
	}
}

const char* Festival::getFestivalName() const{
	return this->festivalName;
}

const Projection* Festival::getProjections() const{
	return projections;
}

int Festival::getNumProjections() const{
	return this->numProjections;
}
