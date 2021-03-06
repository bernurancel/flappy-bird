#include "stdafx.h"
#include<process.h>
#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include<allegro5\allegro_font.h>
#include<allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>

int main()
{
jump:
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	ALLEGRO_DISPLAY *display = al_create_display(1000, 1000);
	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60);
	ALLEGRO_EVENT event;
	ALLEGRO_FONT *font = al_load_font("321impact.ttf", 50, 0);
	ALLEGRO_FONT *font1 = al_load_font("321impact.ttf", 80, 0);
	ALLEGRO_BITMAP *background = al_load_bitmap("background.png");
	ALLEGRO_BITMAP *bird = al_load_bitmap("bird.jpg");
	al_start_timer(timer);
	al_install_keyboard();
	al_install_mouse();
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));

	float a = 200, b = 20;
	int score = 0, tutucu = 0, tutucu1 = 0;
	int m = 800, n = 300, k = 1400, d = 2000;
	while (tutucu1 == 0)
	{
		al_clear_to_color(al_map_rgb(135, 206, 250));
		al_draw_bitmap(background, 0, 0, 0);
		al_draw_bitmap(bird, a, b, 0);

		al_draw_filled_rectangle(m, 0, m + 50, n, al_map_rgb(193, 255, 193));
		al_draw_filled_rectangle(m, 1000 - n, m + 50, 1000, al_map_rgb(193, 255, 193));

		al_draw_filled_rectangle(k, 0, k + 50, n - 100, al_map_rgb(193, 255, 193));
		al_draw_filled_rectangle(k, 750 - n, k + 50, 1000, al_map_rgb(193, 255, 193));

		al_draw_filled_rectangle(d, 0, d + 50, n, al_map_rgb(193, 255, 193));
		al_draw_filled_rectangle(d, 1000 - n, d + 50, 1000, al_map_rgb(193, 255, 193));
		al_flip_display();
		al_wait_for_event(queue, &event);
		if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
			b = b - 30;
		}
		if (a + 60 > m && a + 30 < m + 50 && b + 60>0 && b - 30<n) {
			tutucu = 1;
		}
		else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
			tutucu1 = 1;
		}
		if (a + 60 > k && a + 30 < k + 50 && b + 60>0 && b - 30<n - 100) {
			tutucu = 1;
		}
		if (a + 60 > d && a + 30 < d + 50 && b + 60>0 && b - 30<n) {
			tutucu = 1;
		}
		if (a + 60 > m && a < m + 50 && b + 60>1000 - n && b + 30<1000) {
			tutucu = 1;
		}
		if (a + 60 > k && a  < k + 50 && b + 60>750 - n && b + 30<1000) {
			tutucu = 1;
		}
		if (a + 60 > d && a < d + 50 && b + 60>1000 - n && b + 30<1000) {
			tutucu = 1;
		}
		if (b>1000 || b<-10) {
			tutucu = 1;
		}

		if (m < 1) {
			m = d + 600;
		}
		if (k < 1) {
			k = m + 600;
		}
		if (d < 1) {
			d = k + 600;
		}
		if (m < 170 && m>167) {
			score += 1;

		}
		if (k < 170 && k>167) {
			score += 1;
		}
		if (d < 170 && d>167) {
			score += 1;
		}

		k = k - 2;
		d = d - 2;
		m = m - 2;
		b = b + 3;
		while (tutucu == 1)
		{
			al_draw_filled_rectangle(300, 300, 800, 800, al_map_rgb(180, 180, 180));
			al_draw_multiline_textf(font1, al_map_rgb(255, 255, 65), 350, 400, 1000, 1000, 0, "GAME OVER");
			al_draw_multiline_textf(font, al_map_rgb(255, 255, 0), 500, 550, 1000, 1000, 0, "SCORE = %d", score);
			al_draw_filled_rectangle(420, 680, 700, 750, al_map_rgb(255, 255, 255));
			al_draw_multiline_textf(font, al_map_rgb(255, 255, 65), 430, 700, 1000, 1000, 0, "PLAY AGAIN");
			al_flip_display();
			al_wait_for_event(queue, &event);
			if (event.mouse.x > 420 && event.mouse.x < 700 && event.mouse.y > 680 && event.mouse.y < 750 && event.mouse.button == 1) {
				goto jump;
				break;
			}
		}

		al_flip_display();


	}

	system("pause");
	return 0;
}   