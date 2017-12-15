#include "StdAfx.h"
#include "InterfaceManager.h"

InterfaceManager::InterfaceManager(sf::RenderWindow * rw, ResourceManager * rm, float factor, float max_tile_size)
{
    //ctor
    wptr = rw;
    resource_manager = rm;

	isIncreasingScore = false;
	isDecreasingScore = false;
	currentScore = 0;
	//title_screen_spt.SetImage(resource_manager->GetImageResource(11));

	next_treasure_banner.SetImage(resource_manager->GetImageResource(72));
	next_treasure_banner.Resize((float)(358 * wptr->GetWidth())/1920, (float)(110 * wptr->GetHeight())/1080);
	next_treasure_banner.SetPosition((float)(wptr->GetWidth() * 1508) / 1920, (float)(wptr->GetHeight() * 156) / 1080);
	
	moves_spt.SetImage(resource_manager->GetImageResource(17));
	info_frame_spt.SetImage(resource_manager->GetImageResource(18));
	turns_spt.SetImage(resource_manager->GetImageResource(19));

	moves_bluecrest_spt.SetImage(resource_manager->GetImageResource(43));
	turns_bluecrest_spt.SetImage(resource_manager->GetImageResource(43));

	moves_spt.Resize((float)(263 * wptr->GetWidth())/1920, (float)(86 * wptr->GetHeight())/1080);
	turns_spt.Resize((float)(262 * wptr->GetWidth())/1920, (float)(85 * wptr->GetHeight())/1080);
	
	//info_frame_spt.Resize((411 * wptr->GetWidth())/1920, (714 * wptr->GetHeight())/1080);
	info_frame_spt.Resize((float)(391 * wptr->GetWidth())/1920, (float)(703 * wptr->GetHeight())/1080);
	
	std::cout << "Panel size: [" << info_frame_spt.GetSize().x << "," << info_frame_spt.GetSize().y << "]\n";

	moves_bluecrest_spt.Resize((float)(135 * wptr->GetWidth())/1920, (float)(135 * wptr->GetHeight())/1080);
	turns_bluecrest_spt.Resize((float)(135 * wptr->GetWidth())/1920, (float)(135 * wptr->GetHeight())/1080);

	int right_panel = (float)(wptr->GetWidth()/2 + 4 * factor * max_tile_size);
	
	//1480x330 - position of the panel in the mockup

	moves_spt.SetPosition((float)(wptr->GetWidth() * 31) / 1920, (float)(wptr->GetHeight() * 66) / 1080);
	turns_spt.SetPosition((float)(wptr->GetWidth() * 196) / 1920, (float)(wptr->GetHeight() * 170) / 1080);
	//info_frame_spt.SetPosition((wptr->GetWidth() * 1478) / 1920, (wptr->GetHeight() * 207) / 1080);
	info_frame_spt.SetPosition((float)(wptr->GetWidth() * 1490) / 1920, (float)(wptr->GetHeight() * 340) / 1080);
	

	moves_bluecrest_spt.SetPosition((float)(wptr->GetWidth() * 94) / 1920, (float)(wptr->GetHeight() * 95) / 1080);
	turns_bluecrest_spt.SetPosition((float)(wptr->GetWidth() * 256) / 1920, (float)(wptr->GetHeight() * 195) / 1080);
	
	//Font for growing score and combo size
	this->original_font_size = 48;

    chesster_font.LoadFromFile("GFX/Font/Deutsch.ttf");


	temp_new_game.SetFont(chesster_font);
    temp_new_game.SetText("[R]esume game");
    temp_new_game.SetSize(42);
    temp_new_game.SetColor(sf::Color(200,0,0));
	temp_new_game.SetPosition((float)wptr->GetWidth()/2 - temp_new_game.GetRect().GetWidth()/2, (float)wptr->GetHeight()/2 - temp_new_game.GetRect().GetHeight() - 20);

	temp_resume_game.SetFont(chesster_font);
    temp_resume_game.SetText("[N]ew game");
    temp_resume_game.SetSize(42);
    temp_resume_game.SetColor(sf::Color(200,0,0));
	temp_resume_game.SetPosition((float)wptr->GetWidth()/2 - temp_resume_game.GetRect().GetWidth()/2, (float)temp_new_game.GetPosition().y + temp_new_game.GetRect().GetHeight() + 20);

	temp_cancel.SetFont(chesster_font);
    temp_cancel.SetText("[C]ancel");
    temp_cancel.SetSize(42);
    temp_cancel.SetColor(sf::Color(200,0,0));
	temp_cancel.SetPosition((float)wptr->GetWidth()/2 - temp_cancel.GetRect().GetWidth()/2,(float) temp_resume_game.GetPosition().y + temp_resume_game.GetRect().GetHeight() + 20);


	deselect_info.SetFont(chesster_font);
    deselect_info.SetText("'right button' to deselect current piece" );
    deselect_info.SetSize(24);
    deselect_info.SetColor(sf::Color(200,0,0));
	deselect_info.SetPosition((float)wptr->GetWidth()/2 - deselect_info.GetRect().GetWidth()/2, (float)wptr->GetHeight() - deselect_info.GetRect().GetHeight() - 10);

    temp_info.SetFont(chesster_font);
    temp_info.SetText("Chesster - OSX v0.931 Demo (C) 2013 - Team Checkmate" );
    temp_info.SetSize(22);
    temp_info.SetColor(sf::Color(255,255,255));
	temp_info.SetPosition((float)wptr->GetWidth() - temp_info.GetRect().GetWidth() - 5 , (float)wptr->GetHeight() - temp_info.GetRect().GetHeight() - 10);

	loading_info.SetFont(chesster_font);
    loading_info.SetText("loading..." );
    loading_info.SetSize(24);
    loading_info.SetColor(sf::Color(255,255,255));
	loading_info.SetPosition((float)wptr->GetWidth()/2 - loading_info.GetRect().GetWidth()/2,(float) wptr->GetHeight()/2 - loading_info.GetRect().GetHeight()/2);

	turn_label.SetFont(chesster_font);
    turn_label.SetText("turn");
    turn_label.SetSize(32);
    turn_label.SetColor(sf::Color(197,198,141));
    turn_label.SetPosition(80, (float)wptr->GetHeight()/2 - 300);

	turn_info.SetFont(chesster_font);
    turn_info.SetText("");
    turn_info.SetSize(42);
    turn_info.SetColor(sf::Color(255,255,255));
    turn_info.SetPosition((float)(wptr->GetWidth() * 304) / 1920,(float) (wptr->GetHeight() * 235) / 1080);

	moves_label.SetFont(chesster_font);
    moves_label.SetText("moves");
    moves_label.SetSize(32);
    moves_label.SetColor(sf::Color(197,198,141));
    //moves_label.SetPosition(wptr->GetWidth() - 200, wptr->GetHeight()/2 - 300);
	//moves_label.SetPosition(moves_spt.GetPosition().x + moves_spt.GetSize().x/2 - 5, moves_spt.GetPosition().y + moves_spt.GetSize().y + 100);

	moves_info.SetFont(chesster_font);
    moves_info.SetText("");
    moves_info.SetSize(42);
    moves_info.SetColor(sf::Color(255,255,255));
    moves_info.SetPosition((float)(wptr->GetWidth() * 148) / 1920, (float)(wptr->GetHeight() * 142) / 1080);
	//moves_info.SetPosition(moves_spt.GetPosition().x + moves_spt.GetSize().x/2 - 10, moves_spt.GetPosition().y + moves_spt.GetSize().y - 15);

	turn_points_label.SetFont(chesster_font);
    turn_points_label.SetText("turn points");
    turn_points_label.SetSize(32);
    turn_points_label.SetColor(sf::Color(197,198,141));
    turn_points_label.SetPosition((float)wptr->GetWidth() - 200,(float) wptr->GetHeight()/2 - 150);

	turn_points_info.SetFont(chesster_font);
    turn_points_info.SetText("");
    turn_points_info.SetSize(42);
    turn_points_info.SetColor(sf::Color(255,255,255));
    turn_points_info.SetPosition((float)(wptr->GetWidth() * 1670) / 1920, (float)(wptr->GetHeight() * 508) / 1080);
	//turn_points_info.SetPosition(info_frame_spt.GetPosition().x + 65, info_frame_spt.GetPosition().y + 90);
	//520

	demand_label.SetFont(chesster_font);
    demand_label.SetText("demand" );
    demand_label.SetSize(32);
    demand_label.SetColor(sf::Color(197,198,141));
    demand_label.SetPosition((float)wptr->GetWidth() - 200 + 12,(float) wptr->GetHeight()/2 + 133);

	//((wptr->GetWidth() * x) / 1920)
	//((wptr->GetHeight() * y) / 1080)

	demand_info.SetFont(chesster_font);
    demand_info.SetText("");
    demand_info.SetSize(42);
    demand_info.SetColor(sf::Color(255,255,255));
	demand_info.SetPosition((float)((wptr->GetWidth() * 1670) / 1920) - demand_info.GetRect().GetWidth()/2, (float)(wptr->GetHeight() * 688) / 1080);
	//demand_info.SetPosition(info_frame_spt.GetPosition().x + 65, info_frame_spt.GetPosition().y + 185);
	//706

	total_points_label.SetFont(chesster_font);
    total_points_label.SetText("total");
    total_points_label.SetSize(32);
    total_points_label.SetColor(sf::Color(197,198,141));
    total_points_label.SetPosition((float)wptr->GetWidth() - 200,(float) wptr->GetHeight()/2 + 150);

	total_points_info.SetFont(chesster_font);
    total_points_info.SetText("");
    total_points_info.SetSize(42);
    total_points_info.SetColor(sf::Color(255,255,255));
    total_points_info.SetPosition((float)(wptr->GetWidth() * 1670) / 1920,(float) (wptr->GetHeight() * 896) / 1080);
	//total_points_info.SetPosition(info_frame_spt.GetPosition().x + 65, info_frame_spt.GetPosition().y + 300);
	//908

	match_label.SetFont(chesster_font);
    match_label.SetText("");
    match_label.SetSize(62);
    match_label.SetColor(sf::Color(255,255,255));
    match_label.SetPosition(50,(float) wptr->GetHeight()/2 - 100);

	x_label.SetFont(chesster_font);
    x_label.SetText("");
    x_label.SetSize(48);
    x_label.SetColor(sf::Color(255,255,255));
    x_label.SetPosition((float)(wptr->GetWidth() * 200) / 1920, (float)(wptr->GetHeight() * 590) / 1080);


	match_points_info.SetFont(chesster_font);
    match_points_info.SetText("");
    match_points_info.SetSize((float)this->original_font_size);
    match_points_info.SetColor(sf::Color(255,255,255));
    //match_points_info.SetPosition((wptr->GetWidth() * 180) / 1920, (wptr->GetHeight() * 680) / 1080);
	match_points_info.SetPosition((float)(wptr->GetWidth() * 200) / 1920,(float) (wptr->GetHeight() * 590) / 1080);


	multiply_spt.SetImage(resource_manager->GetImageResource(71));
	multiply_spt.Resize((float)(83 * wptr->GetWidth())/1920, (float)(90 * wptr->GetHeight())/1080);
	//multiply_spt.SetPosition((wptr->GetWidth() * 200) / 1920, (wptr->GetHeight() * 590) / 1080);
	multiply_spt.SetPosition((float)(wptr->GetWidth() * 200) / 1920,(float) match_points_info.GetPosition().y + match_points_info.GetRect().GetHeight() + 110);

	match_amount_info.SetFont(chesster_font);
    match_amount_info.SetText("");
    match_amount_info.SetSize((float)this->original_font_size);
    match_amount_info.SetColor(sf::Color(255,255,255));
    //match_amount_info.SetPosition((wptr->GetWidth() * 290) / 1920,(wptr->GetHeight() * 590) / 1080);
	match_amount_info.SetPosition((float)multiply_spt.GetPosition().x + multiply_spt.GetSize().x + 20, (float)multiply_spt.GetPosition().y);


	play_button_normal.SetImage(resource_manager->GetImageResource(21));
	play_button_focus.SetImage(resource_manager->GetImageResource(22));
	play_button_normal.Resize((float)(307 * wptr->GetWidth())/1920,(float) (113 * wptr->GetHeight())/1080);
	play_button_focus.Resize((float)(307 * wptr->GetWidth())/1920,(float) (113 * wptr->GetHeight())/1080);
	play_button_normal.SetPosition((float)this->wptr->GetWidth()/2 - play_button_normal.GetSize().x/2,(float) (wptr->GetHeight() * 465) / 1080);
	play_button_focus.SetPosition((float)this->wptr->GetWidth()/2 - play_button_focus.GetSize().x/2,(float) (wptr->GetHeight() * 465) / 1080);

	tutorial_button_normal.SetImage(resource_manager->GetImageResource(23));
	tutorial_button_focus.SetImage(resource_manager->GetImageResource(24));
	tutorial_button_normal.Resize((float)(419 * wptr->GetWidth())/1920, (float)(106 * wptr->GetHeight())/1080);
	tutorial_button_focus.Resize((float)(419 * wptr->GetWidth())/1920, (float)(106 * wptr->GetHeight())/1080);
	tutorial_button_normal.SetPosition((float)this->wptr->GetWidth()/2 - tutorial_button_normal.GetSize().x/2,(float) (wptr->GetHeight() * 575) / 1080);
	tutorial_button_focus.SetPosition((float)this->wptr->GetWidth()/2 - tutorial_button_focus.GetSize().x/2, (float)(wptr->GetHeight() * 575) / 1080);
	
	// Version with Puzzle
	puzzle_button_normal.SetImage(resource_manager->GetImageResource(25));
	puzzle_button_focus.SetImage(resource_manager->GetImageResource(26));
	puzzle_button_normal.Resize((float)(396 * wptr->GetWidth())/1920, (float)(91 * wptr->GetHeight())/1080);
	puzzle_button_focus.Resize((float)(396 * wptr->GetWidth())/1920,(float) (91 * wptr->GetHeight())/1080);
	puzzle_button_normal.SetPosition((float)this->wptr->GetWidth()/2 - puzzle_button_normal.GetSize().x/2, (float)(wptr->GetHeight() * 690) / 1080);
	puzzle_button_focus.SetPosition((float)this->wptr->GetWidth()/2 - puzzle_button_focus.GetSize().x/2,(float) (wptr->GetHeight() * 690) / 1080);

	scores_button_normal.SetImage(resource_manager->GetImageResource(27));
	scores_button_focus.SetImage(resource_manager->GetImageResource(28));
	scores_button_normal.Resize((float)(385 * wptr->GetWidth())/1920,(float) (90 * wptr->GetHeight())/1080);
	scores_button_focus.Resize((float)(385 * wptr->GetWidth())/1920, (float)(90 * wptr->GetHeight())/1080);
	scores_button_normal.SetPosition((float)this->wptr->GetWidth()/2 - scores_button_normal.GetSize().x/2,(float) (wptr->GetHeight() * 805) / 1080);
	scores_button_focus.SetPosition((float)this->wptr->GetWidth()/2 - scores_button_focus.GetSize().x/2,(float) (wptr->GetHeight() * 805) / 1080);

	credits_button_normal.SetImage(resource_manager->GetImageResource(29));
	credits_button_focus.SetImage(resource_manager->GetImageResource(30));
	credits_button_normal.Resize((float)(402 * wptr->GetWidth())/1920,(float) (90 * wptr->GetHeight())/1080);
	credits_button_focus.Resize((float)(402 * wptr->GetWidth())/1920, (float)(90 * wptr->GetHeight())/1080);
	credits_button_normal.SetPosition((float)this->wptr->GetWidth()/2 - credits_button_normal.GetSize().x/2,(float) (wptr->GetHeight() * 920) / 1080);
	credits_button_focus.SetPosition((float)this->wptr->GetWidth()/2 - credits_button_focus.GetSize().x/2, (float)(wptr->GetHeight() * 920) / 1080);
	


	//Version without Puzzle
	/*
	scores_button_normal.SetImage(resource_manager->GetImageResource(27));
	scores_button_focus.SetImage(resource_manager->GetImageResource(28));
	scores_button_normal.Resize((385 * wptr->GetWidth())/1920, (90 * wptr->GetHeight())/1080);
	scores_button_focus.Resize((385 * wptr->GetWidth())/1920, (90 * wptr->GetHeight())/1080);
	scores_button_normal.SetPosition(this->wptr->GetWidth()/2 - scores_button_normal.GetSize().x/2, (wptr->GetHeight() * 690) / 1080);
	scores_button_focus.SetPosition(this->wptr->GetWidth()/2 - scores_button_focus.GetSize().x/2, (wptr->GetHeight() * 690) / 1080);

	credits_button_normal.SetImage(resource_manager->GetImageResource(29));
	credits_button_focus.SetImage(resource_manager->GetImageResource(30));
	credits_button_normal.Resize((402 * wptr->GetWidth())/1920, (90 * wptr->GetHeight())/1080);
	credits_button_focus.Resize((402 * wptr->GetWidth())/1920, (90 * wptr->GetHeight())/1080);
	credits_button_normal.SetPosition(this->wptr->GetWidth()/2 - credits_button_normal.GetSize().x/2, (wptr->GetHeight() * 805) / 1080);
	credits_button_focus.SetPosition(this->wptr->GetWidth()/2 - credits_button_focus.GetSize().x/2, (wptr->GetHeight() * 805) / 1080);
	*/

	quit_button_normal.SetImage(resource_manager->GetImageResource(69));
	quit_button_focus.SetImage(resource_manager->GetImageResource(70));
	quit_button_normal.Resize((float)(140 * wptr->GetWidth())/1920,(float) (80 * wptr->GetHeight())/1080);
	quit_button_focus.Resize((float)(140 * wptr->GetWidth())/1920,(float) (80 * wptr->GetHeight())/1080);
	quit_button_normal.SetPosition(20, (float)wptr->GetHeight() - quit_button_focus.GetSize().y - 20);
	quit_button_focus.SetPosition(20,(float) wptr->GetHeight() - quit_button_focus.GetSize().y - 20);

	
	new_button_normal.SetImage(resource_manager->GetImageResource(76));
	new_button_focus.SetImage(resource_manager->GetImageResource(77));
	new_button_normal.Resize((float)(145 * wptr->GetWidth())/1920, (float)(80 * wptr->GetHeight())/1080);
	new_button_focus.Resize((float)(145 * wptr->GetWidth())/1920, (float)(80 * wptr->GetHeight())/1080);
	new_button_normal.SetPosition((float)this->wptr->GetWidth()/2 - new_button_normal.GetSize().x/2,(float) (wptr->GetHeight() * 465) / 1080);
	new_button_focus.SetPosition((float)this->wptr->GetWidth()/2 - new_button_focus.GetSize().x/2, (float)(wptr->GetHeight() * 465) / 1080);


	resume_button_normal.SetImage(resource_manager->GetImageResource(78));
	resume_button_focus.SetImage(resource_manager->GetImageResource(79));
	resume_button_normal.Resize((float)(254 * wptr->GetWidth())/1920,(float) (80 * wptr->GetHeight())/1080);
	resume_button_focus.Resize((float)(254 * wptr->GetWidth())/1920,(float) (80 * wptr->GetHeight())/1080);
	resume_button_normal.SetPosition((float)this->wptr->GetWidth()/2 - resume_button_normal.GetSize().x/2, (float)(wptr->GetHeight() * 575) / 1080);
	resume_button_focus.SetPosition((float)this->wptr->GetWidth()/2 - resume_button_focus.GetSize().x/2,(float) (wptr->GetHeight() * 575) / 1080);

	back_button_normal.SetImage(resource_manager->GetImageResource(80));
	back_button_focus.SetImage(resource_manager->GetImageResource(81));
	back_button_normal.Resize((float)(170 * wptr->GetWidth())/1920, (float)(84 * wptr->GetHeight())/1080);
	back_button_focus.Resize((float)(170 * wptr->GetWidth())/1920,(float) (84 * wptr->GetHeight())/1080);
	back_button_normal.SetPosition((float)this->wptr->GetWidth()/2 - back_button_normal.GetSize().x/2, (float)(wptr->GetHeight() * 690) / 1080);
	back_button_focus.SetPosition((float)this->wptr->GetWidth()/2 - back_button_focus.GetSize().x/2, (float)(wptr->GetHeight() * 690) / 1080);


	combos_button_focus.SetImage(resource_manager->GetImageResource(33));
	combos_button_focus.Resize((float)(146 * wptr->GetWidth())/1920,(float) (146 * wptr->GetHeight())/1080);
	combos_button_focus.SetPosition((float)(wptr->GetWidth() * 301) / 1920,(float) (wptr->GetHeight() * 886) / 1080);
	//combos_button_focus.SetPosition((wptr->GetWidth() * 22) / 1920, (wptr->GetHeight() * 26) / 1080);

	combos_button_off.SetImage(resource_manager->GetImageResource(31));
	combos_button_off.Resize((float)(146 * wptr->GetWidth())/1920, (float)(146 * wptr->GetHeight())/1080);
	combos_button_off.SetPosition((float)(wptr->GetWidth() * 301) / 1920, (float)(wptr->GetHeight() * 886) / 1080);
	//combos_button_off.SetPosition((wptr->GetWidth() * 153) / 1920, (wptr->GetHeight() * 26) / 1080);

	combos_button_on.SetImage(resource_manager->GetImageResource(32));
	combos_button_on.Resize((float)(146 * wptr->GetWidth())/1920, (float)(146 * wptr->GetHeight())/1080);
	combos_button_on.SetPosition((float)(wptr->GetWidth() * 301) / 1920, (float)(wptr->GetHeight() * 886) / 1080);
	combos_button_state = "off";

	movement_button_focus.SetImage(resource_manager->GetImageResource(36));
	movement_button_focus.Resize((float)(146 * wptr->GetWidth())/1920,(float) (146 * wptr->GetHeight())/1080);
	movement_button_focus.SetPosition((float)(wptr->GetWidth() * 42) / 1920, (float)(wptr->GetHeight() * 886) / 1080);

	movement_button_off.SetImage(resource_manager->GetImageResource(34));
	movement_button_off.Resize((float)(146 * wptr->GetWidth())/1920, (float)(146 * wptr->GetHeight())/1080);
	movement_button_off.SetPosition((float)(wptr->GetWidth() * 42) / 1920,(float) (wptr->GetHeight() * 886) / 1080);

	movement_button_on.SetImage(resource_manager->GetImageResource(35));
	movement_button_on.Resize((float)(146 * wptr->GetWidth())/1920, (float)(146 * wptr->GetHeight())/1080);
	movement_button_on.SetPosition((float)(wptr->GetWidth() * 42) / 1920,(float) (wptr->GetHeight() * 886) / 1080);
	movement_button_state = "off";

	treasure_button_focus.SetImage(resource_manager->GetImageResource(39));
	treasure_button_focus.Resize((float)(146 * wptr->GetWidth())/1920,(float) (147 * wptr->GetHeight())/1080);
	treasure_button_focus.SetPosition((float)(wptr->GetWidth() * 174) / 1920, (float)(wptr->GetHeight() * 886) / 1080);

	treasure_button_off.SetImage(resource_manager->GetImageResource(37));
	treasure_button_off.Resize((float)(146 * wptr->GetWidth())/1920, (float)(146 * wptr->GetHeight())/1080);
	treasure_button_off.SetPosition((float)(wptr->GetWidth() * 174) / 1920, (float)(wptr->GetHeight() * 886) / 1080);

	treasure_button_on.SetImage(resource_manager->GetImageResource(38));
	treasure_button_on.Resize((float)(146 * wptr->GetWidth())/1920, (float)(146 * wptr->GetHeight())/1080);
	treasure_button_on.SetPosition((float)(wptr->GetWidth() * 174) / 1920,(float) (wptr->GetHeight() * 886) / 1080);
	treasure_button_state = "off";



	
	combos_board.SetImage(resource_manager->GetImageResource(40));
	combos_board.Resize((float)(483 * wptr->GetWidth())/1920,(float) (809 * wptr->GetHeight())/1080);
	//combos_board.SetPosition((wptr->GetWidth() * 44) / 1920, (wptr->GetHeight() * 80) / 1080);
	combos_board.SetPosition((float)0 - combos_board.GetSize().x - 20,(float) (wptr->GetHeight() * 80) / 1080);
	combosboard_x = combos_board.GetPosition().x;
	combos_board_state = "off";

	movement_board.SetImage(resource_manager->GetImageResource(41));
	movement_board.Resize((float)(483 * wptr->GetWidth())/1920,(float) (809 * wptr->GetHeight())/1080);
	//movement_board.SetPosition((wptr->GetWidth() * 44) / 1920, (wptr->GetHeight() * 80) / 1080);
	movement_board.SetPosition((float)0 - combos_board.GetSize().x - 20,(float) (wptr->GetHeight() * 80) / 1080);
	movesboard_x = movement_board.GetPosition().x;
	movement_board_state = "off";

	treasure_board.SetImage(resource_manager->GetImageResource(42));
	treasure_board.Resize((float)(483 * wptr->GetWidth())/1920, (float)(809 * wptr->GetHeight())/1080);
	//treasure_board.SetPosition((wptr->GetWidth() * 44) / 1920, (wptr->GetHeight() * 80) / 1080);
	treasure_board.SetPosition((float)0 - combos_board.GetSize().x - 20, (float)(wptr->GetHeight() * 80) / 1080);
	treasuresboard_x = treasure_board.GetPosition().x;
	treasure_board_state = "off";
	
	is_sliding_out = false;
	textboard_to_show = "null";
	textboard_to_hide = "null";
	slide_speed = 2000;


	next_treasure_info[0].SetFont(chesster_font);
    next_treasure_info[0].SetText("200pts");
    next_treasure_info[0].SetSize(48);
    next_treasure_info[0].SetColor(sf::Color(0,0,0));
    next_treasure_info[0].SetPosition((float)(wptr->GetWidth() * 1600) / 1920,(float) (wptr->GetHeight() * 238) / 1080);

	next_treasure_info[1].SetFont(chesster_font);
    next_treasure_info[1].SetText("300pts");
    next_treasure_info[1].SetSize(48);
    next_treasure_info[1].SetColor(sf::Color(0,0,0));
    next_treasure_info[1].SetPosition((float)(wptr->GetWidth() * 1600) / 1920,(float) (wptr->GetHeight() * 238) / 1080);

	next_treasure_info[2].SetFont(chesster_font);
    next_treasure_info[2].SetText("400pts");
    next_treasure_info[2].SetSize(48);
    next_treasure_info[2].SetColor(sf::Color(0,0,0));
    next_treasure_info[2].SetPosition((float)(wptr->GetWidth() * 1600) / 1920, (float)(wptr->GetHeight() * 238) / 1080);

	next_treasure_info[3].SetFont(chesster_font);
    next_treasure_info[3].SetText("500pts");
    next_treasure_info[3].SetSize(48);
    next_treasure_info[3].SetColor(sf::Color(0,0,0));
    next_treasure_info[3].SetPosition((float)(wptr->GetWidth() * 1600) / 1920, (float)(wptr->GetHeight() * 238) / 1080);


	demand_animation[0].SetImage(resource_manager->LoadDemandAnimation(0));
	demand_animation[0].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[0].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[1].SetImage(resource_manager->LoadDemandAnimation(1));
	demand_animation[1].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[1].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[2].SetImage(resource_manager->LoadDemandAnimation(2));
	demand_animation[2].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[2].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[3].SetImage(resource_manager->LoadDemandAnimation(3));
	demand_animation[3].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[3].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[4].SetImage(resource_manager->LoadDemandAnimation(0));
	demand_animation[4].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[4].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[5].SetImage(resource_manager->LoadDemandAnimation(5));
	demand_animation[5].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[5].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[6].SetImage(resource_manager->LoadDemandAnimation(6));
	demand_animation[6].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[6].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[7].SetImage(resource_manager->LoadDemandAnimation(7));
	demand_animation[7].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[7].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[8].SetImage(resource_manager->LoadDemandAnimation(8));
	demand_animation[8].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[8].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[9].SetImage(resource_manager->LoadDemandAnimation(9));
	demand_animation[9].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[9].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[10].SetImage(resource_manager->LoadDemandAnimation(10));
	demand_animation[10].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[10].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[11].SetImage(resource_manager->LoadDemandAnimation(11));
	demand_animation[11].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[11].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[12].SetImage(resource_manager->LoadDemandAnimation(12));
	demand_animation[12].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[12].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[13].SetImage(resource_manager->LoadDemandAnimation(13));
	demand_animation[13].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[13].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[14].SetImage(resource_manager->LoadDemandAnimation(14));
	demand_animation[14].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[14].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[15].SetImage(resource_manager->LoadDemandAnimation(15));
	demand_animation[15].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[15].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[16].SetImage(resource_manager->LoadDemandAnimation(16));
	demand_animation[16].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[16].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[17].SetImage(resource_manager->LoadDemandAnimation(17));
	demand_animation[17].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[17].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[18].SetImage(resource_manager->LoadDemandAnimation(18));
	demand_animation[18].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[18].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[19].SetImage(resource_manager->LoadDemandAnimation(19));
	demand_animation[19].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[19].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[20].SetImage(resource_manager->LoadDemandAnimation(20));
	demand_animation[20].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[20].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[21].SetImage(resource_manager->LoadDemandAnimation(21));
	demand_animation[21].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[21].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);

	demand_animation[22].SetImage(resource_manager->LoadDemandAnimation(22));
	demand_animation[22].Resize((float)(600 * wptr->GetWidth())/1920, (float)(600 * wptr->GetHeight())/1080);
	demand_animation[22].SetPosition((float)(wptr->GetWidth() * 1372) / 1920, (float)(wptr->GetHeight() * 232) / 1080);


	positive_score_animation[0].SetImage(resource_manager->LoadPositiveScoreAnimation(0));
	positive_score_animation[0].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[0].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[1].SetImage(resource_manager->LoadPositiveScoreAnimation(1));
	positive_score_animation[1].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[1].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[2].SetImage(resource_manager->LoadPositiveScoreAnimation(2));
	positive_score_animation[2].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[2].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[3].SetImage(resource_manager->LoadPositiveScoreAnimation(3));
	positive_score_animation[3].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[3].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[4].SetImage(resource_manager->LoadPositiveScoreAnimation(4));
	positive_score_animation[4].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[4].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[5].SetImage(resource_manager->LoadPositiveScoreAnimation(5));
	positive_score_animation[5].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[5].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[6].SetImage(resource_manager->LoadPositiveScoreAnimation(6));
	positive_score_animation[6].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[6].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[7].SetImage(resource_manager->LoadPositiveScoreAnimation(7));
	positive_score_animation[7].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[7].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[8].SetImage(resource_manager->LoadPositiveScoreAnimation(8));
	positive_score_animation[8].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[8].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[9].SetImage(resource_manager->LoadPositiveScoreAnimation(9));
	positive_score_animation[9].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[9].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[10].SetImage(resource_manager->LoadPositiveScoreAnimation(10));
	positive_score_animation[10].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[10].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[11].SetImage(resource_manager->LoadPositiveScoreAnimation(11));
	positive_score_animation[11].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[11].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[12].SetImage(resource_manager->LoadPositiveScoreAnimation(12));
	positive_score_animation[12].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[12].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[13].SetImage(resource_manager->LoadPositiveScoreAnimation(13));
	positive_score_animation[13].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[13].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[14].SetImage(resource_manager->LoadPositiveScoreAnimation(14));
	positive_score_animation[14].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[14].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[15].SetImage(resource_manager->LoadPositiveScoreAnimation(15));
	positive_score_animation[15].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[15].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[16].SetImage(resource_manager->LoadPositiveScoreAnimation(16));
	positive_score_animation[16].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[16].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[17].SetImage(resource_manager->LoadPositiveScoreAnimation(17));
	positive_score_animation[17].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[17].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[18].SetImage(resource_manager->LoadPositiveScoreAnimation(18));
	positive_score_animation[18].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[18].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[19].SetImage(resource_manager->LoadPositiveScoreAnimation(19));
	positive_score_animation[19].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[19].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[20].SetImage(resource_manager->LoadPositiveScoreAnimation(20));
	positive_score_animation[20].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[20].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[21].SetImage(resource_manager->LoadPositiveScoreAnimation(21));
	positive_score_animation[21].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[21].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[22].SetImage(resource_manager->LoadPositiveScoreAnimation(22));
	positive_score_animation[22].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[22].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[23].SetImage(resource_manager->LoadPositiveScoreAnimation(23));
	positive_score_animation[23].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[23].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);

	positive_score_animation[24].SetImage(resource_manager->LoadPositiveScoreAnimation(24));
	positive_score_animation[24].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_score_animation[24].SetPosition((float)(wptr->GetWidth() * 1440) / 1920, (float)(wptr->GetHeight() * 260) / 1080);



	positive_total_score_animation[0].SetImage(resource_manager->LoadPositiveScoreAnimation(0));
	positive_total_score_animation[0].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[0].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[1].SetImage(resource_manager->LoadPositiveScoreAnimation(1));
	positive_total_score_animation[1].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[1].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[2].SetImage(resource_manager->LoadPositiveScoreAnimation(2));
	positive_total_score_animation[2].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[2].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[3].SetImage(resource_manager->LoadPositiveScoreAnimation(3));
	positive_total_score_animation[3].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[3].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[4].SetImage(resource_manager->LoadPositiveScoreAnimation(4));
	positive_total_score_animation[4].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[4].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[5].SetImage(resource_manager->LoadPositiveScoreAnimation(5));
	positive_total_score_animation[5].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[5].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[6].SetImage(resource_manager->LoadPositiveScoreAnimation(6));
	positive_total_score_animation[6].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[6].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[7].SetImage(resource_manager->LoadPositiveScoreAnimation(7));
	positive_total_score_animation[7].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[7].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[8].SetImage(resource_manager->LoadPositiveScoreAnimation(8));
	positive_total_score_animation[8].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[8].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[9].SetImage(resource_manager->LoadPositiveScoreAnimation(9));
	positive_total_score_animation[9].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[9].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[10].SetImage(resource_manager->LoadPositiveScoreAnimation(10));
	positive_total_score_animation[10].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[10].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[11].SetImage(resource_manager->LoadPositiveScoreAnimation(11));
	positive_total_score_animation[11].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[11].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[12].SetImage(resource_manager->LoadPositiveScoreAnimation(12));
	positive_total_score_animation[12].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[12].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[13].SetImage(resource_manager->LoadPositiveScoreAnimation(13));
	positive_total_score_animation[13].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[13].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[14].SetImage(resource_manager->LoadPositiveScoreAnimation(14));
	positive_total_score_animation[14].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[14].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[15].SetImage(resource_manager->LoadPositiveScoreAnimation(15));
	positive_total_score_animation[15].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[15].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[16].SetImage(resource_manager->LoadPositiveScoreAnimation(16));
	positive_total_score_animation[16].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[16].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[17].SetImage(resource_manager->LoadPositiveScoreAnimation(17));
	positive_total_score_animation[17].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[17].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[18].SetImage(resource_manager->LoadPositiveScoreAnimation(18));
	positive_total_score_animation[18].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[18].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[19].SetImage(resource_manager->LoadPositiveScoreAnimation(19));
	positive_total_score_animation[19].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[19].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[20].SetImage(resource_manager->LoadPositiveScoreAnimation(20));
	positive_total_score_animation[20].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[20].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[21].SetImage(resource_manager->LoadPositiveScoreAnimation(21));
	positive_total_score_animation[21].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[21].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[22].SetImage(resource_manager->LoadPositiveScoreAnimation(22));
	positive_total_score_animation[22].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[22].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[23].SetImage(resource_manager->LoadPositiveScoreAnimation(23));
	positive_total_score_animation[23].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[23].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	positive_total_score_animation[24].SetImage(resource_manager->LoadPositiveScoreAnimation(24));
	positive_total_score_animation[24].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	positive_total_score_animation[24].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);
	

	negative_total_score_animation[0].SetImage(resource_manager->LoadNegativeScoreAnimation(0));
	negative_total_score_animation[0].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[0].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[1].SetImage(resource_manager->LoadNegativeScoreAnimation(1));
	negative_total_score_animation[1].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[1].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[2].SetImage(resource_manager->LoadNegativeScoreAnimation(2));
	negative_total_score_animation[2].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[2].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[3].SetImage(resource_manager->LoadNegativeScoreAnimation(3));
	negative_total_score_animation[3].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[3].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[4].SetImage(resource_manager->LoadNegativeScoreAnimation(4));
	negative_total_score_animation[4].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[4].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[5].SetImage(resource_manager->LoadNegativeScoreAnimation(5));
	negative_total_score_animation[5].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[5].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[6].SetImage(resource_manager->LoadNegativeScoreAnimation(6));
	negative_total_score_animation[6].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[6].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[7].SetImage(resource_manager->LoadNegativeScoreAnimation(7));
	negative_total_score_animation[7].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[7].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[8].SetImage(resource_manager->LoadNegativeScoreAnimation(8));
	negative_total_score_animation[8].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[8].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[9].SetImage(resource_manager->LoadNegativeScoreAnimation(9));
	negative_total_score_animation[9].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[9].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[10].SetImage(resource_manager->LoadNegativeScoreAnimation(10));
	negative_total_score_animation[10].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[10].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[11].SetImage(resource_manager->LoadNegativeScoreAnimation(11));
	negative_total_score_animation[11].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[11].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[12].SetImage(resource_manager->LoadNegativeScoreAnimation(12));
	negative_total_score_animation[12].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[12].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[13].SetImage(resource_manager->LoadNegativeScoreAnimation(13));
	negative_total_score_animation[13].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[13].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[14].SetImage(resource_manager->LoadNegativeScoreAnimation(14));
	negative_total_score_animation[14].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[14].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[15].SetImage(resource_manager->LoadNegativeScoreAnimation(15));
	negative_total_score_animation[15].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[15].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[16].SetImage(resource_manager->LoadNegativeScoreAnimation(16));
	negative_total_score_animation[16].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[16].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[17].SetImage(resource_manager->LoadNegativeScoreAnimation(17));
	negative_total_score_animation[17].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[17].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[18].SetImage(resource_manager->LoadNegativeScoreAnimation(18));
	negative_total_score_animation[18].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[18].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[19].SetImage(resource_manager->LoadNegativeScoreAnimation(19));
	negative_total_score_animation[19].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[19].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

	negative_total_score_animation[20].SetImage(resource_manager->LoadNegativeScoreAnimation(20));
	negative_total_score_animation[20].Resize((float)(430 * wptr->GetWidth())/1920, (float)(430 * wptr->GetHeight())/1080);
	negative_total_score_animation[20].SetPosition((float)(wptr->GetWidth() * 1464) / 1920, (float)(wptr->GetHeight() * 652) / 1080);

}

