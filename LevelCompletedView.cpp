#include "StdAfx.h"
#include "LevelCompletedView.h"

LevelCompletedView::LevelCompletedView(void)
{
}

LevelCompletedView::~LevelCompletedView(void)
{
}

void LevelCompletedView::Init(sf::RenderWindow * w, ResourceManager * r)
{
	this->wnd_ptr = w;
	this->rm = r;
	chesster_font.LoadFromFile("GFX/Font/Deutsch.ttf");

	level_name.SetFont(chesster_font);
	level_name.SetSize(56);
	level_name.SetColor(sf::Color(255,255,255));
	level_name.SetPosition(wnd_ptr->GetWidth()/2 - level_name.GetRect().GetWidth()/2, 30);

	message.SetFont(chesster_font);
	message.SetSize(36);
	message.SetColor(sf::Color(200,200,0));
	message.SetPosition(wnd_ptr->GetWidth()/2 - message.GetRect().GetWidth()/2, level_name.GetPosition().y + level_name.GetRect().GetHeight() + 50);

	total_score.SetFont(chesster_font);
	total_score.SetSize(42);
	total_score.SetColor(sf::Color(200,200,0));
	total_score.SetPosition(wnd_ptr->GetWidth()/2 - total_score.GetRect().GetWidth()/2, message.GetPosition().y + message.GetRect().GetHeight() + 50);

	exit_message.SetFont(chesster_font);
	exit_message.SetSize(28);
	exit_message.SetColor(sf::Color(200,0,0));
	exit_message.SetPosition(wnd_ptr->GetWidth()/2 - exit_message.GetRect().GetWidth()/2, total_score.GetPosition().y + total_score.GetRect().GetHeight() + 100);

	indiedb_string.SetFont(chesster_font);
	indiedb_string.SetSize(24);
	indiedb_string.SetColor(sf::Color(255,255,255));
	indiedb_string.SetText("www.indiedb.com/games/chesster");
	indiedb_string.SetPosition(wnd_ptr->GetWidth()/2 - indiedb_string.GetRect().GetWidth()/2, wnd_ptr->GetHeight() - indiedb_string.GetRect().GetHeight() - 10);

	facebook_string.SetFont(chesster_font);
	facebook_string.SetSize(24);
	facebook_string.SetColor(sf::Color(255,255,255));
	facebook_string.SetText("www.facebook.com/playchesster");
	facebook_string.SetPosition(wnd_ptr->GetWidth()/2 - facebook_string.GetRect().GetWidth()/2, indiedb_string.GetPosition().y - facebook_string.GetRect().GetHeight() - 10);

	demo_string.SetFont(chesster_font);
	demo_string.SetSize(28);
	demo_string.SetColor(sf::Color(255,255,255));
	demo_string.SetText("Thanks for playing Chesster Demo! Check out our updates on IndieDB and Facebook!");
	demo_string.SetPosition(wnd_ptr->GetWidth()/2 - demo_string.GetRect().GetWidth()/2, facebook_string.GetPosition().y - demo_string.GetRect().GetHeight() - 10);
}

