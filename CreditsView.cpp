#include "StdAfx.h"
#include "CreditsView.h"

CreditsView::CreditsView(void)
{
}

CreditsView::~CreditsView(void)
{
}

void CreditsView::Update()
{
	for (int i = 0; i < 9; i++)
		this->wnd_ptr->Draw(this->credits[i]);
}

void CreditsView::Init(sf::RenderWindow * w, ResourceManager * r)
{
	this->wnd_ptr = w;
	this->rm = r;

	chesster_font.LoadFromFile("GFX/Font/Deutsch.ttf");

	credits[0].SetFont(chesster_font);
    credits[0].SetText("Team Checkmate is" );
    credits[0].SetSize(48);
    credits[0].SetColor(sf::Color(255,255,255));
	credits[0].SetPosition(wnd_ptr->GetWidth()/4 - credits[0].GetRect().GetWidth()/2, wnd_ptr->GetHeight()/2 - credits[0].GetRect().GetHeight() );

	credits[1].SetFont(chesster_font);
    credits[1].SetText("Game Design & Art" );
    credits[1].SetSize(32);
    credits[1].SetColor(sf::Color(200,200,0));
	credits[1].SetPosition(wnd_ptr->GetWidth()/4 - credits[1].GetRect().GetWidth()/2, credits[0].GetPosition().y + credits[0].GetRect().GetHeight() + 25);

	credits[2].SetFont(chesster_font);
    credits[2].SetText("Sean Kiley" );
    credits[2].SetSize(32);
    credits[2].SetColor(sf::Color(200,0,0));
	credits[2].SetPosition(wnd_ptr->GetWidth()/4 - credits[2].GetRect().GetWidth()/2, credits[1].GetPosition().y + credits[1].GetRect().GetHeight() + 10);


	credits[3].SetFont(chesster_font);
    credits[3].SetText("Technical & Programming" );
    credits[3].SetSize(32);
    credits[3].SetColor(sf::Color(200,200,0));
	credits[3].SetPosition(wnd_ptr->GetWidth()/4 - credits[3].GetRect().GetWidth()/2, credits[2].GetPosition().y + credits[2].GetRect().GetHeight() + 25);

	credits[4].SetFont(chesster_font);
    credits[4].SetText("Christian Coimbra" );
    credits[4].SetSize(32);
    credits[4].SetColor(sf::Color(200,0,0));
	credits[4].SetPosition(wnd_ptr->GetWidth()/4 - credits[4].GetRect().GetWidth()/2, credits[3].GetPosition().y + credits[3].GetRect().GetHeight() + 10);


	credits[5].SetFont(chesster_font);
    credits[5].SetText("Special thanks to" );
    credits[5].SetSize(32);
    credits[5].SetColor(sf::Color(255,255,255));
	credits[5].SetPosition(((wnd_ptr->GetWidth()/4) *3 ) - credits[5].GetRect().GetWidth()/2, wnd_ptr->GetHeight()/2 - credits[5].GetRect().GetHeight() );

	credits[6].SetFont(chesster_font);
	credits[6].SetText("Laurent Gomila (SFML)" );
    credits[6].SetSize(24);
    credits[6].SetColor(sf::Color(200,200,0));
	credits[6].SetPosition(((wnd_ptr->GetWidth()/4) *3 ) - credits[6].GetRect().GetWidth()/2, credits[5].GetPosition().y + credits[5].GetRect().GetHeight() + 25);

	credits[7].SetFont(chesster_font);
    credits[7].SetText("Kevon Cronin (music)" );
    credits[7].SetSize(24);
    credits[7].SetColor(sf::Color(200,200,0));
	credits[7].SetPosition(((wnd_ptr->GetWidth()/4) *3 ) - credits[7].GetRect().GetWidth()/2, credits[6].GetPosition().y + credits[6].GetRect().GetHeight() + 10);

	credits[8].SetFont(chesster_font);
    credits[8].SetText("Press any key to return" );
    credits[8].SetSize(32);
    credits[8].SetColor(sf::Color(255,255,255));
	credits[8].SetPosition(wnd_ptr->GetWidth()/2 - credits[8].GetRect().GetWidth()/2, wnd_ptr->GetHeight() - credits[8].GetRect().GetHeight() - 20);
}
