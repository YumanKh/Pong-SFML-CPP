#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "prototypes.h"
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;

//default game state
GameState game_state = MENU;

int main() {
    //rand initialisation
    srand((unsigned int)time(NULL));

    //game clock
    Clock clock;

    //button states
    int volume_setting = 0;
    int fps_setting = 0;

    //loading font
    Font font;
    font.openFromFile("BlackGameFont.ttf");
    if (!font.openFromFile("BlackGameFont.ttf")) cout << "Absent File." << endl;

    //Button texts
    //Menu
    Text play_text(font, "PLAY", 35);
    play_text.setFillColor(Color(150, 150, 150));
    play_text.setPosition({ 30, 150 });

    Text settings_text(font, "SETTINGS", 35);
    settings_text.setFillColor(Color(150, 150, 150));
    settings_text.setPosition({ 30, 233 });

    Text credits_text(font, "CREDITS", 35);
    credits_text.setFillColor(Color(150, 150, 150));
    credits_text.setPosition({ 30, 316 });

    Text quit_text(font, "QUIT", 35);
    quit_text.setFillColor(Color(150, 150, 150));
    quit_text.setPosition({ 30, 400 });

    //Menu Settings
    Text volume(font, "VOLUME", 45);
    volume.setFillColor(Color::White);
    volume.setPosition({ 415, 150 });

    Text on(font, "ON", 30);
    on.setFillColor(Color(150, 150, 150));
    on.setPosition({ 385, 225 });

    Text off(font, "OFF", 30);
    off.setFillColor(Color(150, 150, 150));
    off.setPosition({ 560, 225 });

    Text frame_rate(font, "FRAME RATE", 45);
    frame_rate.setFillColor(Color::White);
    frame_rate.setPosition({ 365, 300 });

    Text fps30(font, "30", 30);;
    fps30.setFillColor(Color(150, 150, 150));
    fps30.setPosition({ 385, 375 });

    Text fps60(font, "60", 30);;
    fps60.setFillColor(Color(150, 150, 150));
    fps60.setPosition({ 560, 375 });

    //Menu Quit
    Text quit_deny(font, "DENY", 35);
    quit_deny.setFillColor(Color(150, 150, 150));
    quit_deny.setPosition({ 460, 215 });

    Text quit_confirm(font, "CONFIRM", 35);
    quit_confirm.setFillColor(Color(150, 150, 150));
    quit_confirm.setPosition({ 425, 360 });

    //loading menu textures 
    Texture menu_texture;
    menu_texture.loadFromFile("MenuSprite.png");
    Sprite menu_sprite(menu_texture);

    Texture middle_texture;
    middle_texture.loadFromFile("MenuQuitSprite.png");
    Sprite menu_middle(middle_texture);

    Texture wallpaper;
    wallpaper.loadFromFile("MenuWallpaper.jpg");
    if (!wallpaper.loadFromFile("MenuWallpaper2.jpg")) cout << "Absent File." << endl;
    Sprite menu_wallpaper(wallpaper);

    float scale_x = 1000.0f / wallpaper.getSize().x;
    float scale_y = 600.0f / wallpaper.getSize().y;

    menu_wallpaper.setScale({ scale_x, scale_y });
    menu_wallpaper.setPosition({ 0, 0 });
    
    //Rendering Window
    RenderWindow window(VideoMode({ 1000, 600 }), "YuKman's Pong");
    window.setFramerateLimit(60);
       
    //Menu buttons
    MenuButtons buttons = menu_buttons();
    SettingsButtons s_buttons = settings_buttons();
    QuitButtons q_buttons = quit_buttons();

    //Players
    Player player_1 = create_player({ 50.f, 260.f }, Color::Red);
    Player player_2 = create_player({ 935.f, 260.f }, Color::Blue);

    //ball
    Ball ball = create_ball();

	//score hitboxes
	Score_Hitbox player_1_score = create_score_hitbox({ 0.f, 0.f });
	Score_Hitbox player_2_score = create_score_hitbox({ 990.f, 0.f });

    //score display
	Score_Display player_1_score_display = create_score_display(font, { 400.f, 20.f }, ball, player_1_score);
	Score_Display player_2_score_display = create_score_display(font, { 600.f, 20.f }, ball, player_2_score);


    while (window.isOpen()) {

        float deltaTime = clock.restart().asSeconds();


        if (game_state == PLAY) {
            control(player_1, Keyboard::Scan::W, Keyboard::Scan::S, deltaTime); 
            control(player_2, Keyboard::Scan::Up, Keyboard::Scan::Down, deltaTime);
            ball_movement(ball, deltaTime, player_1, player_2, player_1_score, player_2_score);
        }

        while (const optional<Event> event = window.pollEvent()) {
            closing(window, *event);
            if (game_state == MENU) mouseMenu(window, font, buttons, play_text, settings_text, credits_text, quit_text, *event);
            if (game_state == SETTINGS) mouseSettings(window, font, s_buttons, on, off, fps30, fps60, *event, volume_setting, fps_setting);
            if (game_state == QUIT) mouseMenu(window, font, q_buttons, quit_deny, quit_confirm, *event);
            
            
        }

        window.clear(Color::White);
        if (game_state != PLAY) window.draw(menu_wallpaper);
        
        if (game_state == PLAY) {
            window.draw(player_1.body);
            window.draw(player_2.body);
            window.draw(ball.body);
			window.draw(player_1_score.score_body);
			window.draw(player_2_score.score_body);
            update_score(player_1_score_display, ball, player_1_score);
            update_score(player_2_score_display, ball, player_2_score);
            window.draw(player_1_score_display.score_text);
            window.draw(player_2_score_display.score_text);

        }
        if (game_state == MENU) {
            draw_menu(window, font, menu_sprite, buttons);
            window.draw(play_text);
            window.draw(settings_text);
            window.draw(credits_text);
            window.draw(quit_text);
        }

        if (game_state == SETTINGS) {
            draw_settings(window, font, menu_middle, s_buttons);
            window.draw(volume);
            window.draw(on);
            window.draw(off);
            window.draw(frame_rate);
            window.draw(fps30);
            window.draw(fps60);
        }

        if (game_state == CREDITS) {
            draw_credits(window, font, menu_middle);
        }

        if (game_state == QUIT) {
            draw_closing(window, font, menu_middle, q_buttons);
            window.draw(quit_confirm);
            window.draw(quit_deny);
        }
        window.display();
    }
    return 0;
}