#pragma once
#include "Wepon.h"
class Pistol : public Wepon {
public:
	Pistol(int renderLayer);
	Pistol();
	
private:
	void initalization();
};