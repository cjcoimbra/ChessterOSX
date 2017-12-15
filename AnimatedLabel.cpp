#include "StdAfx.h"
#include "AnimatedLabel.h"

AnimatedLabel::AnimatedLabel(void)
{
	this->mode = "NONE";
	/*
	this->wnd_ptr = rw;
	this->rm = rm;
	//Load labels gfx
	std::cout << "Loading animated labels...";
	for (int i = 0; i < 13; i++)
	{
		if (i == 6 || i == 7)
			continue;
		
		int base_id;

		if (i == 0)
			base_id = 1000;
		else if (i == 1)
			base_id = 1100;
		else if (i == 2)
			base_id = 1200;
		else if (i == 3)
			base_id = 1300;
		else if (i == 4)
			base_id = 1400;
		else if (i == 5)
			base_id = 1500;
		else if (i == 8)
			base_id = 1800;
		else if (i == 9)
			base_id = 1900;
		else if (i == 10)
			base_id = 2000;
		else if (i == 11)
			base_id = 2100;
		else if (i == 12)
			base_id = 2200;

		for (int j = 0; j < 17; j++)
		{
			base_id += j;
			this->combo_labels[i][j].SetImage(rm->GetImageResource(base_id));
			this->combo_labels[i][j].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
			this->combo_labels[i][j].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
		}		
	}
	std::cout << " Done!\n";
	*/
}

