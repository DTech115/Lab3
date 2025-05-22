#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

int main()
{
	ALLEGRO_DISPLAY* Screen = NULL;
	if (!al_init())
	{
		al_show_native_message_box(NULL, "Error!", "Allegro has failed to initialize.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
			return -1;
	}
	int width = 800, height = 600;
	Screen = al_create_display(width, height);
	if (Screen == NULL)
	{
		al_show_native_message_box(Screen, "Error!", "Failed to create the display.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
			return -1;
	}

	bool draw = false;
	bool byebye = false;

	int xCord = width / 2;
	int yCord = height / 2;

	ALLEGRO_EVENT_QUEUE* eventQueue = NULL;

	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	//font loading here
	ALLEGRO_FONT* font24 = al_load_font("ComicSans.ttf", 24, 0);
	eventQueue = al_create_event_queue();

	al_register_event_source(eventQueue, al_get_display_event_source(Screen));
	al_clear_to_color(al_map_rgb(0, 0, 0));

	//mouse installation & such
	if (!al_install_mouse()) {
		al_show_native_message_box(Screen, "Error!", "Failed to initialize the mouse!\n", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	al_register_event_source(eventQueue, al_get_mouse_event_source());

	//creates a lil UPA in the center
	al_draw_filled_circle(xCord, yCord, 40, al_map_rgb(150, 150, 150)); //body
	al_draw_filled_circle(xCord, yCord - 5, 2, al_map_rgb(0, 0, 0)); //nose
	al_draw_filled_circle(xCord + 25, yCord - 5, 2, al_map_rgb(0, 0, 0)); //right eye
	al_draw_filled_circle(xCord - 25, yCord - 5, 2, al_map_rgb(0, 0, 0)); //left eye
	al_draw_line(xCord - 40, yCord + 15, xCord + 40, yCord + 15, al_map_rgb(0, 0, 0), 3); //line
	al_draw_line(xCord, yCord + 2, xCord - 10, yCord + 10, al_map_rgb(0, 0, 0), 2); //mouth
	al_draw_line(xCord - 10, yCord + 10, xCord - 20, yCord + 2, al_map_rgb(0, 0, 0), 2);
	al_draw_line(xCord, yCord + 2, xCord + 10, yCord + 10, al_map_rgb(0, 0, 0), 2);
	al_draw_line(xCord + 10, yCord + 10, xCord + 20, yCord + 2, al_map_rgb(0, 0, 0), 2);
	al_draw_filled_circle(xCord + 30, yCord - 30, 15, al_map_rgb(150, 150, 150)); //right ear
	al_draw_filled_circle(xCord - 30, yCord - 30, 15, al_map_rgb(150, 150, 150)); //left ear
	al_draw_circle(xCord + 30, yCord - 30, 15, al_map_rgb(0, 0, 0), 5); //right outline
	al_draw_circle(xCord - 30, yCord - 30, 15, al_map_rgb(0, 0, 0), 5); //left outline

	al_flip_display();

	//game loop!!
	while (!byebye) {

		ALLEGRO_EVENT event;
		al_wait_for_event(eventQueue, &event);

		//check if closing
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			byebye = true;
		}
		//store coords upon click for later, then draw smth
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (event.mouse.button & 1) {
				xCord = event.mouse.x;
				yCord = event.mouse.y;
				draw = true;
			}
		}

		if (draw) {
			
			//if clicking on the top left, change the background/text color & show coords
			if (xCord <= width/2 && xCord >= 0 && yCord >= 0 && yCord <= height/2) {
				al_clear_to_color(al_map_rgb(255, 255, 255));
				
				//moves the UPA to wherever the cursor clicks
				al_draw_filled_circle(xCord, yCord, 40, al_map_rgb(150, 150, 150)); //body
				al_draw_filled_circle(xCord, yCord - 5, 2, al_map_rgb(0, 0, 0)); //nose
				al_draw_filled_circle(xCord + 25, yCord - 5, 2, al_map_rgb(0, 0, 0)); //right eye
				al_draw_filled_circle(xCord - 25, yCord - 5, 2, al_map_rgb(0, 0, 0)); //left eye
				al_draw_line(xCord - 40, yCord + 15, xCord + 40, yCord + 15, al_map_rgb(0, 0, 0), 3); //line
				al_draw_line(xCord, yCord + 2, xCord - 10, yCord + 10, al_map_rgb(0, 0, 0), 2); //mouth
				al_draw_line(xCord - 10, yCord + 10, xCord - 20, yCord + 2, al_map_rgb(0, 0, 0), 2);
				al_draw_line(xCord, yCord + 2, xCord + 10, yCord + 10, al_map_rgb(0, 0, 0), 2);
				al_draw_line(xCord + 10, yCord + 10, xCord + 20, yCord + 2, al_map_rgb(0, 0, 0), 2);
				al_draw_filled_circle(xCord + 30, yCord - 30, 15, al_map_rgb(150, 150, 150)); //right ear
				al_draw_filled_circle(xCord - 30, yCord - 30, 15, al_map_rgb(150, 150, 150)); //left ear
				al_draw_circle(xCord + 30, yCord - 30, 15, al_map_rgb(0, 0, 0), 5); //right outline
				al_draw_circle(xCord - 30, yCord - 30, 15, al_map_rgb(0, 0, 0), 5); //left outline

				al_draw_textf(font24, al_map_rgb(0, 0, 0), xCord, yCord, ALLEGRO_ALIGN_LEFT, "Mouse at: %i, %i", xCord, yCord);
				al_flip_display();
			}
			else if (xCord >= width/2 && xCord <= width && yCord >= 0 && yCord <= height/2) {
				al_clear_to_color(al_map_rgb(0, 0, 0));

				//moves the UPA to wherever the cursor clicks
				al_draw_filled_circle(xCord, yCord, 40, al_map_rgb(150, 150, 150)); //body
				al_draw_filled_circle(xCord, yCord - 5, 2, al_map_rgb(0, 0, 0)); //nose
				al_draw_filled_circle(xCord + 25, yCord - 5, 2, al_map_rgb(0, 0, 0)); //right eye
				al_draw_filled_circle(xCord - 25, yCord - 5, 2, al_map_rgb(0, 0, 0)); //left eye
				al_draw_line(xCord - 40, yCord + 15, xCord + 40, yCord + 15, al_map_rgb(0, 0, 0), 3); //line
				al_draw_line(xCord, yCord + 2, xCord - 10, yCord + 10, al_map_rgb(0, 0, 0), 2); //mouth
				al_draw_line(xCord - 10, yCord + 10, xCord - 20, yCord + 2, al_map_rgb(0, 0, 0), 2);
				al_draw_line(xCord, yCord + 2, xCord + 10, yCord + 10, al_map_rgb(0, 0, 0), 2);
				al_draw_line(xCord + 10, yCord + 10, xCord + 20, yCord + 2, al_map_rgb(0, 0, 0), 2);
				al_draw_filled_circle(xCord + 30, yCord - 30, 15, al_map_rgb(150, 150, 150)); //right ear
				al_draw_filled_circle(xCord - 30, yCord - 30, 15, al_map_rgb(150, 150, 150)); //left ear
				al_draw_circle(xCord + 30, yCord - 30, 15, al_map_rgb(0, 0, 0), 5); //right outline
				al_draw_circle(xCord - 30, yCord - 30, 15, al_map_rgb(0, 0, 0), 5); //left outline

				al_draw_textf(font24, al_map_rgb(255, 255, 255), xCord, yCord, ALLEGRO_ALIGN_LEFT, "Mouse at: %i, %i", xCord, yCord);
				al_flip_display();
			}
			else if (xCord <= width/2 && xCord >= 0 && yCord >= height/2 && yCord <= height) {
				al_clear_to_color(al_map_rgb(0, 0, 255));
				
				//moves the UPA to wherever the cursor clicks
				al_draw_filled_circle(xCord, yCord, 40, al_map_rgb(150, 150, 150)); //body
				al_draw_filled_circle(xCord, yCord - 5, 2, al_map_rgb(0, 0, 0)); //nose
				al_draw_filled_circle(xCord + 25, yCord - 5, 2, al_map_rgb(0, 0, 0)); //right eye
				al_draw_filled_circle(xCord - 25, yCord - 5, 2, al_map_rgb(0, 0, 0)); //left eye
				al_draw_line(xCord - 40, yCord + 15, xCord + 40, yCord + 15, al_map_rgb(0, 0, 0), 3); //line
				al_draw_line(xCord, yCord + 2, xCord - 10, yCord + 10, al_map_rgb(0, 0, 0), 2); //mouth
				al_draw_line(xCord - 10, yCord + 10, xCord - 20, yCord + 2, al_map_rgb(0, 0, 0), 2);
				al_draw_line(xCord, yCord + 2, xCord + 10, yCord + 10, al_map_rgb(0, 0, 0), 2);
				al_draw_line(xCord + 10, yCord + 10, xCord + 20, yCord + 2, al_map_rgb(0, 0, 0), 2);
				al_draw_filled_circle(xCord + 30, yCord - 30, 15, al_map_rgb(150, 150, 150)); //right ear
				al_draw_filled_circle(xCord - 30, yCord - 30, 15, al_map_rgb(150, 150, 150)); //left ear
				al_draw_circle(xCord + 30, yCord - 30, 15, al_map_rgb(0, 0, 0), 5); //right outline
				al_draw_circle(xCord - 30, yCord - 30, 15, al_map_rgb(0, 0, 0), 5); //left outline

				al_draw_textf(font24, al_map_rgb(255, 255, 0), xCord, yCord, ALLEGRO_ALIGN_LEFT, "Mouse at: %i, %i", xCord, yCord);
				al_flip_display();
			}
			else {
				al_clear_to_color(al_map_rgb(255, 255, 0));

				//moves the UPA to wherever the cursor clicks
				al_draw_filled_circle(xCord, yCord, 40, al_map_rgb(150, 150, 150)); //body
				al_draw_filled_circle(xCord, yCord - 5, 2, al_map_rgb(0, 0, 0)); //nose
				al_draw_filled_circle(xCord + 25, yCord - 5, 2, al_map_rgb(0, 0, 0)); //right eye
				al_draw_filled_circle(xCord - 25, yCord - 5, 2, al_map_rgb(0, 0, 0)); //left eye
				al_draw_line(xCord - 40, yCord + 15, xCord + 40, yCord + 15, al_map_rgb(0, 0, 0), 3); //line
				al_draw_line(xCord, yCord + 2, xCord - 10, yCord + 10, al_map_rgb(0, 0, 0), 2); //mouth
				al_draw_line(xCord - 10, yCord + 10, xCord - 20, yCord + 2, al_map_rgb(0, 0, 0), 2);
				al_draw_line(xCord, yCord + 2, xCord + 10, yCord + 10, al_map_rgb(0, 0, 0), 2);
				al_draw_line(xCord + 10, yCord + 10, xCord + 20, yCord + 2, al_map_rgb(0, 0, 0), 2);
				al_draw_filled_circle(xCord + 30, yCord - 30, 15, al_map_rgb(150, 150, 150)); //right ear
				al_draw_filled_circle(xCord - 30, yCord - 30, 15, al_map_rgb(150, 150, 150)); //left ear
				al_draw_circle(xCord + 30, yCord - 30, 15, al_map_rgb(0, 0, 0), 5); //right outline
				al_draw_circle(xCord - 30, yCord - 30, 15, al_map_rgb(0, 0, 0), 5); //left outline

				al_draw_textf(font24, al_map_rgb(0, 0, 255), xCord, yCord, ALLEGRO_ALIGN_LEFT, "Mouse at: %i, %i", xCord, yCord);
				al_flip_display();
			}

			draw = false;
		}

		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_event_queue(eventQueue);
	al_destroy_display(Screen);
	return 0;
}