void InterfaceManager::SetupTreasureImagesForNewLevel()
{
	treasure[0].SetImage(resource_manager->OnDemandLoadTreasures(0));
	treasure[0].Resize((float)(120 * wptr->GetWidth())/1920, (float)(120 * wptr->GetHeight())/1080);
	treasure[0].SetPosition((float)(wptr->GetWidth() * 133) / 1920, (float)(wptr->GetHeight() * 327) / 1080);
	unlocked_treasures[0] = false;
	treasure_shadow[0].SetImage(resource_manager->OnDemandLoadTreasures(4));
	treasure_shadow[0].Resize((float)(120 * wptr->GetWidth())/1920, (float)(120 * wptr->GetHeight())/1080);
	treasure_shadow[0].SetPosition((float)(wptr->GetWidth() * 133) / 1920, (float)(wptr->GetHeight() * 327) / 1080);
	next_treasure[0].SetImage(resource_manager->OnDemandLoadTreasures(0));
	next_treasure[0].Resize((float)(160 * wptr->GetWidth())/1920, (float)(160 * wptr->GetHeight())/1080);
	next_treasure[0].SetPosition((float)(wptr->GetWidth() * 1598) / 1920, (float)(wptr->GetHeight() * 51) / 1080);

	treasure[1].SetImage(resource_manager->OnDemandLoadTreasures(1));
	treasure[1].Resize((float)(120 * wptr->GetWidth())/1920, (float)(120 * wptr->GetHeight())/1080);
	treasure[1].SetPosition((float)(wptr->GetWidth() * 294) / 1920, (float)(wptr->GetHeight() * 326) / 1080);
	unlocked_treasures[1] = false;
	treasure_shadow[1].SetImage(resource_manager->OnDemandLoadTreasures(5));
	treasure_shadow[1].Resize((float)(120 * wptr->GetWidth())/1920, (float)(120 * wptr->GetHeight())/1080);
	treasure_shadow[1].SetPosition((float)(wptr->GetWidth() * 294) / 1920, (float)(wptr->GetHeight() * 326) / 1080);
	next_treasure[1].SetImage(resource_manager->OnDemandLoadTreasures(1));
	next_treasure[1].Resize((float)(160 * wptr->GetWidth())/1920, (float)(160 * wptr->GetHeight())/1080);
	next_treasure[1].SetPosition((float)(wptr->GetWidth() * 1598) / 1920, (float)(wptr->GetHeight() * 51) / 1080);

	treasure[2].SetImage(resource_manager->OnDemandLoadTreasures(2));
	treasure[2].Resize((float)(120 * wptr->GetWidth())/1920, (float)(120 * wptr->GetHeight())/1080);
	treasure[2].SetPosition((float)(wptr->GetWidth() * 141) / 1920, (float)(wptr->GetHeight() * 554) / 1080);
	unlocked_treasures[2] = false;
	treasure_shadow[2].SetImage(resource_manager->OnDemandLoadTreasures(6));
	treasure_shadow[2].Resize((float)(120 * wptr->GetWidth())/1920,(float) (120 * wptr->GetHeight())/1080);
	treasure_shadow[2].SetPosition((float)(wptr->GetWidth() * 141) / 1920, (float)(wptr->GetHeight() * 554) / 1080);
	next_treasure[2].SetImage(resource_manager->OnDemandLoadTreasures(2));
	next_treasure[2].Resize((float)(160 * wptr->GetWidth())/1920, (float)(160 * wptr->GetHeight())/1080);
	next_treasure[2].SetPosition((float)(wptr->GetWidth() * 1598) / 1920, (float)(wptr->GetHeight() * 51) / 1080);

	treasure[3].SetImage(resource_manager->OnDemandLoadTreasures(3));
	treasure[3].Resize((float)(120 * wptr->GetWidth())/1920, (float)(120 * wptr->GetHeight())/1080);
	treasure[3].SetPosition((float)(wptr->GetWidth() * 301) / 1920, (float)(wptr->GetHeight() * 538) / 1080);
	unlocked_treasures[3] = false;
	treasure_shadow[3].SetImage(resource_manager->OnDemandLoadTreasures(7));
	treasure_shadow[3].Resize((float)(120 * wptr->GetWidth())/1920, (float)(120 * wptr->GetHeight())/1080);
	treasure_shadow[3].SetPosition((float)(wptr->GetWidth() * 301) / 1920, (float)(wptr->GetHeight() * 538) / 1080);
	next_treasure[3].SetImage(resource_manager->OnDemandLoadTreasures(3));
	next_treasure[3].Resize((float)(160 * wptr->GetWidth())/1920, (float)(160 * wptr->GetHeight())/1080);
	next_treasure[3].SetPosition((float)(wptr->GetWidth() * 1598) / 1920, (float)(wptr->GetHeight() * 51) / 1080);
}

