#pragma once
#include "Weapon.h"
class Pistol : public Weapon {
public:
	Pistol(int renderLayer);
	Pistol();
	
private:
	void initalization();
};