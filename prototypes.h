#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

enum GameState {
	MENU,
	PLAY,
	HOW_TO_PLAY,
	SETTINGS,
	CREDITS,
	QUIT
};

extern GameState game_state;
//play state prototypes

struct PlayStateButtons {
	RectangleShape _continue;
	RectangleShape settings;
	RectangleShape quit;

};

PlayStateButtons play_state_buttons();

//menu prototypes
void menu(RenderWindow& window, const Event& event, Font &font);

struct MenuButtons {
	RectangleShape play;
	RectangleShape settings;
	RectangleShape credits;
	RectangleShape quit;

};

struct SettingsButtons {
	RectangleShape on;
	RectangleShape off;
	RectangleShape fps30;
	RectangleShape fps60;

};

struct QuitButtons {
	RectangleShape deny;
	RectangleShape confirm;

};
//score display
struct Score_Hitbox {
	RectangleShape score_body;
	int score = 0;
};
struct Score_Display {
	Text score_text;
};



MenuButtons menu_buttons();
SettingsButtons settings_buttons();
QuitButtons quit_buttons();

//main menu prototypes
void draw_menu(RenderWindow& window, Font &font, Sprite &sprite, MenuButtons& buttons);
void mouseMenu(RenderWindow& window, Font& font, MenuButtons& buttons, Text& play_text, Text& settings_text, Text& credits_text, Text& quit_text, const Event& event);

//settings prototypes
void draw_settings(RenderWindow& window, Font& font, Sprite& menu_settings, SettingsButtons& s_buttons);
void mouseSettings(RenderWindow& window, Font& font, SettingsButtons& s_buttons, Text& on_text, Text& off_text, Text& fps30_text, Text& fps60_text, const Event& event, int &volume_setting, int &frame_setting);

//credits prototypes
void draw_credits(RenderWindow& window, Font& font, Sprite& menu_credits);

//back | closing prototypes
void closing(RenderWindow &window, const Event &event);
void draw_closing(RenderWindow& window, Font& font, Sprite& menu_quit, QuitButtons& q_buttons);
void mouseMenu(RenderWindow& window, Font& font, QuitButtons& q_buttons, Text& deny_text, Text& confirm_text, const Event& event);

//PLAYING PROTOTYPES
//players
struct Player {
	RectangleShape body;
};

Player create_player(Vector2f position, Color color);


//player control
void control(Player& player, Keyboard::Scan up, Keyboard::Scan down, float deltaTime);

//ball
struct Ball {
	CircleShape body;
};

Ball create_ball();
void ball_movement(Ball& ball, float deltaTime, Player& player_1, Player& player_2, Score_Hitbox &hb1, Score_Hitbox &hb2);
Score_Hitbox create_score_hitbox(Vector2f position);
Score_Display create_score_display(Font& font, Vector2f position, Ball& ball, Score_Hitbox& score_hitbox);
void update_score(Score_Display& score_display, Ball& ball, Score_Hitbox& score_hitbox);