#include "StdAfx.h"
#include "AnimatedSpike.h"

AnimatedSpike::AnimatedSpike(void)
{
	/*
	this->rm = r;
	this->wnd_ptr = w;
	spike_count = 0;
	is_adding_spike = false;
	is_removing_spike = false;
	tile_size = ts;

	for (int i = 0; i < 8; i++)
		this->spikes[i] = false;
	
	for (int j = 0; j < 8; j++)
		current_frame_of_spike[j] = 0;

	int base = 10000;
	for (int k = 0; k < 11; k++)
	{
		base += k;
		vertical_spike[0][k].SetImage(rm->GetImageResource(base));
		vertical_spike[1][k].SetImage(rm->GetImageResource(base));
		vertical_spike[2][k].SetImage(rm->GetImageResource(base));
		vertical_spike[3][k].SetImage(rm->GetImageResource(base));
		vertical_spike[4][k].SetImage(rm->GetImageResource(base));
		vertical_spike[5][k].SetImage(rm->GetImageResource(base));
		vertical_spike[6][k].SetImage(rm->GetImageResource(base));
		vertical_spike[7][k].SetImage(rm->GetImageResource(base));
	}

	int base2 = 11000;
	for (int k = 0; k < 11; k++)
	{
		base += k;
		horizontal_spike[0][k].SetImage(rm->GetImageResource(base2));
		horizontal_spike[1][k].SetImage(rm->GetImageResource(base2));
		horizontal_spike[2][k].SetImage(rm->GetImageResource(base2));
		horizontal_spike[3][k].SetImage(rm->GetImageResource(base2));
		horizontal_spike[4][k].SetImage(rm->GetImageResource(base2));
		horizontal_spike[5][k].SetImage(rm->GetImageResource(base2));
		horizontal_spike[6][k].SetImage(rm->GetImageResource(base2));
		horizontal_spike[7][k].SetImage(rm->GetImageResource(base2));
	}
*/
}

void AnimatedSpike::ResetAnimationFrames()
{
	for (int j = 0; j < 8; j++)
		current_frame_of_spike[j] = 0;
}

