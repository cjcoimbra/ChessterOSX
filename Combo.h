#pragma once

class Combo
{
public:
	Combo(int, int, int);
	Combo(void);
	~Combo(void);
	int combo_id;
	int amount;
	int sprite_id;
	std::vector<int> ids;
};
