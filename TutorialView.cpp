#include "StdAfx.h"
#include "TutorialView.h"

TutorialView::TutorialView(void)
{
}

TutorialView::~TutorialView(void)
{
}

void TutorialView::SetTutorialStage(int newStage)
{
	this->current_tutorial_stage = newStage;
	switch (this->current_tutorial_stage)
	{
		case 0:
			 ingame_tutorial_text.SetText("Drag and drop to connect 3 or more pieces...");
			break;
		case 1:
			ingame_tutorial_text.SetText("Move 3 pieces total to complete your turn!");
			break;
		case 2 :
			this->first_invalid_move = true;
			ingame_tutorial_text.SetText("Each piece moves like in Chess! The highlighted\nsquares show where that piece can move...");
			break;
		case 3:
			ingame_tutorial_text.SetText("The piece you move on top of is removed.");
			break;
		case 4:
			this->first_valid_move = true;
			ingame_tutorial_text.SetText("Great!\nNow you have 2 more moves.");
			break;
		case 5:
			this->first_valid_move = true;
			this->first_invalid_move = true;
			ingame_tutorial_text.SetText("Each piece moves like in Chess! The highlighted\nsquares show where that piece can move...");
			break;
		case 6:
			ingame_tutorial_text.SetText("The piece you move on top of is removed.\nNow you have 2 more moves!");
			break;
		case 7:
			this->piece_already_moved = true;
			ingame_tutorial_text.SetText("This piece has already been moved.");
			break;
		case 8:
			this->second_valid_move = true;
			ingame_tutorial_text.SetText("Pieces have different values. Press the \nmovement button to check it out...");
			break;
		case 9:
			ingame_tutorial_text.SetText("One more move to complete this turn!");
			break;
		case 10:
			this->third_valid_move = true;
			ingame_tutorial_text.SetText("Let's see how well you did!");
			break;
		case 11:
			this->first_turn_score = true;
			ingame_tutorial_text.SetText("You earned a certain amount of points this turn...");
			break;
		case 12:
			ingame_tutorial_text.SetText("But to keep playing, you must\nsacrifice some of them!");
			break;
		case 13:
			ingame_tutorial_text.SetText("The Demand will now be taken from your score!");
			break;
		case 14:
			this->first_demand_taken = true;
			ingame_tutorial_text.SetText("Now your score will be combined with your total.");
			break;
		case 15:
			this->first_queen = true;
			ingame_tutorial_text.SetText("You've got a Queen!");
			break;
		case 16:
			ingame_tutorial_text.SetText("By connecting 5 or more pieces you\ncan bring a Queen to the board...");
			break;
		case 17:
			ingame_tutorial_text.SetText("Press the Combos button to see how to use\nQueens with other pieces for big points!");
			break;
		case 18:
			ingame_tutorial_text.SetText("These combos are valid horizontally and vertically.");
			break;
		case 19: //Somente Tesouro
			this->first_treasure = true;
			ingame_tutorial_text.SetText("You've earned enough points for a treasure!");
			break;
		case 20: //Somente Tesouro
			ingame_tutorial_text.SetText("By earning the amount under the treasure\nbanner during a turn, you can release that\ntreasure onto the board...");
			break;
		case 21: //Somente Tesouro
			ingame_tutorial_text.SetText("Get a combo next to the treasure to capture it. See\ncollected treasures by pressing the Treasures button.");
			break;
		case 22: //Somente Score Negativo
			this->first_negative_score = true;
			ingame_tutorial_text.SetText("Uh oh! A negative total will\nshut down part of the board!");
			break;
		case 23: //Somente Score Negativo
			ingame_tutorial_text.SetText("Open the board up again with a positive total.");
			break;
		case 24:
			this->first_negative_score = true;
			this->first_treasure = true;
			ingame_tutorial_text.SetText("Two things important things happened:\nYou´ve got enough points to spawn a treasure!\nUh oh! Your total score went negative...");
			break;
		case 25: 
			ingame_tutorial_text.SetText("By earning the amount under the treasure\nbanner during a turn, you can release that\ntreasure onto the board...");
			break;
		case 26:
			ingame_tutorial_text.SetText("Get a combo next to the treasure to capture it. See\ncollected treasures by pressing the Treasures button.");
			break;
		case 27: 
			ingame_tutorial_text.SetText("A negative total will shut down part of the board!\nOpen the board up again with a positive total.");
			break;
		case 28: 
			this->second_turn = true;
			ingame_tutorial_text.SetText("Survive for 9 more turns to advance!");
			break;
	}
	ingame_tutorial_text.SetPosition(this->tutorial_sheet.GetPosition().x + this->tutorial_sheet.GetSize().x/2 - ingame_tutorial_text.GetRect().GetWidth()/2, this->tutorial_sheet.GetPosition().y + this->tutorial_sheet.GetSize().y/2 - ingame_tutorial_text.GetRect().GetHeight()/2);
}
/*
void TutorialView::HandleTutorialButtonsEffects()
{
	
	int x = wptr->GetInput().GetMouseX();
	int y = wptr->GetInput().GetMouseY();

	if (x > next_arrow_button.GetPosition().x && x < next_arrow_button.GetPosition().x + next_arrow_button.GetSize().x
			&& y > next_arrow_button.GetPosition().y && y < next_arrow_button.GetPosition().y + next_arrow_button.GetSize().y)
	{
		if (this->current_tutorial_stage == 0)
	}
}
*/
void TutorialView::Init(sf::RenderWindow * w, ResourceManager * r)
{
	this->first_invalid_move = false;
	this->first_valid_move = false;
	this->piece_already_moved = false;
	this->second_valid_move = false;
	this->third_valid_move = false;
	this->first_turn_score = false;
	this->first_demand_taken = false;
	this->first_queen = false;
	this->first_treasure = false;
	this->first_negative_score = false;
	this->second_turn = false;

	this->wnd_ptr = w;
	this->rm = r;
	this->SetTutorialStage(0);
	//isTutorialFinished = false;
	//this->current_index = 0;
	//ConfigureSprite(current_index);
	showTutorial = true;
	this->tutorial_sheet.SetImage(this->rm->GetImageResource(86));
	this->tutorial_sheet.Resize((float)(795 * wnd_ptr->GetWidth())/1920, (float)(264 * wnd_ptr->GetHeight())/1080);
	this->tutorial_sheet.SetPosition((float)wnd_ptr->GetWidth()/2 - this->tutorial_sheet.GetSize().x/2, (float)wnd_ptr->GetHeight()/2 - this->tutorial_sheet.GetSize().y/2);

	this->close_button.SetImage(this->rm->GetImageResource(82));
	this->close_button.Resize((float)(104 * wnd_ptr->GetWidth())/1920, (float)(113 * wnd_ptr->GetHeight())/1080);
	this->close_button.SetPosition((float)this->tutorial_sheet.GetPosition().x + this->tutorial_sheet.GetSize().x - this->close_button.GetSize().x, (float)this->tutorial_sheet.GetPosition().y + this->tutorial_sheet.GetSize().y - this->close_button.GetSize().y);

	this->close_button_over.SetImage(this->rm->GetImageResource(83));
	this->close_button_over.Resize((float)(104 * wnd_ptr->GetWidth())/1920, (float)(113 * wnd_ptr->GetHeight())/1080);
	this->close_button_over.SetPosition((float)this->tutorial_sheet.GetPosition().x + this->tutorial_sheet.GetSize().x - this->close_button.GetSize().x,(float) this->tutorial_sheet.GetPosition().y + this->tutorial_sheet.GetSize().y - this->close_button.GetSize().y);

	this->next_arrow_button.SetImage(this->rm->GetImageResource(84));
	this->next_arrow_button.Resize((float)(147 * wnd_ptr->GetWidth())/1920, (float)(78 * wnd_ptr->GetHeight())/1080);
	this->next_arrow_button.SetPosition((float)this->tutorial_sheet.GetPosition().x + this->tutorial_sheet.GetSize().x - this->next_arrow_button.GetSize().x, (float)this->tutorial_sheet.GetPosition().y + this->tutorial_sheet.GetSize().y - this->next_arrow_button.GetSize().y);

	this->next_arrow_button_over.SetImage(this->rm->GetImageResource(85));
	this->next_arrow_button_over.Resize((float)(147 * wnd_ptr->GetWidth())/1920, (float)(78 * wnd_ptr->GetHeight())/1080);
	this->next_arrow_button_over.SetPosition((float)this->tutorial_sheet.GetPosition().x + this->tutorial_sheet.GetSize().x - this->next_arrow_button.GetSize().x, (float)this->tutorial_sheet.GetPosition().y + this->tutorial_sheet.GetSize().y - this->next_arrow_button.GetSize().y);
	
	float size = 32;
	if (wnd_ptr->GetHeight() >= 1080)
		size = 32;
	else if (wnd_ptr->GetHeight() >= 900)
		size = 26;
	else if (wnd_ptr->GetHeight() >= 800)
		size = 20;
	else
		size = 18;
	
	ingame_tutorial_text.SetFont(chesster_font);
    ingame_tutorial_text.SetText("placeholder");
    ingame_tutorial_text.SetSize(size);
    ingame_tutorial_text.SetColor(sf::Color(0,0,0));
	ingame_tutorial_text.SetPosition((float)this->tutorial_sheet.GetPosition().x + this->tutorial_sheet.GetSize().x/2 - ingame_tutorial_text.GetRect().GetWidth()/2, (float)this->tutorial_sheet.GetPosition().y + this->tutorial_sheet.GetSize().y/2 - ingame_tutorial_text.GetRect().GetHeight()/2);

	chesster_font.LoadFromFile("GFX/Font/Deutsch.ttf");
	/*
	for (int i=0; i < 10; i++)
	{
		this->tutorial_text[i].SetFont(chesster_font);
		this->tutorial_text[i].SetText(GetTextForTutorial(i));
		this->tutorial_text[i].SetSize(40);
		this->tutorial_text[i].SetColor(sf::Color(210,210,0));
		//this->tutorial_text[i].SetPosition(60, 60);
		this->tutorial_text[i].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_text[i].GetRect().GetWidth()/2, this->tutorial_spt[i].GetPosition().y - this->tutorial_text[i].GetRect().GetHeight() - 8);
		if (this->tutorial_text[i].GetPosition().y < 0)
			this->tutorial_text[i].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_text[i].GetRect().GetWidth()/2, 5);
		//std::cout << "String size: " << this->tutorial_text[i].GetSize() << "\n";
	}
	
	escape.SetFont(chesster_font);
    escape.SetText("Press 'Escape' to return" );
    escape.SetSize(32);
    escape.SetColor(sf::Color(255,255,255));
	escape.SetPosition(wnd_ptr->GetWidth()/2 - escape.GetRect().GetWidth()/2, wnd_ptr->GetHeight() - escape.GetRect().GetHeight() - 20);
	
	next.SetFont(chesster_font);
    next.SetText("Press 'Right Arrow'\nto show the next image" );
    next.SetSize(28);
    next.SetColor(sf::Color(200,0,0));
	next.SetPosition(wnd_ptr->GetWidth() - next.GetRect().GetWidth() - 10, wnd_ptr->GetHeight()/2 - next.GetRect().GetHeight()/2 );

	back.SetFont(chesster_font);
    back.SetText("Press 'Left Arrow'\nto show the previous image" );
    back.SetSize(28);
    back.SetColor(sf::Color(200,0,0));
    back.SetPosition(10, wnd_ptr->GetHeight()/2 - back.GetRect().GetHeight()/2 );

	this->shade = sf::Shape::Rectangle(0, 0, (float)wnd_ptr->GetWidth(), (float)wnd_ptr->GetHeight(),
												 sf::Color(0,0,0,180), 0,
												 sf::Color(0,0,0,180));
												 */
}