void LevelCompletedView::SetupVictoryView(int level, std::string score)
{
	switch (level)
	{
		case 1:
			level_name.SetText("The Dungeon");
			level_name.SetPosition(wnd_ptr->GetWidth()/2 - level_name.GetRect().GetWidth()/2, 30);
			
			message.SetText("Level Completed! Your total score was");
			message.SetPosition(wnd_ptr->GetWidth()/2 - message.GetRect().GetWidth()/2, level_name.GetPosition().y + level_name.GetRect().GetHeight() + 50);
			
			total_score.SetText(score);
			total_score.SetPosition(wnd_ptr->GetWidth()/2 - total_score.GetRect().GetWidth()/2, message.GetPosition().y + message.GetRect().GetHeight() + 50);
			
			exit_message.SetText("Press any key to advance to the next level");
			exit_message.SetPosition(wnd_ptr->GetWidth()/2 - exit_message.GetRect().GetWidth()/2, total_score.GetPosition().y + total_score.GetRect().GetHeight() + 100);
		break;

		case 2:
			level_name.SetText("Castle Walls");
			level_name.SetPosition(wnd_ptr->GetWidth()/2 - level_name.GetRect().GetWidth()/2, 30);
			
			message.SetText("Level Completed! Your total score was");
			message.SetPosition(wnd_ptr->GetWidth()/2 - message.GetRect().GetWidth()/2, level_name.GetPosition().y + level_name.GetRect().GetHeight() + 50);
			
			total_score.SetText(score);
			total_score.SetPosition(wnd_ptr->GetWidth()/2 - total_score.GetRect().GetWidth()/2, message.GetPosition().y + message.GetRect().GetHeight() + 50);
			
			exit_message.SetText("Press any key to advance to the next level");
			exit_message.SetPosition(wnd_ptr->GetWidth()/2 - exit_message.GetRect().GetWidth()/2, total_score.GetPosition().y + total_score.GetRect().GetHeight() + 100);
		break;

		case 3:
			level_name.SetText("The Courtyard");
			level_name.SetPosition(wnd_ptr->GetWidth()/2 - level_name.GetRect().GetWidth()/2, 30);
			
			message.SetText("Level Completed! Your total score was");
			message.SetPosition(wnd_ptr->GetWidth()/2 - message.GetRect().GetWidth()/2, level_name.GetPosition().y + level_name.GetRect().GetHeight() + 50);
			
			total_score.SetText(score);
			total_score.SetPosition(wnd_ptr->GetWidth()/2 - total_score.GetRect().GetWidth()/2, message.GetPosition().y + message.GetRect().GetHeight() + 50);
			
			exit_message.SetText("Press any key to return");
			exit_message.SetPosition(wnd_ptr->GetWidth()/2 - exit_message.GetRect().GetWidth()/2, total_score.GetPosition().y + total_score.GetRect().GetHeight() + 100);
		break;
	}

	this->current_view = "victory";
}

void LevelCompletedView::SetupDefeatView(int level, std::string score)
{
	switch (level)
	{
		case 1:
			level_name.SetText("The Dungeon");
			level_name.SetPosition(wnd_ptr->GetWidth()/2 - level_name.GetRect().GetWidth()/2, 30);
			
			message.SetText("You were defeated! Your total score was");
			message.SetPosition(wnd_ptr->GetWidth()/2 - message.GetRect().GetWidth()/2, level_name.GetPosition().y + level_name.GetRect().GetHeight() + 50);
			
			total_score.SetText(score);
			total_score.SetPosition(wnd_ptr->GetWidth()/2 - total_score.GetRect().GetWidth()/2, message.GetPosition().y + message.GetRect().GetHeight() + 50);
			
			exit_message.SetText("Press any key to return");
			exit_message.SetPosition(wnd_ptr->GetWidth()/2 - exit_message.GetRect().GetWidth()/2, total_score.GetPosition().y + total_score.GetRect().GetHeight() + 100);
		break;

		case 2:
			level_name.SetText("Castle Walls");
			level_name.SetPosition(wnd_ptr->GetWidth()/2 - level_name.GetRect().GetWidth()/2, 30);
			
			message.SetText("You were defeated! Your total score was");
			message.SetPosition(wnd_ptr->GetWidth()/2 - message.GetRect().GetWidth()/2, level_name.GetPosition().y + level_name.GetRect().GetHeight() + 50);
			
			total_score.SetText(score);
			total_score.SetPosition(wnd_ptr->GetWidth()/2 - total_score.GetRect().GetWidth()/2, message.GetPosition().y + message.GetRect().GetHeight() + 50);
			
			exit_message.SetText("Press any key to return");
			exit_message.SetPosition(wnd_ptr->GetWidth()/2 - exit_message.GetRect().GetWidth()/2, total_score.GetPosition().y + total_score.GetRect().GetHeight() + 100);
		break;

		case 3:
			level_name.SetText("The Courtyard");
			level_name.SetPosition(wnd_ptr->GetWidth()/2 - level_name.GetRect().GetWidth()/2, 30);
			
			message.SetText("You were defeated! Your total score was");
			message.SetPosition(wnd_ptr->GetWidth()/2 - message.GetRect().GetWidth()/2, level_name.GetPosition().y + level_name.GetRect().GetHeight() + 50);
			
			total_score.SetText(score);
			total_score.SetPosition(wnd_ptr->GetWidth()/2 - total_score.GetRect().GetWidth()/2, message.GetPosition().y + message.GetRect().GetHeight() + 50);
			
			exit_message.SetText("Press any key to return");
			exit_message.SetPosition(wnd_ptr->GetWidth()/2 - exit_message.GetRect().GetWidth()/2, total_score.GetPosition().y + total_score.GetRect().GetHeight() + 100);
		break;
	}

	this->current_view = "defeat";
}

