#include "StdAfx.h"
#include "Combo.h"

Combo::Combo(int id, int spt, int first_id)
{
	this->combo_id = id;
	this->amount = 1;
	this->sprite_id = spt;
	ids.push_back(first_id);
}

Combo::Combo(void)
{
}

Combo::~Combo(void)
{
}