void TutorialView::Reset()
{
	//current_index = 0;
	//isTutorialFinished =  false;
	//tutorial_spt[current_index].SetImage(rm->OnDemandLoadForTutorialView(current_index));
	//ConfigureSprite(current_index);
}
/*
std::string TutorialView::GetTextForTutorial(int index)
{
	std::string text;
	switch (index)
	{
		case 0:
			text = "Connect three or more of the same pieces to get points.";
			break;
		case 1:
			text = "Five or more piece combos give you a queen!";
			break;
		case 2:
			text = "Each piece moves like its counterpart in Chess.\nThe move button displays this info.";
			break;
		case 3:
			text = "Move three pieces to get enough points for the demand amount.";
			break;
		case 4:
			text = "Points left over are added to your total.\nIf you don't earn enough points, the remainder is taken from your total.";
			break;
		case 5:
			text = "Each turn you have a negative total, part of the game board will close!";
			break;
		case 6:
			text = "Blocks are pieces that can't be moved.\nDestroy them with adjacent combos.";
			break;
		case 7:
			text = "Special combos give you more points.\nUse the combo button to refer to this list.";
			break;
		case 8:
			text = "Treasure appears when you get a lot of points in one turn!";
			break;
		case 9:
			text = "Treasure is collected by adjacent combos.\nThe treasure button displays your treasures.";
			break;
	}
	return text;
}

void TutorialView::DrawTutorialView()
{
	if (!isTutorialFinished)
	{
		this->wnd_ptr->Draw(this->shade);
		this->wnd_ptr->Draw(tutorial_spt[current_index]);
		this->wnd_ptr->Draw(tutorial_text[current_index]);
		if (current_index > 0)
			this->wnd_ptr->Draw(this->back);
		if (current_index < 9)
			this->wnd_ptr->Draw(this->next);

		this->wnd_ptr->Draw(this->escape);
	}
}

void TutorialView::ConfigureSprite(int current)
{
	tutorial_spt[current_index].SetImage(rm->OnDemandLoadForTutorialView(current_index));

	switch (current)
	{
		case 0:
			this->tutorial_spt[0].Resize((958 * (float)wnd_ptr->GetWidth())/1920, (627 * (float)wnd_ptr->GetHeight())/1080);
			this->tutorial_spt[0].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_spt[0].GetSize().x/2, wnd_ptr->GetHeight()/2 - this->tutorial_spt[0].GetSize().y/2);
		break;

		case 1:
			//this->tutorial_spt[1].SetImage(this->rm->GetImageResource(51));
			this->tutorial_spt[1].Resize((958 * wnd_ptr->GetWidth())/1920, (627 * wnd_ptr->GetHeight())/1080);
			this->tutorial_spt[1].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_spt[1].GetSize().x/2, wnd_ptr->GetHeight()/2 - this->tutorial_spt[1].GetSize().y/2);
		break;
		
		case 2:
			//this->tutorial_spt[2].SetImage(this->rm->GetImageResource(52));
			this->tutorial_spt[2].Resize((964 * wnd_ptr->GetWidth())/1920, (887 * wnd_ptr->GetHeight())/1080);
			this->tutorial_spt[2].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_spt[2].GetSize().x/2, wnd_ptr->GetHeight()/2 - this->tutorial_spt[2].GetSize().y/2);
		break;

		case 3:
			//this->tutorial_spt[3].SetImage(this->rm->GetImageResource(53));
			this->tutorial_spt[3].Resize((958 * wnd_ptr->GetWidth())/1920, (887 * wnd_ptr->GetHeight())/1080);
			this->tutorial_spt[3].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_spt[3].GetSize().x/2, wnd_ptr->GetHeight()/2 - this->tutorial_spt[3].GetSize().y/2);
			break;

		case 4:
			//this->tutorial_spt[4].SetImage(this->rm->GetImageResource(54));
			this->tutorial_spt[4].Resize((958 * wnd_ptr->GetWidth())/1920, (887 * wnd_ptr->GetHeight())/1080);
			this->tutorial_spt[4].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_spt[4].GetSize().x/2, wnd_ptr->GetHeight()/2 - this->tutorial_spt[4].GetSize().y/2);
			break;

		case 5:
			//this->tutorial_spt[5].SetImage(this->rm->GetImageResource(55));
			this->tutorial_spt[5].Resize((958 * wnd_ptr->GetWidth())/1920, (887 * wnd_ptr->GetHeight())/1080);
			this->tutorial_spt[5].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_spt[5].GetSize().x/2, wnd_ptr->GetHeight()/2 - this->tutorial_spt[5].GetSize().y/2);
			break;

		case 6:
			//this->tutorial_spt[6].SetImage(this->rm->GetImageResource(56));
			this->tutorial_spt[6].Resize((958 * wnd_ptr->GetWidth())/1920, (887 * wnd_ptr->GetHeight())/1080);
			this->tutorial_spt[6].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_spt[6].GetSize().x/2, wnd_ptr->GetHeight()/2 - this->tutorial_spt[6].GetSize().y/2);
			break;

		case 7:
			//this->tutorial_spt[7].SetImage(this->rm->GetImageResource(57));
			this->tutorial_spt[7].Resize((590 * wnd_ptr->GetWidth())/1920, (887 * wnd_ptr->GetHeight())/1080);
			this->tutorial_spt[7].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_spt[7].GetSize().x/2, wnd_ptr->GetHeight()/2 - this->tutorial_spt[7].GetSize().y/2);
			break;

		case 8:
			//this->tutorial_spt[8].SetImage(this->rm->GetImageResource(58));
			this->tutorial_spt[8].Resize((958 * wnd_ptr->GetWidth())/1920, (887 * wnd_ptr->GetHeight())/1080);
			this->tutorial_spt[8].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_spt[8].GetSize().x/2, wnd_ptr->GetHeight()/2 - this->tutorial_spt[7].GetSize().y/2);
			break;

		case 9:
			//this->tutorial_spt[9].SetImage(this->rm->GetImageResource(59));
			this->tutorial_spt[9].Resize((986 * wnd_ptr->GetWidth())/1920, (887 * wnd_ptr->GetHeight())/1080);
			this->tutorial_spt[9].SetPosition(wnd_ptr->GetWidth()/2 - this->tutorial_spt[9].GetSize().x/2, wnd_ptr->GetHeight()/2 - this->tutorial_spt[7].GetSize().y/2);
			break;
	}
}

void TutorialView::NextEvent()
{
	if (current_index < 9)
	{
		current_index++;
		ConfigureSprite(current_index);
	}
}

void TutorialView::BackEvent()
{
	if (current_index > 0)
	{
		current_index--;
		ConfigureSprite(current_index);
	}
}

void TutorialView::EscapeEvent()
{
	isTutorialFinished = true;
	this->current_index = 0;
	//tutorial_spt[current_index].SetImage(rm->OnDemandLoadForTutorialView(current_index));
	ConfigureSprite(current_index);
}

bool TutorialView::IsTutorialFinished()
{
	return this->isTutorialFinished;
}
*/