void InterfaceManager::PerformTextboardSlide()
{
	if (is_sliding_out)
	{
		if (textboard_to_hide == "treasure")
		{
			if (treasuresboard_x > moving_textboard_target_x)
			{
				treasuresboard_x -= slide_speed * wptr->GetFrameTime();
				treasure_board.SetPosition(treasuresboard_x, (wptr->GetHeight() * 80) / 1080);
			}
			else
			{
				textboard_to_hide = "null";
				treasure_board_state = "off";

				if (textboard_to_show == "moves")
				{
					movement_board_state = "on";
					moving_textboard_target_x = (float)(wptr->GetWidth() * 44) / 1920;
				}
				else if (textboard_to_show == "combos")
				{
					combos_board_state = "on";
					moving_textboard_target_x = (float)(wptr->GetWidth() * 44) / 1920;
				}

				is_sliding_out = false;
			}
		}
		else if (textboard_to_hide == "moves")
		{
			if (movesboard_x > moving_textboard_target_x)
			{
				movesboard_x -= slide_speed * wptr->GetFrameTime();
				movement_board.SetPosition((float)movesboard_x, (float)(wptr->GetHeight() * 80) / 1080);
			}
			else
			{	
				textboard_to_hide = "null";
				movement_board_state = "off";

				if (textboard_to_show == "treasure")
				{
					treasure_board_state = "on";
					moving_textboard_target_x = (float)(wptr->GetWidth() * 44) / 1920;
				}
				else if (textboard_to_show == "combos")
				{
					combos_board_state = "on";
					moving_textboard_target_x = (float)(wptr->GetWidth() * 44) / 1920;
				}

				is_sliding_out = false;
			}
		}
		else if (textboard_to_hide == "combos")
		{
			if (combosboard_x > moving_textboard_target_x)
			{
				combosboard_x  -= slide_speed * wptr->GetFrameTime();
				combos_board.SetPosition((float)combosboard_x , (float)(wptr->GetHeight() * 80) / 1080);
			}
			else
			{
				textboard_to_hide = "null";
				combos_board_state = "off";

				if (textboard_to_show == "moves")
				{
					movement_board_state = "on";
					moving_textboard_target_x = (float)(wptr->GetWidth() * 44) / 1920;
				}
				else if (textboard_to_show == "treasure")
				{
					treasure_board_state = "on";
					moving_textboard_target_x = (float)(wptr->GetWidth() * 44) / 1920;
				}

				is_sliding_out = false;
			}
		}
	}
	else // Slide in
	{
		if (textboard_to_show == "treasure")
		{
			if (treasuresboard_x < moving_textboard_target_x)
			{
				treasuresboard_x += slide_speed * wptr->GetFrameTime();
				treasure_board.SetPosition((float)treasuresboard_x, (float)(wptr->GetHeight() * 80) / 1080);
			}
			else
			{
				textboard_to_show = "null";

			}
		}
		else if (textboard_to_show == "moves")
		{
			if (movesboard_x < moving_textboard_target_x)
			{
				movesboard_x += slide_speed * wptr->GetFrameTime();
				movement_board.SetPosition((float)movesboard_x, (float)(wptr->GetHeight() * 80) / 1080);
			}
			else
			{
				textboard_to_show = "null";
			}
		}
		else if (textboard_to_show == "combos")
		{
			if (combosboard_x < moving_textboard_target_x)
			{
				combosboard_x  += slide_speed * wptr->GetFrameTime();
				combos_board.SetPosition((float)combosboard_x , (float)(wptr->GetHeight() * 80) / 1080);
			}
			else
			{
				textboard_to_show = "null";
			}
		}
	}
}

