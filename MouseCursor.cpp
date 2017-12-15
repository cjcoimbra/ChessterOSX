#include "StdAfx.h"
#include "MouseCursor.h"

MouseCursor::MouseCursor(void)
{
}

void MouseCursor::Init(sf::RenderWindow * w, ResourceManager * r)
{
	this->wnd_ptr = w;
	this->rm = r;

	custom_cursor.SetImage(this->rm->GetImageResource(60));
	custom_cursor.Resize(72,72);
	custom_cursor.SetPosition((float)this->wnd_ptr->GetInput().GetMouseX() - 16,(float)this->wnd_ptr->GetInput().GetMouseY() - 16);
}

void MouseCursor::Update()
{
	custom_cursor.SetPosition((float)this->wnd_ptr->GetInput().GetMouseX() - 16,(float)this->wnd_ptr->GetInput().GetMouseY() - 16);
	this->wnd_ptr->Draw(custom_cursor);
}

MouseCursor::~MouseCursor(void)
{
}
