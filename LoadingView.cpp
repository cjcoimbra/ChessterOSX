#include "StdAfx.h"
#include "LoadingView.h"

LoadingView::LoadingView(sf::RenderWindow * rw, ResourceManager * resm)
{
	this->wnd_ptr = rw;
	this->rm = resm;
	this->last_sprite_index = 0;
	for(int i = 0 ; i < 17; i++)
	{
		this->loading_spt[i].SetImage(rm->GetImageResource(73));
		this->loading_spt[i].Resize((float)(60 * wnd_ptr->GetWidth())/1920, (float)(84 * wnd_ptr->GetHeight())/1080);
	}
	this->loading_spt[last_sprite_index].SetPosition((float)wnd_ptr->GetWidth()/4 ,(float) wnd_ptr->GetHeight()/2 + 100);
}

void LoadingView::AddNextSprite()
{
	if (last_sprite_index < 16) //Boundary Check
	{
		last_sprite_index++;
		this->loading_spt[last_sprite_index].SetPosition((float)wnd_ptr->GetWidth()/4 + ((last_sprite_index) * this->loading_spt[last_sprite_index].GetSize().x + 5),(float) wnd_ptr->GetHeight()/2 + 100);
	}
}

void LoadingView::ShowLoading()
{
	for (int i = 0; i < 17; i++)
	{
		if (i <= this->last_sprite_index)
			this->wnd_ptr->Draw(this->loading_spt[i]);
	}
}