void AnimatedSpike::Init(sf::RenderWindow * w, ResourceManager * r, float ts)
{
	this->rm = r;
	this->wnd_ptr = w;
	spike_count = 0;
	is_adding_spike = false;
	is_removing_spike = false;
	tile_size = ts;

	for (int i = 0; i < 8; i++)
		this->spikes[i] = false;
	
	for (int j = 0; j < 8; j++)
		current_frame_of_spike[j] = 0;


	vertical_spike[0][0].SetImage(rm->GetImageResource(10000));
	vertical_spike[0][0].Resize((float)tile_size,(float) tile_size*8);
	vertical_spike[0][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[1][0].SetImage(rm->GetImageResource(10000));
	vertical_spike[1][0].Resize(tile_size, (float)tile_size*8);
	vertical_spike[1][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[2][0].SetImage(rm->GetImageResource(10000));
	vertical_spike[2][0].Resize(tile_size, (float)tile_size*8);
	vertical_spike[2][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 2*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[3][0].SetImage(rm->GetImageResource(10000));
	vertical_spike[3][0].Resize(tile_size, tile_size*8);
	vertical_spike[3][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 1*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[4][0].SetImage(rm->GetImageResource(10000));
	vertical_spike[4][0].Resize(tile_size, (float)tile_size*8);
	vertical_spike[4][0].SetPosition((float)wnd_ptr->GetWidth()/2, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[5][0].SetImage(rm->GetImageResource(10000));
	vertical_spike[5][0].Resize(tile_size,(float) tile_size*8);
	vertical_spike[5][0].SetPosition((float)wnd_ptr->GetWidth()/2 + 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[6][0].SetImage(rm->GetImageResource(10000));
	vertical_spike[6][0].Resize(tile_size,(float) tile_size*8);
	vertical_spike[6][0].SetPosition((float)wnd_ptr->GetWidth()/2 + 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[7][0].SetImage(rm->GetImageResource(10000));
	vertical_spike[7][0].Resize(tile_size, (float)tile_size*8);
	vertical_spike[7][0].SetPosition((float)wnd_ptr->GetWidth()/2 + 3*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	
	vertical_spike[0][1].SetImage(rm->GetImageResource(10001));
	vertical_spike[0][1].Resize(tile_size, (float)tile_size*8);
	vertical_spike[0][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[1][1].SetImage(rm->GetImageResource(10001));
	vertical_spike[1][1].Resize(tile_size, tile_size*8);
	vertical_spike[1][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[2][1].SetImage(rm->GetImageResource(10001));
	vertical_spike[2][1].Resize(tile_size, (float)tile_size*8);
	vertical_spike[2][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[3][1].SetImage(rm->GetImageResource(10001));
	vertical_spike[3][1].Resize(tile_size, (float)tile_size*8);
	vertical_spike[3][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 1*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[4][1].SetImage(rm->GetImageResource(10001));
	vertical_spike[4][1].Resize(tile_size,(float) tile_size*8);
	vertical_spike[4][1].SetPosition((float)wnd_ptr->GetWidth()/2,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[5][1].SetImage(rm->GetImageResource(10001));
	vertical_spike[5][1].Resize(tile_size, (float)tile_size*8);
	vertical_spike[5][1].SetPosition((float)wnd_ptr->GetWidth()/2 + 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[6][1].SetImage(rm->GetImageResource(10001));
	vertical_spike[6][1].Resize(tile_size, (float)tile_size*8);
	vertical_spike[6][1].SetPosition((float)wnd_ptr->GetWidth()/2 + 2*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[7][1].SetImage(rm->GetImageResource(10001));
	vertical_spike[7][1].Resize(tile_size, (float)tile_size*8);
	vertical_spike[7][1].SetPosition((float)wnd_ptr->GetWidth()/2 + 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);

	vertical_spike[0][2].SetImage(rm->GetImageResource(10002));
	vertical_spike[0][2].Resize(tile_size,(float) tile_size*8);
	vertical_spike[0][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[1][2].SetImage(rm->GetImageResource(10002));
	vertical_spike[1][2].Resize(tile_size, (float)tile_size*8);
	vertical_spike[1][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 3*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[2][2].SetImage(rm->GetImageResource(10002));
	vertical_spike[2][2].Resize(tile_size, (float)tile_size*8);
	vertical_spike[2][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[3][2].SetImage(rm->GetImageResource(10002));
	vertical_spike[3][2].Resize(tile_size, (float)tile_size*8);
	vertical_spike[3][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[4][2].SetImage(rm->GetImageResource(10002));
	vertical_spike[4][2].Resize(tile_size,(float) tile_size*8);
	vertical_spike[4][2].SetPosition((float)wnd_ptr->GetWidth()/2, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[5][2].SetImage(rm->GetImageResource(10002));
	vertical_spike[5][2].Resize(tile_size, tile_size*8);
	vertical_spike[5][2].SetPosition((float)wnd_ptr->GetWidth()/2 + 1*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[6][2].SetImage(rm->GetImageResource(10002));
	vertical_spike[6][2].Resize(tile_size, (float)tile_size*8);
	vertical_spike[6][2].SetPosition((float)wnd_ptr->GetWidth()/2 + 2*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[7][2].SetImage(rm->GetImageResource(10002));
	vertical_spike[7][2].Resize(tile_size, (float)tile_size*8);
	vertical_spike[7][2].SetPosition((float)wnd_ptr->GetWidth()/2 + 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);

	vertical_spike[0][3].SetImage(rm->GetImageResource(10003));
	vertical_spike[0][3].Resize(tile_size,(float) tile_size*8);
	vertical_spike[0][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[1][3].SetImage(rm->GetImageResource(10003));
	vertical_spike[1][3].Resize(tile_size, tile_size*8);
	vertical_spike[1][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[2][3].SetImage(rm->GetImageResource(10003));
	vertical_spike[2][3].Resize(tile_size, (float)tile_size*8);
	vertical_spike[2][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[3][3].SetImage(rm->GetImageResource(10003));
	vertical_spike[3][3].Resize(tile_size, (float)tile_size*8);
	vertical_spike[3][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 1*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[4][3].SetImage(rm->GetImageResource(10003));
	vertical_spike[4][3].Resize(tile_size,(float) tile_size*8);
	vertical_spike[4][3].SetPosition((float)wnd_ptr->GetWidth()/2, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[5][3].SetImage(rm->GetImageResource(10003));
	vertical_spike[5][3].Resize(tile_size,(float) tile_size*8);
	vertical_spike[5][3].SetPosition((float)wnd_ptr->GetWidth()/2 + 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[6][3].SetImage(rm->GetImageResource(10003));
	vertical_spike[6][3].Resize(tile_size, (float)tile_size*8);
	vertical_spike[6][3].SetPosition((float)wnd_ptr->GetWidth()/2 + 2*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[7][3].SetImage(rm->GetImageResource(10003));
	vertical_spike[7][3].Resize(tile_size,(float) tile_size*8);
	vertical_spike[7][3].SetPosition((float)wnd_ptr->GetWidth()/2 + 3*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);

	vertical_spike[0][4].SetImage(rm->GetImageResource(10004));
	vertical_spike[0][4].Resize(tile_size, (float)tile_size*8);
	vertical_spike[0][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[1][4].SetImage(rm->GetImageResource(10004));
	vertical_spike[1][4].Resize(tile_size,(float) tile_size*8);
	vertical_spike[1][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[2][4].SetImage(rm->GetImageResource(10004));
	vertical_spike[2][4].Resize(tile_size,(float) tile_size*8);
	vertical_spike[2][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 2*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[3][4].SetImage(rm->GetImageResource(10004));
	vertical_spike[3][4].Resize(tile_size,(float) tile_size*8);
	vertical_spike[3][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[4][4].SetImage(rm->GetImageResource(10004));
	vertical_spike[4][4].Resize(tile_size,(float) tile_size*8);
	vertical_spike[4][4].SetPosition((float)wnd_ptr->GetWidth()/2,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[5][4].SetImage(rm->GetImageResource(10004));
	vertical_spike[5][4].Resize(tile_size, (float)tile_size*8);
	vertical_spike[5][4].SetPosition((float)wnd_ptr->GetWidth()/2 + 1*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[6][4].SetImage(rm->GetImageResource(10004));
	vertical_spike[6][4].Resize(tile_size, (float)tile_size*8);
	vertical_spike[6][4].SetPosition((float)wnd_ptr->GetWidth()/2 + 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[7][4].SetImage(rm->GetImageResource(10004));
	vertical_spike[7][4].Resize(tile_size, (float)tile_size*8);
	vertical_spike[7][4].SetPosition((float)wnd_ptr->GetWidth()/2 + 3*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);

	vertical_spike[0][5].SetImage(rm->GetImageResource(10005));
	vertical_spike[0][5].Resize(tile_size, (float)tile_size*8);
	vertical_spike[0][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[1][5].SetImage(rm->GetImageResource(10005));
	vertical_spike[1][5].Resize(tile_size, (float)tile_size*8);
	vertical_spike[1][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 3*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[2][5].SetImage(rm->GetImageResource(10005));
	vertical_spike[2][5].Resize(tile_size, (float)tile_size*8);
	vertical_spike[2][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 2*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[3][5].SetImage(rm->GetImageResource(10005));
	vertical_spike[3][5].Resize(tile_size,(float) tile_size*8);
	vertical_spike[3][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[4][5].SetImage(rm->GetImageResource(10005));
	vertical_spike[4][5].Resize(tile_size, (float)tile_size*8);
	vertical_spike[4][5].SetPosition((float)wnd_ptr->GetWidth()/2,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[5][5].SetImage(rm->GetImageResource(10005));
	vertical_spike[5][5].Resize(tile_size,(float) tile_size*8);
	vertical_spike[5][5].SetPosition((float)wnd_ptr->GetWidth()/2 + 1*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[6][5].SetImage(rm->GetImageResource(10005));
	vertical_spike[6][5].Resize(tile_size, (float)tile_size*8);
	vertical_spike[6][5].SetPosition((float)wnd_ptr->GetWidth()/2 + 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[7][5].SetImage(rm->GetImageResource(10005));
	vertical_spike[7][5].Resize(tile_size, (float)tile_size*8);
	vertical_spike[7][5].SetPosition((float)wnd_ptr->GetWidth()/2 + 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);

	vertical_spike[0][6].SetImage(rm->GetImageResource(10006));
	vertical_spike[0][6].Resize(tile_size, (float)tile_size*8);
	vertical_spike[0][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[1][6].SetImage(rm->GetImageResource(10006));
	vertical_spike[1][6].Resize(tile_size, (float)tile_size*8);
	vertical_spike[1][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 3*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[2][6].SetImage(rm->GetImageResource(10006));
	vertical_spike[2][6].Resize(tile_size,(float) tile_size*8);
	vertical_spike[2][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 2*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[3][6].SetImage(rm->GetImageResource(10006));
	vertical_spike[3][6].Resize(tile_size, (float)tile_size*8);
	vertical_spike[3][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[4][6].SetImage(rm->GetImageResource(10006));
	vertical_spike[4][6].Resize(tile_size,(float) tile_size*8);
	vertical_spike[4][6].SetPosition((float)wnd_ptr->GetWidth()/2,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[5][6].SetImage(rm->GetImageResource(10006));
	vertical_spike[5][6].Resize(tile_size, (float)tile_size*8);
	vertical_spike[5][6].SetPosition((float)wnd_ptr->GetWidth()/2 + 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[6][6].SetImage(rm->GetImageResource(10006));
	vertical_spike[6][6].Resize(tile_size,(float) tile_size*8);
	vertical_spike[6][6].SetPosition((float)wnd_ptr->GetWidth()/2 + 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[7][6].SetImage(rm->GetImageResource(10006));
	vertical_spike[7][6].Resize(tile_size,(float) tile_size*8);
	vertical_spike[7][6].SetPosition((float)wnd_ptr->GetWidth()/2 + 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);

	vertical_spike[0][7].SetImage(rm->GetImageResource(10007));
	vertical_spike[0][7].Resize(tile_size, (float)tile_size*8);
	vertical_spike[0][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[1][7].SetImage(rm->GetImageResource(10007));
	vertical_spike[1][7].Resize(tile_size, (float)tile_size*8);
	vertical_spike[1][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[2][7].SetImage(rm->GetImageResource(10007));
	vertical_spike[2][7].Resize(tile_size,(float) tile_size*8);
	vertical_spike[2][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 2*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[3][7].SetImage(rm->GetImageResource(10007));
	vertical_spike[3][7].Resize(tile_size,(float) tile_size*8);
	vertical_spike[3][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[4][7].SetImage(rm->GetImageResource(10007));
	vertical_spike[4][7].Resize(tile_size, (float)tile_size*8);
	vertical_spike[4][7].SetPosition((float)wnd_ptr->GetWidth()/2, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[5][7].SetImage(rm->GetImageResource(10007));
	vertical_spike[5][7].Resize(tile_size, (float)tile_size*8);
	vertical_spike[5][7].SetPosition((float)wnd_ptr->GetWidth()/2 + 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[6][7].SetImage(rm->GetImageResource(10007));
	vertical_spike[6][7].Resize(tile_size,(float) tile_size*8);
	vertical_spike[6][7].SetPosition((float)wnd_ptr->GetWidth()/2 + 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[7][7].SetImage(rm->GetImageResource(10007));
	vertical_spike[7][7].Resize(tile_size, (float)tile_size*8);
	vertical_spike[7][7].SetPosition((float)wnd_ptr->GetWidth()/2 + 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);

	vertical_spike[0][8].SetImage(rm->GetImageResource(10008));
	vertical_spike[0][8].Resize(tile_size, (float)tile_size*8);
	vertical_spike[0][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[1][8].SetImage(rm->GetImageResource(10008));
	vertical_spike[1][8].Resize(tile_size,(float) tile_size*8);
	vertical_spike[1][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 3*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[2][8].SetImage(rm->GetImageResource(10008));
	vertical_spike[2][8].Resize(tile_size,(float) tile_size*8);
	vertical_spike[2][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[3][8].SetImage(rm->GetImageResource(10008));
	vertical_spike[3][8].Resize(tile_size,(float) tile_size*8);
	vertical_spike[3][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[4][8].SetImage(rm->GetImageResource(10008));
	vertical_spike[4][8].Resize(tile_size, (float)tile_size*8);
	vertical_spike[4][8].SetPosition((float)wnd_ptr->GetWidth()/2,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[5][8].SetImage(rm->GetImageResource(10008));
	vertical_spike[5][8].Resize(tile_size,(float) tile_size*8);
	vertical_spike[5][8].SetPosition((float)wnd_ptr->GetWidth()/2 + 1*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[6][8].SetImage(rm->GetImageResource(10008));
	vertical_spike[6][8].Resize(tile_size, (float)tile_size*8);
	vertical_spike[6][8].SetPosition((float)wnd_ptr->GetWidth()/2 + 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[7][8].SetImage(rm->GetImageResource(10008));
	vertical_spike[7][8].Resize(tile_size, (float)tile_size*8);
	vertical_spike[7][8].SetPosition((float)wnd_ptr->GetWidth()/2 + 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);

	vertical_spike[0][9].SetImage(rm->GetImageResource(10009));
	vertical_spike[0][9].Resize(tile_size,(float) tile_size*8);
	vertical_spike[0][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[1][9].SetImage(rm->GetImageResource(10009));
	vertical_spike[1][9].Resize(tile_size, (float)tile_size*8);
	vertical_spike[1][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 3*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[2][9].SetImage(rm->GetImageResource(10009));
	vertical_spike[2][9].Resize(tile_size,(float) tile_size*8);
	vertical_spike[2][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[3][9].SetImage(rm->GetImageResource(10009));
	vertical_spike[3][9].Resize(tile_size, (float)tile_size*8);
	vertical_spike[3][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 1*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[4][9].SetImage(rm->GetImageResource(10009));
	vertical_spike[4][9].Resize(tile_size,(float) tile_size*8);
	vertical_spike[4][9].SetPosition((float)wnd_ptr->GetWidth()/2,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[5][9].SetImage(rm->GetImageResource(10009));
	vertical_spike[5][9].Resize(tile_size, (float)tile_size*8);
	vertical_spike[5][9].SetPosition((float)wnd_ptr->GetWidth()/2 + 1*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[6][9].SetImage(rm->GetImageResource(10009));
	vertical_spike[6][9].Resize(tile_size, (float)tile_size*8);
	vertical_spike[6][9].SetPosition((float)wnd_ptr->GetWidth()/2 + 2*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[7][9].SetImage(rm->GetImageResource(10009));
	vertical_spike[7][9].Resize(tile_size,(float) tile_size*8);
	vertical_spike[7][9].SetPosition((float)wnd_ptr->GetWidth()/2 + 3*tile_size,(float)wnd_ptr->GetHeight()/2 - 4*tile_size);

	vertical_spike[0][10].SetImage(rm->GetImageResource(10010));
	vertical_spike[0][10].Resize(tile_size,(float) tile_size*8);
	vertical_spike[0][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[1][10].SetImage(rm->GetImageResource(10010));
	vertical_spike[1][10].Resize(tile_size, (float)tile_size*8);
	vertical_spike[1][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 3*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[2][10].SetImage(rm->GetImageResource(10010));
	vertical_spike[2][10].Resize(tile_size, (float)tile_size*8);
	vertical_spike[2][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 2*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[3][10].SetImage(rm->GetImageResource(10010));
	vertical_spike[3][10].Resize(tile_size, (float)tile_size*8);
	vertical_spike[3][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 1*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[4][10].SetImage(rm->GetImageResource(10010));
	vertical_spike[4][10].Resize(tile_size, (float)tile_size*8);
	vertical_spike[4][10].SetPosition((float)wnd_ptr->GetWidth()/2, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[5][10].SetImage(rm->GetImageResource(10010));
	vertical_spike[5][10].Resize(tile_size, (float)tile_size*8);
	vertical_spike[5][10].SetPosition((float)wnd_ptr->GetWidth()/2 + 1*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[6][10].SetImage(rm->GetImageResource(10010));
	vertical_spike[6][10].Resize(tile_size, (float)tile_size*8);
	vertical_spike[6][10].SetPosition((float)wnd_ptr->GetWidth()/2 + 2*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	vertical_spike[7][10].SetImage(rm->GetImageResource(10010));
	vertical_spike[7][10].Resize(tile_size, (float)tile_size*8);
	vertical_spike[7][10].SetPosition((float)wnd_ptr->GetWidth()/2 + 3*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);

	//HORIZONTAL SPIKES
	horizontal_spike[0][0].SetImage(rm->GetImageResource(11000));
	horizontal_spike[0][0].Resize((float)tile_size*8, tile_size);
	horizontal_spike[0][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	horizontal_spike[1][0].SetImage(rm->GetImageResource(11000));
	horizontal_spike[1][0].Resize((float)tile_size*8, tile_size);
	horizontal_spike[1][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 3*tile_size);
	horizontal_spike[2][0].SetImage(rm->GetImageResource(11000));
	horizontal_spike[2][0].Resize((float)tile_size*8, tile_size);
	horizontal_spike[2][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 2*tile_size);
	horizontal_spike[3][0].SetImage(rm->GetImageResource(11000));
	horizontal_spike[3][0].Resize((float)tile_size*8, tile_size);
	horizontal_spike[3][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 1*tile_size);
	horizontal_spike[4][0].SetImage(rm->GetImageResource(11000));
	horizontal_spike[4][0].Resize((float)tile_size*8, tile_size);
	horizontal_spike[4][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2);
	horizontal_spike[5][0].SetImage(rm->GetImageResource(11000));
	horizontal_spike[5][0].Resize((float)tile_size*8, tile_size);
	horizontal_spike[5][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 1*tile_size);
	horizontal_spike[6][0].SetImage(rm->GetImageResource(11000));
	horizontal_spike[6][0].Resize((float)tile_size*8, tile_size);
	horizontal_spike[6][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 2*tile_size);
	horizontal_spike[7][0].SetImage(rm->GetImageResource(11000));
	horizontal_spike[7][0].Resize((float)tile_size*8, tile_size);
	horizontal_spike[7][0].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 3*tile_size);

	horizontal_spike[0][1].SetImage(rm->GetImageResource(11001));
	horizontal_spike[0][1].Resize((float)tile_size*8, tile_size);
	horizontal_spike[0][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	horizontal_spike[1][1].SetImage(rm->GetImageResource(11001));
	horizontal_spike[1][1].Resize((float)tile_size*8, tile_size);
	horizontal_spike[1][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 3*tile_size);
	horizontal_spike[2][1].SetImage(rm->GetImageResource(11001));
	horizontal_spike[2][1].Resize((float)tile_size*8, tile_size);
	horizontal_spike[2][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 2*tile_size);
	horizontal_spike[3][1].SetImage(rm->GetImageResource(11001));
	horizontal_spike[3][1].Resize((float)tile_size*8, tile_size);
	horizontal_spike[3][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 1*tile_size);
	horizontal_spike[4][1].SetImage(rm->GetImageResource(11001));
	horizontal_spike[4][1].Resize((float)tile_size*8, tile_size);
	horizontal_spike[4][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2);
	horizontal_spike[5][1].SetImage(rm->GetImageResource(11001));
	horizontal_spike[5][1].Resize((float)tile_size*8, tile_size);
	horizontal_spike[5][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 1*tile_size);
	horizontal_spike[6][1].SetImage(rm->GetImageResource(11001));
	horizontal_spike[6][1].Resize((float)tile_size*8, tile_size);
	horizontal_spike[6][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 2*tile_size);
	horizontal_spike[7][1].SetImage(rm->GetImageResource(11001));
	horizontal_spike[7][1].Resize((float)tile_size*8, tile_size);
	horizontal_spike[7][1].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 3*tile_size);

	horizontal_spike[0][2].SetImage(rm->GetImageResource(11002));
	horizontal_spike[0][2].Resize((float)tile_size*8, tile_size);
	horizontal_spike[0][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	horizontal_spike[1][2].SetImage(rm->GetImageResource(11002));
	horizontal_spike[1][2].Resize((float)tile_size*8, tile_size);
	horizontal_spike[1][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 3*tile_size);
	horizontal_spike[2][2].SetImage(rm->GetImageResource(11002));
	horizontal_spike[2][2].Resize((float)tile_size*8, tile_size);
	horizontal_spike[2][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 2*tile_size);
	horizontal_spike[3][2].SetImage(rm->GetImageResource(11002));
	horizontal_spike[3][2].Resize((float)tile_size*8, tile_size);
	horizontal_spike[3][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 1*tile_size);
	horizontal_spike[4][2].SetImage(rm->GetImageResource(11002));
	horizontal_spike[4][2].Resize((float)tile_size*8, tile_size);
	horizontal_spike[4][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2);
	horizontal_spike[5][2].SetImage(rm->GetImageResource(11002));
	horizontal_spike[5][2].Resize((float)tile_size*8, tile_size);
	horizontal_spike[5][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 1*tile_size);
	horizontal_spike[6][2].SetImage(rm->GetImageResource(11002));
	horizontal_spike[6][2].Resize((float)tile_size*8, tile_size);
	horizontal_spike[6][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 2*tile_size);
	horizontal_spike[7][2].SetImage(rm->GetImageResource(11002));
	horizontal_spike[7][2].Resize((float)tile_size*8, tile_size);
	horizontal_spike[7][2].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 3*tile_size);

	horizontal_spike[0][3].SetImage(rm->GetImageResource(11003));
	horizontal_spike[0][3].Resize((float)tile_size*8, tile_size);
	horizontal_spike[0][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	horizontal_spike[1][3].SetImage(rm->GetImageResource(11003));
	horizontal_spike[1][3].Resize((float)tile_size*8, tile_size);
	horizontal_spike[1][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 3*tile_size);
	horizontal_spike[2][3].SetImage(rm->GetImageResource(11003));
	horizontal_spike[2][3].Resize((float)tile_size*8, tile_size);
	horizontal_spike[2][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 2*tile_size);
	horizontal_spike[3][3].SetImage(rm->GetImageResource(11003));
	horizontal_spike[3][3].Resize((float)tile_size*8, tile_size);
	horizontal_spike[3][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 1*tile_size);
	horizontal_spike[4][3].SetImage(rm->GetImageResource(11003));
	horizontal_spike[4][3].Resize((float)tile_size*8, tile_size);
	horizontal_spike[4][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2);
	horizontal_spike[5][3].SetImage(rm->GetImageResource(11003));
	horizontal_spike[5][3].Resize((float)tile_size*8, tile_size);
	horizontal_spike[5][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 1*tile_size);
	horizontal_spike[6][3].SetImage(rm->GetImageResource(11003));
	horizontal_spike[6][3].Resize((float)tile_size*8, tile_size);
	horizontal_spike[6][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 2*tile_size);
	horizontal_spike[7][3].SetImage(rm->GetImageResource(11003));
	horizontal_spike[7][3].Resize((float)tile_size*8, tile_size);
	horizontal_spike[7][3].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 3*tile_size);

	horizontal_spike[0][4].SetImage(rm->GetImageResource(11004));
	horizontal_spike[0][4].Resize((float)tile_size*8, tile_size);
	horizontal_spike[0][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	horizontal_spike[1][4].SetImage(rm->GetImageResource(11004));
	horizontal_spike[1][4].Resize((float)tile_size*8, tile_size);
	horizontal_spike[1][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 3*tile_size);
	horizontal_spike[2][4].SetImage(rm->GetImageResource(11004));
	horizontal_spike[2][4].Resize((float)tile_size*8, tile_size);
	horizontal_spike[2][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 2*tile_size);
	horizontal_spike[3][4].SetImage(rm->GetImageResource(11004));
	horizontal_spike[3][4].Resize((float)tile_size*8, tile_size);
	horizontal_spike[3][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 1*tile_size);
	horizontal_spike[4][4].SetImage(rm->GetImageResource(11004));
	horizontal_spike[4][4].Resize((float)tile_size*8, tile_size);
	horizontal_spike[4][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2);
	horizontal_spike[5][4].SetImage(rm->GetImageResource(11004));
	horizontal_spike[5][4].Resize((float)tile_size*8, tile_size);
	horizontal_spike[5][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 1*tile_size);
	horizontal_spike[6][4].SetImage(rm->GetImageResource(11004));
	horizontal_spike[6][4].Resize((float)tile_size*8, tile_size);
	horizontal_spike[6][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 2*tile_size);
	horizontal_spike[7][4].SetImage(rm->GetImageResource(11004));
	horizontal_spike[7][4].Resize((float)tile_size*8, tile_size);
	horizontal_spike[7][4].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 3*tile_size);

	horizontal_spike[0][5].SetImage(rm->GetImageResource(11005));
	horizontal_spike[0][5].Resize((float)tile_size*8, tile_size);
	horizontal_spike[0][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	horizontal_spike[1][5].SetImage(rm->GetImageResource(11005));
	horizontal_spike[1][5].Resize((float)tile_size*8, tile_size);
	horizontal_spike[1][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 3*tile_size);
	horizontal_spike[2][5].SetImage(rm->GetImageResource(11005));
	horizontal_spike[2][5].Resize((float)tile_size*8, tile_size);
	horizontal_spike[2][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 2*tile_size);
	horizontal_spike[3][5].SetImage(rm->GetImageResource(11005));
	horizontal_spike[3][5].Resize((float)tile_size*8, tile_size);
	horizontal_spike[3][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 1*tile_size);
	horizontal_spike[4][5].SetImage(rm->GetImageResource(11005));
	horizontal_spike[4][5].Resize((float)tile_size*8, tile_size);
	horizontal_spike[4][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2);
	horizontal_spike[5][5].SetImage(rm->GetImageResource(11005));
	horizontal_spike[5][5].Resize((float)tile_size*8, tile_size);
	horizontal_spike[5][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 1*tile_size);
	horizontal_spike[6][5].SetImage(rm->GetImageResource(11005));
	horizontal_spike[6][5].Resize((float)tile_size*8, tile_size);
	horizontal_spike[6][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 2*tile_size);
	horizontal_spike[7][5].SetImage(rm->GetImageResource(11005));
	horizontal_spike[7][5].Resize((float)tile_size*8, tile_size);
	horizontal_spike[7][5].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 3*tile_size);

	horizontal_spike[0][6].SetImage(rm->GetImageResource(11006));
	horizontal_spike[0][6].Resize((float)tile_size*8, tile_size);
	horizontal_spike[0][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	horizontal_spike[1][6].SetImage(rm->GetImageResource(11006));
	horizontal_spike[1][6].Resize((float)tile_size*8, tile_size);
	horizontal_spike[1][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 3*tile_size);
	horizontal_spike[2][6].SetImage(rm->GetImageResource(11006));
	horizontal_spike[2][6].Resize((float)tile_size*8, tile_size);
	horizontal_spike[2][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 2*tile_size);
	horizontal_spike[3][6].SetImage(rm->GetImageResource(11006));
	horizontal_spike[3][6].Resize((float)tile_size*8, tile_size);
	horizontal_spike[3][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 1*tile_size);
	horizontal_spike[4][6].SetImage(rm->GetImageResource(11006));
	horizontal_spike[4][6].Resize((float)tile_size*8, tile_size);
	horizontal_spike[4][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2);
	horizontal_spike[5][6].SetImage(rm->GetImageResource(11006));
	horizontal_spike[5][6].Resize((float)tile_size*8, tile_size);
	horizontal_spike[5][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 1*tile_size);
	horizontal_spike[6][6].SetImage(rm->GetImageResource(11006));
	horizontal_spike[6][6].Resize((float)tile_size*8, tile_size);
	horizontal_spike[6][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 2*tile_size);
	horizontal_spike[7][6].SetImage(rm->GetImageResource(11006));
	horizontal_spike[7][6].Resize((float)tile_size*8, tile_size);
	horizontal_spike[7][6].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 3*tile_size);

	horizontal_spike[0][7].SetImage(rm->GetImageResource(11007));
	horizontal_spike[0][7].Resize((float)tile_size*8, tile_size);
	horizontal_spike[0][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	horizontal_spike[1][7].SetImage(rm->GetImageResource(11007));
	horizontal_spike[1][7].Resize((float)tile_size*8, tile_size);
	horizontal_spike[1][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 3*tile_size);
	horizontal_spike[2][7].SetImage(rm->GetImageResource(11007));
	horizontal_spike[2][7].Resize((float)tile_size*8, tile_size);
	horizontal_spike[2][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 2*tile_size);
	horizontal_spike[3][7].SetImage(rm->GetImageResource(11007));
	horizontal_spike[3][7].Resize((float)tile_size*8, tile_size);
	horizontal_spike[3][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 1*tile_size);
	horizontal_spike[4][7].SetImage(rm->GetImageResource(11007));
	horizontal_spike[4][7].Resize((float)tile_size*8, tile_size);
	horizontal_spike[4][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2);
	horizontal_spike[5][7].SetImage(rm->GetImageResource(11007));
	horizontal_spike[5][7].Resize((float)tile_size*8, tile_size);
	horizontal_spike[5][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 1*tile_size);
	horizontal_spike[6][7].SetImage(rm->GetImageResource(11007));
	horizontal_spike[6][7].Resize((float)tile_size*8, tile_size);
	horizontal_spike[6][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 2*tile_size);
	horizontal_spike[7][7].SetImage(rm->GetImageResource(11007));
	horizontal_spike[7][7].Resize((float)tile_size*8, tile_size);
	horizontal_spike[7][7].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 3*tile_size);

	horizontal_spike[0][8].SetImage(rm->GetImageResource(11008));
	horizontal_spike[0][8].Resize((float)tile_size*8, tile_size);
	horizontal_spike[0][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	horizontal_spike[1][8].SetImage(rm->GetImageResource(11008));
	horizontal_spike[1][8].Resize((float)tile_size*8, tile_size);
	horizontal_spike[1][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 3*tile_size);
	horizontal_spike[2][8].SetImage(rm->GetImageResource(11008));
	horizontal_spike[2][8].Resize((float)tile_size*8, tile_size);
	horizontal_spike[2][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 2*tile_size);
	horizontal_spike[3][8].SetImage(rm->GetImageResource(11008));
	horizontal_spike[3][8].Resize((float)tile_size*8, tile_size);
	horizontal_spike[3][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 1*tile_size);
	horizontal_spike[4][8].SetImage(rm->GetImageResource(11008));
	horizontal_spike[4][8].Resize((float)tile_size*8, tile_size);
	horizontal_spike[4][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2);
	horizontal_spike[5][8].SetImage(rm->GetImageResource(11008));
	horizontal_spike[5][8].Resize((float)tile_size*8, tile_size);
	horizontal_spike[5][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 1*tile_size);
	horizontal_spike[6][8].SetImage(rm->GetImageResource(11008));
	horizontal_spike[6][8].Resize((float)tile_size*8, tile_size);
	horizontal_spike[6][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 2*tile_size);
	horizontal_spike[7][8].SetImage(rm->GetImageResource(11008));
	horizontal_spike[7][8].Resize((float)tile_size*8, tile_size);
	horizontal_spike[7][8].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 3*tile_size);
	
	horizontal_spike[0][9].SetImage(rm->GetImageResource(11009));
	horizontal_spike[0][9].Resize((float)tile_size*8, tile_size);
	horizontal_spike[0][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	horizontal_spike[1][9].SetImage(rm->GetImageResource(11009));
	horizontal_spike[1][9].Resize((float)tile_size*8, tile_size);
	horizontal_spike[1][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 3*tile_size);
	horizontal_spike[2][9].SetImage(rm->GetImageResource(11009));
	horizontal_spike[2][9].Resize((float)tile_size*8, tile_size);
	horizontal_spike[2][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 2*tile_size);
	horizontal_spike[3][9].SetImage(rm->GetImageResource(11009));
	horizontal_spike[3][9].Resize((float)tile_size*8, tile_size);
	horizontal_spike[3][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 1*tile_size);
	horizontal_spike[4][9].SetImage(rm->GetImageResource(11009));
	horizontal_spike[4][9].Resize((float)tile_size*8, tile_size);
	horizontal_spike[4][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2);
	horizontal_spike[5][9].SetImage(rm->GetImageResource(11009));
	horizontal_spike[5][9].Resize((float)tile_size*8, tile_size);
	horizontal_spike[5][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 1*tile_size);
	horizontal_spike[6][9].SetImage(rm->GetImageResource(11009));
	horizontal_spike[6][9].Resize((float)tile_size*8, tile_size);
	horizontal_spike[6][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 2*tile_size);
	horizontal_spike[7][9].SetImage(rm->GetImageResource(11009));
	horizontal_spike[7][9].Resize((float)tile_size*8, tile_size);
	horizontal_spike[7][9].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 3*tile_size);

	horizontal_spike[0][10].SetImage(rm->GetImageResource(11010));
	horizontal_spike[0][10].Resize((float)tile_size*8, tile_size);
	horizontal_spike[0][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 4*tile_size);
	horizontal_spike[1][10].SetImage(rm->GetImageResource(11010));
	horizontal_spike[1][10].Resize((float)tile_size*8, tile_size);
	horizontal_spike[1][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 3*tile_size);
	horizontal_spike[2][10].SetImage(rm->GetImageResource(11010));
	horizontal_spike[2][10].Resize((float)tile_size*8, tile_size);
	horizontal_spike[2][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 2*tile_size);
	horizontal_spike[3][10].SetImage(rm->GetImageResource(11010));
	horizontal_spike[3][10].Resize((float)tile_size*8, tile_size);
	horizontal_spike[3][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2 - 1*tile_size);
	horizontal_spike[4][10].SetImage(rm->GetImageResource(11010));
	horizontal_spike[4][10].Resize((float)tile_size*8, tile_size);
	horizontal_spike[4][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, (float)wnd_ptr->GetHeight()/2);
	horizontal_spike[5][10].SetImage(rm->GetImageResource(11010));
	horizontal_spike[5][10].Resize((float)tile_size*8, tile_size);
	horizontal_spike[5][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 1*tile_size);
	horizontal_spike[6][10].SetImage(rm->GetImageResource(11010));
	horizontal_spike[6][10].Resize((float)tile_size*8, tile_size);
	horizontal_spike[6][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 2*tile_size);
	horizontal_spike[7][10].SetImage(rm->GetImageResource(11010));
	horizontal_spike[7][10].Resize((float)tile_size*8, tile_size);
	horizontal_spike[7][10].SetPosition((float)wnd_ptr->GetWidth()/2 - 4*tile_size, wnd_ptr->GetHeight()/2 + 3*tile_size);
}

void AnimatedSpike::LoadSavedSpikes(int amount)
{
	for (int j = 0; j < amount; j++)
	{
		spike_count++;
		this->spikes[j] = true;
		current_frame_of_spike[j] = 10;
		
	}
}

void AnimatedSpike::DrawSpikes()
{
	for (int j = 0; j < 8; j++)
	{
		if (this->spikes[j])
		{
			wnd_ptr->Draw(horizontal_spike[j][current_frame_of_spike[j]]);
			wnd_ptr->Draw(vertical_spike[j][current_frame_of_spike[j]]);
		}
	}
	UpdateSpikes();
}

void AnimatedSpike::AddSpike()
{
	spike_count++;
	is_adding_spike = true;
	is_removing_spike = false;

	for (int i = 0; i < this->spike_count; i++)
	{
		this->spikes[i] = true;
	}
	spike_animation_timer.Reset();
}

void AnimatedSpike::ResetSpikes()
{
	is_removing_spike = false;
	is_adding_spike = false;
	for (int i = 0; i < 8; i++)
	{
		this->spikes[i] = false;
		current_frame_of_spike[i] = 0;
	}
	spike_count = 0;
}

void AnimatedSpike::RemoveSpikes()
{
	
	
	/*
	for (int i = 0; i < 8; i++)
		this->spikes[i] = false;
	*/

	is_removing_spike = true;

	spike_animation_timer.Reset();
}

void AnimatedSpike::UpdateSpikes()
{
	if (is_adding_spike)
	{
		//std::cout << "\n ADDING SPIKE !!! \n";

		if (spike_animation_timer.GetElapsedTime() >= 0.04f)
		{
			if (current_frame_of_spike[spike_count - 1] < 10)
				current_frame_of_spike[spike_count - 1]++;
			else
				is_adding_spike = false;

			spike_animation_timer.Reset();
		}
	}
	else if (is_removing_spike)
	{
		//std::cout << "\n REMOVING SPIKE !!! \n";
		
		if (spike_animation_timer.GetElapsedTime() >= 0.04f)
		{
			for (int i = 0; i < spike_count; i++)
			{
				if (current_frame_of_spike[i] > 0)
					current_frame_of_spike[i]--;
				else
				{
					is_removing_spike = false;
					
					for (int i = 0; i < 8; i++)
						this->spikes[i] = false;

					spike_count = 0;
				}
			}

			spike_animation_timer.Reset();
		}
	}
	else
		return;
}

AnimatedSpike::~AnimatedSpike(void)
{
}