void AnimatedLabel::Init(sf::RenderWindow * rw, ResourceManager * rm)
{
	this->wnd_ptr = rw;
	this->rm = rm;
	//Load labels gfx
	std::cout << "Loading animated labels...";

	this->combo_labels[0][0].SetImage(rm->GetImageResource(1000));
	this->combo_labels[0][0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][1].SetImage(rm->GetImageResource(1001));
	this->combo_labels[0][1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][2].SetImage(rm->GetImageResource(1002));
	this->combo_labels[0][2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][3].SetImage(rm->GetImageResource(1003));
	this->combo_labels[0][3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][4].SetImage(rm->GetImageResource(1004));
	this->combo_labels[0][4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][5].SetImage(rm->GetImageResource(1005));
	this->combo_labels[0][5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][6].SetImage(rm->GetImageResource(1006));
	this->combo_labels[0][6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][7].SetImage(rm->GetImageResource(1007));
	this->combo_labels[0][7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][8].SetImage(rm->GetImageResource(1008));
	this->combo_labels[0][8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][9].SetImage(rm->GetImageResource(1009));
	this->combo_labels[0][9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][10].SetImage(rm->GetImageResource(1010));
	this->combo_labels[0][10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][11].SetImage(rm->GetImageResource(1011));
	this->combo_labels[0][11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920,(float) (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][12].SetImage(rm->GetImageResource(1012));
	this->combo_labels[0][12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][13].SetImage(rm->GetImageResource(1013));
	this->combo_labels[0][13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][14].SetImage(rm->GetImageResource(1014));
	this->combo_labels[0][14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][15].SetImage(rm->GetImageResource(1015));
	this->combo_labels[0][15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[0][16].SetImage(rm->GetImageResource(1016));
	this->combo_labels[0][16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[0][16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	//knight
	this->combo_labels[1][0].SetImage(rm->GetImageResource(1100));
	this->combo_labels[1][0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][1].SetImage(rm->GetImageResource(1101));
	this->combo_labels[1][1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][2].SetImage(rm->GetImageResource(1102));
	this->combo_labels[1][2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][3].SetImage(rm->GetImageResource(1103));
	this->combo_labels[1][3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][4].SetImage(rm->GetImageResource(1104));
	this->combo_labels[1][4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][5].SetImage(rm->GetImageResource(1105));
	this->combo_labels[1][5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][6].SetImage(rm->GetImageResource(1106));
	this->combo_labels[1][6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][7].SetImage(rm->GetImageResource(1107));
	this->combo_labels[1][7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][8].SetImage(rm->GetImageResource(1108));
	this->combo_labels[1][8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][9].SetImage(rm->GetImageResource(1109));
	this->combo_labels[1][9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][10].SetImage(rm->GetImageResource(1110));
	this->combo_labels[1][10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][11].SetImage(rm->GetImageResource(1111));
	this->combo_labels[1][11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][12].SetImage(rm->GetImageResource(1112));
	this->combo_labels[1][12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][13].SetImage(rm->GetImageResource(1113));
	this->combo_labels[1][13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][14].SetImage(rm->GetImageResource(1114));
	this->combo_labels[1][14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][15].SetImage(rm->GetImageResource(1115));
	this->combo_labels[1][15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[1][16].SetImage(rm->GetImageResource(1116));
	this->combo_labels[1][16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[1][16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	//Rook
	this->combo_labels[2][0].SetImage(rm->GetImageResource(1200));
	this->combo_labels[2][0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][1].SetImage(rm->GetImageResource(1201));
	this->combo_labels[2][1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][2].SetImage(rm->GetImageResource(1202));
	this->combo_labels[2][2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][3].SetImage(rm->GetImageResource(1203));
	this->combo_labels[2][3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][4].SetImage(rm->GetImageResource(1204));
	this->combo_labels[2][4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][5].SetImage(rm->GetImageResource(1205));
	this->combo_labels[2][5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920,(float) (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][6].SetImage(rm->GetImageResource(1206));
	this->combo_labels[2][6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][7].SetImage(rm->GetImageResource(1207));
	this->combo_labels[2][7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][8].SetImage(rm->GetImageResource(1208));
	this->combo_labels[2][8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][9].SetImage(rm->GetImageResource(1209));
	this->combo_labels[2][9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][10].SetImage(rm->GetImageResource(1210));
	this->combo_labels[2][10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][11].SetImage(rm->GetImageResource(1211));
	this->combo_labels[2][11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][12].SetImage(rm->GetImageResource(1212));
	this->combo_labels[2][12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][13].SetImage(rm->GetImageResource(1213));
	this->combo_labels[2][13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][14].SetImage(rm->GetImageResource(1214));
	this->combo_labels[2][14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][15].SetImage(rm->GetImageResource(1215));
	this->combo_labels[2][15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[2][16].SetImage(rm->GetImageResource(1216));
	this->combo_labels[2][16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[2][16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);


	//Bishop
	this->combo_labels[3][0].SetImage(rm->GetImageResource(1300));
	this->combo_labels[3][0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][1].SetImage(rm->GetImageResource(1301));
	this->combo_labels[3][1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][2].SetImage(rm->GetImageResource(1302));
	this->combo_labels[3][2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][3].SetImage(rm->GetImageResource(1303));
	this->combo_labels[3][3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][4].SetImage(rm->GetImageResource(1304));
	this->combo_labels[3][4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][5].SetImage(rm->GetImageResource(1305));
	this->combo_labels[3][5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][6].SetImage(rm->GetImageResource(1306));
	this->combo_labels[3][6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][7].SetImage(rm->GetImageResource(1307));
	this->combo_labels[3][7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][8].SetImage(rm->GetImageResource(1308));
	this->combo_labels[3][8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][9].SetImage(rm->GetImageResource(1309));
	this->combo_labels[3][9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][10].SetImage(rm->GetImageResource(1310));
	this->combo_labels[3][10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][11].SetImage(rm->GetImageResource(1311));
	this->combo_labels[3][11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][12].SetImage(rm->GetImageResource(1312));
	this->combo_labels[3][12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][13].SetImage(rm->GetImageResource(1313));
	this->combo_labels[3][13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][14].SetImage(rm->GetImageResource(1314));
	this->combo_labels[3][14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][15].SetImage(rm->GetImageResource(1315));
	this->combo_labels[3][15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[3][16].SetImage(rm->GetImageResource(1316));
	this->combo_labels[3][16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[3][16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);


//King
	this->combo_labels[4][0].SetImage(rm->GetImageResource(1400));
	this->combo_labels[4][0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][1].SetImage(rm->GetImageResource(1401));
	this->combo_labels[4][1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][2].SetImage(rm->GetImageResource(1402));
	this->combo_labels[4][2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][3].SetImage(rm->GetImageResource(1403));
	this->combo_labels[4][3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][4].SetImage(rm->GetImageResource(1404));
	this->combo_labels[4][4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][5].SetImage(rm->GetImageResource(1405));
	this->combo_labels[4][5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][6].SetImage(rm->GetImageResource(1406));
	this->combo_labels[4][6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][7].SetImage(rm->GetImageResource(1407));
	this->combo_labels[4][7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][8].SetImage(rm->GetImageResource(1408));
	this->combo_labels[4][8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][9].SetImage(rm->GetImageResource(1409));
	this->combo_labels[4][9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][10].SetImage(rm->GetImageResource(1410));
	this->combo_labels[4][10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][11].SetImage(rm->GetImageResource(1411));
	this->combo_labels[4][11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][12].SetImage(rm->GetImageResource(1412));
	this->combo_labels[4][12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][13].SetImage(rm->GetImageResource(1413));
	this->combo_labels[4][13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][14].SetImage(rm->GetImageResource(1414));
	this->combo_labels[4][14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][15].SetImage(rm->GetImageResource(1415));
	this->combo_labels[4][15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[4][16].SetImage(rm->GetImageResource(1416));
	this->combo_labels[4][16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[4][16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	//Queen

	this->combo_labels[5][0].SetImage(rm->GetImageResource(1500));
	this->combo_labels[5][0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][1].SetImage(rm->GetImageResource(1501));
	this->combo_labels[5][1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][2].SetImage(rm->GetImageResource(1502));
	this->combo_labels[5][2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][3].SetImage(rm->GetImageResource(1503));
	this->combo_labels[5][3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][4].SetImage(rm->GetImageResource(1504));
	this->combo_labels[5][4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][5].SetImage(rm->GetImageResource(1505));
	this->combo_labels[5][5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][6].SetImage(rm->GetImageResource(1506));
	this->combo_labels[5][6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][7].SetImage(rm->GetImageResource(1507));
	this->combo_labels[5][7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][8].SetImage(rm->GetImageResource(1508));
	this->combo_labels[5][8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][9].SetImage(rm->GetImageResource(1509));
	this->combo_labels[5][9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][10].SetImage(rm->GetImageResource(1510));
	this->combo_labels[5][10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][11].SetImage(rm->GetImageResource(1511));
	this->combo_labels[5][11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][12].SetImage(rm->GetImageResource(1512));
	this->combo_labels[5][12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][13].SetImage(rm->GetImageResource(1513));
	this->combo_labels[5][13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][14].SetImage(rm->GetImageResource(1514));
	this->combo_labels[5][14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][15].SetImage(rm->GetImageResource(1515));
	this->combo_labels[5][15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[5][16].SetImage(rm->GetImageResource(1516));
	this->combo_labels[5][16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[5][16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);


	//queens...
	this->combo_labels[8][0].SetImage(rm->GetImageResource(1800));
	this->combo_labels[8][0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][1].SetImage(rm->GetImageResource(1801));
	this->combo_labels[8][1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][2].SetImage(rm->GetImageResource(1802));
	this->combo_labels[8][2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][3].SetImage(rm->GetImageResource(1803));
	this->combo_labels[8][3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][4].SetImage(rm->GetImageResource(1804));
	this->combo_labels[8][4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][5].SetImage(rm->GetImageResource(1805));
	this->combo_labels[8][5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][6].SetImage(rm->GetImageResource(1806));
	this->combo_labels[8][6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][7].SetImage(rm->GetImageResource(1807));
	this->combo_labels[8][7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][8].SetImage(rm->GetImageResource(1808));
	this->combo_labels[8][8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][9].SetImage(rm->GetImageResource(1809));
	this->combo_labels[8][9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][10].SetImage(rm->GetImageResource(1810));
	this->combo_labels[8][10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][11].SetImage(rm->GetImageResource(1811));
	this->combo_labels[8][11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][12].SetImage(rm->GetImageResource(1812));
	this->combo_labels[8][12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][13].SetImage(rm->GetImageResource(1813));
	this->combo_labels[8][13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][14].SetImage(rm->GetImageResource(1814));
	this->combo_labels[8][14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][15].SetImage(rm->GetImageResource(1815));
	this->combo_labels[8][15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[8][16].SetImage(rm->GetImageResource(1816));
	this->combo_labels[8][16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[8][16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);


	//queens...
	this->combo_labels[9][0].SetImage(rm->GetImageResource(1900));
	this->combo_labels[9][0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][1].SetImage(rm->GetImageResource(1901));
	this->combo_labels[9][1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][2].SetImage(rm->GetImageResource(1902));
	this->combo_labels[9][2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][3].SetImage(rm->GetImageResource(1903));
	this->combo_labels[9][3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][4].SetImage(rm->GetImageResource(1904));
	this->combo_labels[9][4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][5].SetImage(rm->GetImageResource(1905));
	this->combo_labels[9][5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][6].SetImage(rm->GetImageResource(1906));
	this->combo_labels[9][6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][7].SetImage(rm->GetImageResource(1907));
	this->combo_labels[9][7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][8].SetImage(rm->GetImageResource(1908));
	this->combo_labels[9][8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][9].SetImage(rm->GetImageResource(1909));
	this->combo_labels[9][9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][10].SetImage(rm->GetImageResource(1910));
	this->combo_labels[9][10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][11].SetImage(rm->GetImageResource(1911));
	this->combo_labels[9][11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][12].SetImage(rm->GetImageResource(1912));
	this->combo_labels[9][12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][13].SetImage(rm->GetImageResource(1913));
	this->combo_labels[9][13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][14].SetImage(rm->GetImageResource(1914));
	this->combo_labels[9][14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][15].SetImage(rm->GetImageResource(1915));
	this->combo_labels[9][15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[9][16].SetImage(rm->GetImageResource(1916));
	this->combo_labels[9][16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[9][16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);


	//queens...
	this->combo_labels[10][0].SetImage(rm->GetImageResource(2000));
	this->combo_labels[10][0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][1].SetImage(rm->GetImageResource(2001));
	this->combo_labels[10][1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][2].SetImage(rm->GetImageResource(2002));
	this->combo_labels[10][2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][3].SetImage(rm->GetImageResource(2003));
	this->combo_labels[10][3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][4].SetImage(rm->GetImageResource(2004));
	this->combo_labels[10][4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][5].SetImage(rm->GetImageResource(2005));
	this->combo_labels[10][5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][6].SetImage(rm->GetImageResource(2006));
	this->combo_labels[10][6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][7].SetImage(rm->GetImageResource(2007));
	this->combo_labels[10][7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][8].SetImage(rm->GetImageResource(2008));
	this->combo_labels[10][8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][9].SetImage(rm->GetImageResource(2009));
	this->combo_labels[10][9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][10].SetImage(rm->GetImageResource(2010));
	this->combo_labels[10][10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][11].SetImage(rm->GetImageResource(2011));
	this->combo_labels[10][11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][12].SetImage(rm->GetImageResource(2012));
	this->combo_labels[10][12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][13].SetImage(rm->GetImageResource(2013));
	this->combo_labels[10][13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][14].SetImage(rm->GetImageResource(2014));
	this->combo_labels[10][14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][15].SetImage(rm->GetImageResource(2015));
	this->combo_labels[10][15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[10][16].SetImage(rm->GetImageResource(2016));
	this->combo_labels[10][16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[10][16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);




	
	//queens...
	this->combo_labels[11][0].SetImage(rm->GetImageResource(2100));
	this->combo_labels[11][0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][1].SetImage(rm->GetImageResource(2101));
	this->combo_labels[11][1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][2].SetImage(rm->GetImageResource(2102));
	this->combo_labels[11][2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][3].SetImage(rm->GetImageResource(2103));
	this->combo_labels[11][3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][4].SetImage(rm->GetImageResource(2104));
	this->combo_labels[11][4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][5].SetImage(rm->GetImageResource(2105));
	this->combo_labels[11][5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][6].SetImage(rm->GetImageResource(2106));
	this->combo_labels[11][6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][7].SetImage(rm->GetImageResource(2107));
	this->combo_labels[11][7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][8].SetImage(rm->GetImageResource(2108));
	this->combo_labels[11][8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][9].SetImage(rm->GetImageResource(2109));
	this->combo_labels[11][9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][10].SetImage(rm->GetImageResource(2110));
	this->combo_labels[11][10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][11].SetImage(rm->GetImageResource(2111));
	this->combo_labels[11][11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][12].SetImage(rm->GetImageResource(2112));
	this->combo_labels[11][12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][13].SetImage(rm->GetImageResource(2113));
	this->combo_labels[11][13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][14].SetImage(rm->GetImageResource(2114));
	this->combo_labels[11][14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][15].SetImage(rm->GetImageResource(2115));
	this->combo_labels[11][15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[11][16].SetImage(rm->GetImageResource(2116));
	this->combo_labels[11][16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[11][16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);





	//queens...
	this->combo_labels[12][0].SetImage(rm->GetImageResource(2200));
	this->combo_labels[12][0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][1].SetImage(rm->GetImageResource(2201));
	this->combo_labels[12][1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][2].SetImage(rm->GetImageResource(2202));
	this->combo_labels[12][2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][3].SetImage(rm->GetImageResource(2203));
	this->combo_labels[12][3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][4].SetImage(rm->GetImageResource(2204));
	this->combo_labels[12][4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][5].SetImage(rm->GetImageResource(2205));
	this->combo_labels[12][5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][6].SetImage(rm->GetImageResource(2206));
	this->combo_labels[12][6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][7].SetImage(rm->GetImageResource(2207));
	this->combo_labels[12][7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][8].SetImage(rm->GetImageResource(2208));
	this->combo_labels[12][8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][9].SetImage(rm->GetImageResource(2209));
	this->combo_labels[12][9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][10].SetImage(rm->GetImageResource(2210));
	this->combo_labels[12][10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][11].SetImage(rm->GetImageResource(2211));
	this->combo_labels[12][11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][12].SetImage(rm->GetImageResource(2212));
	this->combo_labels[12][12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][13].SetImage(rm->GetImageResource(2213));
	this->combo_labels[12][13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][14].SetImage(rm->GetImageResource(2214));
	this->combo_labels[12][14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][15].SetImage(rm->GetImageResource(2215));
	this->combo_labels[12][15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);

	this->combo_labels[12][16].SetImage(rm->GetImageResource(2216));
	this->combo_labels[12][16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->combo_labels[12][16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);




	this->puzzle_solved[0].SetImage(rm->GetImageResource(20000));
	this->puzzle_solved[0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[1].SetImage(rm->GetImageResource(20001));
	this->puzzle_solved[1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[2].SetImage(rm->GetImageResource(20002));
	this->puzzle_solved[2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[3].SetImage(rm->GetImageResource(20003));
	this->puzzle_solved[3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[4].SetImage(rm->GetImageResource(20004));
	this->puzzle_solved[4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[5].SetImage(rm->GetImageResource(20005));
	this->puzzle_solved[5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[6].SetImage(rm->GetImageResource(20006));
	this->puzzle_solved[6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[7].SetImage(rm->GetImageResource(20007));
	this->puzzle_solved[7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[8].SetImage(rm->GetImageResource(20008));
	this->puzzle_solved[8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[9].SetImage(rm->GetImageResource(20009));
	this->puzzle_solved[9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[10].SetImage(rm->GetImageResource(20010));
	this->puzzle_solved[10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[11].SetImage(rm->GetImageResource(20011));
	this->puzzle_solved[11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[12].SetImage(rm->GetImageResource(20012));
	this->puzzle_solved[12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[13].SetImage(rm->GetImageResource(20013));
	this->puzzle_solved[13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[14].SetImage(rm->GetImageResource(20014));
	this->puzzle_solved[14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[15].SetImage(rm->GetImageResource(20015));
	this->puzzle_solved[15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_solved[16].SetImage(rm->GetImageResource(20016));
	this->puzzle_solved[16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_solved[16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);


	this->puzzle_failed[0].SetImage(rm->GetImageResource(20100));
	this->puzzle_failed[0].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[0].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[1].SetImage(rm->GetImageResource(20101));
	this->puzzle_failed[1].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[1].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[2].SetImage(rm->GetImageResource(20102));
	this->puzzle_failed[2].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[2].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[3].SetImage(rm->GetImageResource(20103));
	this->puzzle_failed[3].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[3].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[4].SetImage(rm->GetImageResource(20104));
	this->puzzle_failed[4].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[4].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[5].SetImage(rm->GetImageResource(20105));
	this->puzzle_failed[5].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[5].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[6].SetImage(rm->GetImageResource(20106));
	this->puzzle_failed[6].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[6].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[7].SetImage(rm->GetImageResource(20107));
	this->puzzle_failed[7].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[7].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[8].SetImage(rm->GetImageResource(20108));
	this->puzzle_failed[8].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[8].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[9].SetImage(rm->GetImageResource(20109));
	this->puzzle_failed[9].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[9].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[10].SetImage(rm->GetImageResource(20110));
	this->puzzle_failed[10].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[10].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[11].SetImage(rm->GetImageResource(20111));
	this->puzzle_failed[11].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[11].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[12].SetImage(rm->GetImageResource(20112));
	this->puzzle_failed[12].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[12].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[13].SetImage(rm->GetImageResource(20113));
	this->puzzle_failed[13].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[13].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[14].SetImage(rm->GetImageResource(20114));
	this->puzzle_failed[14].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[14].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[15].SetImage(rm->GetImageResource(20115));
	this->puzzle_failed[15].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[15].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	this->puzzle_failed[16].SetImage(rm->GetImageResource(20116));
	this->puzzle_failed[16].Resize((float)(500 * wnd_ptr->GetWidth())/1920, (float)(300 * wnd_ptr->GetHeight())/1080);
	this->puzzle_failed[16].SetPosition((float)(wnd_ptr->GetWidth() * 1) / 1920, (float)(wnd_ptr->GetHeight() * 358) / 1080);
	

	/*
		else if (i == 3)
		base_id = 1300;

	else if (i == 4)
		base_id = 1400;
	else if (i == 5)
		base_id = 1500;
	else if (i == 8)
		base_id = 1800;
	else if (i == 9)
		base_id = 1900;
	else if (i == 10)
		base_id = 2000;
	else if (i == 11)
		base_id = 2100;
	else if (i == 12)
		base_id = 2200;
	*/
	std::cout << " Done!\n";
}

int AnimatedLabel::GetSpriteIdByComboId(int combo_id)
{
	//std::cout << "\nCombo Id passed to this animated label is [" << combo_id << "]\n\n";

	int sprite_id;

	if (combo_id >= 400 && combo_id < 500)
		sprite_id = 0;
	else if (combo_id >= 500 && combo_id < 600)
		sprite_id = 1;
	else if (combo_id >= 600 && combo_id < 700)
		sprite_id = 2;
	else if (combo_id >= 700 && combo_id < 800)
		sprite_id = 3;
	else if (combo_id >= 800 && combo_id < 900)
		sprite_id = 4;
	else if (combo_id >= 900 && combo_id < 1000)
		sprite_id = 5;
	else if (combo_id >= 1000 && combo_id < 1100)
		sprite_id = 8;
	else if (combo_id >= 1100 && combo_id < 1200)
		sprite_id = 9;
	else if (combo_id >= 1200 && combo_id < 1300)
		sprite_id = 10;
	else if (combo_id >= 1300 && combo_id < 1400)
		sprite_id = 11;
	else if (combo_id >= 1400 && combo_id < 1500)
		sprite_id = 12;

	return sprite_id;
}

bool AnimatedLabel::IsAnimating()
{
	return this->is_animating;
}

void AnimatedLabel::SetupNewLabel(int label_sprite_id)
{
	//std::cout << "\nCombo Id passed to this animated label is [" << label_sprite_id << "]\n";
	//this->current_label_id = this->GetSpriteIdByComboId(label_sprite_id);
	this->current_label_id = (int)label_sprite_id;
	this->current_frame = 0;
	this->animation_timer.Reset();
	this->is_animating = true;
	//std::cout << "\nSeting up Current animated label [" << current_label_id << "][" << current_frame <<"]\n";
}

void AnimatedLabel::SetupPuzzleLabel(std::string m)
{
	this->current_frame = 0;
	this->animation_timer.Reset();
	this->is_animating_puzzle_label = true;
	this->mode = m;
	std::cout << "\nPuzzle finished with status: [" << this->mode << "]\n";
}

void AnimatedLabel::DrawComboLabel()
{
	if (is_animating)
	{
		//std::cout << "\nCurrent drawning animated label [" << current_label_id << "][" << current_frame <<"]\n";
		this->wnd_ptr->Draw(combo_labels[current_label_id][current_frame]);
		this->UpdateLabel();
	}
	else 
	{
		this->wnd_ptr->Draw(combo_labels[current_label_id][16]);
	}
}

void AnimatedLabel::DrawPuzzleLabel()
{
	/*
	if (is_animating_puzzle_label)
	{
		this->wnd_ptr->Draw(puzzle_solved[current_frame]);
		this->UpdatePuzzleLabel();
	}
	else 
	{
		this->wnd_ptr->Draw(puzzle_solved[16]);
	}
	*/
	
	if (this->mode == "SOLVED") //Puzzle solved label
	{
		if (is_animating_puzzle_label)
		{
			this->wnd_ptr->Draw(puzzle_solved[current_frame]);
			this->UpdatePuzzleLabel();
		}
		else 
		{
			this->wnd_ptr->Draw(puzzle_solved[16]);
		}
	}
	
	else if (this->mode == "FAILED") //Puzzle failed label
	{
		if (is_animating_puzzle_label)
		{
			this->wnd_ptr->Draw(puzzle_failed[current_frame]);
			this->UpdatePuzzleLabel();
		}
		else 
		{
			this->wnd_ptr->Draw(puzzle_failed[16]);
		}
	}
	
}

void AnimatedLabel::UpdatePuzzleLabel()
{
	if (this->animation_timer.GetElapsedTime() >= 0.035f)
	{
		if (this->current_frame < 16)
		{
			this->current_frame++;
		}
		else
		{
			this->is_animating_puzzle_label = false;
		}
		this->animation_timer.Reset();
	}
}

void AnimatedLabel::UpdateLabel()
{
	if (this->animation_timer.GetElapsedTime() >= 0.035f)
	{
		if (this->current_frame < 16)
		{
			this->current_frame++;
			//std::cout << "\nCurrent animated label [" << current_label_id << "][" << current_frame <<"]\n";
		}
		else
		{
			//What to do here?
			this->is_animating = false;
		}
		this->animation_timer.Reset();
	}
}

AnimatedLabel::~AnimatedLabel(void)
{
}