void InterfaceManager::SetupTextboardTransition(std::string in, std::string out)
{
	//one going out and another going in
	if (in != "null" && out != "null")
	{
		//std::cout <<"ONE IN ANOTHER OUT \n\n";

		if (out == "combos")
		{
			textboard_to_hide = "combos";
			moving_textboard_target_x = 0 - combos_board.GetSize().x - 20;
		}
		else if (out == "moves")
		{
			textboard_to_hide = "moves";
			moving_textboard_target_x = 0 - movement_board.GetSize().x - 20;
		}
		else if (out == "treasure")
		{
			textboard_to_hide = "treasure";
			moving_textboard_target_x = 0 - treasure_board.GetSize().x - 20;
		}
		
		textboard_to_show = in;
		is_sliding_out = true;
	}

	//just one going out
	else if (in == "null" && out != "null")
	{
		//std::cout <<"JUST ONE OUT \n\n";

		if (out == "combos")
		{
			textboard_to_hide = "combos";
			moving_textboard_target_x = 0 - combos_board.GetSize().x - 20;
		}
		else if (out == "moves")
		{
			textboard_to_hide = "moves";
			moving_textboard_target_x = 0 - movement_board.GetSize().x - 20;
		}
		else if (out == "treasure")
		{
			textboard_to_hide = "treasure";
			moving_textboard_target_x = 0 - treasure_board.GetSize().x - 20;
		}
		
		textboard_to_show = "null";
		is_sliding_out = true;
	}

	//just one going in
	else if (in != "null" && out == "null")
	{
		//std::cout <<"JUST ONE IN \n\n";

		if (in == "combos")
		{
			textboard_to_show = "combos";
			combos_board_state = "on";
			moving_textboard_target_x = (float)(wptr->GetWidth() * 44) / 1920;
		}
		else if (in == "moves")
		{
			textboard_to_show = "moves";
			movement_board_state = "on";
			moving_textboard_target_x = (float)(wptr->GetWidth() * 44) / 1920;
		}
		else if (in == "treasure")
		{
			textboard_to_show = "treasure";
			treasure_board_state = "on";
			moving_textboard_target_x = (float)(wptr->GetWidth() * 44) / 1920;
		}
		
		textboard_to_hide = "null";
		is_sliding_out = false;
	}
}

