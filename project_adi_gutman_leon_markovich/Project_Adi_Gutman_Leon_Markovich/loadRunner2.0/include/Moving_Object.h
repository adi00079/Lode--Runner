#include "Game_Object.h"
#include <cstdlib>
#include <iostream>
#pragma once
class Moving_Object : public Game_Object {
	//--------------public--------functions-----------------------//
protected:
	using Game_Object::Game_Object;
	//using Game_Object::effect;
	//virtual void move(sf::Keyboard::Key key) {};
	bool check_movment(sf::RectangleShape& cur_loc, std::vector<Game_Object*>m_All_Objects[],
		Game_Object& last_Loc);
	void move_Object(sf::Vector2f& DIrection, sf::Time delta_time, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS]);
	bool check_ladder(sf::RectangleShape& cur_Loc, std::vector<Game_Object*>m_All_Objects[],
		Game_Object& last_Loc);
	char What_In_Loc(sf::RectangleShape& temp, std::vector<Game_Object*>m_All_Objects[]);
	bool check_pole(std::vector<Game_Object*>m_All_Objects[],
		Game_Object& last_Loc, sf::RectangleShape& cur_Loc);
	bool check_space(std::vector<Game_Object*>m_All_Objects[],
		Game_Object& last_Loc, sf::RectangleShape& cur_Loc);
	void move_to_center_ladder(std::vector<Game_Object*>& m_All_Objects);
	void change__Curr_Texture(std::vector<Game_Object*>m_All_Objects[], sf::Vector2f& Direction);
	void move_to_center_pole(std::vector<Game_Object*>& m_All_Objects);
	void handleCollision_moving(Game_Object& me, std::vector<Game_Object*>m_All_Objects[]);
	void handle_dig
	(Game_Object& me, std::vector<Game_Object*>& m_All_Objects, sf::Vector2f& Direction, sf::Time delta_time);
	void handleCollision(Wall& enemy)override {};
	bool in_Gg(sf::RectangleShape& next_Loc, std::vector<Game_Object*>m_All_Objects) const;
	const static sf::Clock& get_Clock() { return m_clock; }
public:
	bool is_Out_Of_Bounds();//checking if player is out of bounds

	void on_Floor(std::vector<Game_Object*>m_All_Objects[]);

protected:
	bool m_direction = right;
	int m_dig = undig;
	static sf::Clock m_clock;
	bool m_Out_Of_Bounds = false;
};