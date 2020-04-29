#pragma once
#include "Weapon.h"
class Sniper : public Weapon {
public:
	Sniper(int renderLayer);
	Sniper();

private:
	void initalization();


};