void InterfaceManager::ShowNextTreasure()
{
	if (!this->unlocked_treasures[3] && !this->unlocked_treasures[2] && !this->unlocked_treasures[1] && !this->unlocked_treasures[0])
	{
		//show first treasure
		this->wptr->Draw(this->next_treasure[0]);
		this->wptr->Draw(this->next_treasure_info[0]);
		this->wptr->Draw(this->next_treasure_banner);
	}
	else if (!this->unlocked_treasures[3] && !this->unlocked_treasures[2] && !this->unlocked_treasures[1] && this->unlocked_treasures[0])
	{
		//show second treasure
		this->wptr->Draw(this->next_treasure[1]);
		this->wptr->Draw(this->next_treasure_info[1]);
		this->wptr->Draw(this->next_treasure_banner);
	}
	else if (!this->unlocked_treasures[3] && !this->unlocked_treasures[2] && this->unlocked_treasures[1] && this->unlocked_treasures[0])
	{
		//show third treasure
		this->wptr->Draw(this->next_treasure[2]);
		this->wptr->Draw(this->next_treasure_info[2]);
		this->wptr->Draw(this->next_treasure_banner);
	}
	else if (!this->unlocked_treasures[3] && this->unlocked_treasures[2] && this->unlocked_treasures[1] && this->unlocked_treasures[0])
	{
		//show fourth treasure
		this->wptr->Draw(this->next_treasure[3]);
		this->wptr->Draw(this->next_treasure_info[3]);
		this->wptr->Draw(this->next_treasure_banner);
	}
}

