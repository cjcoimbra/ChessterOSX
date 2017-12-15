#include "StdAfx.h"
#include "ScoresView.h"

ScoresView::ScoresView(void)
{
}

void ScoresView::Init(sf::RenderWindow * w, ResourceManager * r)
{
	this->wnd_ptr = w;
	this->rm = r;
}

void ScoresView::ConfigScoresView(std::string local, std::string online)
{
	chesster_font.LoadFromFile("GFX/Font/Deutsch.ttf");

	scores[0].SetFont(chesster_font);
    scores[0].SetText("Your highest score is");
    scores[0].SetSize(32);
    scores[0].SetColor(sf::Color(200,200,0));
	scores[0].SetPosition((float)wnd_ptr->GetWidth()/4 - scores[0].GetRect().GetWidth()/2, (float)wnd_ptr->GetHeight()/2);

	scores[1].SetFont(chesster_font);
    scores[1].SetText(local);
    scores[1].SetSize(42);
    scores[1].SetColor(sf::Color(200,0,0));
	scores[1].SetPosition(wnd_ptr->GetWidth()/4 - scores[1].GetRect().GetWidth()/2, scores[0].GetPosition().y + scores[0].GetRect().GetHeight() + 30);


	scores[2].SetFont(chesster_font);
    scores[2].SetText("Online highest score is");
    scores[2].SetSize(32);
    scores[2].SetColor(sf::Color(200,200,0));
	scores[2].SetPosition((float)((wnd_ptr->GetWidth()/4) * 3) - scores[0].GetRect().GetWidth()/2,(float) wnd_ptr->GetHeight()/2);

	scores[3].SetFont(chesster_font);
    scores[3].SetText(online);
    scores[3].SetSize(42);
    scores[3].SetColor(sf::Color(200,0,0));
	scores[3].SetPosition(((wnd_ptr->GetWidth()/4) * 3) - scores[3].GetRect().GetWidth()/2, scores[2].GetPosition().y + scores[2].GetRect().GetHeight() + 30);


	back_message.SetFont(chesster_font);
    back_message.SetText("Press any key to return");
    back_message.SetSize(32);
    back_message.SetColor(sf::Color(255,255,255));
	back_message.SetPosition(wnd_ptr->GetWidth()/2 - back_message.GetRect().GetWidth()/2, wnd_ptr->GetHeight() - back_message.GetRect().GetHeight() - 20);
}

void ScoresView::Update()
{
	for (int i = 0; i < 4; i++)
		this->wnd_ptr->Draw(this->scores[i]);

	this->wnd_ptr->Draw(this->back_message);
}

ScoresView::~ScoresView(void)
{
}
