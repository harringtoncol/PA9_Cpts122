#pragma once
#include "Weapon.h"
class AK47 : public Weapon {
public:
	AK47(int renderLayer);
	AK47();

private:
	void initalization();

};