void InterfaceManager::RetifyTextPositions()
{
	demand_info.SetPosition((float)((wptr->GetWidth() * 1670) / 1920) - demand_info.GetRect().GetWidth()/2, (float)(wptr->GetHeight() * 688) / 1080);
	turn_points_info.SetPosition((float)((wptr->GetWidth() * 1670) / 1920) - turn_points_info.GetRect().GetWidth()/2, (float)(wptr->GetHeight() * 508) / 1080);
	total_points_info.SetPosition((float)((wptr->GetWidth() * 1670) / 1920) - total_points_info.GetRect().GetWidth()/2, (float)(wptr->GetHeight() * 896) / 1080);
}

void InterfaceManager::ResetFontSize()
{
	this->match_amount_info.SetSize((float)this->original_font_size);
	this->match_points_info.SetSize((float)this->original_font_size);
}

void InterfaceManager::IncreaseFontSize()
{
	if (this->match_amount_info.GetSize() < 68)
	{
		this->match_amount_info.SetSize((float)this->match_amount_info.GetSize() + 4);
		this->match_points_info.SetSize((float)this->match_points_info.GetSize() + 4);
	}
}

void InterfaceManager::UnlockTreasure(int id)
{
	this->unlocked_treasures[id] = true;
}

void InterfaceManager::ResetSlidingConditions()
{
	is_sliding_out = false;
	textboard_to_show = "null";
	textboard_to_hide = "null";
	combos_board_state = "off";
	movement_board_state = "off";
	treasure_board_state = "off";

	combos_button_state = "off";			
	movement_button_state = "off";
	treasure_button_state = "off";

	treasure_board.SetPosition((float)0 - combos_board.GetSize().x - 20, (float)(wptr->GetHeight() * 80) / 1080);
	treasuresboard_x = treasure_board.GetPosition().x;

	combos_board.SetPosition((float)0 - combos_board.GetSize().x - 20, (float)(wptr->GetHeight() * 80) / 1080);
	combosboard_x = combos_board.GetPosition().x;

	movement_board.SetPosition((float)0 - combos_board.GetSize().x - 20, (float)(wptr->GetHeight() * 80) / 1080);
	movesboard_x = movement_board.GetPosition().x;


}