void LevelCompletedView::SetupIntroView(int level, std::string demand)
{
	switch (level)
	{
		case 1:
			level_name.SetText("The Dungeon");
			level_name.SetPosition(wnd_ptr->GetWidth()/2 - level_name.GetRect().GetWidth()/2, 30);
			
			message.SetText("Current level's demand is");
			message.SetPosition(wnd_ptr->GetWidth()/2 - message.GetRect().GetWidth()/2, level_name.GetPosition().y + level_name.GetRect().GetHeight() + 50);
			
			total_score.SetText(demand);
			total_score.SetPosition(wnd_ptr->GetWidth()/2 - total_score.GetRect().GetWidth()/2, message.GetPosition().y + message.GetRect().GetHeight() + 50);
			
			exit_message.SetText("Press any key to start!");
			exit_message.SetPosition(wnd_ptr->GetWidth()/2 - exit_message.GetRect().GetWidth()/2, total_score.GetPosition().y + total_score.GetRect().GetHeight() + 100);
		break;
		
		case 2:
			level_name.SetText("Castle Walls");
			level_name.SetPosition(wnd_ptr->GetWidth()/2 - level_name.GetRect().GetWidth()/2, 30);
			
			message.SetText("Current level's demand is");
			message.SetPosition(wnd_ptr->GetWidth()/2 - message.GetRect().GetWidth()/2, level_name.GetPosition().y + level_name.GetRect().GetHeight() + 50);
			
			total_score.SetText(demand);
			total_score.SetPosition(wnd_ptr->GetWidth()/2 - total_score.GetRect().GetWidth()/2, message.GetPosition().y + message.GetRect().GetHeight() + 50);
			
			exit_message.SetText("Press any key to start!");
			exit_message.SetPosition(wnd_ptr->GetWidth()/2 - exit_message.GetRect().GetWidth()/2, total_score.GetPosition().y + total_score.GetRect().GetHeight() + 100);
		break;

		case 3:
			level_name.SetText("The Courtyard");
			level_name.SetPosition(wnd_ptr->GetWidth()/2 - level_name.GetRect().GetWidth()/2, 30);
			
			message.SetText("Current level's demand is");
			message.SetPosition(wnd_ptr->GetWidth()/2 - message.GetRect().GetWidth()/2, level_name.GetPosition().y + level_name.GetRect().GetHeight() + 50);
			
			total_score.SetText(demand);
			total_score.SetPosition(wnd_ptr->GetWidth()/2 - total_score.GetRect().GetWidth()/2, message.GetPosition().y + message.GetRect().GetHeight() + 50);
			
			exit_message.SetText("Press any key to start!");
			exit_message.SetPosition(wnd_ptr->GetWidth()/2 - exit_message.GetRect().GetWidth()/2, total_score.GetPosition().y + total_score.GetRect().GetHeight() + 100);
		break;
	}

	this->current_view = "intro";
}

void LevelCompletedView::Update()
{
	this->wnd_ptr->Draw(this->level_name);
	this->wnd_ptr->Draw(this->message);
	this->wnd_ptr->Draw(this->exit_message);
	this->wnd_ptr->Draw(this->total_score);
	//Only for Demo version
	this->wnd_ptr->Draw(this->demo_string);
	this->wnd_ptr->Draw(this->facebook_string);
	this->wnd_ptr->Draw(this->indiedb_string);
}