std::string InterfaceManager::ButtonInput(int game_state, int x, int y)
{
	std::string response;

	if (game_state == 0)
	{

		if (x > play_button_normal.GetPosition().x && x < play_button_normal.GetPosition().x + play_button_normal.GetSize().x
			&& y > play_button_normal.GetPosition().y && y < play_button_normal.GetPosition().y + play_button_normal.GetSize().y)
			response = "Play";

		if (x > tutorial_button_normal.GetPosition().x && x < tutorial_button_normal.GetPosition().x + tutorial_button_normal.GetSize().x
			&& y > tutorial_button_normal.GetPosition().y && y < tutorial_button_normal.GetPosition().y + tutorial_button_normal.GetSize().y)
			response = "Tutorial";
		
		
		if (x > puzzle_button_normal.GetPosition().x && x < puzzle_button_normal.GetPosition().x + puzzle_button_normal.GetSize().x
			&& y > puzzle_button_normal.GetPosition().y && y < puzzle_button_normal.GetPosition().y + puzzle_button_normal.GetSize().y)
			response = "Puzzle";
		

		if (x > scores_button_normal.GetPosition().x && x < scores_button_normal.GetPosition().x + scores_button_normal.GetSize().x
			&& y > scores_button_normal.GetPosition().y && y < scores_button_normal.GetPosition().y + scores_button_normal.GetSize().y)
			response = "Scores";

		if (x > credits_button_normal.GetPosition().x && x < credits_button_normal.GetPosition().x + credits_button_normal.GetSize().x
			&& y > credits_button_normal.GetPosition().y && y < credits_button_normal.GetPosition().y + credits_button_normal.GetSize().y)
			response = "Credits";

		if (x > quit_button_normal.GetPosition().x && x < quit_button_normal.GetPosition().x + quit_button_normal.GetSize().x
			&& y > quit_button_normal.GetPosition().y && y < quit_button_normal.GetPosition().y + quit_button_normal.GetSize().y)
			response = "Quit";
		
		return response;
	}
	else if (game_state == 30)
	{
		if (x > new_button_normal.GetPosition().x && x < new_button_normal.GetPosition().x + new_button_normal.GetSize().x
			&& y > new_button_normal.GetPosition().y && y < new_button_normal.GetPosition().y + new_button_normal.GetSize().y)
			response = "New";

		if (x > resume_button_normal.GetPosition().x && x < resume_button_normal.GetPosition().x + resume_button_normal.GetSize().x
			&& y > resume_button_normal.GetPosition().y && y < resume_button_normal.GetPosition().y + resume_button_normal.GetSize().y)
			response = "Resume";
		
		
		if (x > back_button_normal.GetPosition().x && x < back_button_normal.GetPosition().x + back_button_normal.GetSize().x
			&& y > back_button_normal.GetPosition().y && y < back_button_normal.GetPosition().y + back_button_normal.GetSize().y)
			response = "Back";

		return response;
	}
	else if (game_state == 1)
	{
		if (x > combos_button_off.GetPosition().x && x < combos_button_off.GetPosition().x + combos_button_off.GetSize().x
			&& y > combos_button_off.GetPosition().y && y < combos_button_off.GetPosition().y + combos_button_off.GetSize().y)
		{
			if (combos_button_state == "focused")
			{
				//ReloadBoard(1);
				//std::cout << "Combos button was clicked\n\n";

				if (movement_board_state == "on")
				{
					//std::cout << "Movement textboard is on\n\n";
					SetupTextboardTransition("combos", "moves");
				}
				else if (treasure_board_state == "on")
				{
					//std::cout << "Treasure textboard is on\n\n";
					SetupTextboardTransition("combos", "treasure");
				}
				else if (combos_board_state == "off" && movement_board_state == "off" && treasure_board_state == "off")
				{
					//std::cout << "All textboards are off\n\n";
					SetupTextboardTransition("combos", "null");
				}

				//combos_board_state = "on";
				combos_button_state = "on";
				
				//movement_board_state = "off";
				movement_button_state = "off";
				
				//treasure_board_state = "off";
				treasure_button_state = "off";
			}
			else if (combos_button_state == "on")
			{
				combos_button_state = "off";
				//combos_board_state = "off";

				SetupTextboardTransition("null", "combos");
			}
		}

		else if (x > movement_button_off.GetPosition().x && x < movement_button_off.GetPosition().x + movement_button_off.GetSize().x
			&& y > movement_button_off.GetPosition().y && y < movement_button_off.GetPosition().y + movement_button_off.GetSize().y)
		{
			if (movement_button_state == "focused")
			{
				//ReloadBoard(0);
				//std::cout << "Movement button was clicked\n\n";

				if (combos_board_state == "on")
				{
					//std::cout << "Combos textboard is on\n\n";
					SetupTextboardTransition("moves", "combos");
				}
				else if (treasure_board_state == "on")
				{
					//std::cout << "Treasure textboard is on\n\n";
					SetupTextboardTransition("moves", "treasure");
				}
				else if (movement_board_state == "off" && combos_board_state == "off" && treasure_board_state == "off")
				{
					//std::cout << "All textboards are off\n\n";
					SetupTextboardTransition("moves", "null");
				}

				movement_button_state = "on";
				//movement_board_state = "on";
				
				//combos_board_state = "off";
				combos_button_state = "off";
				
				//treasure_board_state = "off";
				treasure_button_state = "off";
			}
			else if (movement_button_state == "on")
			{
				movement_button_state = "off";
				//movement_board_state = "off";

				SetupTextboardTransition("null", "moves");
			}
		}
		
		else if (x > treasure_button_off.GetPosition().x && x < treasure_button_off.GetPosition().x + treasure_button_off.GetSize().x
			&& y > treasure_button_off.GetPosition().y && y < treasure_button_off.GetPosition().y + treasure_button_off.GetSize().y)
		{
			if (treasure_button_state == "focused")
			{
				//ReloadBoard(2);

				if (combos_board_state == "on")
				{
					SetupTextboardTransition("treasure", "combos");
				}
				else if (movement_board_state == "on")
				{
					SetupTextboardTransition("treasure", "moves");
				}
				else if (treasure_board_state == "off" && combos_board_state == "off" && movement_board_state == "off")
				{
					SetupTextboardTransition("treasure", "null");
				}

				treasure_button_state = "on";
				//treasure_board_state = "on";

				movement_button_state = "off";
				//movement_board_state = "off";
				
				//combos_board_state = "off";
				combos_button_state = "off";
			}
			else if (treasure_button_state == "on")
			{
				treasure_button_state = "off";
				//treasure_board_state = "off";
				SetupTextboardTransition("null", "treasure");
			}
		}
		return "Null";
	}
}

void InterfaceManager::ResetTreasures()
{
	for (int i = 0; i < 4; i++)
	{
		this->unlocked_treasures[i] = false;
	}
	this->SetupTreasureImagesForNewLevel();
}

void InterfaceManager::LoadSavedTreasures(int t1, int t2, int t3, int t4)
{
		if (t1 == 1)
			this->unlocked_treasures[0] = true;
		if (t2 == 1)
			this->unlocked_treasures[1] = true;
		if (t3 == 1)
			this->unlocked_treasures[2] = true;
		if (t4 == 1)
			this->unlocked_treasures[3] = true;
}

void InterfaceManager::ReloadBoard(int brd)
{
	if (brd == 2)
	{
		treasure_board.SetImage(resource_manager->OnDemandLoadForBoards(2));
		treasure_board.Resize((float)(483 * wptr->GetWidth())/1920, (float)(809 * wptr->GetHeight())/1080);
		treasure_board.SetPosition((float)(wptr->GetWidth() * 44) / 1920, (float)(wptr->GetHeight() * 80) / 1080);
	}
	else if (brd == 0)
	{
		movement_board.SetImage(resource_manager->OnDemandLoadForBoards(0));
		movement_board.Resize((float)(483 * wptr->GetWidth())/1920, (float)(809 * wptr->GetHeight())/1080);
		movement_board.SetPosition((float)(wptr->GetWidth() * 44) / 1920, (float)(wptr->GetHeight() * 80) / 1080);
	}
	else if (brd == 1)
	{
		combos_board.SetImage(resource_manager->OnDemandLoadForBoards(1));
		combos_board.Resize((float)(483 * wptr->GetWidth())/1920, (float)(809 * wptr->GetHeight())/1080);
		combos_board.SetPosition((float)(wptr->GetWidth() * 44) / 1920, (float)(wptr->GetHeight() * 80) / 1080);
	}
}

void InterfaceManager::HandleGameButtons(int game_state)
{
	int x = wptr->GetInput().GetMouseX();
	int y = wptr->GetInput().GetMouseY();
	
	if (combos_button_state == "off")
		this->wptr->Draw(combos_button_off);
	else if (combos_button_state == "on")
		this->wptr->Draw(combos_button_on);
	else if (combos_button_state == "focused")
		this->wptr->Draw(combos_button_focus);
	
	if (movement_button_state == "off")
		this->wptr->Draw(movement_button_off);
	else if (movement_button_state == "on")
		this->wptr->Draw(movement_button_on);
	else if (movement_button_state == "focused")
		this->wptr->Draw(movement_button_focus);

	if (treasure_button_state == "off")
		this->wptr->Draw(treasure_button_off);
	else if (treasure_button_state == "on")
		this->wptr->Draw(treasure_button_on);
	else if (treasure_button_state == "focused")
		this->wptr->Draw(treasure_button_focus);

	if (game_state == 1) //show textboards only when the player has control over the board
	{
		if (combos_board_state == "on")
			this->wptr->Draw(combos_board);
		if (movement_board_state == "on")
			this->wptr->Draw(movement_board);
		if (treasure_board_state == "on")
		{
			this->wptr->Draw(treasure_board);
			if (!is_sliding_out && treasure_board.GetPosition().x >= moving_textboard_target_x)
			{
				for (int i = 0; i < 4; i++)
				{
					if (this->unlocked_treasures[i])
						this->wptr->Draw(this->treasure[i]);
					else
						this->wptr->Draw(this->treasure_shadow[i]);

				}
			}
		}
	}

	if (x > combos_button_off.GetPosition().x && x < combos_button_off.GetPosition().x + combos_button_off.GetSize().x
		&& y > combos_button_off.GetPosition().y && y < combos_button_off.GetPosition().y + combos_button_off.GetSize().y)
	{
		if (combos_button_state == "off")
			combos_button_state = "focused";
	}
	else
	{
		if (combos_button_state == "focused")
		combos_button_state = "off";
	}

	if (x > movement_button_off.GetPosition().x && x < movement_button_off.GetPosition().x + movement_button_off.GetSize().x
		&& y > movement_button_off.GetPosition().y && y < movement_button_off.GetPosition().y + movement_button_off.GetSize().y)
	{
		if (movement_button_state == "off")
			movement_button_state = "focused";
	}
	else
	{
		if (movement_button_state == "focused")
		movement_button_state = "off";
	}

	if (x > treasure_button_off.GetPosition().x && x < treasure_button_off.GetPosition().x + treasure_button_off.GetSize().x
		&& y > treasure_button_off.GetPosition().y && y < treasure_button_off.GetPosition().y + treasure_button_off.GetSize().y)
	{
		if (treasure_button_state == "off")
			treasure_button_state = "focused";
	}
	else
	{
		if (treasure_button_state == "focused")
		treasure_button_state = "off";
	}

	this->PerformTextboardSlide();
}

void InterfaceManager::HandleMainMenuButtons(int screenId)
{
	int x = wptr->GetInput().GetMouseX();
	int y = wptr->GetInput().GetMouseY();
	
	if (screenId == 0) // Main Menu
	{
		if (x > play_button_normal.GetPosition().x && x < play_button_normal.GetPosition().x + play_button_normal.GetSize().x
			&& y > play_button_normal.GetPosition().y && y < play_button_normal.GetPosition().y + play_button_normal.GetSize().y)
			wptr->Draw(play_button_focus);
		else
			wptr->Draw(play_button_normal);

		if (x > tutorial_button_normal.GetPosition().x && x < tutorial_button_normal.GetPosition().x + tutorial_button_normal.GetSize().x
			&& y > tutorial_button_normal.GetPosition().y && y < tutorial_button_normal.GetPosition().y + tutorial_button_normal.GetSize().y)
			wptr->Draw(tutorial_button_focus);
		else
			wptr->Draw(tutorial_button_normal);
		
		
		if (x > puzzle_button_normal.GetPosition().x && x < puzzle_button_normal.GetPosition().x + puzzle_button_normal.GetSize().x
			&& y > puzzle_button_normal.GetPosition().y && y < puzzle_button_normal.GetPosition().y + puzzle_button_normal.GetSize().y)
			wptr->Draw(puzzle_button_focus);
		else
			wptr->Draw(puzzle_button_normal);
		

		if (x > scores_button_normal.GetPosition().x && x < scores_button_normal.GetPosition().x + scores_button_normal.GetSize().x
			&& y > scores_button_normal.GetPosition().y && y < scores_button_normal.GetPosition().y + scores_button_normal.GetSize().y)
			wptr->Draw(scores_button_focus);
		else
			wptr->Draw(scores_button_normal);

		if (x > credits_button_normal.GetPosition().x && x < credits_button_normal.GetPosition().x + credits_button_normal.GetSize().x
			&& y > credits_button_normal.GetPosition().y && y < credits_button_normal.GetPosition().y + credits_button_normal.GetSize().y)
			wptr->Draw(credits_button_focus);
		else
			wptr->Draw(credits_button_normal);

		if (x > quit_button_normal.GetPosition().x && x < quit_button_normal.GetPosition().x + quit_button_normal.GetSize().x
			&& y > quit_button_normal.GetPosition().y && y < quit_button_normal.GetPosition().y + quit_button_normal.GetSize().y)
			wptr->Draw(quit_button_focus);
		else
			wptr->Draw(quit_button_normal);
	}
	else if (screenId == 1) //New or Resume selection submenu
	{
		if (x > new_button_normal.GetPosition().x && x < new_button_normal.GetPosition().x + new_button_normal.GetSize().x
			&& y > new_button_normal.GetPosition().y && y < new_button_normal.GetPosition().y + new_button_normal.GetSize().y)
			wptr->Draw(new_button_focus);
		else
			wptr->Draw(new_button_normal);

		if (x > resume_button_normal.GetPosition().x && x < resume_button_normal.GetPosition().x + resume_button_normal.GetSize().x
			&& y > resume_button_normal.GetPosition().y && y < resume_button_normal.GetPosition().y + resume_button_normal.GetSize().y)
			wptr->Draw(resume_button_focus);
		else
			wptr->Draw(resume_button_normal);

		if (x > back_button_normal.GetPosition().x && x < back_button_normal.GetPosition().x + back_button_normal.GetSize().x
			&& y > back_button_normal.GetPosition().y && y < back_button_normal.GetPosition().y + back_button_normal.GetSize().y)
			wptr->Draw(back_button_focus);
		else
			wptr->Draw(back_button_normal);
	}
}

void InterfaceManager::SetupScoreUpdate(int tScore, int mode, bool remainder)
{
	if (mode == 0) //Add turn points
	{
		targetScore = tScore + currentScore;
		isIncreasingScore = true;
		isDecreasingScore = false;
		isAnimating = true;
		positive_score_animation_frame = 0;
		positive_score_animation_timer.Reset();
	}
	else if (mode == 1) //Decrease demand
	{
		targetScore = currentScore - 100;
		isIncreasingScore = false;
		isDecreasingScore = false;
		isAnimating = true;
		demand_animation_timer.Reset();
		demand_animation_frame = 0;
		hasEndTimerStarted = false;
	}
	else if (mode == 2)
	{
		isIncreasingScore = false;
		isDecreasingScore = true;
		targetScore = 0;
		isAnimating = true;
		positive_score_animation_frame = 0;
		positive_score_animation_timer.Reset();
		hasPositiveRemainder = remainder;	
	}
	scoreUpdateTimer.Reset();
}

void InterfaceManager::UpdateScore(int mode)
{
	if (mode == 0) //Add turn points
	{
		if (scoreUpdateTimer.GetElapsedTime() >= 0.0001f && isIncreasingScore)
		{
			currentScore++;
			std::stringstream out;
			out << currentScore;
			this->turn_points_info.SetText(out.str());

			if (currentScore >= targetScore)
			{
				isIncreasingScore = false;
				return;
			}
			else
			{
				scoreUpdateTimer.Reset();
			}

			currentScore++;
			std::stringstream out2;
			out2 << currentScore;
			this->turn_points_info.SetText(out2.str());

			if (currentScore >= targetScore)
			{
				isIncreasingScore = false;
				return;
			}
			else
			{
				scoreUpdateTimer.Reset();
			}
		}

		if (isAnimating)
		{
			if (positive_score_animation_timer.GetElapsedTime() >= 0.04f)
			{
				if (positive_score_animation_frame < 24)
				{
					positive_score_animation_frame++;
					positive_score_animation_timer.Reset();
				}
				else
				{
					isAnimating = false;
				}
			}
		}
	}
	else if (mode == 1) //Decrease demand
	{
		if (scoreUpdateTimer.GetElapsedTime() >= 0.01f && isDecreasingScore)
		{
			currentScore--;
			std::stringstream out;
			out << currentScore;
			this->turn_points_info.SetText(out.str());

			if (currentScore <= targetScore)
			{
				isDecreasingScore = false;
				return;
			}
			else
			{
				scoreUpdateTimer.Reset();
			}
		}

		if (isAnimating)
		{
			if (demand_animation_timer.GetElapsedTime() >= 0.04f)
			{
				if (demand_animation_frame < 22)
				{
					demand_animation_frame++;
					demand_animation_timer.Reset();
					
					if (demand_animation_frame >= 10 && isDecreasingScore == false)
						isDecreasingScore = true;
				}
				else
				{
					isAnimating = false;
				}
			}
		}
	}
	else if (mode == 2) //Total calculation
	{
		if (scoreUpdateTimer.GetElapsedTime() >= 0.01f && isDecreasingScore)
		{
			if (hasPositiveRemainder)
			{
				currentScore--;
				std::stringstream out;
				out << currentScore;
				this->turn_points_info.SetText(out.str());

				currentTotalScore++;
				std::stringstream out2;
				out2 << currentTotalScore;
				this->total_points_info.SetText(out2.str());

				if (currentScore <= targetScore)
				{
					isDecreasingScore = false;
					return;
				}
				else
				{
					scoreUpdateTimer.Reset();
				}

				currentScore--;
				std::stringstream out3;
				out3 << currentScore;
				this->turn_points_info.SetText(out3.str());

				currentTotalScore++;
				std::stringstream out4;
				out4 << currentTotalScore;
				this->total_points_info.SetText(out4.str());

				if (currentScore <= targetScore)
				{
					isDecreasingScore = false;
					return;
				}
				else
				{
					scoreUpdateTimer.Reset();
				}
			}
			else
			{
				if(currentScore != 0)
				{
					currentScore++;
					std::stringstream out5;
					out5 << currentScore;
					this->turn_points_info.SetText(out5.str());

					currentTotalScore--;
					std::stringstream out6;
					out6 << currentTotalScore;
					this->total_points_info.SetText(out6.str());
				}
				if (currentScore >= targetScore)
				{
					isDecreasingScore = false;
					return;
				}
				else
				{
					scoreUpdateTimer.Reset();
				}
			}
		}

		if (isAnimating)
		{
			if (hasPositiveRemainder)
			{
				if (positive_score_animation_timer.GetElapsedTime() >= 0.04f)
				{
					if (positive_score_animation_frame < 24)
					{
						positive_score_animation_frame++;
						positive_score_animation_timer.Reset();
					}
					else
					{
						isAnimating = false;
					}
				}
			}
			else
			{
				if (positive_score_animation_timer.GetElapsedTime() >= 0.04f)
				{
					if (positive_score_animation_frame < 20)
					{
						positive_score_animation_frame++;
						positive_score_animation_timer.Reset();
					}
					else
					{
						isAnimating = false;
					}
				}
			}
		}
	}
}
